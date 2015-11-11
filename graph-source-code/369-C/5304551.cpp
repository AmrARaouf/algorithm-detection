//Language: GNU C++


//#include <bits/stdc++.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <numeric>
#include <stack>
#include <functional>
#include <bitset>
#include <iomanip>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstring>
#include <cstdlib>

#define _ ios_base::sync_with_stdio(0);
#define ms(ar,val) memset(ar,val,sizeof(ar))
#define all(s) (s).begin(),(s).end()
#define lp(i,s,n) for(int i=s;i<n;i++)
#define rp(i,n) lp(i,0,n)
#define pb push_back
#define LL long long
#define Read(x) freopen(x,"r",stdin)
#define Write(x) freopen(x,"w",stdout)
#define st(N,pos) (sts[N]=sts[N] | (1<<pos))
#define check(N,pos) ((bool)(sts[N] & (1<<pos)))
#define i_s(num)  static_cast<ostringstream*>( &(ostringstream() << num) )->str();
#define inf INT_MAX
#define hi 100010
using namespace std;
int n;
int  par[hi],dist[hi];
bool vis[hi];
vector <int> ans;
bool mark[hi];
vector <int> ed[hi],we[hi];
int dfs(int x,int w)
{
    if(vis[x])return 0;
    int mx=0;
    vis[x]=1;
    if(w)
    {
        dist[x]=w;
        par[x]=x;
    }
    rp(i,ed[x].size())
    {
        int d=dfs(ed[x][i],we[x][i]);
        if(d>mx)
        {
            mx=d;
            par[x]=par[ed[x][i]];
        }
    }
    return mx+w;
}
int main()
{
#if defined( rifat_pc )
    //Write("out.txt");
    Read("in.txt");
#endif
    cin>>n;
    int u,v,w;
    rp(i,n-1)
    {
        scanf("%d %d %d",&u,&v,&w);
        ed[u].pb(v);
        ed[v].pb(u);
        we[u].pb(w-1);
        we[v].pb(w-1);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)if(par[i]>1)ans.pb(par[i]);
    vector <int> ans1;
    for(int i=0;i<ans.size();i++)
    {
        if(!mark[ans[i]])
        {
            mark[ans[i]]=1;
            ans1.pb(ans[i]);
        }
    }
    cout<<ans1.size()<<endl;
    for(int i=0;i<ans1.size();i++)
    {
        if(i)printf(" %d",ans1[i]);
        else printf("%d",ans1[i]);
    }
    cout<<endl;



    return 0;
}

