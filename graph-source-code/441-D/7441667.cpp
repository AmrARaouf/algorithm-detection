//Language: GNU C++


#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 3010
using namespace std;
int n,m,k,cur,p[N],pos[N];
bool f[N];
int Abs(int x){return x>0?x:-x;}
void dfs(int i){for (;!f[i];i=p[i]) f[i]=1;}
int main(){
  int i,j;
  for (scanf("%d",&n),i=1;i<=n;i++) scanf("%d",&p[i]);
  for (scanf("%d",&m),i=1;i<=n;i++) if (!f[i]) k++,dfs(i);
  for (m=n-m,i=1;i<=n;i++) f[i]=0;
  printf("%d\n",Abs(m-k));
  if (m<k) for (dfs(1),i=2;i<=n&&k>m;i++) if (!f[i]) {
    dfs(i);
    printf("%d %d ",1,i);
    k--;
  }
  if (m>k) for (i=1;i<=n&&k<m;i++) {
    vector<int>pos(n+1,-1);
    for (cur=-1,j=p[i];j!=i;j=p[j]) pos[j]=++cur;
    pos[i]=++cur;
    for (cur=0,j=i+1;j<=n&&k<m;j++) if (pos[j]>=cur){
      printf("%d %d ",i,j);
      k++;
      cur=pos[j]+1;
      swap(p[i],p[j]);
    }
  }
  return 0;
}
