//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
typedef int ll;

const ll Maxn=3e5+10;
const ll Mod=1e9+7;
const ll Max=1e4+2;

ll place[Maxn],MAX_MASIR[Maxn],dis,tmp,tmp1,tmp2,depth,depth_max,depth1_max;
bool mark[Maxn],markk[Maxn],markkk[Maxn];
vector<ll>E[Maxn],V[Maxn],Component;

void dsu(ll u,ll v){
        if(place[u]==place[v])
                return;
        ll u1=place[u],v1=place[v];
        if(E[u1].size()>=E[v1].size())
                for(ll i=0;i<E[v1].size();i++){
                        place[E[v1][i]]=u1;
                        E[u1].push_back(E[v1][i]);
                }
        else
                for(ll i=0;i<E[u1].size();i++){
                        place[E[u1][i]]=v1;
                        E[v1].push_back(E[u1][i]);
                }
        return;
}

void dfs(ll u){
    mark[u]=true;
    for(ll i=0;i<V[u].size();i++){
        if(!mark[V[u][i]]){
            dis++;
            if(dis>depth_max)
                depth=V[u][i];
            depth_max=max(depth_max,dis);
            dfs(V[u][i]);
            dis--;
        }
    }
        return;
}

void DFS(ll u){
    markkk[u]=true;
    for(ll i=0;i<V[u].size();i++){
        if(!markkk[V[u][i]]){
            dis++;
            depth1_max=max(depth1_max,dis);
            DFS(V[u][i]);
            dis--;
        }
    }
        return;
}

int main(){
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    ll n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    //cin>>n>>m>>q;
    for(ll i=1;i<=n;i++){
        E[i].push_back(i);
        place[i]=i;
    }
    //printf("%d\n",n);return 0;
    for(ll i=1;i<=m;i++){
        ll u,v;
        scanf("%d%d",&v,&u);
        //cin>>u>>v;
        V[u].push_back(v);
        V[v].push_back(u);
        dsu(u,v);
    }
    for(ll i=1;i<=n;i++){
        if(!markk[place[i]]){
            Component.push_back(place[i]);
            markk[place[i]]=true;
        }
    }
    for(ll j=0;j<Component.size();j++){
        ll i=Component[j];
        depth=i;
        depth_max=0;
        depth1_max=0;
        dfs(i);
        DFS(depth);
        MAX_MASIR[place[i]]=depth1_max;
    }
    for(ll i=1;i<=q;i++){
        ll k,u,v;
        cin>>k;
        if(k==1){
            scanf("%d",&u);
        
            printf("%d\n",MAX_MASIR[place[u]]);
        
        }
        else{
            //cin>>u>>v;
            scanf("%d%d",&u,&v);
            tmp1=MAX_MASIR[place[u]];
            tmp2=MAX_MASIR[place[v]];
            if(place[u]==place[v]){
                continue;
            }
            tmp=((tmp1+1)/2)+((tmp2+1)/2)+1;
            dsu(u,v);
            MAX_MASIR[place[u]]=max(tmp1,max(tmp2,tmp));
        }
    }
    return 0;
}