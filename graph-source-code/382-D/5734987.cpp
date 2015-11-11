//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZE = 2020;

int n,m;
char maze[SIZE][SIZE];
int dp[SIZE][SIZE];
bool vis[SIZE][SIZE];
int root[SIZE][SIZE],id;
int maxi[SIZE*SIZE];
char opp[SIZE];

void dfs(int x,int y)
{
    if(vis[x][y])
        return;
    if(maze[x][y] == '#')
    {
        dp[x][y] = 0;
        return;
    }
    int tx = x,ty = y;
    if(maze[x][y] == '>')ty++;
    if(maze[x][y] == '<')ty--;
    if(maze[x][y] == '^')tx--;
    if(maze[x][y] == 'v')tx++;
    if(opp[maze[x][y]] == maze[tx][ty])
    {
        puts("-1");
        exit(0);
    }
    dfs(tx,ty);
    dp[x][y] = dp[tx][ty]+1;
    if(dp[x][y] == 1)
    {
        ++id;
        root[x][y] = id;
    }
    else
        root[x][y] = root[tx][ty];
    maxi[root[x][y]] = max(maxi[root[x][y]],dp[x][y]);
    vis[x][y] = true;
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)for(int j=1; j<=m; j++)
        cin >> maze[i][j];
    opp['>'] = '<';
    opp['<'] = '>';
    opp['^'] = 'v';
    opp['v'] = '^';
    memset(vis,0,sizeof(vis));
    memset(maxi,0,sizeof(maxi));
    id = 0;
    for(int i=1; i<=n; i++)for(int j=1; j<=m; j++)
        if(!vis[i][j] && maze[i][j] != '#')
            dfs(i,j);
    int Max1 = 0,Max2 = 0;
    for(int i=1; i<=id; i++)
    {
        if(Max2 < maxi[i])
            Max2 = maxi[i];
        if(Max2 > Max1)
            swap(Max1,Max2);
    }
    cout << max(2*Max1-1,Max1+Max2) << endl;
    return 0;
}

/*
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define ls l,mid,rt<<1
#define rs mid+1,r,rt<<1|1

typedef long long LL;
const int SIZE = 2024;

int n,m;
char ma[SIZE][SIZE];
int dp[SIZE][SIZE],e[SIZE][SIZE];
bool vis[SIZE][SIZE];
int x[SIZE],y[SIZE];

int dfs(int a,int b)
{
    if(ma[a][b] == '#')
    {
        dp[a][b] = 0;
        e[a][b] = (a-1)*n+b;
        return 0;
    }
    if(vis[a][b])
        return dp[a][b];
    dp[a][b] = 1;
    if(ma[a][b] == '>')
    {
        if(ma[a][b+1] == '<')
        {
            puts("-1");
            exit(0);
        }
        dp[a][b] += dfs(a,b+1);
        e[a][b] = e[a][b+1];
    }
    else if(ma[a][b] == '<')
    {
        if(ma[a][b-1] == '>')
        {
            puts("-1");
            exit(0);
        }
        dp[a][b] += dfs(a,b-1);
        e[a][b] = e[a][b-1];
    }
    else if(ma[a][b] == '^')
    {
        if(ma[a-1][b] == 'v')
        {
            puts("-1");
            exit(0);
        }
        dp[a][b] += dfs(a-1,b);
        e[a][b] = e[a-1][b];
    }
    else if(ma[a][b] == 'v')
    {
        if(ma[a+1][b] == '^')
        {
            puts("-1");
            exit(0);
        }
        dp[a][b] += dfs(a+1,b);
        e[a][b] = e[a+1][b];
    }
    vis[a][b] = true;
    return dp[a][b];
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> ma[i][j];
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    int id = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(vis[i][j] || ma[i][j] =='#')continue;
            dp[i][j] = dfs(i,j);
            if(ma[i][j] == '>' && ma[i-1][j] == '#' && ma[i+1][j] == '#' && ma[i][j-1] == '#')
                x[++id] = i,y[id] = j;
            if(ma[i][j] == '<' && ma[i-1][j] == '#' && ma[i+1][j] == '#' && ma[i][j+1] == '#')
                x[++id] = i,y[id] = j;
            if(ma[i][j] == '^' && ma[i][j+1] == '#' && ma[i+1][j] == '#' && ma[i][j-1] == '#')
                x[++id] = i,y[id] = j;
            if(ma[i][j] == 'v' && ma[i][j+1] == '#' && ma[i-1][j] == '#' && ma[i][j-1] == '#')
                x[++id] = i,y[id] = j;
        }
    }
    int ans = 0;
    for(int i=1; i<=id; i++)
    {
        int a,b;
        a = x[i],b = y[i];
        ans = max(ans,dp[a][b]+dp[a][b]-1);
        for(int j=i+1; j<=id; j++)
        {
            int aa = x[j],bb = y[j];
            if(e[a][b] != e[aa][bb])
                ans = max(ans,dp[a][b]+dp[aa][bb]);
            else
            {
                if(dp[a][b] == dp[aa][bb])
                {
                    int all = 0;
                    int t = e[a][b];
                    int yy = t-(t/n*n);
                    int xx = (t/n)+1;
                    if(ma[xx][yy-1] == '#')all++;
                    if(ma[xx][yy+1] == '#')all++;
                    if(ma[xx+1][yy] == '#')all++;
                    if(ma[xx-1][yy] == '#')all++;
                    if(all < 3)
                        ans = max(ans,dp[a][b]+dp[aa][bb]);
                    else
                        ans = max(ans,dp[a][b]+dp[aa][bb]-1);
                }
                else
                    ans = max(ans,dp[a][b]+dp[aa][bb]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
*/
