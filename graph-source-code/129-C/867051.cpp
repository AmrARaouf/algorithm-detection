//Language: GNU C++


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
#define INF 0x3fffffff
char g[10][10];
int vis[10][10][10],dp[10][10][10];
int move[9][2]={{0,0},{0,1},{0,-1},{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1}};
int main()
{
    int i,j,k,p;
    while(scanf("%s",g[0])!=EOF)
    {
        for(i=1;i<8;i++)
        {
            scanf("%s",g[i]);
        }
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(g[i][j]=='S')
                for(k=0;k<8;k++)
                {
                    if(i+k<8)
                    {
                        vis[k][i+k][j]=1;
                    }
                }
            }
        }
        dp[0][7][0]=1;
        for(k=0;k<8;k++)
        {
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    if(dp[k][i][j])
                    {
                        for(p=0;p<9;p++)
                        {
                            int tx=i+move[p][0];
                            int ty=j+move[p][1];
                            if(tx>=0&&tx<8&&ty>=0&&ty<8)
                            {
                                if(!vis[k+1][tx][ty]&&!vis[k][tx][ty])
                                {
                                    dp[k+1][tx][ty]=1;
                                }
                            }
                        }
                    }
                }
            }
        }
        int win=0;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(dp[7][i][j])
                {
                    win=1;
                }
            }
        }
        if(win) printf("WIN\n");
        else    printf("LOSE\n");
    }
    return 0;
}
