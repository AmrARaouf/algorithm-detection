//Language: GNU C++


#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<deque>
#include<map>
#include<set>
#define oo 1000000000
#define ooll (1ll<<50)
#define base 1000000007ll
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
                            /*                           END OF TEMPLATE                            */
//IOI 2014
int V,E,cost[100005],low[100005],num[100005],cnt,use[100005];
ll ans,nans=1;
vector<int> G[100005];
stack<int> S;
void tarjan(int u)
{
    low[u]=num[u]=++cnt;
    S.push(u);
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!num[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!use[v]) low[u]=min(low[u],num[v]);
    }
    if(low[u]==num[u])
    {
        int v,res=oo+1,nres=1;
        do
        {
            v=S.top(); S.pop();
            if(cost[v]<res) res=cost[v],nres=1;
            else if(cost[v]==res) nres++;
            use[v]=1;
        } while(v!=u);
        ans+=res; nans=nans*nres%base;
    }
    
}
int main()
{
    //freopen("C.inp","r",stdin);
    //freopen("C.out","w",stdout);
    int u,v;
    scanf("%d",&V);
    for(int i=1; i<=V; i++) scanf("%d",&cost[i]);
    scanf("%d",&E);
    for(int i=1; i<=E; i++)
    {
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
    }
    for(int i=1; i<=V; i++)
        if(!num[i]) tarjan(i);
    cout<<ans<<' '<<nans<<endl;
    return 0;
}
