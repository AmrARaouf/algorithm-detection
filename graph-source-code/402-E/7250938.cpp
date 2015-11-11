//Language: GNU C++


#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 2001

int head[MAX], low[MAX], num[MAX], st[MAX], del[MAX];
struct{
    int v, link;
}e[MAX * MAX];

int n, m = 0, id = 0, top = 0, ans = 1;

void dfs(int u)
{
    st[top++] = u;
    num[u] = ++id;
    low[u] = n + 1;

    for (int i = head[u]; i > 0; i = e[i].link)
    {
        int v = e[i].v;
        if (!del[v])
        {
            if (!num[v])
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else
                low[u] = min(low[u], num[v]);
        }
    }

    if (low[u] >= num[u])
    {
        int cnt = 0;
        int v;
        do {
            cnt++;
            v = st[--top];
            del[v] = 1;
        } while (v != u);

        if (cnt < n)
            ans = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
//  freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    {
        int w;
        cin >> w;
        if (w && (i != j))
        {
            m++;
            e[m] = { j, head[i] };
            head[i] = m;
        }
    }

    dfs(1); 

    if (ans)
        cout << "YES";
    else
        cout << "NO";


}