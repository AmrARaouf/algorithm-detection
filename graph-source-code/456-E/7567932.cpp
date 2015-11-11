//Language: GNU C++


#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#define mod 1000000007
#define INF 200000000
using namespace std;
int parent[300010];
int r[300010];
int f(int i)
{
    if(parent[i]==i)
        return i;
    return parent[i]=f(parent[i]);
}
bool union_n(int i,int j)
{
    int ri=f(i);
    int rj=f(j);
    if(ri==rj)
        return false;
    parent[rj]=ri;
    return true;
}
bool union_r(int i,int j)
{
    int ri=f(i);
    int rj=f(j);
    if(ri==rj)
        return false;
    if(r[ri]>r[rj])
    {
        parent[rj]=ri;
        r[ri]=max(r[ri],(r[ri]+1)/2 + (r[rj]+1)/2 +1 );
        return true;
    }
    else
    {
        parent[ri]=rj;
        r[rj]=max(r[rj],(r[ri]+1)/2 + (r[rj]+1)/2 +1 );
        return true;
    }
}
int n ,m ,q;
vector < vector < int > > graph(300010);
bool visited1[300010];
bool visited2[300010];
int l,ma;
void dfs1(int v, int depth)
{
    visited1[v]=true;
    if(ma<depth)
        ma=depth,l=v;
    for(int i =0;i<graph[v].size();i++)
        if(!visited1[graph[v][i]])
            dfs1(graph[v][i],depth+1);
}
void dfs2(int v,int depth)
{
    visited2[v]=true;
    if(ma<depth)
        ma=depth;
    for(int i =0;i<graph[v].size();i++)
        if(!visited2[graph[v][i]])
            dfs2(graph[v][i],depth+1);
}
int main()
{
    //freopen("budget.in","r",stdin);
    //freopen("budget.out","w",stdout);
    scanf("%d %d %d",&n,&m,&q);
    for(int i =1;i<=n;i++)
        parent[i]=i;
    for(int i =0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
        union_n(x,y);
    }
    for(int i =1;i<=n;i++)
    {
       if(!visited1[i])
       {
           ma=0;
           l=i;
           dfs1(i,0);
           ma=0;
           dfs2(l,0);
           r[f(i)]=ma;
       }
    }
    for (int i =0;i<q;i++)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",r[f(x)]);
        }
        else
        {
            int x,y;
            scanf("%d %d",&x,&y);
            union_r(x,y);
        }
    }
    return 0;
}

