//Language: GNU C++


# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <algorithm>
# define INF 1000000007 // 10^9 + 7
# define rep(i,n) for(i=0;i<n;i++)

using namespace std;

FILE * fi = fopen("file.in","r");
FILE * fo = fopen("file.out","w");

int cmp(void const *x,void const *y)
{
	long a = *(long*)x;
	long b = *(long*)y;
	
	return a-b;
}

__int64 n,m,k,l,i,j,t,a,b,c,d;
__int64 x[1000100];

main()
{
	scanf("%I64d %I64d",&n,&m);
	
	rep(i,m)
	{
		scanf("%I64d %I64d",&a,&b);
		
		x[a]++;x[b]++;
	}
	
	t=0;k=0;
	
	t=n*(n-1);
	t*=(n-2);
	t/=6;
	
	rep(i,n+1)
	{
		k+=(x[i]*(n-x[i]-1));
	}
	
	k/=2;
	
	printf("%I64d\n",(t-k));
	
	getchar();getchar();
}
