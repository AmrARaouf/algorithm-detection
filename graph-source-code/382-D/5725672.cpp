//Language: MS C++


#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;
 
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
typedef unsigned long long ullong;
#define mp make_pair
#define sqr(x) ((x)*(x))
const double PI = 3.14159265359;
#define y1 Y1
#define y0 alalal1231

struct azaza
{
    azaza(){}
    azaza(int x, int y, int dir) : x(x), y(y), dir(dir) {}
    bool operator < (const azaza &a) const
    {
        return x < a.x ||
            x == a.x && y < a.y ||
            x == a.x && y == a.y && dir < a.dir;
    }
    int x, y, dir;
};

int n, m;
char f[2050][2050];
int color[2050][2050];
int len[2050][2050];
azaza id[2050][2050];
int maxLen;
set<azaza> maxId;
bool inf;
int dir[256];

int move(int nx, int ny);

int dfs(int x, int y)
{
    color[x][y] = 1;
    int nx, ny;
    if (f[x][y] == '#')
    {
        id[x][y] = azaza(x, y, 0);
        color[x][y] = 2;
        return 0;
    }
    else if (f[x][y] == '>')
        nx = x, ny = y + 1;
    else if (f[x][y] == '<')
        nx = x, ny = y - 1;
    else if (f[x][y] == '^')
        nx = x - 1, ny = y;
    else
        nx = x + 1, ny = y;
    len[x][y] = move(nx, ny) + 1;

    id[x][y] = f[nx][ny] == '#' ? azaza(nx, ny, dir[f[x][y]]) : id[nx][ny];
    if (len[x][y] > maxLen)
        maxLen = len[x][y], maxId.clear(), maxId.insert(id[x][y]);
    else if (len[x][y] == maxLen)
        maxId.insert(id[x][y]);
    color[x][y] = 2;
    return len[x][y];
}

int move(int nx, int ny)
{
    if (color[nx][ny] == 1)
    {
        inf = true;
        return INT_MIN;
    }
    else if (color[nx][ny] == 2)
        return len[nx][ny];
    else
        return dfs(nx, ny);
}

int main()
{
#ifdef MYLOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t beginTime = clock();
#endif

    dir['>'] = 1;
    dir['<'] = 2;
    dir['^'] = 3;
    dir['v'] = 4;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", f[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!color[i][j])
            {
                dfs(i, j);
                if (inf) break;
            }
    if (inf)
        puts("-1");
    else if (!maxLen)
        puts("0");
    else if (maxId.size() > 1)
        printf("%d", maxLen * 2);
    else 
        printf("%d", maxLen * 2 - 1);

#ifdef MYLOCAL
    cout << endl << "time: " << double(clock() - beginTime) / CLOCKS_PER_SEC;
#endif
    return 0;
}