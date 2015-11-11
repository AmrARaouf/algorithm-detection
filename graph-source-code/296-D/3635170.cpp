//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define FOR0(i,MAXTT) for(long i=0;i<=MAXTT;++i)
#define FOR1(i,MAXTT) for(long i=1;i<=MAXTT;++i)
#define FOR(i,SS,TT)  for(long i=SS;i<=TT;++i)
#define DW0(i,MAXTT) for(long i=MAXTT;i>=0;--i)
#define DW1(i,MAXTT) for(long i=MAXTT;i>=1;--i)
#define DW(i,TT,SS)  for(long i=TT;i>=SS;--i)
#define min(x,y) ((x) < (y) ? (x) : (y))
#define N 512
typedef long long LL;
using namespace std;
int id[N],n;
LL dist[N][N],ans[N];
void floyd()
{
	int cnt(0);
	FOR1(k,n)
	{	
		FOR1(i,n)
			FOR1(j,n)
			{
				if (i == k || i == j || k == j) continue;
				int x(id[i]),z(id[k]),y(id[j]);
				dist[x][y] = min(dist[x][y],dist[x][z] + dist[z][y]);
			}
		LL sum(0);
		FOR1(i,k)
			FOR1(j,k)
			{
				if (i == j) continue;
				sum += dist[id[i]][id[j]];
			}
		ans[++cnt] = sum;
	}
}				
int main()
{
	cin >> n;
	FOR1(i,n)
		FOR1(j,n)
			scanf("%I64d",&dist[i][j]);
	int cnt(n);
	FOR1(i,n) cin >> id[cnt--];
	floyd();
	DW(i,n,2) cout << ans[i] << " ";
	cout << ans[1] << endl;
	return 0;
}
