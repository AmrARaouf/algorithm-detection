//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

struct edge
{
    int next, x, y;
};

struct triplet
{
    int a, b, c;
};

const int maxn = 3010, maxm = 20010;
int n, m, k, num;
typedef int node[maxm << 1];
node head, d, pre, q;
edge e[maxm << 1];

inline bool operator<(const triplet &s1, const triplet &s2)
{
    return (s1.a < s2.a) || (s1.a == s2.a && s1.b < s2.b) || (s1.a == s2.a && s1.b == s2.b && s1.c < s2.c);
}

set<triplet> S;

inline void add(int a, int b)
{
    num++;
    e[num].next = head[a];
    head[a] = num;
    e[num].x = a;
    e[num].y = b;
}

queue<int> Q;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    memset(head, -1, sizeof(head));
    num = -1;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    S.clear();
    for (int i = 0; i < k; i++)
    {
        triplet p;
        scanf("%d%d%d", &p.a, &p.b, &p.c);
        S.insert(p);
    }
    memset(d, 63, sizeof(d));
    for (int i = 0; i <= num; i++)
        if (e[i].x == 1)
        {
            d[i] = 0;
            pre[i] = -1;
            Q.push(i);
        }
    int ans = -1;
    while (!Q.empty())
    {
        triplet p;
        int i = Q.front();
        Q.pop();
        p.a = e[i].x, p.b = e[i].y;
        if (p.b == n)
        {
            ans = i;
            break;
        }
        for (int temp = head[p.b]; temp >= 0; temp = e[temp].next)
        {
            p.c = e[temp].y;
            if (d[temp] > d[i] + 1 && S.find(p) == S.end())
            {
                d[temp] = d[i] + 1;
                pre[temp] = i;
                Q.push(temp);
            }
        }
    }
    if (ans >= 0)
    {
        printf("%d\n", d[ans] + 1);
        int top = 0;
        for (int temp = ans; temp >= 0; temp = pre[temp])
            q[top++] = e[temp].x;
        for (int i = top - 1; i >= 0; i--)
            printf("%d ", q[i]);
        printf("%d\n", n);
    }
    else
    {
        printf("-1\n");
    }
    
    return 0;
} 
