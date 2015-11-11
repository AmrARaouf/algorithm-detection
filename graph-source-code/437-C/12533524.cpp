//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define min(a,b)  (a<b)?(a):(b)
#define max(a,b)  (a>b)?(a):(b)
#define minn(a,b,c) (min(a,b)<c)?min(a,b):c
#define maxx(a,b,c) (max(a,b)>c)?max(a,b):c
#define swap(a,b) {a+=b;b=a-b;a-=b;}
typedef struct pair{int st,nd;}pair;
int sum,n,m,v[1005],x,y;
int main ()
{
	int i;
	scanf("%d %d",&n,&m);
	for(i=1; i<=n; i++)
		scanf("%d",v+i);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		sum+=min(v[x],v[y]);
	}
	cout<<sum;
}
