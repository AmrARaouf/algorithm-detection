//Language: GNU C++


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<map>
#include<ctime>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<bitset>
#include<functional>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))
using namespace std;

typedef long long LL;
typedef long double ld;

const int MAX=2000+10;

int n,k;
int g[MAX][MAX];
ld ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	int i,j;
	scanf("%d%d",&n,&k);
	REP(i,1,n)
	{
		g[i][i]=-1;
		REP(j,i+1,n)
		{
			scanf("%d",&g[i][j]);
			g[j][i]=g[i][j];
		}
	}
	REP(i,1,n)
	{
		LL all=0;
		int num=0;
		REP(j,1,n)
			if(g[i][j]!=-1)
			{
				++num;
				all+=g[i][j];
			}
		if(num<k)
			continue;
		//i*C(num-1,k-1)/C(num,k)
		//all* ( (num-k+1)...(n-k)/(num+1)...n )
		ld cc=(ld)all*k;
		for(j=n-num;j>=1;--j)
		{
			cc/=num+j;
			cc*=num-k+j;
		}
		ans+=cc/num;
	}
	cout<<(LL)(ans+1e-5)<<endl;
	return 0;
}
