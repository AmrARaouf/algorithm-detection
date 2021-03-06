//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;

int flow[205][205],N,x,mark[205],lim[105],res;
char tar[105],s[105];

int f(int a,int mal)
{
	mark[a]=1;	
	if(a==N+27)
	{
		return mal;
	}
	int Min=0;
	for(int i=0;i<=N+27;i++)
		if(!mark[i] && flow[a][i])
		{
			Min=f(i,min(mal,flow[a][i]));
			if(Min>0)
			{
				flow[a][i]-=Min;
				flow[i][a]+=Min;
				return Min;
			}
		}
	return Min;
}

int main ()
{
	scanf("%s",tar);
	scanf("%d",&N);
	for(int i=0;i<(int)strlen(tar);i++)
		flow[N+tar[i]-'a'+1][N+27]++;
	for(int i=1;i<=N;i++)
	{
		scanf("%s",s);
		for(int j=0;j<(int)strlen(s);j++)
			flow[i][N+1+s[j]-'a']++;
		scanf("%d",&x);
		flow[0][i]=x;
		lim[i]=x;
	}
	while(f(0,0x7fffffff))
	{
		memset(mark,0,sizeof(mark));	
	}	
	for(int i=N+1;i<=N+26;i++)
		if(flow[i][N+27])
		{
			printf("-1\n");
			return 0;
		}
	for(int i=1;i<=N;i++)
	{
		res+=(lim[i]-flow[0][i])*i;
	}
	printf("%d\n",res);
}
