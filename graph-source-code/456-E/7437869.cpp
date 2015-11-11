//Language: GNU C++



#include <string>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#define FOR(p,star,end) for(int p = star ; p<end ; p++)
#define FORR(p,star,end) for(int p = star ; p>=end ; p--)
#define pb push_back
#define INF 1000000000
#define MOD  5
#define MAX 300020
#define REF 97
using namespace std;
int A[MAX],diamter[MAX];
bool vis[MAX];
int dis[MAX];
vector<vector<int > >G;
int parent(int node)
{
    if(A[node]==node)return node;
    return A[node]=parent(A[node]);
}
void Union(int node1 , int node2 )
{
    A[parent(node1)]=parent(node2);
}
vector<int>Comp(MAX);
int getdiameter(int node, int lev)
{

    queue<int>BFS;
    BFS.push(node);
    dis[node]=0;
    int c=0;
    Comp[c++]=(node);
    int Max = 0 , ind = node;
    while(!BFS.empty())
    {
        int cur = BFS.front();
        BFS.pop();

        FOR(i,0,G[cur].size())
        {
            if(dis[G[cur][i]]==INF)
            {
                Comp[c++]=(G[cur][i]);
                dis[G[cur][i]]=dis[cur]+1;
                if(dis[G[cur][i]]>Max)
                {
                    Max=dis[G[cur][i]];
                    ind = G[cur][i];
                }
                BFS.push(G[cur][i]);
            }
        }
    }
    FOR(i,0,c)dis[Comp[i]]=INF;
    if(lev == 1 ) return Max;
    return getdiameter(ind,lev+1);
//    return 1;

}
/*
8 6 1000
1 2
2 3
4 5
4 6
6 7
6 8
*/


int main()
{
    int q , n , m , u , v ;
    scanf("%d %d %d",&n,&m,&q);

    FOR(i,1,n+1)diamter[i]=-1,A[i]=i;

    G.assign(n+3 ,vector<int>());
    FOR(i,0,m)
    {
        scanf("%d%d",&u,&v);
        G[u].pb(v);
        G[v].pb(u);
        Union(u,v);

    }
    FOR(i,0,MAX)dis[i]=INF;
    FOR(i,1,n+1)
    if(diamter[parent(i)]==-1)
        diamter[parent(i)]=getdiameter(i,0);




    FOR(i,0,q)
    {
        scanf("%d",&m);
        if(m==1)
        {
            scanf("%d",&u);
            printf("%d\n",diamter[parent(u)]);

        }
        else
        {
            scanf("%d %d",&u,&v);
            if(parent(u)!=parent(v))
            {
                int diam1=diamter[parent(u)],diam2=diamter[parent(v)];
                Union(parent(u),parent(v));
                diamter[parent(v)]=max(diam1,max(diam2,1+(int)ceil(double(diam1)/2.0)+(int)ceil(double(diam2)/2.0)));
            }

        }
    }


    return 0;


}


