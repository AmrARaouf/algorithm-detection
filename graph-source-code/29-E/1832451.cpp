//Language: MS C++


#include <cstdio>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <cmath>
using namespace std;
bool a[505][505];
bool used[505][505][2];
pair<int,int> pr[505][505][2];
pair<pair<int,int>, int> q[500005];
int n,m;
void PRINT(int i, int j)
{
    vector<int> a[2];
    a[0].push_back(i);
    a[1].push_back(j);
    int st = 0;
    while ((i != 0) || (j != (n-1)))
    {
        if (st == 0)
            a[1].push_back(pr[i][j][0].second); else
            a[0].push_back(pr[i][j][1].first);
        int i1,j1;
        i1 = i;
        j1 = j;
        i = pr[i1][j1][st].first;
        j = pr[i1][j1][st].second;
        st = 1- st;
    }
    printf("%d\n", a[0].size()-1);
    for (int i = a[0].size()-1; i>= 0; i--)
    {
        printf("%d%c", a[0][i]+1, (!i) ? '\n' : ' ');
    }
    for (int i =  a[1].size()-1; i>=0; i--)
    {
        printf("%d%c", a[1][i]+1, (!i) ? '\n' : ' ');
    }
}
int main(void)
{

    scanf("%d%d",&n,&m);
    for (int i = 0 ; i < m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    int st, sl;
    st = sl = 0;
    q[st++] = make_pair(make_pair(0,n-1),0);
    used[0][n-1][0] = 1;
    while (sl != st)
    {
        pair<pair<int,int>,int> p = q[sl++];
        int u = p.first.first;
        int v = p.first.second;
        int w = p.second;
        if (!w)
        {
            for (int i = 0 ; i < n; i++)
                if (a[u][i])
                    if (!used[i][v][1])
                    {
                        q[st++] = make_pair(make_pair(i,v),1);
                        used[i][v][1] = 1;
                        pr[i][v][1] = make_pair(u,v);
                    }
        } else
            for (int i = 0 ; i < n; i++)
                if (a[v][i])
                    if (i != u)
                        if (!used[u][i][0])
                        {
                            q[st++] = make_pair(make_pair(u,i),0);
                            used[u][i][0] = 1;
                            pr[u][i][0] = make_pair(u,v);
                            if ((u == (n-1)) && (i == 0))
                            {
                                PRINT(n-1,0);
                                return 0;
                            }
                        }
        
    }
    printf("-1\n");
    return 0;   
}