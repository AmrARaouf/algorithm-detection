//Language: GNU C++11


#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

#define nln        puts("")                         ///prLLInewline
#define getLLI(a)  scanf("%d",&a);
#define max3(a,b,c) max(a,max(b,c))                  ///3 ta theke max
#define min3(a,b,c) min(a,min(b,c))                  ///3 ta theke min

#define FOR1(i,n)  for(LLI i=1;i<=n;i++)
#define FOR0(i,n)  for(LLI i=0;i<n;i++)                 ///looping
#define FORR(i,n)  for(LLI i=n-1;i>=0;i--)
#define ALL(p)     p.begin(),p.end()

#define SET(p)     memset(p,-1,sizeof(p))
#define CLR(p)     memset(p,0,sizeof(p))            ///memset
#define MEM(p,v)   memset(p,v,sizeof(p))

#define READ(f)    freopen(f, "r", stdin)           /// file
#define WRITE(f)   freopen(f, "w", stdout)

#define SZ(c)      (LLI)c.size()
#define PB(x)      push_back(x)                     ///STL defines
#define MP(x,y)    make_pair(x,y)
#define ff         first
#define ss         second

#define LI         long LLI
#define LLI        long long
#define f64        long double
#define PI         acos(-1.0)                        ///PI er value
#define mx 300005
#define ll long long
#define inf 1e10
vector<LLI>G[mx],dis[mx];
void CI(LLI &_x)
{
    scanf("%I64d",&_x);

}

map<pair<LLI,LLI>,LLI>train_route;

struct node
{
    ll city,cost;
    bool operator <(const node& p)const
    {
        return cost>p.cost;
    }
};

//vector<ll>G[mx],dis[mx];
LLI col[mx];
ll d[mx];
ll path[mx];
ll djs(ll src)
{
    for(ll i=0; i<mx; i++)
        d[i]=inf,path[i]=-1;
    d[src]=0;
    node a;
    a.city=src,a.cost=0;
    priority_queue<node>Q;
    Q.push(a);
    while(!Q.empty())
    {
        a=Q.top();
        Q.pop();
        ll u=a.city;
        if(col[u]==1)continue;
            col[u]=1;
//        if(des==u)
//        {
//            // puts("ffffffffff");
//            return d[u];
//
//        }

        for(ll i=0; i<G[u].size(); i++)
        {

            ll v=G[u][i];
            //  cout<<v<<" ";
            //cout<<d[u]<<" "<<dis[u][i]<<endl;
            if(d[u]+dis[u][i]<d[v])
            {
                //puts("ffffffffff");

                d[v]=d[u]+dis[u][i];
                path[v]=u;
                a.city=v;
                a.cost=d[v];
                Q.push(a);

            }



        }

    }
    return -1;
}
LLI used[mx];
int main()
{

    LLI n,m,k;
//    cin>>n>>m>>k;
    CI(n);
    CI(m);
    CI(k);
    LLI u,v,w;

    FOR0(i,m)
    {

        LLI u,v,w;
//        cin>>u>>v>>w;
        CI(u);
        CI(v);
        CI(w);
//        if(found[MP(min(u,v),max(u,v))]==0)
//            found[MP(min(u,v),max(u,v))]=1<<30;
        //   found[MP(min(u,v),max(u,v))]=min(w,found[MP(min(u,v),max(u,v))]);
        G[u].PB(v);
        G[v].PB(u);
        dis[u].PB(w);
        dis[v].PB(w);
    }


    vector<LLI>V;
    memset(col,-1,sizeof col);
    LLI kount=0;
    FOR0(i,k)
    {
        LLI s,y;
        // cin>>s>>y;
        CI(s);
        CI(y);
        V.PB(s);
        G[1].PB(s);
        dis[1].PB(y);

    }
    djs(1);
    FOR0(i,k)
    {
        G[1].pop_back();
        dis[1].pop_back();
    }
    for(LLI i=1; i<=n; i++)
        for(LLI j=0; j<G[i].size(); j++)
        {

            LLI u=i,v=G[i][j];
            if(d[v]==d[u]+dis[i][j])
                used[v]=1;
        }
     //   LLI kount=0;
    for(LLI i=0; i<V.size(); i++)
    {
        if(used[V[i]]==1){


        }
        else{


            kount++;
            used[V[i]]=1;
        }



    }

cout<<k-kount<<"\n";
}
