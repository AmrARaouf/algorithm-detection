//Language: GNU C++0x


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define N 123456

#define ll __int64
ll n,m,p,q;
struct Edge{
    ll from, to, dis;
}edge[N*2];
ll edgenum;
void add(ll u,ll v,ll dis){
    Edge E={u,v,dis};
    edge[edgenum++] = E;
}
ll f[N];
ll find(ll x){return x==f[x]?x:f[x]=find(f[x]);}
void Union(ll x,ll y){
    ll fx = find(x), fy = find(y);
    if(fx==fy)return ;
    if(fx<fy)swap(fx,fy);
    f[fx]=fy;
}
set<ll>myset;
set<ll>::iterator pp;
ll siz[N];
vector<int>L,R;
struct node{
    ll fa, val;
    bool operator<(const node&x)const{
        if(x.val==val)return x.fa<fa;
        return x.val>val;
    }
    node(ll x=0,ll y = 0):fa(x),val(y){}
};
set<node>hehe;
set<node>::iterator dd;
void init(){
    hehe.clear();
    L.clear(); R.clear();
    memset(siz, 0, sizeof siz);
    myset.clear();
    for(ll i = 1; i <= n; i++)f[i]=i;
    edgenum = 0;
}

void go(){
    dd = hehe.begin();
    node x = *dd;
    hehe.erase(dd);
    dd = hehe.begin();
    node y = *dd;
    hehe.erase(dd);
    Union(x.fa,y.fa);
    ll now = min((ll)1000000000, x.val+y.val+1);
    node z = node(find(x.fa),x.val+y.val+now);
    hehe.insert(z);
    L.push_back(x.fa); R.push_back(y.fa);
    add(x.fa,y.fa,1);
}
int main(){
    ll i, j, u, v, d;
    while(~scanf("%I64d %I64d %I64d %I64d",&n,&m,&p,&q)){
        init();
        while(m--){
            scanf("%I64d %I64d %I64d",&u,&v,&d);
            add(u,v,d);
            Union(u,v);
        }
        for(i = 1; i <= n; i++)find(i);
        for(i = 1; i <= n; i++)myset.insert(f[i]);
        for(i = 0; i < edgenum; i++){
            siz[f[edge[i].from]]+=edge[i].dis;
        }
        if(myset.size()<q){puts("NO");continue;}
        if(myset.size()==q)
        {
            if(p && edgenum==0)puts("NO");
            else 
                {
                    puts("YES");
                    while(p--){
                        cout<<edge[0].from<<" "<<edge[0].to<<endl;
                    }
            }
            continue;
        }
        ll ned = myset.size()-q;
        if(ned>p){puts("NO");continue;}
        p-=ned;

        for(pp=myset.begin(); pp!=myset.end(); pp++)hehe.insert(node(*pp,siz[*pp]));
        while(ned--)go();

        puts("YES");
        for(i = 0; i < L.size(); i++)cout<<L[i]<<" "<<R[i]<<endl;
        while(p--)
            cout<<edge[0].from<<" "<<edge[0].to<<endl;
    }
    return 0;
}
/*
5
1 2
5 1
4 2
2 3

12
1 1
2 3
3 1
3 2
3 3
3 4
1 2
2 4
3 1
3 3
3 4
3 5

*/