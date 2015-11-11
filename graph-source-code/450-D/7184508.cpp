//Language: MS C++


#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long Int;
const int Maxn=100005;
const Int Inf=((Int)1)<<60;
int n,m,k;
vector<pair<int,Int> >G[Maxn];
struct Edge
{
	int u,v;
	Int w;
	Edge(){}
	Edge(int u,int v,Int w):u(u),v(v),w(w){}
}e[Maxn*5];
int out[Maxn];
Int d[Maxn];
pair<int,Int>P[Maxn];
struct Node
{
	int u;
	Int dd;
	Node(){}
	Node(int u,Int dd):u(u),dd(dd){}
	friend bool operator <(const Node a,const Node b)
	{
		return a.dd>b.dd;
	}
};
bool via[Maxn];
void dij()
{
	for(int i=1;i<=n;i++)
	   d[i]=i==1?0:Inf;
    memset(via,0,sizeof(via));
    priority_queue<Node>q;
    q.push(Node(1,d[1]));
    while(!q.empty())
    {
    	Node x=q.top();q.pop();
    	if(via[x.u])continue;
    	via[x.u]=1;
    	int u=x.u;
    	for(int i=0;i<G[u].size();i++)
    	{
    		int v=G[u][i].first;
    		Int w=G[u][i].second;
    		if(d[v]>d[u]+w)
    		{
    			d[v]=d[u]+w;
    			q.push(Node(v,d[v]));
			}
		}
	}
}
int main()
{
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		for(int i=1;i<=m;i++)
		{
			int u,v;
			Int w;
			scanf("%d%d%I64d",&u,&v,&w);
			e[i]=Edge(u,v,w);
			G[u].push_back(make_pair(v,w));
			G[v].push_back(make_pair(u,w));
		}
		for(int i=1;i<=k;i++)
            scanf("%d%I64d",&P[i].first,&P[i].second);
        sort(P+1,P+k+1);
        P[0].first=-1;
        int kk=0;
        for(int i=1;i<=k;i++)
        {
        	if(P[i].first!=P[i-1].first)
        	   P[++kk]=P[i];
		}
		int ans=k-kk;
		for(int i=1;i<=kk;i++)
		{
		     int v=P[i].first;
		     Int w=P[i].second;
		     G[1].push_back(make_pair(v,w));
		     G[v].push_back(make_pair(1,w));
		}
		dij();
		for(int i=1;i<=m;i++)
		{
			int u=e[i].u,v=e[i].v;
			Int w=e[i].w;
			if(d[u]==d[v]+w)out[u]++;
			if(d[v]==d[u]+w)out[v]++;
		}
		for(int i=1;i<=kk;i++)
		{
			int v=P[i].first;
			Int w=P[i].second;
			if(d[v]!=w||out[v])
			   ans++;
		}
	//	for(int i=1;i<=n;i++)printf("%I64d\n",d[i]);
		printf("%d\n",ans);
	}
}