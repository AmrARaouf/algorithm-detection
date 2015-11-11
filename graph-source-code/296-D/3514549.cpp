//Language: MS C++


#pragma comment(linker, "/STACK:134217728")
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
#define RFor(i,a,b) for(int (i)=(a);(i)>=(b);--(i)) 
#define For(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i)) 
#define ll long long
#define UI unsigned int
#define LD long double
#define pii pair<int,int>
#define mp make_pair
#define MOD 1000000007
//#define x first
//#define y second
int g[500][500];
int v[500];
ll ans[500];
int when[500];
int main()
{
	//freopen("input.txt","rt",stdin);
	int n;
	scanf("%d",&n);
	FOR(i,0,n)
		FOR(j,0,n)
		scanf("%d",&g[i][j]);
	FOR(i,0,n)
	{
		scanf("%d",&v[i]);
		when[--v[i]]=i;
	}
	RFOR(k,n,0)
	{
		FOR(i,0,n)
			FOR(j,0,n)
			if(g[i][j]>g[i][v[k]]+g[v[k]][j])
				g[i][j]=g[i][v[k]]+g[v[k]][j];
		FOR(i,0,n)
			FOR(j,0,n)
			if(when[i]>=k&&when[j]>=k)
				ans[k]+=g[i][j];
	}
	FOR(i,0,n)
		printf("%I64d ",ans[i]);
	return 0;
}