//Language: GNU C++11


#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define ZERO 1e-9
using namespace std;
int n,m;
vector<pair<int,int> >g[100005];
pair<pair<int,int>,int>el[100005];
int p[100005];
int vis[100005];
int vvis[100005];
int rvis[100005];
map<int,pair<set<pair<int,int> >,set<pair<int,int> > > >ev;
pair<int,int>par[100005];
int getp(int c){
    return (p[c]==c)?c:p[c]=getp(p[c]);
}
int l[100005],t=1;
void dfs(int u,int d){
    rvis[u]=d;
    int en=t;
    for(int i=0,v,w,id;i<g[u].size();++i){
        v=g[u][i].F;
        id=g[u][i].S;
        w=el[id].S;
        if(!rvis[v]&&vvis[id]){
            if(vis[id]==1)ev[w].F.insert(mp(-d,id));
            else if(vis[id]==2)ev[w].S.insert(mp(-d,id));
            dfs(v,d+1);
            ev[w].F.erase(mp(-d,id));
            ev[w].S.erase(mp(-d,id));
            par[v]=mp(u,id);
        }else if(rvis[v]>0&&!vvis[id]){
            vector<pair<int,int> >tmp;
            if(-ev[w].F.begin()->F>=rvis[v]||-ev[w].S.begin()->F>=rvis[v])vis[id]=2;
            for(auto &k:ev[w].F){
                if(-k.F<rvis[v])break;
                vis[k.S]=2;
                ev[w].S.insert(k);
                tmp.pb(k);
            }
            for(int i=0;i<tmp.size();++i)ev[w].F.erase(tmp[i]);
        }else if(rvis[v]==-1&&l[v]<en&&!vvis[id]){
            int lca=v;
            while(rvis[lca]==-1){
                if(el[par[lca].S].S==el[id].S){
                    vis[par[lca].S]=vis[id]=2;
                }lca=par[lca].F;
            }
            vector<pair<int,int> >tmp;
            if(-ev[w].F.begin()->F>=rvis[lca]||-ev[w].S.begin()->F>=rvis[lca])vis[id]=2;
            for(auto &k:ev[w].F){
                if(-k.F<rvis[lca])break;
                vis[k.S]=2;
                ev[w].S.insert(k);
                tmp.pb(k);
            }
            for(int i=0;i<tmp.size();++i)ev[w].F.erase(tmp[i]);
        }
    }
    l[u]=t++;
    rvis[u]=-1;
}
struct cmp{
    bool operator()(const pair<int,int>&a,const pair<int,int>&b){
        return a.F>b.F;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n>>m;
    priority_queue<pair<int,int> ,vector<pair<int,int>>,cmp>pq;
    for(int i=0;i<n;++i)p[i]=i;
    for(int i=0,u,v,w;i<m;++i){
        cin>>u>>v>>w;
        el[i]=mp(mp(u-1,v-1),w);
        pq.push(mp(w,i));
        g[u-1].pb(mp(v-1,i));
        g[v-1].pb(mp(u-1,i));
    }
    for(int i=1;i<n;++i){
        while(true){
            int id=pq.top().S,pu,pv;
            pq.pop();
            pu=getp(el[id].F.F);
            pv=getp(el[id].F.S);
            if(pu!=pv){
                p[pv]=pu;
                vis[id]=vvis[id]=1;
                break;
            }
        }
    }

    dfs(0,2);
    for(int i=0;i<m;++i){
        if(vis[i]==0)cout<<"none\n";
        if(vis[i]==1)cout<<"any\n";
        if(vis[i]==2)cout<<"at least one\n";
    }
}
