//Language: GNU C++


#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 100005;
vector <int> v[2][N];
int a[N], q[N], n;
bool vst[2][N];
void bfs (int val)
{
    int i, j, qh = 0, qe = 0, k = val - 1, s, out;
    for (i = 1; i <= n; i ++)
    if (a[i] == val) q[qe ++] = i, vst[k][i] = 1;
    while (qh < qe)
    {
        out = q[qh ++];
        if (val != 2 || a[out] != 1)
        for (i = 0, s = v[k][out].size (); i < s; i ++)
        if (!vst[k][j = v[k][out][i]])
        q[qe ++] = j, vst[k][j] = 1;
    }
}
int main()
{
    int i, j, e;
    while (2 == scanf ("%d%d", &n, &e))
    {
        for (i = 1; i <= n; i ++)
        scanf ("%d", a + i), v[0][i].clear (), v[1][i].clear ();

        while (e --)
        {
            scanf ("%d%d", &i, &j);
            v[0][i].push_back (j);
            v[1][j].push_back (i);
        }
        memset (vst, 0, sizeof vst); bfs (1); bfs (2);
        for (i = 1; i <= n; i ++) puts (vst[0][i] && vst[1][i] ? "1" : "0");
    }
    return 0;
}
