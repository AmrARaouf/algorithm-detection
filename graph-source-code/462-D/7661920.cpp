//Language: GNU C++



#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<time.h>
#include<string>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define REP2(i,a,b) for(int i=a;i>=b;--i)
#define MP make_pair
#define LL long long
#define X first
#define Y second
#define MAXN 500050
#define MOD 1000000007
using namespace std;
LL dp[MAXN][2];
int c[MAXN];
vector<int>e[MAXN];
void gao(int now,int fa)
{
	dp[now][c[now]]=1;
	dp[now][1-c[now]]=0;
	for(int i=0;i<e[now].size();++i)
	{
		int u=e[now][i];
		if(u==fa)continue;
		gao(u,now);
		if(c[now]==1){
			dp[now][1]=(dp[now][1]*dp[u][0])%MOD;
		}
		else
		{
			dp[now][1]=(dp[now][1]*dp[u][0])%MOD;
			dp[now][1]=(dp[now][1]+dp[now][0]*dp[u][1])%MOD;
			dp[now][0]=(dp[now][0]*dp[u][0])%MOD;
		}
	}
	dp[now][0]+=dp[now][1];
	dp[now][0]%=MOD;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		e[x].push_back(i);
		e[i].push_back(x);
	}
	for(int i=0;i<n;++i)
		scanf("%d",&c[i]);
	gao(0,-1);
	printf("%I64d\n",dp[0][1]);
}
