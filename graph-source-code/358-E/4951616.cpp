//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
using namespace std;
bool s[1010][1010],t[1010][1010];
int r[1010][1010],f[1001000],g[1001000],n,m,i,j,p,ans,ch,L,R;
int gcd(int a,int b)
{
	if(b==0)return a;
	if(a<b)swap(a,b);
	return gcd(b,a%b);
}
void bfs(int x,int y)
{
	t[x][y]=0;f[1]=x;g[1]=y;
	for(L=1,R=1;L<=R;L++)
		{
		int i=f[L],j=g[L];
		if(t[i-1][j])f[++R]=i-1,g[R]=j,t[i-1][j]=0;
		if(t[i+1][j])f[++R]=i+1,g[R]=j,t[i+1][j]=0;
		if(t[i][j-1])f[++R]=i,g[R]=j-1,t[i][j-1]=0;
		if(t[i][j+1])f[++R]=i,g[R]=j+1,t[i][j+1]=0;
		}
}
int main()
{
//	freopen("scan.in","r",stdin);
//	freopen("scan.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			{
			scanf("%d",&r[i][j]);
			if(r[i][j])s[i][j]=1;
			if(r[i][j])t[i][j]=1;
			}
	p=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(t[i][j])bfs(i,j),p++;
	if(p>1)
		{
		printf("-1 ");
		return 0;
		}
	p=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(s[i][j])
				{
				if((r[i-1][j]+r[i+1][j]+r[i][j-1]+r[i][j+1])%2)p++;
				t[i][j]=(s[i-1][j]^s[i+1][j])||(s[i][j-1]^s[i][j+1])||((s[i-1][j]||s[i+1][j])&&(s[i][j-1]||s[i][j+1]));
				}
	if(p>2)
		{
		printf("-1 ");
		return 0;
		}
	for(i=1;i<=n;i++)
		{
		p=0;
		for(j=1;j<=m;j++)
			if(t[i][j])
				{
				if(p>0)ans=gcd(j-p,ans);
				p=j;
				}
		}
	for(i=1;i<=m;i++)
		{
		p=0;
		for(j=1;j<=n;j++)
			if(t[j][i])
				{
				if(p>0)gcd(j-p,ans);
				p=j;
				}
		}
	for(i=2;i<=ans;i++)
		if(ans%i==0)printf("%d ",i);
	if(ans<2)printf("-1 ");
}
