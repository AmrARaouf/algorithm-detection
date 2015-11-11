//Language: GNU C++


#include <cstdio>
using namespace std;

const int Maxn = 200000 + 10;
int pre[Maxn << 1], other[Maxn << 1], last[Maxn];
bool v[Maxn];
int s[2][Maxn];
int a[Maxn], d[Maxn], st[Maxn], et[Maxn];
int n, m, l, time;

void Add_edge(int p, int q)
{
    pre[++l] = last[p]; last[p] = l; other[l] = q;
    pre[++l] = last[q]; last[q] = l; other[l] = p;
}

void Init()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        Add_edge(x, y);
    }
}

void Dfs(int p)
{
    v[p] = 1;
    st[p] = ++time;
    for (int q = last[p]; q; q = pre[q])
        if (!v[other[q]]){
            d[other[q]] = d[p] ^ 1;
            Dfs(other[q]);
        }
    et[p] = time;
}

void Add(int t, int x, int val)
{
    while (x <= time){
        s[t][x] += val;
        x += x & (-x);
    }
}

int Ask(int t, int x)
{
    int ans = 0;
    while (x){
        ans += s[t][x];
        x -= x & (-x);
    }
    return ans;
}

void Work()
{
    d[1] = 0;
    Dfs(1);
    for (int i = 0; i < m; ++i){
        int t;
        scanf("%d", &t);
        if (t == 1){
            int x, val;
            scanf("%d%d", &x, &val);
            Add(d[x], st[x], val); Add(d[x], et[x] + 1, -val);
            Add(d[x] ^ 1, st[x], -val); Add(d[x] ^ 1, et[x] + 1, val);
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", Ask(d[x], st[x]) + a[x]);
        }
    }
}

int main()
{
    Init();
    Work();
    return 0;
}
