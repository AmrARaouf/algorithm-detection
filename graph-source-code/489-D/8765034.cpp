//Language: GNU C++


//gskhirtladze

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int ans[3003],f[3][3003];
int a,b,n,m,i,j;
vector < int > g[3003];
long long res;

void dfs(int u,int sig)
 {
  if (sig == 2) {  res+=ans[u]; ans[u]++; return; }
  f[sig][u]=1;
  for (int i=0;i<g[u].size();i++)
   if (!f[sig+1][g[u][i]]) dfs(g[u][i],sig+1);
 }

main()
 {
  cin>>n>>m;
  for (i=1;i<=m;i++)
   {
    cin>>a>>b;
    g[a].push_back(b);
   }
  for (i=1;i<=n;i++)
   {
    for (j=0;j<=n;j++)
     f[1][j]=0,f[2][j]=0,ans[j]=0;
    f[1][i]=1;
    f[2][i]=1;
    dfs(i,0);
   }
  cout<<res<<endl;
 }
