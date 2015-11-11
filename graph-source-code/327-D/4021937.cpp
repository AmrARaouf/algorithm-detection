//Language: GNU C++


#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int vis[600][600];
int map[600][600];
int n,m;
int dd[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct node
{
  char a;
  int i;
  int j;
};
queue<node> s;
node tmp;
int ans;
void dfs(int i,int j,int tot)
{
    ans++;
    tmp.a='B';
    tmp.i=i;
    tmp.j=j;
    s.push(tmp);
    for(int d=0;d<4;d++)
    {
        int ni=i+dd[d][0];
        int nj=j+dd[d][1];
        if(ni>=1&&ni<=n&&nj>=1&&nj<=m&&map[ni][nj]&&!vis[ni][nj])
        {
            vis[ni][nj]=1;
            dfs(ni,nj,tot+1);
        }
    }
    if(tot!=1)
    {
        ans+=2;
        tmp.a='D';
        tmp.i=i;
        tmp.j=j;
        s.push(tmp);
        tmp.a='R';
        s.push(tmp);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int tot=0;
        memset(vis,0,sizeof(vis));
        char a[600];
        ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",a);
            for(int j=1;j<=m;j++)
            {
                if(a[j-1]=='.') {map[i][j]=1;tot++;}
                else
                {
                    map[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]) continue;
                vis[i][j]=1;
                dfs(i,j,1);
            }
        }
        printf("%d\n",ans);
        while(!s.empty())
        {
            printf("%c %d %d\n",s.front().a,s.front().i,s.front().j);
            s.pop();
        }
    }
    return 0;
}
