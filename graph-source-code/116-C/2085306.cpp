//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

#define pb push_back
#define clean(a,b) memset(a,b,sizeof(a))
#define oo 1<<20
#define dd double
#define ll long long
#define ull unsigned long long
#define ff float
#define EPS 10E-10
#define fr first
#define sc second
#define MAXX 100000
#define PRIME_N 1000000
#define INFI 1<<30
#define SZ(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define paii pair<int,int>

//int rx[] = {0,-1,0,1,1,-1,-1,0,1}; //four direction x
//int ry[] = {0,1,1,1,0,0,-1,-1,-1 };  //four direction y
//int rep[] = {1,1,4,4,2,1,1,4,4,2}; //repet cycle for mod
//void ullpr(){printf("range unsigned long long : %llu\n",-1U);} //for ull
//void ulpr(){printf("range unsigned long : %lu\n",-1U);} //for ull
//void upr(){printf("range unsigned : %u\n",-1U);} //for ull

int col[MAXX];

vector<int>vAdj[MAXX];

vector<int>Order;

void dfs_top(int u)
{
    col[u]  =1 ;
    for(int i = 0 ; i<SZ(vAdj[u]) ; i++)
    {
        int v = vAdj[u][i];
        if(!col[v])
            dfs_top(v);
    }
    Order.pb(u);
    return;
}

int dfs(int u,int depth)
{
    col[u] = 1;
    int ret = depth;
    for(int i = 0 ; i<SZ(vAdj[u]) ; i++)
    {
        int v = vAdj[u][i];
        if(!col[v])
            ret = max(ret , dfs(v,depth+1));
    }
    return ret;
}

int main()
{
    int n;
    while(scanf(" %d",&n)==1)
    {
        for(int i  =1 ; i<=n ;i++) vAdj[i].clear();
        clean(col,0);
        int max_depth = 0;
        int par;
        for(int i =1 ; i<=n ; i++)
        {
            scanf(" %d",&par);
            if(par==-1) continue;
            vAdj[par].pb(i);
        }
        Order.clear();
        for(int i =1  ; i<=n ; i++)
            if(!col[i])
                dfs_top(i);
        clean(col,0);
        for(int i =SZ(Order)-1 ;i>=0  ; i--)
            if(!col[Order[i]])
                max_depth = max(max_depth , dfs(Order[i],1));
        printf("%d\n",max_depth);
    }
    return 0;
}
