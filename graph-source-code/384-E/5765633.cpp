//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define ls l,mid,rt<<1
#define rs mid+1,r,rt<<1|1

const int SIZE = 200020;
int n,m,a[SIZE];
int dep,col[SIZE];
int val[SIZE<<2][2],lazy[SIZE<<2][2];
int L[SIZE],R[SIZE];
vector <int> V[SIZE];

void pushDown(int rt)
{
    if(lazy[rt] == 0)return;
    for(int i=0; i<=1; i++)
    {
        val[rt<<1][i] += lazy[rt][i];
        lazy[rt<<1][i] += lazy[rt][i];
        val[rt<<1|1][i] += lazy[rt][i];
        lazy[rt<<1|1][i] += lazy[rt][i];
        lazy[rt][i] = 0;
    }
}

void update(int l,int r,int rt,int L,int R,int V,int index)
{
    if(L <= l && r <= R)
    {
        val[rt][index] += V;
        lazy[rt][index] += V;
        val[rt][index^1] -= V;
        lazy[rt][index^1] -= V;
        return;
    }
    pushDown(rt);
    int mid = (l+r) >> 1;
    if(L <= mid) update(ls,L,R,V,index);
    if(R > mid) update(rs,L,R,V,index);
}

int query(int l,int r,int rt,int pos,int index)
{
    if(l == r)
        return val[rt][index];
    pushDown(rt);
    int mid = (l+r) >> 1;
    if(pos <= mid)
        return query(ls,pos,index);
    return query(rs,pos,index);
}

void dfs(int rt,int fa)
{
    L[rt] = ++dep;
    for(int i=0; i<(int)V[rt].size(); i++)
    {
        int to = V[rt][i];
        if(to == fa)continue;
        col[to] = col[rt]+1;
        dfs(to,rt);
    }
    R[rt] = dep;
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        V[u].push_back(v);
        V[v].push_back(u);
    }
    dep = 0;
    col[1] = 1;
    dfs(1,-1);
    memset(val,0,sizeof(val));
    memset(lazy,0,sizeof(lazy));
    while(m--)
    {
        int o,x,v;
        scanf("%d%d",&o,&x);
        if(o == 1)
        {
            scanf("%d",&v);
            update(1,dep,1,L[x],R[x],v,col[x]&1);
        }
        else
        {
            int ans = query(1,dep,1,L[x],col[x]&1);
            printf("%d\n",ans+a[x]);
        }
    }
    return 0;
}
