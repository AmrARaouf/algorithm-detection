//Language: GNU C++


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int map[1010][1010];
int vis[1010][1010];
int f[4][2]={0,1,1,0,0,-1,-1,0};
int m,maxx,maxy;
void dfs(int x,int y)
{
    vis[x][y]=1;
    m++;
    int px,py;;
    int flag;
    for(int i=0;i<4;i++)
    {
        px=x;py=y;
        flag=0;
        while(1){
        px=px+f[i][0];
        py=py+f[i][1];
        if(px>=1&&px<=maxx&&py>=1&&py<=maxy&&vis[px][py]==0&&map[px][py]==1)
        {
            flag=1;
            break;
        }
        if(px<1||px>maxx||py<1||py>maxy)
            break;
        }
        if(flag==1)
            dfs(px,py);
    }

}

int main()
{
    int n;
    int x,y;
    while(~scanf("%d",&n))
    {
        maxx=-1;maxy=-1;
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++)
            {
                scanf("%d %d",&x,&y);
                if(x>maxx)
                    maxx=x;
                if(y>maxy)
                    maxy=y;
                map[x][y]=1;
            }
        int ans=0;
        memset(vis,0,sizeof(vis));
        m=0;
        for(int i=1;i<=maxx;i++)
        {
            for(int j=1;j<=maxy;j++)
                if(map[i][j]==1&&vis[i][j]==0)
                {
                    dfs(i,j);
                    ans++;
                    if(m==n)
                        break;
                }
            if(m==n)
                break;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}



