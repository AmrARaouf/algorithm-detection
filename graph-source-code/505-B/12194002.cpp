//Language: MS C++


#include<iostream>
#include<string.h>
using namespace std;
int gra[200][200][200];
int main()
{
	int i,j,k;
	int n,m,q;
	int a,b,c,sum;
	memset(gra,0,sizeof(gra));
	scanf("%d%d",&n,&m);
	for(i=0;i<m;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		gra[a-1][b-1][0]=gra[b-1][a-1][0]=1;
		gra[a-1][b-1][c]=gra[b-1][a-1][c]=1;
	}
	for(k=0;k<n;++k)
	{
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				if(gra[i][k][0]==1&&gra[k][j][0]==1)
				{
					gra[j][i][0]=gra[i][j][0]=1;
					for(a=1;a<=m;++a)
					{
						if(gra[i][j][a]==1||gra[j][i][a]==1)continue;
						else
						{
							gra[i][j][a]=gra[i][k][a]&&gra[k][j][a];
							gra[j][i][a]=gra[j][k][a]&&gra[k][i][a];
						}
					}

				}

			}
		}
	}
	scanf("%d",&q);
	for(i=0;i<q;++i)
	{
		scanf("%d%d",&a,&b);
		if(gra[a-1][b-1][0]==0)
		{
			printf("0\n");
		}
		else
		{
			sum=0;
			for(j=1;j<=m;++j)
			{
				if(gra[a-1][b-1][j]==1)
				{
					++sum;
				}
			}
			printf("%d\n",sum);
		}
	}
}
	  	  		 	 	  	 		 		   	 	 	 	