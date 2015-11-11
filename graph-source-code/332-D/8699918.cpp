//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

typedef long long LL;

const int N=2000+5;

int n,m,g[N][N],deg[N];
LL ans;

int main(int argc,char **argv)
{
	#ifndef ONLINE_JUDGE
		if (argc==1) freopen("332D.in","r",stdin),freopen("332D.out","w",stdout);
		else freopen(argv[1],"r",stdin),freopen(argv[2],"w",stdout);
	#endif
	int x;
	scanf("%d%d",&n,&m);
	if (m!=2)
	{
		for (int i=1;i<n;++i)
			for (int j=i+1;j<=n;++j)
			{
				scanf("%d",&x);
				if (~x) ans+=x;
			}
		cout<<ans*2/n<<endl;
	}else{
		for (int i=1;i<n;++i)
			for (int j=i+1;j<=n;++j)
			{
				scanf("%d",&g[i][j]);
				if (~g[i][j]) ++deg[i],++deg[j];
			}
		for (int i=1;i<n;++i)
			for (int j=i+1;j<=n;++j)
				if (~g[i][j])
					if (deg[i]==2 && deg[j]==2) ans+=g[i][j]<<1;
					else ans+=g[i][j]*(LL)(n-1);
		cout<<ans/(n*(LL)(n-1)>>1)<<endl;
	}
	return 0;
}
