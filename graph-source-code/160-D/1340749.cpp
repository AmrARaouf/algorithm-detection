//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define mp make_pair
typedef pair<int,int> per;
const int N = 100005;
const int INF = 1000000005;
struct P
{
	int u,v,key,id;
}E[N];
vector<per>q[N];
vector<per>g[N];
bool cmp(P x,P y)
{
	return x.key<y.key;
}
int f[N],lca[N],fa[N],df[N],d[N],mini[N];
int find(int x)
{
	if(x!=f[x])f[x]=find(f[x]);
	return f[x];
}
bool u[N],vis[N];
void LCA(int x)
{
	int i,j;
	for(i=g[x].size()-1;i>=0;i--)
	{
		j=g[x][i].first;
		if(j!=fa[x])
		{
			fa[j]=x;
			d[j]=d[x]+1;
			df[j]=g[x][i].second;
			LCA(j);
		}
	}
	for(i=q[x].size()-1;i>=0;i--)
	{
		int y=q[x][i].first;
		if(vis[y])
		{
			lca[q[x][i].second]=find(y);
		}
	}
	vis[x]=true;
	f[x]=fa[x];
}
int r[N];
void get(int u,int v,int val,int la)
{
	int x;
	while(d[u]>d[la])
	{
		x=find(fa[u]);
		int j=df[u];
		if(E[j].key==val)r[E[j].id]=2;
		f[u]=x;
		u=x;
	}
	while(d[v]>d[la])
	{
		x=find(fa[v]);
		int j=df[v];
		if(E[j].key==val)r[E[j].id]=2;
		f[v]=x;
		v=x;
	}
}
struct PP
{
	int l,r,mid,key;
}arr[4*N];
void build(int L,int R,int c)
{
	arr[c].l=L;
	arr[c].r=R;
	arr[c].mid=(L+R)/2;
	arr[c].key=0;
	if(L==R)return ;
	build(L,arr[c].mid,c+c);
	build(arr[c].mid+1,R,c+c+1);
}
int max(const int &x,const int &y){return x>y?x:y;}
void up(int x,int v,int c)
{
	if(arr[c].l==arr[c].r)
	{
		arr[c].key=v;
		return ;
	}
	if(x<=arr[c].mid)up(x,v,c+c);
	else up(x,v,c+c+1);
	arr[c].key=max(arr[c+c].key,arr[c+c+1].key);
}
int res;
void find(int L,int R,int c)
{
	//printf("L:%d R:%d c:%d l:%d r:%d key:%d \n",L,R,c,arr[c].l,arr[c].r,arr[c].key);
	if(res>=arr[c].key)return ;
	if(L<=arr[c].l&&R>=arr[c].r)
	{
		res=arr[c].key;
		return ;
	}
	if(L<=arr[c].mid)find(L,R,c+c);
	if(R>arr[c].mid)find(L,R,c+c+1);
}
int k;
void dfs(int x)
{
	if(x!=1)
	{
		k++;
		//printf("~~~~!@!@!#!# x:%d V:%d \n",x,E[df[x]].key);
		up(k,E[df[x]].key,1);
	}
	int i,j;
	for(i=g[x].size()-1;i>=0;i--)
	{
		j=g[x][i].first;
		if(j!=fa[x])dfs(j);
	}
	for(i=q[x].size()-1;i>=0;i--)
	{
		int y=q[x][i].second,la=lca[y];
		res=0;
		if(x!=la)
		{
			//printf("L:%d R:%d \n",d[la]+1,d[x]);
			find(d[la]+1,d[x],1);
			if(E[y].key==res)r[E[y].id]=2;
			//printf("x:%d y:%d u:%d v:%d key:%d res:%d id:%d \n",
			//	x,y,E[y].u,E[y].v,E[y].key,res,E[y].id);
		}
		//lca[q[x][i].second]=find(y);
	}
	if(x!=1)k--;
}
int main()
{
	int i,j,x,y,n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)f[i]=i;
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].key);
		E[i].id=i;
	}
	sort(E,E+m,cmp);
	for(j=i=0;j<n-1&&i<m;i++)
	{
		x=find(E[i].u);
		y=find(E[i].v);
		if(x!=y)
		{
			g[E[i].u].push_back(mp(E[i].v,i));
			g[E[i].v].push_back(mp(E[i].u,i));
			f[x]=y;
			j++;
			u[i]=true;
			r[E[i].id]=1;
		}
	}
	for(i=0;i<m;i++)if(!u[i])
	{
	//	printf("i:%d u:%d v:%d \n",i,E[i].u,E[i].v);
		q[E[i].u].push_back(mp(E[i].v,i));
		q[E[i].v].push_back(mp(E[i].u,i));
	}
	for(i=1;i<=n;i++)f[i]=i;
	memset(vis,false,sizeof(vis));
	LCA(1);
//	for(i=0;i<m;i++)if(!u[i])printf("i:%d lca:%d \n",i,lca[i]);
	for(i=1;i<=n;i++){f[i]=i;mini[i]=INF;}
	for(i=0;i<m;i++)if(!u[i])
	{
		get(E[i].u,E[i].v,E[i].key,lca[i]);
	}
	/*for(i=0;i<m;i++)
	{
		if(u[i])printf("id:%d u:%d v:%d r:%d \n",E[i].id,E[i].u,E[i].v,r[E[i].id]);
	}*/
	//for(i=1;i<=n;i++)printf("i:%d d:%d \n",i,d[i]);
	build(1,n,1);
	dfs(1);
	//for(i=0;i<m;i++)printf("i:%d r:%d \n",i,r[i]);
	for(i=0;i<m;i++)
	{
		if(!r[i])puts("none");
		else if(r[i]==1)puts("any");
		else puts("at least one");
	}
	return 0;
}
