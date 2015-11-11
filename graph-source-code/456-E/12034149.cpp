//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) a.begin() , a.end()
int const MAX = 300007;
int n,q,m;
vector<vector<int> > G;
int longestPath[MAX];
int p[MAX];

int find(int x){
    return ( p[x]==x ? x : p[x] = find(p[x]) );
}
int len,at;
void dfs(int u,int p,int l){
    if(len<l){
        len = l;
        at = u;
    }
    for(int i=0;i<(int)G[u].size();i++){
        if(G[u][i]==p) continue;
        dfs(G[u][i],u,l+1);
    }
}

int main(void){
//  freopen("file.in","r",stdin);
    cin >> n >> m >> q;
    G.resize(n);
    for(int i=0;i<n;i++) p[i] = i;
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        G[--u].pb(--v);
        G[v].pb(u);
        p[ find(u) ] = find(v);
    }
    for(int i=0;i<n;i++){
        if(p[i]!=i) continue;
        len = -1;
        dfs(i,-1,0);
        len = -1;
        dfs(at,-1,0);
        longestPath[ i ] = len;
    }
//  for(int i=0;i<n;i++){
//      cout << i+1 << " " << p[i] << " " << len << endl;
//  }
    while(q--){
        int c;
        scanf("%d",&c);
        if(c==1){
            int x;
            scanf("%d",&x);
            --x;
            printf("%d\n",longestPath[find(x)]);
        }else{
            int x,y;
            scanf("%d%d",&x,&y);
            --x , --y;
            x = find(x);
            y = find(y);
            if(x==y) continue;
            p[x] = y;
            longestPath[y] = max(longestPath[y] , max( longestPath[x] , (longestPath[x]+1)/2+1+(longestPath[y]+1)/2 ) );
        }
    }
    return 0;
}




