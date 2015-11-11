//Language: GNU C++0x


#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void) 
{
    ios_base::sync_with_stdio(false);
    const long long INF = 10000000000000;
    int n, m;
    cin >> n >> m;
    vector < vector < pair<int,int> > > g (n);
    vector< vector<int> > t(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    for (int i = 0; i < n; ++i)
    {
        int k, a;
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> a;
            t[i].push_back(a);
        }
    }           
    int s = 0; 
    vector<long long> d (n, INF),  p (n);
    d[s] = 0;
    set < pair<long long,long long> > q;
    q.insert (make_pair (d[s], s));
    while (!q.empty()) 
    {
        int v = q.begin()->second;
        q.erase (q.begin());
        if (v != n-1)
            for (size_t j = 0; j < t[v].size(); ++j)
            {
                if (t[v][j] == d[v])
                    ++d[v];
                else if (t[v][j] > d[v])
                    break;
            }
            for (size_t j=0; j<g[v].size(); ++j)
            {
                int to = g[v][j].first,
                    len = g[v][j].second;
                if (d[v] + len < d[to]) {
                    q.erase (make_pair (d[to], to));
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.insert (make_pair (d[to], to));
                }
            }
    }
    if (d[n-1] == INF)
        d[n-1] = -1;
    cout << d[n-1] << endl;
    return 0;
}