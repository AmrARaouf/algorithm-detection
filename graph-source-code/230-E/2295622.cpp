//Language: GNU C++


#include <algorithm>
#include <stdio.h>
#define  MAXN      1000002
using    namespace std;
typedef  long long llint;

llint N,M,ans;
llint sz[MAXN];

int main()
{
  scanf("%I64d%I64d",&N,&M);
  for(llint i=0,x,y ; i<M ; i++)
  {
    scanf("%I64d%I64d",&x,&y);
    sz[x]++,sz[y]++;
  }
  for(llint i=1 ; i<=N ; i++)
  {
    llint x=sz[i],y=N-sz[i]-1;
    ans+=x*(x-1)+y*(y-1)-x*y;
  }
  printf("%I64d\n",ans/6);
  return 0;
}
