//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int path[105][105];
void init()
{
	int  i,j;
	for(i=0;i<=105;i++)
	for(j=0;j<=105;j++)
	{
		path[i][j]=i;
	}
}

int find(int x,int color)
{
	int z,k;
	k=x;
	while(path[k][color]!=k)
	{
		k=path[k][color];		
	}
	while(path[x][color]!=k)
	{
		x=path[x][color];
		path[x][color]=k;
	}
	return k;
}

void unite(int x,int y,int color)
{
	x=find(x,color);
	y=find(y,color);
	if(x!=y)
	path[x][color]=y;
}
int main()
{
	int n,m,i,j,k,q,ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int x,y,color;
		k=m;
		init();
		while(k--)
		{
			scanf("%d%d%d",&x,&y,&color);
			unite(x,y,color);
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&x,&y);
			ans=0;
			for(i=1;i<=m;i++)
			{
				if(find(x,i)==find(y,i))
					ans++;			
			}
			printf("%d\n",ans);
		}
	}



	return 0;
}
 	    	 	  	  	  		 	 	 				  	