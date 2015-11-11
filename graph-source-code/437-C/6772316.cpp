//Language: GNU C++


#include<cstdio>
#include<algorithm>
using namespace std;

int a[1000+5];

struct node{
	int u;
	int v;
}b[2000];


int main()
{
	int i,j,n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int sum=0;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&b[i].u,&b[i].v);
			if(a[ b[i].u ]<a[ b[i].v ])
			{
				sum+=a[ b[i].u ];
			}
			else sum+=a[ b[i].v ];

		}
		printf("%d\n",sum);
	}
	return 0;
}
