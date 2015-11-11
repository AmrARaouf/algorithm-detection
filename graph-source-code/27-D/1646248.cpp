//Language: MS C++


#include <cstdio>
#include <algorithm>

using namespace std;

bool flag,f[101][101];
int n,m,a[101],b[101],c[101];

void dfs(int x,int z)
{
  c[x]=z;
  for(int y=1;y<=m;++y)
  {
    if(f[x][y])
    {
      if(c[y]==0)
      {
        dfs(y,-z);
        if(!flag)
          return;
      }
      else if(c[y]==z)
      {
        flag=false;
        false;
      }
    }
  }
  return;
}

int main(void)
{
  scanf("%d %d",&n,&m);
  for(int i=1;i<=m;++i)
  {
    scanf("%d %d",&a[i],&b[i]);
    if(a[i]>b[i])
      swap(a[i],b[i]);
  }
  for(int i=1;i<m;++i)
  {
    for(int j=i+1;j<=m;++j)
    {
      if((a[i]<a[j])&&(a[j]<b[i])&&(b[i]<b[j])||(a[j]<a[i])&&(a[i]<b[j])&&(b[j]<b[i]))
      {
        f[i][j]=true;
        f[j][i]=true;
      }
    }
  }
  flag=true;
  for(int i=1;i<=m;++i)
  {
    if(c[i]==0)
    {
      dfs(i,1);
      if(!flag)
        break;
    }
  }
  if(flag)
  {
    for(int i=1;i<=m;++i)
    {
      if(c[i]==1)
        printf("o");
      else if(c[i]==-1)
        printf("i");
    }
    printf("\n");
  }
  else
    printf("Impossible\n");
  return 0;
}