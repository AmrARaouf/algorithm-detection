//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

const int N = 100010;
bool marker[N];

struct P
{
    long long sum;
    int vertex;
    P () {}
    P (long long a, int b) :
        sum(a), vertex(b) {}
};

P heap[N * 2];
int size_heap;

void down(int i)
{
    while ((i << 1) < size_heap)
    {
        int j = i << 1;
        if (j + 1 < size_heap && heap[j + 1].sum < heap[j].sum)
            j++;
        if (heap[i].sum <= heap[j].sum)
            break;
        swap(heap[j], heap[i]);
        i = j;
    }
}

void up(int i)
{
    while (i > 0)
    {
        if (heap[i].sum >= heap[i >> 1].sum)
            break;
        swap(heap[i], heap[i >> 1]);
        i >>= 1;
    }
}

P get_min()
{
    P res = heap[0];
    heap[0] = heap[--size_heap];
    down(0);
    return res;
}

void push(P x)
{
    heap[size_heap] = x;
    up(size_heap++);
}

vector< pair<int, int> > E[N];

long long dfs(int i)
{
    marker[i] = true;
    long long res = 0;
    for (int j = 0; j < E[i].size(); j++)
    {
        int to = E[i][j].first;
        if (marker[to] == false)
            res += dfs(to);
        res += E[i][j].second;

    }

    return res;
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, p, d;
    scanf("%d %d %d %d", &n, &m, &p, &d);

    if (n == 1)
    {
        if (p == 0 && d == 1)
            printf("YES");
        else
            printf("NO");
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        E[a].push_back(make_pair(b, c));
        E[b].push_back(make_pair(a, c));
    }

    int cnt = 0;
    pair<int, int> last_ans = make_pair(-1, -1);
    for (int i = 0; i < n; i++)
    {
        if (marker[i] == false)
        {
            cnt++;
            long long sum = dfs(i) / 2;
            push(P(sum, i));
            if (sum > 0)
                last_ans = make_pair(i, E[i][0].first);
        }
    }

    if (cnt < d || cnt - p > d || (cnt == d && last_ans.first == -1 && p > 0))
    {
        printf("NO");
        return 0;
    }

    printf("YES\n");

    for (int i = 0; i < cnt - d; i++)
    {
        P a, b;
        a = get_min();
        b = get_min();
        long long len = min(10000LL * 10000 * 10, a.sum + b.sum + 1);
        a.sum += b.sum + len;
        push(a);
        printf("%d %d\n", a.vertex + 1, b.vertex + 1);
        last_ans = make_pair(a.vertex, b.vertex);
    }

    if (last_ans.first == -1)
        for (int i = 0; i < p - (cnt - d); i++)
            printf("%d %d\n", last_ans.first + 1, last_ans.second + 1);
    else
        for (int i = 0; i < p - (cnt - d); i++)
            printf("%d %d\n", last_ans.first + 1, last_ans.second + 1);

    return 0;
}