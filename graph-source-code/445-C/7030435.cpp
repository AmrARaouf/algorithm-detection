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
#define x first
#define y second
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
const LL Linfi = (LL) 9e18;
const LL MOD = 1000000007;
#define maxn 1000005

struct edge{
    int st, en;
    int cost, sum;
};

int n, m, u, v, c;
int x[505];
int adj[505][505];
double ans = 0;

void solve(){

}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    #endif
    memset(adj,0,sizeof(adj));
    cin >> n >> m;
    FOR(i,1,n) cin >> x[i];
    FOR(i,1,m){
        cin >> u >> v >> c;
        adj[u][v] = adj[v][u] = c;
        double tu = x[u]+x[v];
        double mau = c;
        ans = max(ans, tu/mau);
    }
    printf("%.9lf\n", ans);
    solve();

    return 0;
}


