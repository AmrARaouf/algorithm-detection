//Language: GNU C++


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<bitset>
#include<stack>
#include<queue>
#include<list>
#define F first
#define S second
using namespace std;
typedef long long int lli;
typedef unsigned long long int llu;
int scan()
{
 int t=0;char c;c=getchar();while(c<'0' || c>'9') c=getchar();while(c>='0' && c<='9'){t=(t<<3)+(t<<1)+c-'0';c=getchar();}
return(t);
}
int x[]={-1,0,1,0},y[]={0,-1,0,1};
char grid[52][52],check[52][52];
int solve(int vx,int vy)
{	
	int maxm=0;
	for(int i=0;i<4;i++)
	{
		if(grid[vx+x[i]][vy+y[i]]=='#' and check[vx+x[i]][vy+y[i]]==0)
		{
			check[vx+x[i]][vy+y[i]]=1;
			maxm++;
			maxm+=solve(vx+x[i],vy+y[i]);
		}
	}
	return(maxm);
}
int main()
{	
	vector< pair<int,int> >v;
	vector< pair<int,int> >::iterator it,it2;
	int n=scan(),m=scan();
	char dum;
	int ans=2;
	memset(check,0,sizeof(check));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			grid[i][j]=getchar();	
			if(grid[i][j]=='#')
			v.push_back(make_pair(i,j));
		}
		dum=getchar();
	}
	if(v.size()==1 || v.size()==2)
	{
		printf("-1\n");
		return(0);	
	}
	it=v.begin();it++; it2=v.begin();
	for(;it!=v.end();it++)
	{
		check[it2->F][it2->S]=check[it->F][it->S]=1;
		if(solve(it2->F,it2->S)<v.size()-2)
		{		
			ans=1;break;
		}
		memset(check,0,sizeof(check));
	}
	if(ans!=1)
	{	
		check[it2->F][it2->S]=1;
		it2++;
		check[it2->F][it2->S]=1;
		if(solve(it2->F,it2->S)<v.size()-2)
		ans=1;
	}
	printf("%d\n",ans);
	return(0);
}
	
