//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
#define MAXN 58
char str[MAXN][MAXN];
char in[MAXN][MAXN];
int n,m;
int dir[][2] = {0,1,1,0,0,-1,-1,0};
void dfs(int x,int y)
{
    if(in[x][y] == '#')in[x][y] = '.';
    int i;
    for(i = 0; i < 4; i++)
    {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(xx >= 0 && xx < n && yy >= 0 && yy < m && in[xx][yy] == '#')dfs(xx,yy);
    }
}
bool check(int x,int y)
{
    int i,j;
    int cnt = 0;
    memcpy(in,str,sizeof(str));
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(in[i][j] == '#')
            {
                cnt++;
                dfs(i,j);
            }
        }
    }
    return cnt > 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    int cnt = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%s",str[i]);
        for(j = 0; j < m; j++)
        {
            if(str[i][j] == '#')cnt++;
        }
    }
    if(cnt < 3)
    {
        printf("-1\n");
        return 0;
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(str[i][j] == '#')
            {
                str[i][j] = '.';
                if(check(i,j))
                {
                    printf("1\n");
                    return 0;
                }
                str[i][j] = '#';
            }
        }
    }
    printf("2\n");
    return 0;
}
