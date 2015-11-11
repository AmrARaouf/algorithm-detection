//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Point{
	int x,y;
}d[205];
bool operator <(const Point &x,const Point &y)
{
	return x.x<y.x;	
}
int n,m,ans;
bool v[205];
int g[205][205];
void Work(int a,int b,int c)
{
	for(int i=1;i<=n;i++)
		d[i].x=g[a][i],
		d[i].y=g[b][i];
	sort(d+1,d+n+1);
	for(int i=n,t,ma=0;i;i--)
	{
		if(d[i].x-ma<c&&ma-d[i].x<c)
			t=ma+d[i].x+c;
		else
			t=max(ma,d[i].x)*2;
		ans=min(ans,t);
		ma=max(ma,d[i].y);
	}
}
int x[20005],y[20005],z[20005];
int main()
{		
	ans=0x7fffffff;
	scanf("%d%d",&n,&m);
	memset(g,63,sizeof(g));
	for(int i=1;i<=n;i++)
		g[i][i]=0;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&x[i],&y[i],&z[i]),
		g[x[i]][y[i]]=g[y[i]][x[i]]=z[i];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=m;i++)
		Work(x[i],y[i],z[i]);
	printf("%lf\n",ans/2.0);
}