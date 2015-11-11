//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ties[120];

struct edge
{
	int u,v;
};
edge es[10010];
bool chk[10010]={0};
int ecnt=0;

int main()
{
	int n,m; scanf("%d%d",&n,&m);
	memset(ties,0,sizeof(ties));

	int i;
	for(i=0;i<m;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		ties[a]++; ties[b]++;
		es[ecnt].u=a;
		es[ecnt].v=b;
		ecnt++;
	}

	int rounds=0;

	bool find=true;
	while(find)
	{
		find=false;
		int nn[120],ncnt=0;
		for(i=1;i<=n;i++)
			if(ties[i]==1)
				nn[ncnt++]=i,find=true;

		for(i=0;i<ncnt;i++)
		{
			int d=nn[i],j;
			for(j=0;j<ecnt;j++)
				if(es[j].u==d||es[j].v==d&&!chk[j])
					ties[es[j].u]--,ties[es[j].v]--,chk[j]=true;
		}
		rounds++;
	}
	rounds--;
	printf("%d\n",rounds);
	return 0;
}