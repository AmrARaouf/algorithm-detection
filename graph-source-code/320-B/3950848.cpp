//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=11111;
struct {
	int v,next;
}edge[111111];
int head[111];
struct {
	int l,r;
}ve[111];
int tot;
int flag;
int vis[111];
void add(int u,int v)
{
	edge[tot].v=v;
	edge[tot].next=head[u];
	head[u]=tot++;	
}
	int l,r;
	void dfs(int u)
	{
		if (flag) return ;
		int i;
		for(i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			
			if(vis[v]) continue ;
			vis[v]=1;
			if(v==r)
			{
				flag=1;
				return ;
			}

			dfs(v);
		}	
	}
int main()
{ 
	int i,j,n,m,k;
	int t;
	while(scanf("%d",&n)!=EOF)
	{
		 tot=0;
		memset(head,-1,sizeof(head));
		int tt=0;
		for(i=1;i<=n;i++)			
		{
			scanf("%d",&t);
			if(t==1)
			{
				tt++;
				scanf("%d%d",&ve[tt].l,&ve[tt].r);	
				for(j=1;j<tt;j++)
				{
					if(ve[tt].r>ve[j].l){
						
						if(ve[tt].r<ve[j].r)
						{
							add(tt,j);
							if(ve[tt].l<ve[j].l)	
							add(j,tt);
						}
						else if(ve[tt].r==ve[j].r)
						{
							if(ve[tt].l>ve[j].l)
							add(tt,j);
							else if(ve[tt].l<ve[j].l)
							add(j,tt);
						}
						else 
						{
							if(ve[tt].l<ve[j].r){
								add(j,tt);
								if(ve[tt].l>ve[j].l)
								add(tt,j);	
							}	
						}
					}
				}
			}
			else 
			{
				memset(vis,0,sizeof(vis));
				 flag=0;
				scanf("%d%d",&l,&r);
				dfs(l);
				if(flag) printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
} 
