//Language: GNU C++


#include<cstdio>
#include<cstring>
int n,m,s,l,r,L,i,j,p,ans;
int d[100010],f[100010],son[100010],x[100010],y[100010],z[100010];
int q[10000010];
int ed[200010],next[200010],w[200010];
void addedge(int i,int j,int k)
{
	ed[++p]=j,w[p]=k,next[p]=son[i],son[i]=p;
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		addedge(x[i],y[i],z[i]),addedge(y[i],x[i],z[i]);
	}
	scanf("%d",&L);
	memset(d,127,sizeof(d));
	f[s]=1,d[s]=0;
	q[1]=s;
	for(l=0,r=1;l<r;)
	{
		i=q[++l];
		f[i]=0;
		for(j=son[i];j;j=next[j])
			if(d[ed[j]]>d[i]+w[j])
			{
				d[ed[j]]=d[i]+w[j];
				if(!f[ed[j]])
				{
					f[ed[j]]=1;
					q[++r]=ed[j];
				}
			}
	}
	for(i=1;i<=n;i++)
		if(d[i]==L)
			ans++;
	for(i=1;i<=m;i++)
	{
		if(d[x[i]]+z[i]==d[y[i]])
		{
			if(d[x[i]]<L&&d[y[i]]>L)
				ans++;
		}
		else
			if(d[y[i]]+z[i]==d[x[i]])
			{
				if(d[y[i]]<L&&d[x[i]]>L)
					ans++;
			}
			else
			{
				if(d[x[i]]<L&&d[y[i]]+(z[i]-(L-d[x[i]]))>=L)
					ans++;
				if(d[y[i]]<L&&d[x[i]]+(z[i]-(L-d[y[i]]))>=L)
					ans++;
				if(d[x[i]]<L&&d[y[i]]<L&&(L-d[x[i]])+(L-d[y[i]])==z[i])
					ans--;
			}
	}
	printf("%d\n",ans);
	return 0;
}