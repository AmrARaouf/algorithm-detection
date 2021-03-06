//Language: GNU C++


#include<stdio.h>
int n, m, a[1010][1010], edge[1010];
bool chk[1010][1010], cc[1010][1010];
int gcd(int a, int b){ return a%b?gcd(b,a%b):b; }
void back(int r, int c)
{
	cc[r][c]=true;
	if(r>1 && !cc[r-1][c] && a[r-1][c]==1) back(r-1, c);
	if(r<n && !cc[r+1][c] && a[r+1][c]==1) back(r+1, c);
	if(c>1 && !cc[r][c-1] && a[r][c-1]==1) back(r, c-1);
	if(c<m && !cc[r][c+1] && a[r][c+1]==1) back(r, c+1);
}
bool flood_fill()
{
	int i, j, p=0;
	for(i=1; i<=n; ++i)
	{
		for(j=1; j<=m; ++j)
		{
			if(!cc[i][j] && a[i][j]==1)
			{
				if(p==0){ back(i, j); ++p; }
				else return true;
			}
		}
	}
	return false;
}
int main()
{
	int i, j, t=0, c=0, l;
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; ++i)
	{
		for(j=1; j<=m; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
	if(flood_fill()){ printf("-1"); return 0; }
	for(i=1; i<=n; ++i)
	{
		for(j=1; j<=m; ++j)
		{
			if(a[i][j] && (a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1])%2 == 1){ chk[i][j]=true; ++c; }
			if(a[i][j] && a[i-1][j]+a[i+1][j]>0 && a[i][j-1]+a[i][j+1]>0) chk[i][j]=true;
		}
		chk[i][m+1]=true;
	}
	for(i=1; i<=m; ++i) chk[n+1][i]=true;
	if(c>2 || c==1){ printf("-1"); return 0; }
	//�� ����
	for(i=1; i<=n; ++i)
	{
		c=0;
		for(j=1; j<=m; ++j) if(chk[i][j]) edge[++c]=j;
		if(c==1) continue;
		for(j=1; j<c; ++j) if(edge[j+1]-edge[j]==1){ printf("-1"); return 0; }
		for(j=1; j<c; ++j)
		{
			l=edge[j+1]-edge[j];
			if(a[edge[j]+1]==0) continue;
			t=gcd(t, l);
		}
	}
	//�� ����
	for(j=1; j<=m; ++j)
	{
		c=0;
		for(i=1; i<=n; ++i) if(chk[i][j]) edge[++c]=i;
		if(c==1) continue;
		for(i=1; i<c; ++i) if(edge[i+1]-edge[i]==1){ printf("-1"); return 0; }
		for(i=1; i<c; ++i)
		{
			l=edge[i+1]-edge[i];
			if(a[edge[i]+1]==0) continue;
			t=gcd(t, l);
		}
	}
	if(t<=1) printf("-1");
	else
	{
		for(i=2; i<=t; ++i) if(t%i==0) printf("%d ", i);
	}
}
