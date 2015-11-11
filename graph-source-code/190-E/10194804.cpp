//Language: GNU C++


// In the Name of GOD //
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <fstream>
#include <queue>
#include <cstring>
#include <map>
#include <cstdio>
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
using namespace std;
#define err(x) cout<<#x<<" : "<<x<<'\n';


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back
#define X first
#define Y second

const int N=2000*1000+2;


int n, m, x, y, cnt = 0, par[N], sum, s[N], deg[N], mo[N];
vector <int> adj[N], A, B, ans[N];
bool vis[N] ,is[N] ;

int get_par(int v)
{
    if( par[v] == v )
        return v;
    return par[v] = get_par(par[v]) ;
}

void add(int u,int v)
{
    u = get_par(u);
    v = get_par(v);
    if(u==v)return ;
    if( s[u] < s[v] )
        swap(u,v);
    par[v] =  u ;
    s[u] += s[v] ;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
        deg[x]++;
        deg[y]++;
    }
    int u = min_element(deg + 1,deg + n + 1) - deg;
    for(int i=0;i< sz(adj[u]);i++)
    {
        vis[adj[u][i]] = true;
        A.pb(adj[u][i]);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
            B.pb(i);
    for(int i=1;i<=n;i++)
        s[i]=1;
    s[u]=sz(B);
    for(int i=1;i<=n;i++)
        par[i]=(vis[i])?i:u;
    for(int i=0;i<sz(A);i++)
    {
        int v = A[i];
        for(int j=0;j<sz(adj[v]);j++)
            is[adj[v][j]] = true;
        for(int j=0;j<sz(A);j++ )
            if(!is[A[j]])
               add(v, A[j]);
         for(int j=0;j<sz(adj[v]);j++)
            is[adj[v][j]] = false ;
    }
    for(int i=0;i<sz(A);i++)
    {
        int v = A[i];
        for(int j=0;j<sz(adj[v]);j++)
            is[adj[v][j]] = true;
        for(int j=0;j<sz(B);j++ )
            if(!is[B[j]])
               add(v, B[j]);
         for(int j=0;j<sz(adj[v]);j++)
            is[adj[v][j]] = false ;
    }
    for(int i=1;i<=n;i++)
    {
        int k = get_par(i);
        if(mo[k] == 0)
            mo[k] = ++cnt;
        ans[mo[k]].pb(i);
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
    {
        printf("%d ",sz(ans[i]));
        for(int j=0;j<sz(ans[i]);j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0 ;
}

		 	  	 						       		   	