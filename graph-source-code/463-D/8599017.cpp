//Language: MS C++


#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int mod=1000000007;
const int MAXN=1002;

int n,K;
int a[6][MAXN],pos[6][MAXN],dp[MAXN];

void solve(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=K;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			pos[i][a[i][j]]=j;
		}
	int k,res=0;
	for(int j=1;j<=n;j++){
		int mx=0;
		for(int i=1;i<j;i++){
			for(k=2;k<=K && pos[k][a[1][i]]<pos[k][a[1][j]];k++);
			if(k==K+1 && mx<dp[i])
				mx=dp[i];
		}
		dp[j]=mx+1;
		res=max(res,dp[j]);
	}
	printf("%d\n",res);
}

int main()
{
	solve();
	return 0;
}


