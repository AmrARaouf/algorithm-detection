//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

#define cls(x,y); memset(x,y,sizeof(x));
typedef long long LL;

const int maxn=1e5+50;
int n,m;
int flag=0;
int color[maxn],depth[maxn],fa[maxn];
int d[maxn];
LL b[maxn],w[maxn];
vector<int>G[maxn];


void dfs(int u,int c,int f)
{
      color[u]=c;
      if(c==1) b[f]++;
      else w[f]++;

	for(int i=0;i<G[u].size();i++)
      {
            int v=G[u][i];
            if(!color[v])
            {
                  dfs(v,3-c,f);
            }
            else if( color[v]==color[u] )
            {
                  flag=0;
                  return;
            }
      }
}

int main()
{
	cin>>n>>m;
	cls(color,0);  cls(b,0); cls(w,0); cls(depth,0); cls(d,0);

	if(m==0)//加三条边
	{
		cout<<"3 "<<(long long)n*(n-1)*(n-2)/6<<endl;
		return 0;
	}

	for(int i=1;i<=m;i++)//建图
	{
		int st,ed;
		cin>>st>>ed;
		G[st].push_back(ed);
		G[ed].push_back(st);
		++depth[st];
		++depth[ed];
		if(depth[st]>1 || depth[ed]>1) flag=1;
	}

	if(!flag)//加两条边
	{
		cout<<"2 "<<(long long)m*(n-2)<<endl;
		return 0;
	}

	int cnt=0;
	for(int i=1;i<=n;i++)fa[i]=i;

	for(int i=1;i<=n;i++)//跑一遍染色
		if(color[i]==0)	dfs(i,1,++cnt);

	if(!flag) cout<<"0 1"<<endl;//不加边
	else//加一条边
	{
		LL ans=0;
		for(int i=1;i<=cnt;i++)
			ans+=(b[i]-1)*b[i]/2+ (w[i]-1)*w[i]/2;
		cout<<"1 "<<ans<<endl;
	}

	return 0;
}
 			 	 		   		 		  	   		   	 	