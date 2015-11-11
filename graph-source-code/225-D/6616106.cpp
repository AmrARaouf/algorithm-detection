//Language: GNU C++


#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define MAX_N 20
using namespace std;

int n, m;

char maze[MAX_N][MAX_N];
int d[MAX_N][MAX_N][100000];
pair<int, int> sna[10];
int sx, sy, ss, tx, ty;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int snackLen = -1;

int power(int a, int b)
{
    int s = 1;
    for (int i = 0; i < b; i++)
        s *= a;
    return s;
}

struct node
{
    int x, y, sn;
    node(int _x, int _y, int _sn)
    {
        x = _x;
        y = _y;
        sn = _sn;
    }
};

int bfs()
{
    memset(d, -1, sizeof(d));
    ss = 0;
    sx = sna[1].first;
    sy = sna[1].second;
    for (int i = 1; i < snackLen; i++)
        for (int j = 0; j < 4; j++)
        {
            int nx = sna[i].first + dx[j], ny = sna[i].second + dy[j];
            if (nx == sna[i + 1].first&&ny == sna[i + 1].second)
                ss += power(4, i - 1)*j;
        }
    queue<node> que;
    que.push(node(sx, sy, ss));
    d[sx][sy][ss] = 0;
    while (!que.empty())
    {
        node now = que.front();
        que.pop();
        if (now.x == tx&&now.y == ty)
            return d[now.x][now.y][now.sn];
        for (int i = 0; i < 4; i++)
        {
            if (i == now.sn % 4 && ss != 0)
                continue;
            int nx = now.x + dx[i], ny = now.y + dy[i], nsn = (now.sn % power(4, snackLen - 2)) * 4 + (i + 2) % 4;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || maze[nx][ny] == '#' || d[nx][ny][nsn] != -1)
                continue;
            int x = nx, y = ny;
            bool flag = 0;
            int tempSn = nsn;
            for (int j = 0; j < snackLen - 1; j++)
            {
                int dir = tempSn % 4;
                x += dx[dir];
                y += dy[dir];
                if (nx == x&&ny == y)
                {
                    flag = 1;
                    break;
                }
                tempSn /= 4;
            }
            if (flag)
                continue;
            d[nx][ny][nsn] = d[now.x][now.y][now.sn] + 1;
            que.push(node(nx, ny, nsn));
        }
    }
    return -1;
}

int main()
{
    int cas = 1;
    while (cas == 1 && cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                char c;
                cin >> c;
                if (c >'0'&&c <= '9')
                {
                    maze[i][j] = '.';
                    snackLen = max(snackLen, c - '0');
                    sna[c - '0'] = make_pair(i, j);
                }
                else if (c == '@')
                {
                    tx = i;
                    ty = j;
                    maze[i][j] = c;
                }
                else
                    maze[i][j] = c;
            }
        //cout << "Case #" << cas << ": " << bfs() << endl;
        cout << bfs() << endl;
        cas++;
    }
    return 0;
}