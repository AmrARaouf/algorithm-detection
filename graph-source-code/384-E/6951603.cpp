//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<set>
#include<queue>
#include<vector>
#include<map>
using namespace std;
#define ll __int64
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define N 201000
ll n ,m;
inline ll Mid(ll a,ll b){return (a+b)>>1;}
struct Edge{
    ll from, to, nex;
}edge[N<<1];
ll head[N], edgenum;
void add(ll u,ll v){
    Edge E = {u,v,head[u]};
    edge[edgenum] = E;
    head[u] = edgenum++;
}
ll in[N], out[N], fa[N], Time, dep[N], V[N];
void dfs(ll u, ll father, ll deep){
    fa[u] = father;
    dep[u] = deep;
    in[u] = ++Time;

    for(ll i = head[u];~i; i = edge[i].nex){
        ll v = edge[i].to;      if(v==father)continue;
        dfs(v,u,deep+1);
    }
    out[u] = Time;
}
struct node{
    struct E{
        ll l, r, val, lazy;
    }t[N<<2];
    void push_down(ll id){
        if(t[id].l==t[id].r || t[id].lazy == 0)return ;
        t[L(id)].val += t[id].lazy;
        t[R(id)].val += t[id].lazy;
        t[L(id)].lazy+=t[id].lazy;
        t[R(id)].lazy+=t[id].lazy;
        t[id].lazy = 0;
    }
    void build(ll l, ll r, ll id){
        t[id].l = l; t[id].r = r;
        t[id].val = 0;
        t[id].lazy = 0;
        if(l==r)return;
        ll mid = Mid(l,r);
        build(l,mid,L(id));build(mid+1,r,R(id));
    }
    void update(ll l, ll r,ll val,ll id){
        push_down(id);
        if(l == t[id].l && t[id].r == r) { t[id].val += val; t[id].lazy = val; return ;}
        
        ll mid = Mid(t[id].l, t[id].r);
        if(mid<l)update(l,r,val,R(id));
        else if(r<=mid)update(l,r,val,L(id));
        else {
            update(l,mid,val,L(id));
            update(mid+1,r,val,R(id));
        }
    }
    ll query(ll l, ll r, ll id){
        push_down(id);
        if(l == t[id].l && t[id].r == r)return t[id].val;
        
        ll mid = Mid(t[id].l, t[id].r);
        if(mid<l)return query(l,r,R(id));
        else if(r<=mid)return query(l,r,L(id));
        return query(l,mid,L(id))+query(mid+1,r,R(id));
    }
}tree[2];
ll query(ll u){
    ll ans = tree[dep[u]&1].query(in[u],in[u],1);
    return ans;
}
void init(){Time = 0; memset(head, -1, sizeof head); edgenum = 0;}
int main(){  
    ll i, j, u, v;
    while(cin>>n>>m) {
        init();
        for(i=1;i<=n;i++)cin>>V[i];
        for(i=1;i<n;i++){
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        dfs(1,-1,1);
        tree[0].build(1,n,1);   
        tree[1].build(1,n,1);
        while(m--){
            cin>>u;
            if(u==1) {
                cin>>u>>v;
                tree[dep[u]&1].update(in[u],out[u],v,1);
                if(in[u]<out[u])
                    tree[!(dep[u]&1)].update(in[u]+1,out[u],-v,1);
            }
            else {
                cin>>u;
                cout<<query(u)+V[u]<<endl;
            }
        }
    }
    return 0;  
}
/*
1 4
10
1 1 10
2 1
1 1 -100
2 1

2 99
10 100
1 2
1 1 10
2 1
2 2
1 1 -10
2 1
2 2

ans 1:
20
-80
ans 2:
20
90
10
100

*/