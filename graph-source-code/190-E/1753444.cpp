//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 500005, Size = 18800005;
int T[N], D[N], U[N], v[N], n, nr, poz;
char READ[Size];

vector<int> graph[N];

inline int max(int a, int b)
{
    return a > b ? a : b;
}

void standard()
{
    #ifndef ONLINE_JUDGE
        freopen("cf.in", "r", stdin);
        freopen("cf.out", "w", stdout);
    #endif
}

int tata(int x)
{
    if (x == T[x])
        return x;
    return T[x] = tata(T[x]);
}

void merge(int x, int y)
{
    x = tata(x);
    y = tata(y);

    if (x == y)
        return;

    if (D[x] > D[y])
        T[y] = x;

    if (D[x] < D[y])
        T[x] = y;

    if (D[x] == D[y])
    {
        T[y] = x;
        D[x]++;
    }
}

void merge_up(int nod, int st, int dr)
{
    if (st > dr)
        return;

    merge(nod, st);

    U[st] = max(U[st], dr);
}

void transfer(int v[], vector<int>& a)
{
    v[0] = 0;

    for (vector<int> :: iterator it = a.begin() ; it != a.end() ; it++)
        v[++v[0]] = *it;

    a.clear();
}

void solve()
{
    for (int x = 1 ; x <= n ; x++)
    {
        transfer(v, graph[x]);

        sort(v + 1, v + v[0] + 1);

        for (int i = 2 ; i <= v[0] ; i++)
            merge_up(x, v[i - 1] + 1, v[i] - 1);
    }

    for (int i = 1; i < n ; i++)
    {
        U[i] = max(U[i], U[i - 1]);

        if (i < U[i])
            merge(i, i + 1);
    }
}

inline bool cifra(char c)
{
    return '0' <= c && c <= '9';
}

void get(int& x)
{
    x = 0;

    while (!cifra(READ[poz]))
        poz++;

    while (cifra(READ[poz]))
        x = x * 10 + READ[poz++] - '0';
}

int main()
{
    standard();

    int m, x, y;

    cin.getline(READ, Size, '\0');

    get(n); get(m);

    while (m--)
    {
        get(x); get(y);

        graph[x].push_back(y);
        graph[y].push_back(x);

    }

    for (int i = 1 ; i <= n ; i++)
    {
        T[i] = i;
        D[i] = 1;

        graph[i].push_back(0);
        graph[i].push_back(n + 1);

    }

    solve();

    for (int i = 1 ; i <= n ; i++)
        graph[ tata(i) ].push_back(i);

    for (int i = 1 ; i <= n ; i++)
        if (!graph[i].empty())
            nr++;

    cout << nr << "\n";

    for (int i = 1 ; i <= n ; i++)
    {
        if (graph[i].empty())
            continue;

        cout << graph[i].size();

        for (vector<int> :: iterator it = graph[i].begin() ; it != graph[i].end() ; it++)
            cout << " " << *it;

        cout << "\n";
    }

    return 0;
}
