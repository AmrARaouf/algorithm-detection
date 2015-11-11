//Language: MS C++


#include <iostream>
#include <vector>

using namespace std;

struct point{
    int x,y;    
    point(int a, int b)
    {
        x = a;
        y = b;
    }
    point()
    {

    }
};

bool mark[51][51];
char X[51][51];
int n,m;

bool sharrp(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (X[x][y] == '#')
        return true;
    return false;

}

void dfs(point p)
{
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    for (int i = 0; i < 4; i++)
    {
        if (sharrp(p.x + dx[i], p.y + dy[i]) && !mark[p.x+dx[i]][p.y+dy[i]])
        {
            mark[p.x+dx[i]][p.y+dy[i]] = true;
            dfs(point(p.x+dx[i], p.y+dy[i]));
            mark[p.x+dx[i]][p.y+dy[i]] = true;
        
        }
    }
}


bool CHECK(point p)
{
    for (int i = 0; i < 51; i++)
        for (int j = 0; j < 51; j++)
            mark[i][j] = 0;
    mark[p.x][p.y] = true;
    point hamsaye;
    if (sharrp(p.x-1, p.y))
        hamsaye = point(p.x-1, p.y);
    if (sharrp(p.x+1, p.y))
        hamsaye = point(p.x+1, p.y);
    if (sharrp(p.x, p.y+1))
        hamsaye = point(p.x, p.y+1);
    if (sharrp(p.x, p.y-1))
        hamsaye = point(p.x, p.y-1);
    mark[hamsaye.x][hamsaye.y] = true;
    dfs(hamsaye);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (X[i][j] == '#' && !mark[i][j])
                return true;
        }
    return false;
}


int main()
{
    cin >> n >> m;
    vector<point> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> X[i][j];
            if (X[i][j] == '#')
                v.push_back(point(i,j));
        }
    }
    if (v.size() <= 2)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (CHECK(v[i]))
        {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 2 << endl;
}