//Language: GNU C++


#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<stack>
#define N 200
#define mk make_pair
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;

pii A[N+5];
int m,tiempo[N+5],scc[N+5],low[N+5],num=0,comp=0,inc[N+5];
vector<int>adj[N+5];
vector<int>ADJ[N+5];
stack<int>s;
bool apar[N+5][N+5],vis[N+5];
int valor[N+5];

int neg(int x){
   if(x>=m)return x-m;
   return x+m;
}

void create(int x,int y){
   adj[neg(x)].pb(y);
   adj[neg(y)].pb(x);
}

bool intersect(int x,int y){
   //fijo x
   int igual=0;
   if(A[y].fi == A[x].fi || A[y].fi == A[x].se)return 0;
   if(A[y].se == A[x].fi || A[y].se == A[x].se)return 0; 
   int der=0;
   if(A[y].fi > A[x].fi && A[y].fi < A[x].se)der++;
   if(A[y].se > A[x].fi && A[y].se < A[x].se)der++;
   if(der==1)return 1;
   return 0;
}

void dfs(int u){
   tiempo[u]=num, low[u]=num++,s.push(u);
   for(int i=0;i<adj[u].size();++i){
      int v=adj[u][i];
      if(tiempo[v]==-1){
         dfs(v);
         low[u]=min(low[u],low[v]);
      }
      else if(scc[v]==-1)low[u]=min(low[u],low[v]);
   } 
   if(tiempo[u]==low[u]){
      while(scc[u]!=comp){
         int x=s.top();
         s.pop();
         scc[x]=comp;
      }
      comp++;
   }
}

int main(){
   int n,x,y;
   scanf("%d%d",&n,&m);
   for(int i=0;i<m;++i){
      scanf("%d%d",&x,&y);
      A[i]=mk(min(x,y),max(x,y));
   }
   for(int i=0;i<2*m;++i){
      adj[i].clear();
      tiempo[i]=-1,scc[i]=-1;
      valor[i]=-1;
   }
   for(int i=0;i<m;++i){
      for(int j=i+1;j<m;++j){
         if(intersect(i,j)){
            create(i,j);
            create(neg(i),neg(j));
         }
      }
   }
   for(int i=0;i<2*m;++i){
      if(tiempo[i]==-1)dfs(i);
   }
   bool vale=1;
   for(int i=0;i<m;++i){
      if(scc[i]!=-1  && scc[i]==scc[neg(i)])vale=0;
   }
   if(!vale){
      puts("Impossible");
      return 0;
   }
   for(int i=0;i<2*m;++i){
      for(int j=0;j<adj[i].size();++j){
         int v=adj[i][j];
         if(scc[i]!=scc[v] && !apar[scc[i]][scc[v]]){
            ADJ[scc[i]].pb(scc[v]);
            inc[scc[v]]++;
            apar[scc[i]][scc[v]]=1;
         }
      }
   }
   vector<int>res;
   deque<int>Q;
   for(int i=0;i<comp;++i){
      if(inc[i]==0){
         Q.pb(i);
         break;
      }
   }
   while(!Q.empty()){
      int x=Q.front();
      res.pb(x);
      vis[x]=1;
      Q.pop_front();
      for(int i=0;i<ADJ[x].size();++i){
         inc[ ADJ[x][i] ]--;
      }
      for(int i=0;i<comp;++i){
         if(inc[i]==0 && !vis[i]){
            Q.pb(i);
            break;
         }
      }
   }
   for(int i=res.size()-1;i>=0;i--){
      for(int j=0;j<2*m;++j){
         if(scc[j]==res[i]){
            if(valor[j]==-1 && valor[neg(j)]==-1){
               valor[j]=1;   
            }
         }
      }
   }
   for(int i=0;i<m;++i){
      if(valor[i]==-1){
         valor[i]=1-valor[neg(i)];
      }
   }
   for(int i=0;i<m;++i){
      if(valor[i])printf("i");
      else printf("o");
   }
   puts("");
}
