//Language: GNU C++0x


#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define N 600
using namespace std;

char s[N][N];
int vis[N][N];

struct Node
{
    char a;
    int x,y;
}f[1000009];

int n,m;
int num;

int fun(char c,int x,int y)
{
    s[x][y]=c;
    num++;
    f[num].a=c;
    f[num].x=x;
    f[num].y=y;

}

void dfs(int x,int y)
{
    if(s[x][y]!='B' || vis[x][y] ) return;

    vis[x][y]=1;

    if(y>1) dfs(x,y-1);
    if(x>1) dfs(x-1,y);
    if(y<m) dfs(x,y+1);
    if(x<n) dfs(x+1,y);

    fun('D',x,y);
    fun('R',x,y);
    return;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);

        memset(vis,0,sizeof vis);
        num=0;

        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='.')
            fun('B',i,j);
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            if(s[i][j]=='B')
            {
                vis[i][j]=1;

                if(j>1) dfs(i,j-1);
                if(i>1) dfs(i-1,j);
                if(j<m) dfs(i,j+1);
                if(i<n) dfs(i+1,j);

            }
        }

        printf("%d\n",num);
        for(int i=1;i<=num;i++)
        {
            printf("%c %d %d\n",f[i].a,f[i].x,f[i].y);
        }

    }
    return 0;
}
