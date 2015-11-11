//Language: GNU C++


#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#define PB push_back
#define MP make_pair
#define BG begin()
#define SZ size()
#define SS second
#define ED end()
#define FF first
#define foreach(i,x) for (__typeof((x).begin()) i=(x).begin();i!=(x).end();i++)
#define N 800000
using namespace std;

int t,ok,d[N],p[N],next[N],a[N],b[N],z[N],o[N];

void link(int a,int b) {next[++t]=d[a],d[a]=t,p[t]=b;}

void dfs(int i,int ff) {
  o[ff]=1;
  a[i]=b[i]=++t;
  z[t]=i;
  for (int k=d[i],j=p[k];k;k=next[k],j=p[k]) if ((k^ff)!=1) {
    if (!a[j]) dfs(j,k);
    if (b[j]<b[i]) b[i]=b[j];
    if (a[j]<a[i]) o[k]=1;
  };
  if (a[i]==b[i] && i!=1) ok=1;
};

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  t=1;
  for (int i=1;i<=m;i++) {
    int x,y;
    scanf("%d%d",&x,&y);
    link(x,y);
    link(y,x);
  };
  t=0;
  dfs(1,0);
  for (int i=1;i<=n;i++) if (!a[i]) ok=1;
  if (ok) puts("0"); else {
    for (int j=1;j<=2*m+4;j++) if (o[j]) 
      printf("%d %d\n",p[j^1],p[j]);
  };
  return 0;
}
