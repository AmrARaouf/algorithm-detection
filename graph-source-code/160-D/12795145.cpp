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
#include <numeric>
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

#define ATLEAST_ONE 0
#define NONE 1
#define ANY 2
int n, e, ticks, ans[100005], sz[100005], par[100005], disc[100005], low[100005];
vector<int> weightedEdges[1000004], adj[100005];
vector<ii> edgeList;


int root(int i){
    while(i != par[i])  i = par[i];
    return i;
}


void unite(int a, int b){

    int ra = root(a), rb = root(b);
    if(ra == rb)    return;

    if(sz[ra] > sz[rb]){
        sz[ra] += sz[rb];
        par[rb] = ra;
    }
    else{
        sz[rb] += sz[ra];
        par[ra] = rb;        
    }
}


void findBridges(int v, int par){
    disc[v] = low[v] = ++ticks;
    int edgeToParent = 0;
    for(int i=0;i<(int)adj[v].size();i++){
        int id = adj[v][i];
        int vv = v ^ root(edgeList[id].ff) ^ root(edgeList[id].ss);
        if(vv == par){
            edgeToParent++;
            if(edgeToParent == 1)   continue;
        }
        if(disc[vv] == -1){
            findBridges(vv, v);
            low[v] = min(low[v], low[vv]);
            if(low[vv] > disc[v])   ans[id] = ANY;
        }
        else
            low[v] = min(low[v], disc[vv]);
    }
}


int main()
{
    // ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);

    scanf("%d%d", &n, &e);
    for(int i=0;i<e;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edgeList.pb(ii (a, b));
        weightedEdges[c].pb(i);
    }

    for(int i=1;i<=n;i++){
        sz[i] = 1;
        par[i] = i;
    }

    memset(disc, -1, sizeof(disc));
    set<int> affected;
    for(int w=1;w<=1000000;w++){

        for(int i=0;i<(int)weightedEdges[w].size();i++){

            int id = weightedEdges[w][i];
            int a = edgeList[id].ff, b = edgeList[id].ss;

            if(root(a) == root(b)){
                ans[id] = NONE;
                continue;
            }

            a = root(a);    b = root(b);
            adj[a].pb(id);
            adj[b].pb(id);
            affected.insert(a);
            affected.insert(b);
        }

        for(set<int>::iterator it=affected.begin();it!=affected.end();it++)
            if(disc[(*it)] == -1)
                findBridges((*it), -1);

        for(set<int>::iterator it=affected.begin();it!=affected.end();it++)
            disc[(*it)] = -1;
        affected.clear();
        for(int i=0;i<(int)weightedEdges[w].size();i++){
            int id = weightedEdges[w][i];
            int a = edgeList[id].ff, b = edgeList[id].ss;
            a = root(a);    b = root(b);
            if(a == b || w==2)  continue;
            adj[a].pop_back();
            adj[b].pop_back();
        }

        for(int i=0;i<(int)weightedEdges[w].size();i++){
            int id = weightedEdges[w][i];
            int a = edgeList[id].ff, b = edgeList[id].ss;
            a = root(a);    b = root(b);
            unite(a, b);
        }
    }

// for(int i=1;i<=n;i++)   cout<<root(i)<<" ";cout<<endl;
// cout<<"affected: ";for(set<int>::iterator it=affected.begin();it!=affected.end();it++) cout<<(*it)<<" ";cout<<endl;
// for(int i=1;i<=n;i++)   cout<<disc[i]<<" ";cout<<endl;
// for(int i=1;i<=n;i++)   cout<<low[i]<<" ";cout<<endl;
// for(int i=1;i<=n;i++){
//     cout<<i<<" : ";for(int j=0;j<(int)adj[i].size();j++)    cout<<adj[i][j]<<" ";cout<<endl;
// }cout<<endl;


    for(int i=0;i<e;i++)
        if(ans[i] == ATLEAST_ONE)   printf("at least one\n");
        else if(ans[i] == ANY)  printf("any\n");
        else    printf("none\n");
    return 0;
}












