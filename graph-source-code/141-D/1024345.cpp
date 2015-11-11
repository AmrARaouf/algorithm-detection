//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

#define mp make_pair
#define pb push_back
#define fs first
#define sc second

typedef long long int64;
typedef long double ext;

using namespace std;

const int maxn = 1000000;
const int maxp = 1000000;
const int maxe = 1000000;
const int inf = 2000 * 1000 * 1000;

struct tr
{
    int x, y;
    int t;
};
struct edge
{
    int v, u, t, id;
};

int n, l, m, cnt, res;
int ans[maxn];
tr t[maxn];
int first[maxp], last[maxp], next[maxe];
edge e[maxe];
int p[maxp], d[maxp], id[maxp];
int tree[2 * maxp], tid[2 * maxp];
bool b[maxp];


void addp(int x)
{
    p[m++] = x;
}

void add(int v, int u, int t, int id)
{
    if (first[v] == -1)
        first[v] = cnt;
    else
        next[last[v]] = cnt;
    e[cnt].v = v;
    e[cnt].u = u;
    e[cnt].t = t;
    e[cnt].id = id;
    last[v] = cnt;
    next[cnt] = -1;
    cnt++;
}

void update(int v)
{
    int a = tree[2 * v + 1];
    int aid = tid[2 * v + 1];
    int b = tree[2 * v + 2];
    int bid = tid[2 * v + 2];
    if (a < b)
    {
        tree[v] = a;
        tid[v] = aid;
    }
    else
    {
        tree[v] = b;
        tid[v] = bid;
    }
}

void build(int v, int l, int r)
{
    if (l == r - 1)
    {
        tree[v] = d[l];
        tid[v] = l;
    }
    else
    {
        int m = (l + r) / 2;
        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);
        update(v);
    }
}

void modify(int v, int l, int r, int x, int y)
{
    if ((x < l) || (x >= r))
        return;
    else if (l == r - 1)
    {
        tree[v] = y;
        tid[v] = x;
    }
    else
    {
        int m = (l + r) / 2;
        modify(2 * v + 1, l, m, x, y);
        modify(2 * v + 2, m, r, x, y);
        update(v);
    }
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    scanf("%d %d", &n, &l);
    m = 0;
    addp(0);
    addp(l);
    for (int i = 0; i < n; i++)
    {
        int x, d, tt, p;
        scanf("%d %d %d %d", &x, &d, &tt, &p);
        t[i].x = x - p;
        t[i].y = x + d;
        t[i].t = p + tt;
        if (t[i].x >= 0)
        {
            addp(t[i].x);
            addp(t[i].y);
        }
    }
    sort(p, p + m);
    cnt = 0;
    for (int i = 0; i < m; i++)
        first[i] = last[i] = -1;
    for (int i = 0; i < n; i++)
    {
        if (t[i].x < 0)
            continue;
        t[i].x = lower_bound(p, p + m, t[i].x) - p;
        t[i].y = lower_bound(p, p + m, t[i].y) - p;
        add(t[i].x, t[i].y, t[i].t, i);
    }
    for (int i = 0; i < m - 1; i++)
    {
        add(i, i + 1, p[i + 1] - p[i], -1);
        add(i + 1, i, p[i + 1] - p[i], -1);
    }

    for (int i = 0; i < m; i++)
    {
        d[i] = inf;
    }
    d[0] = 0;
    build(0, 0, m);
    for (int i = 0; i < m; i++)
    {
        int mid = tid[0];
        for (int j = first[mid]; j != -1; j = next[j])
        {
            edge w = e[j];
            if (d[w.u] > d[mid] + w.t)
            {
                d[w.u] = d[mid] + w.t;
                id[w.u] = j;
                modify(0, 0, m, w.u, d[w.u]);
            }
        }
        modify(0, 0, m, mid, inf + 1);
    }
    printf("%d\n", d[m - 1]);
    res = 0;
    for (int i = m - 1; i != 0;)
    {
        edge w = e[id[i]];
        if (w.id != -1)
            ans[res++] = w.id + 1;
        i = w.v;
    }
    printf("%d\n", res);
    for (int i = res - 1; i >= 0; i--)
        printf("%d ", ans[i]);

    return 0;
}
