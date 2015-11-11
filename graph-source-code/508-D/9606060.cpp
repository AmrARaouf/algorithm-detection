//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <fstream>
#include <ctime>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOD(i,a,b) for(int i=a;i>b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl

using namespace std;

typedef pair<int,int>II;
typedef pair<int,II>PII;
template<class T> T gcd(T a, T b) {T r; while(b!=0) {r=a%b;a=b;b=r;} return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }

const double PI = 2*acos(0.0);
const double eps = 1e-9;
const int infi = 1e9;
const LL Linfi = (LL) 1e18;
const LL MOD = 1000000007;
#define maxn 200005

/**
bridges are the last edgees you want to cross
only two odd edges
*/

int n, m;
string s[maxn];
int in[maxn], out[maxn], xet[maxn];
vector<int> adj[maxn];


int encode(char a){
    if(a >= 'a' && a <= 'z') return a - 'a';
    if(a >= 'A' && a <= 'Z') return a - 'A' + 26;
    if(a >= '0' && a <= '9') return a - '0' + 52;
}

int encode2(char a, char b){
    return encode(a) * 62 + encode(b);
}

char decode(int u){
    if(u < 26) return 'a' + u;
    else if(u < 52) return 'A' + (u-26);
    else return '0' + (u-52);
}

string decode2(int u){
    string ans = "";
    char x = decode(u/62);
    char y = decode(u%62); //cout << x << " " << y << endl;
    ans += x; ans += y;
    return ans;
}

void solve(){
    n = 62*62;
    int st = -1, c1 = 0, c2 = 0;

    FOR(i,0,n){
        if(in[i] == out[i]) continue;
        else if(in[i] > out[i] + 1){
            cout << "NO" << endl; return;
        }
        else if(out[i] > in[i] + 1){
            cout << "NO" << endl; return;
        }
        else if(in[i] == out[i]+1){
            c2++;
        }
        else if(out[i] == in[i]+1){
            c1++;
            st = i;
        }
    }
    //cout << c1 << " " << c2 << endl;
    if(c1 > 1 || c2 > 1){ cout << "NO" << endl; return; }
    if(c1 != c2) { cout << "NO" << endl; return;} /// Euler path or Euler cycle

    /// Euler cycle case
    if(st == -1){
        FOR(i,0,n){
            if(out[i] > 0) {
                st = i;
                break;
            }
        }
    }

    vector<int> res;
    stack<int> S;
    S.push(st);
    while(!S.empty()){
        int u = S.top();
        if(adj[u].empty()){
            res.pb(u);
            S.pop();
        }
        else{
            S.push(adj[u].back());
            adj[u].pop_back();
        }
    }

    if(res.size() != m+1){
        cout << "NO" << endl; return;
    }

    reverse(res.begin(), res.end());
    cout << "YES" << endl;
    cout << decode2(res[0]);
    FO(i,1,res.size()){
        cout << decode(res[i]%62);
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    #endif
    cin >> m;
    FOR(i,1,m){
        cin >> s[i];
        int u = encode2(s[i][0], s[i][1]);
        int v = encode2(s[i][1], s[i][2]);
        adj[u].pb(v);
        out[u]++; in[v]++;
    }

    solve();


    return 0;
}

