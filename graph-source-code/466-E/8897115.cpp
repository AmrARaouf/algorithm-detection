//Language: GNU C++


#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100003
typedef struct Tseg *Pseg;
struct Tseg
{
    int mm;
    int l, r;
    Pseg left, right;
};
void buildseg(Pseg &h, int l, int r, int *a)
{
    if (l == r)
    {
        h = NULL;
        return;
    }
    h = new Tseg();
    h->l = l, h->r = r;
    if (l + 1 == r)
    {
        h->mm = a[l];
        h->left = h->right = NULL;
    }
    else
    {
        int mid = (l + r) / 2;
        buildseg(h->left, l, mid, a);
        buildseg(h->right, mid, r, a);
        h->mm = max(h->left->mm, h->right->mm);
    }
}
int queryseg(Pseg h, int l, int r)
{
    if (h == NULL || l == r)
        return 0;
    if (l <= h->l && h->r <= r)
        return h->mm;
    int mid = (h->l + h->r) / 2;
    if (r <= mid)
        return queryseg(h->left, l, r);
    if (mid <= l)
        return queryseg(h->right, l, r);
    return max(queryseg(h->left, l, r), queryseg(h->right, l, r));
}
typedef struct Tedge *Pedge;
struct Tedge
{
    int to, val;
    Pedge next;
    Tedge(int _to, int _val, Pedge _next)
        : to(_to), val(_val), next(_next) {}
};
Pedge edge[MAXN];
bool vis[MAXN];
struct Tree
{
    int wei, sum, dep;
    Pedge son, fa;
} tr[MAXN];
void buildtree(int x, Pedge fa, int deep)
{
    vis[x] = true;
    tr[x].fa = fa;
    tr[x].sum = 1;
    tr[x].wei = -1;
    tr[x].son = NULL;
    tr[x].dep = deep;
    for (Pedge i = edge[x]; i; i = i->next)
        if (!vis[i->to])
        {
            buildtree(i->to, new Tedge(x, i->val, NULL), deep + 1);
            tr[x].son = new Tedge(i->to, i->val, tr[x].son);
            tr[x].sum += tr[i->to].sum;
            if (tr[x].wei == -1 || tr[tr[x].wei].sum < tr[i->to].sum)
                tr[x].wei = i->to;
        }
}
Pseg root[MAXN];
int pos[MAXN], fa2[MAXN];
int tmp[MAXN], tmp2[MAXN];
void buildseg(int x)
{
    int ct = 0;
    for (int i = x;; i = tr[i].fa->to)
    {
        tmp[ct++] = i;
        if (tr[i].fa == NULL || tr[tr[i].fa->to].wei != i)
            break;
        tmp2[ct - 1] = tr[i].fa->val;
    }
    reverse(tmp, tmp + ct);
    reverse(tmp2, tmp2 + ct - 1);
    buildseg(root[tmp[0]], 0, ct - 1, tmp2);
    for (int i = 0; i < ct; ++i)
    {
        pos[tmp[i]] = i;
        fa2[tmp[i]] = tmp[0];
    }
}
int query(int x, int y)
{
    int ans = 0;
    while (fa2[x] != fa2[y])
    {
        ans = max(ans, queryseg(root[fa2[x]], 0, pos[x]));
        x = fa2[x];
        ans = max(ans, tr[x].fa->val);
        x = tr[x].fa->to;
    }
    if (x != y)
        ans = max(ans, queryseg(root[fa2[x]], pos[y], pos[x]));
    return ans;
}
bool notfa(int x, int fa)
{
    while (fa2[x] != fa2[fa])
    {
        if (tr[fa].dep > tr[x].dep || tr[fa2[x]].fa == NULL)
            return true;
        x = tr[fa2[x]].fa->to;
    }
    return pos[fa] > pos[x];
}
int n, m;
struct Etype
{
    int t, x, y;
} evt[MAXN];
struct Qtype
{
    int nu, x, i;
    bool operator< (const Qtype &a) const
    {
        return i < a.i;
    }
} que[MAXN];
bool ans[MAXN];
bool ind[MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    int Q = 0;
    int ct = 0;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &evt[i].t);
        if (evt[i].t == 1)
        {
            scanf("%d%d", &evt[i].x, &evt[i].y);
            --evt[i].x, --evt[i].y;
            edge[evt[i].y] = new Tedge(evt[i].x, i, edge[evt[i].y]);
            ind[evt[i].x] = true;
        }
        else if (evt[i].t == 2)
        {
            scanf("%d", &evt[i].x);
            --evt[i].x;
        }
        else
        {
            scanf("%d%d", &evt[i].x, &evt[i].y);
            --evt[i].x, --evt[i].y;
            que[Q].nu = ct++;
            que[Q].x = evt[i].x;
            que[Q].i = evt[i].y;
            ++Q;
        }
    }
    sort(que, que + Q);
    for (int i = 0; i < n; ++i)
        if (!ind[i])
            buildtree(i, NULL, 0);
    for (int i = 0; i < n; ++i)
        if (tr[i].son == NULL)
            buildseg(i);
    int j = ct = 0;
    for (int i = 0; i < m; ++i)
        if (evt[i].t == 2)
        {
            while (j < Q && que[j].i == ct)
            {
                if (notfa(evt[i].x, que[j].x))
                {
                    ans[que[j++].nu] = false;
                    continue;
                }
                int t = query(evt[i].x, que[j].x);
                ans[que[j].nu] = t <= i;
                ++j;
            }
            ++ct;
        }
    for (int i = 0; i < Q; ++i)
        printf(ans[i] ? "YES\n" : "NO\n");
    return 0;
}
