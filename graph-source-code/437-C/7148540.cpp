//Language: GNU C++


#include<stdio.h>
#include<algorithm>
using namespace std;
int x[5000];
int main()
{
  int n,m,i,j,sum,a,b;
  scanf("%d%d",&n,&m);
  sum=0;
  for(i=1;i<=n;i++)
  {
  	scanf("%d",&x[i]);
  }
  for(i=1;i<=m;i++)
  {
  	scanf("%d%d",&a,&b);
  	sum=sum+min(x[a],x[b]);
  }
  printf("%d\n",sum);
}