//Language: GNU C++11


#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;
typedef long long ll;

struct edge
{
    ll a, b, w, ind;
};

const int LEN = 100100;
const ll INF = 100000000000000;

int n, m, s, t, use[LEN], use1[LEN], ans[LEN], timer, tin[LEN], fup[LEN];
vector <edge> ar[LEN], ar1[LEN], ar2[LEN];
edge ed[LEN];

ll dist[LEN], dist1[LEN], min_dist, a, b, l;
set <pair <ll, int> > q;

void deixtra(ll (&dist)[LEN], vector <edge> (&ar)[LEN], int s);
void get_gate(int v, int ind);

int main()
{
    scanf("%i %i %i %i", &n, &m, &s, &t);
    s--;
    t--;

    for (int i = 0; i < m; i++)
    {
        scanf("%I64d %I64d %I64d", &a, &b, &l);

        ed[i].w = l;
        ed[i].ind = i;

        ed[i].a = b - 1;
        ed[i].b = a - 1;
        ar1[b - 1].push_back(ed[i]);

        swap(ed[i].a, ed[i].b);
        ar[a - 1].push_back(ed[i]);
    }

    deixtra(dist, ar, s);
    deixtra(dist1, ar1, t);

    min_dist = dist[t];

    for (int i = 0; i < m; i++)
        if (dist[ed[i].a] + ed[i].w + dist1[ed[i].b] == min_dist)
        {
            ar2[ed[i].a].push_back(ed[i]);
            swap(ed[i].a, ed[i].b);
            ar2[ed[i].a].push_back(ed[i]);
            swap(ed[i].a, ed[i].b);
        }

    get_gate(t, -1);

    for (int i = 0; i < m; i++)
        if (ans[i])
            printf("YES\n");
        else if (dist[ed[i].a] + ed[i].w + dist1[ed[i].b] - min_dist + 1 < ed[i].w)
            printf("CAN %I64d\n", dist[ed[i].a] + ed[i].w + dist1[ed[i].b] - min_dist + 1);
        else
            printf("NO\n");

    return 0;
}

void deixtra(ll (&dist)[LEN], vector <edge> (&ar)[LEN], int s)
{
    int x, to, len;
    pair <ll, int> u;

    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[s] = 0;

    q.insert(make_pair(0, s));
    while (!q.empty())
    {
        x = q.begin()->second;
        q.erase(q.begin());

        for (int i = 0; i < ar[x].size(); i++)
        {
            to = ar[x][i].b;
            len = ar[x][i].w;

            if (dist[to] > dist[x] + len)
            {
                q.erase(make_pair(dist[to], to));
                dist[to] = dist[x] + len;
                q.insert(make_pair(dist[to], to));
            }
        }
    }
}

void get_gate(int v, int ind)
{
    int u;

    tin[v] = fup[v] = timer++;
    use1[v] = 1;

    for (int i = 0; i < ar2[v].size(); i++)
    {
        if (ar2[v][i].ind == ind)
            continue;

        u = ar2[v][i].b;

        if (use1[u])
            fup[v] = min(fup[v], tin[u]);
        else
        {
            get_gate(u, ar2[v][i].ind);
            fup[v] = min(fup[v], fup[u]);

            if (fup[u] > tin[v])
                ans[ar2[v][i].ind] = 1;
        }
    }
}
