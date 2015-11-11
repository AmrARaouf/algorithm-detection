//Language: GNU C++


#include <string>    
#include <vector>    
#include <map>    
#include <utility>    
#include <cmath>    
#include <cstdlib>    
#include <cstring>    
#include <queue>    
#include <stack>    
#include <set>    
#include <sstream>    
#include <algorithm>    
#include <iostream>    
#include <iomanip>
#include <cstdio>
#include <cassert> 
using namespace std;    
     
#define INF 0x3f3f3f3f   
#define INFL 1LL<<62   
#define ALL(v) v.begin(),v.end()    
typedef pair<int,int> pii;    
typedef long long ll;

ll mat[1005][1005];
int n;
ll taxitime[1005];
ll taxicost[1005];
int seen[1005];
int vis[1005];
ll d[1005];

void dfs(int x,ll cost){
    seen[x]=1;
    for(int i=0;i<n;i++)
        if(mat[x][i]&&!seen[i]&&cost>=mat[x][i])
            dfs(i,cost-mat[x][i]);
        
}

int main(){
    int e;
    cin>>n>>e;
    int s,t; 
    cin>>s>>t; s--;t--;
    for(int i=0;i<e;i++){
        int a,b; ll c; 
        cin>>a>>b>>c; a--;b--;
        if(!mat[a][b]) mat[a][b]=mat[b][a]=c;
        else mat[a][b]=mat[b][a]=min(mat[a][b],c);
    }
    
    for(int i=0;i<n;i++)
        cin>>taxitime[i]>>taxicost[i];
    
    for(int i=0;i<n;i++) d[i]=INFL;
    memset(vis,0,sizeof(vis));
    d[s]=0;
    while(1){
        int u=-1; ll dmin=INFL;
        for(int i=0;i<n;i++)
            if(!vis[i]&&d[i]<dmin){
                u=i;
                dmin=d[i];
            }
        if(u==-1||u==t) break;
        vis[u]=1;
        
        memset(seen,0,sizeof(seen));
        dfs(u,taxitime[u]);
        
        for(int i=0;i<n;i++)
            if(u!=i&&seen[i]&&d[u]+taxicost[u]<d[i]){
                d[i]=d[u]+taxicost[u];
            }
    }
    if(d[t]==INFL) cout<<"-1"<<endl;
    else cout<<d[t]<<endl;
    
    return 0;
}
