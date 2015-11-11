//Language: MS C++


#include <stdio.h>
#include <vector>
#include <set>
#include <memory.h>
using namespace std;
#define mp make_pair
int n, m, x, y, u, v, w, i, j, s, to, len, t[1001], c[1001];
long long d[1001][1001], ms[1001];
const long long INF=1000000000000;
bool used[1001];
vector < pair<int, int> > g[1001], a[1001];
set < pair<int, int> > q;
int main()
{
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for(i=0; i<m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(mp(v, w));
        g[v].push_back(mp(u, w));
    }
    for(i=1; i<=n; i++)
        scanf("%d%d", &t[i], &c[i]);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            d[i][j]=INF;
    for(s=1; s<=n; s++)
    {
        d[s][s]=0;
        q.insert(mp(0, s));
        while(!q.empty())
        {
            v=q.begin()->second;
            q.erase(q.begin());
            for(i=0; i<g[v].size(); i++)
            {
                to=g[v][i].first;
                len=g[v][i].second;
                if(d[s][v]+len<d[s][to])
                {
                    q.erase(mp(d[s][to], to));
                    d[s][to]=d[s][v]+len;
                    q.insert(mp(d[s][to], to));
                }
            }
        }
    }
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(d[i][j]<=t[i])
                a[i].push_back(mp(j, c[i]));
    for(i=1; i<=n; i++)
        ms[i]=INF;
    ms[x]=0;
    q.insert(mp(0, x));
    while(!q.empty())
    {
        v=q.begin()->second;
        q.erase(q.begin());
        for(i=0; i<a[v].size(); i++)
        {
            to=a[v][i].first;
            len=a[v][i].second;
            if(ms[v]+len<ms[to])
            {
                q.erase(mp(ms[to], to));
                ms[to]=ms[v]+len;
                q.insert(mp(ms[to], to));
            }
        }
    }
    if(ms[y]==INF)
        printf("-1");
    else
        printf("%I64d", ms[y]);
    return 0;
}