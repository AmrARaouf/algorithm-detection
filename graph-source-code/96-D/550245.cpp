//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define in(n) scanf("%d",&n)
#define inl(n) scanf("%lld",&n)
#define out(n) printf("%d ",n)
#define outln(n) printf("%d\n",n)
#define outl(n) printf("%lld ",n)
#define outlln(n) printf("%lld\n",n)
#define LL long long 
#define pb push_back
#define INF 100000000000000LL
using namespace std;
int n,m,s,d;
vector<int> g[1024],gg[1024];
vector<LL> w[1024],ww[1024];
int t[1024];
int c[1024];
LL dis[1024];
struct state 
{
        int v;
        LL d;
};
bool operator<(state x,state y)
{
        return x.d  > y.d;
}
void dijkstra(int u)
{
        state ss;
        rep(i,0,n)dis[i]=INF;
        dis[u]=0;
        priority_queue<state> heap;
        ss.v=u;ss.d=0;
        heap.push(ss);
        LL d;
        int v;
        while(!heap.empty())
        {
                u=(heap.top()).v;
                d=(heap.top()).d;
                heap.pop();
                if(dis[u]<d)continue;
                rep(j,0,g[u].size())
                {
                        v=g[u][j];
                        if(dis[v]>dis[u]+w[u][j])
                        {
                                dis[v]=dis[u]+w[u][j];
                                ss.v=v;ss.d=dis[v];
                                heap.push(ss);
                        }

                }
        }
}

int main()
{
        cin>>n>>m>>s>>d;
        s--;d--;
        int a,b,wt;
        rep(i,0,m)
        {
                cin>>a>>b>>wt;
                a--;b--;
                g[a].pb(b);w[a].pb(wt);
                g[b].pb(a);w[b].pb(wt);
        }
        rep(i,0,n)cin>>t[i]>>c[i];
        rep(i,0,n)
        {
                dijkstra(i);
                rep(j,0,n)
                {
                        if(dis[j]<=t[i])
                        {
                                gg[i].pb(j);
                                ww[i].pb(c[i]);
                        }
                }
        }
        rep(i,0,n)g[i]=gg[i],w[i]=ww[i];
        dijkstra(s);
        cout<<(dis[d]<INF?dis[d]:-1)<<endl;
        return 0;
}