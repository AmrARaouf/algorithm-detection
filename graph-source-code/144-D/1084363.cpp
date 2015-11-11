//Language: GNU C++


#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX(a,b) ((a)<(b))?(b):(a)
#define MIN(a,b) ((a)>(b))?(b):(a)
#define PI acos(-1.0)
#define INF 1<<30
#define EPS 1e-7
#define SIZE 100010
int Nodes,Edges,D[SIZE],length;
struct Edge{
   int v,w,u;
   Edge(){};
   Edge(int vv,int ww){
      v=vv,   w=ww;
   }
};
vector<Edge> E[SIZE];
struct EGE{
    int u,v,w;
}EG[SIZE];
struct Node{
   int n,cost;
   Node(){};
   Node(int nn,int cc){
      n=nn,   cost=cc;
   }
   bool operator<(const Node& NN) const { return cost > NN.cost; }
};
void Dijkstra(int S){
   int i,u,v,w,s;
   priority_queue<Node>Q;
   for(i=0;i<=Nodes;i++)D[i]=INF;
    D[S]=0;
    Q.push(Node(S,0));
   while(!Q.empty()){
      u=Q.top().n,   w=Q.top().cost,   Q.pop();

      for(i=0;i<E[u].size();i++){
         v=E[u][i].v,   w=E[u][i].w;

         if(D[u]+w<D[v]){
            D[v]=D[u]+w,   Q.push(Node(v,D[v]));
         }
      }
   }
}

int main(void)
{
    //freopen("In.txt","r",stdin);
    //freopen("Out.txt","w",stdout);
    int i, j,k,TEST,S,cnt,u,v,tem,w,res;
    while(scanf("%d%d%d",&Nodes,&Edges,&S)==3){
            for(j=0;j<=Nodes;j++)E[j].clear();
            tem=Edges;cnt=res=0;
            while(tem--){
                scanf("%d%d%d",&u,&v,&w);
                E[u].push_back(Edge(v,w));
                E[v].push_back(Edge(u,w));
                EG[cnt].u=u,EG[cnt].v=v,EG[cnt].w=w;cnt++;
            }
             scanf("%d",&length);
             Dijkstra(S);
             //for(j=1;j<=Nodes;j++)printf("%d ",D[j]);
             //printf("\n");

             for(j=0;j<cnt;j++){
                 u=EG[j].u,v=EG[j].v,w=EG[j].w;
                 if(D[u]<length&&w>length-D[u]&&w-(length-D[u])+D[v]>length)res++;
                 if(D[v]<length&&w>length-D[v]&&w-(length-D[v])+D[u]>length)res++;
                 if(D[u]<length&&D[v]<length&&(w+D[u]+D[v])==2*length)res++;
             }
              for(j=1;j<=Nodes;j++)if(D[j]==length)res++;
             printf("%d\n",res);

    }

    return 0;
}
