//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int D[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
int N,M,K,a[1005][1005],c[1005][1005];
bool b[1005][1005][4];

void init()
{
	scanf("%d%d",&N,&M);
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++) scanf("%d",&a[i][j]);
	memcpy(c,a,sizeof(a));
}

void dfs(int x,int y,int d,int l)
{
	c[x][y]=0;
	int z=0;
	for (int i=0; i<4; i++)
	{
		int u=x+D[i][0],v=y+D[i][1],w;
		if (u<1||u>N||v<1||v>M||!a[u][v]||b[x][y][i]) continue;
		b[x][y][i]=b[u][v][3-i]=1;
		if (d==i) w=l+1; else K=__gcd(K,l),w=1;
		z++,dfs(u,v,i,w);
	}
	if (!z) K=__gcd(K,l);
}

void doit()
{
	int t=0;
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++) if (a[i][j])
		{
			int s=0;
			for (int k=0; k<4; k++) if (a[i+D[k][0]][j+D[k][1]]) s++;
			if (s&1) t++;
		}
	if (t&&t!=2) {puts("-1"); return;}
	t=0;
	for (int i=1; t<2&&i<=N; i++)
		for (int j=1; t<2&&j<=M; j++) if (c[i][j]) dfs(i,j,-1,0),t++;
	if (t>1||K<2) puts("-1"); else for (int i=2; i<=K; i++) if (K%i==0) printf("%d%c",i,i==K?'\n':' ');
}

int main()
{
	init();
	doit();
	return 0;
}
			 		 		 	    	 			 							  	