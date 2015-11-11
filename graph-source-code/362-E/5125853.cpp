//Language: GNU C++


#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<algorithm>
#include<list>
#include<cstdio>
#include<stack>
#include<cstring>
#include <climits>
#include<cmath>
#include<string>
#include <functional>
#include<sstream>
#include<map>
using namespace std;
#define     For(i,a,b)        for (int i=a; i<b; i++)
#define     Rep(i,a)          for (int i=0; i<a; i++)
#define     ALL(v)            (v).begin(),(v).end()
#define     Set(a,x)          memset((a),(x),sizeof(a))
#define     EXIST(a,b)        find(ALL(a),(b))!=(a).end()
#define     Sort(x)           sort(ALL(x))
#define     GSORT(x)          sort(ALL(x), greater<typeof(*((x).begin()))>())
#define     UNIQUE(v)         Sort(v); (v).resize(unique(ALL(v)) - (v).begin())
#define     MP                make_pair
#define     SF                scanf
#define     PF                printf
#define     MAXN               1001
#define     MAXM               1001
#define     MOD               1000000007
#define     Dbug             cout<<"";
#define     EPS              1e-15
typedef long long ll;
typedef pair<ll, ll> pii;
struct node
{
    vector<int> adj, cap, cost, rev;
    bool v;
    int d, p, e;
}nd[500];
void add(int a, int b, int c, int w)
{
    nd[a].adj.push_back(b), nd[b].adj.push_back(a);
    nd[a].cost.push_back(w), nd[b].cost.push_back(-w);
    nd[a].cap.push_back(c), nd[b].cap.push_back(0);
    nd[a].rev.push_back(nd[b].adj.size()-1), nd[b].rev.push_back(nd[a].adj.size()-1);
}
int inf=1<<30;
bool dijkstra(int s, int d, int n)
{
    int c, w, k;
    Rep(i, n) nd[i].d=inf, nd[i].v=0;
    queue<int> q;
    q.push(s), nd[s].d=0, nd[s].p=-1;
    while (!q.empty())
    {
        s=q.front(), q.pop();
        nd[s].v=0;
        Rep(i, nd[s].adj.size())
        {
            k=nd[s].adj[i], c=nd[s].cap[i], w=nd[s].cost[i];
            if(!c) continue;
            if(w+nd[s].d<nd[k].d)
            {
                nd[k].d=w+nd[s].d, nd[k].p=s, nd[k].e=i;
                if(!nd[k].v) nd[k].v=1, q.push(k);
            }
        }
    }
    return nd[d].d!=inf;
}
pii flow(int s,int d, int n, ll k)
{
    ll ans=0, m, p, f=0;
    while (dijkstra(s, d, n))
    {
        m=inf;
        for(p=d; p!=s; p=nd[p].p) 
            m=min(m, (ll)nd[nd[p].p].cap[nd[p].e]);
        ll o=m*nd[d].d;
		if(ans+o<=k) ans+=o;
		else
		{
			ll l=k-ans;
			l=l/nd[d].d;
			return MP(f+l, ans);
		}
		f+=m;
        for(p=d; p!=s; p=nd[p].p) nd[nd[p].p].cap[nd[p].e]-=m, nd[p].cap[nd[nd[p].p].rev[nd[p].e]]+=m;
    }
    return MP(f, ans);
}

int org[MAXN][MAXN];
int main(){
	//ios_base::sync_with_stdio(false);
//	freopen("a.in","r",stdin);
	int k, n;
	cin>>n>>k;
	Rep(i, n) Rep(j, n) cin>>org[i][j];
	Rep(i, n) Rep(j, n) if(org[i][j])
	{
		add(i, j, org[i][j], 0);
		add(i, j, k, 1);
	}
	pii ans=flow(0, n-1, n, k);
	cout<<ans.first<<endl;
	return 0;
}