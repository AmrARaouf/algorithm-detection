//Language: GNU C++


//satyaki3794
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cctype>
#include <cassert>
#include <bitset>
#include <iomanip>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define PI (3.14159265)
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define INF (100000005)
#define SIZE (2)
#define TREESIZE (302144)
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define epsilon 1e-8 //add to double before casting to integer
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;


#define matrix vector< vector<ll> >

matrix matmul(matrix &a, matrix &b){
    int i, j, k, n = a.size();
    matrix ans (n, vector<ll>(n));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            ll temp = 0;
            for(k=0;k<n;k++)    temp = (temp + a[i][k] * b[k][j]) % MOD;
            ans[i][j] = temp;
        }

    return ans;
}

matrix matpwr(matrix &a, ll p){
    int n = a.size();
    matrix ans(n, vector<ll> (n));
    for(int i=0;i<n;i++)    ans[i][i] = 1;

    while(p){
        if(p&1) ans = matmul(ans, a);

        a = matmul(a, a);
        p >>= 1;
    }
    return ans;
}


ll pwr(ll base, ll p, ll mod = MOD){
    ll ans = 1;
    while(p){
        if(p & 1)   ans = (ans * base) % mod;
        base = (base * base) % mod;
        p /= 2;
    }
    return ans;
}


ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}


ll lcm(ll a, ll b){
    return (a*b) / gcd(a, b);
}


ll invMod(ll n, ll mod = MOD){
    return pwr(n, mod-2);
}


int n, state[102];
vector<ii> adj[102];
vector<int> affected;
bool impossible = false;

void dfs(int v){

    affected.pb(v);
    for(int i=0;i<(int)adj[v].size();i++){

        int vv = adj[v][i].ff;
        int val = adj[v][i].ss;

        if(state[vv] == -1){
            state[vv] = val ^ state[v];
            dfs(vv);
        }
        else if(state[v]^state[vv] != val)
            impossible = true;
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);

    //bipartite matching
    //colour graph using 2 colors such that endpoints of edges valued 1 are different
    //and endpoints of edges coloured 0 are same

    int e;
    cin>>n>>e;
    while(e--){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].pb(ii (b, 1^c));
        adj[b].pb(ii (a, 1^c));
    }
    memset(state, -1, sizeof(state));

    for(int i=1;i<=n;i++){

        if(state[i] != -1)  continue;

        affected.clear();
        state[i] = 0;
        dfs(i);

        if(!impossible) continue;

        while(!affected.empty()){
            state[affected.back()] = -1;
            affected.pop_back();
        }
        impossible = false;
        state[i] = 1;
        dfs(i);

        if(impossible){
            cout<<"Impossible";
            return 0;
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
        ans += state[i];
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        if(state[i] == 1)   cout<<i<<" ";
    return 0;
}














