//Language: GNU C++11


/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll              long long int
#define vi              vector<int>
#define vl              vector<ll>
#define pii             pair<int,int>
#define pil             pair<int, ll>
#define pll             pair<ll, ll>
#define pli             pair<ll, int>
#define pb(v, a)        v.push_back(a)
#define mp(a, b)        make_pair(a, b)
#define MOD             1000000007
#define rep(i, a, b)    for(i=a; i<=b; ++i)
#define rrep(i, a, b)   for(i=a; i>=b; --i)
#define si(a)           scanf("%d", &a)
#define sl(a)           scanf("%lld", &a)
#define pi(a)           printf("%d", a)
#define pl(a)           printf("%lld", a)
#define pn              printf("\n")
ll pow_mod(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
vector<int> adj[100005];
bool visited[100005];
int cnt = 0;
void dfs(int nd)
{
    cnt++;
    visited[nd] = true;
    int i, sz = (int)adj[nd].size();
    rep(i, 0, sz - 1)
    {
        if(!visited[adj[nd][i]])
            dfs(adj[nd][i]);
    }
}
int col[100005];
int c0 = 0, c1 = 0;
bool isBipartite(int src)
{
    col[src] = 1;
    c1++;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int nd = q.front();
        q.pop();
        int i = 0;
        rep(i, 0, (int)adj[nd].size() - 1)
        {
            if(col[adj[nd][i]] == -1)
            {
                col[adj[nd][i]] = 1 - col[nd];
                if(col[adj[nd][i]] == 1)
                    c1++;
                else
                    c0++;
                q.push(adj[nd][i]);
            }
            else if(col[adj[nd][i]] == col[nd])
                return false;
        }
    }
    return true;
}
int main()
{
    int n, m, i, x, y;
    si(n); si(m);
    rep(i, 0, m - 1)
    {
        si(x); si(y);
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    //check1
    memset(col, -1, sizeof(col));
    rep(i, 0, n - 1)
    {
        if(col[i] == -1)
        {
            if(!isBipartite(i))
            {
                cout<<"0 1\n";
                return 0;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    int maxx = 0, cnt2 = 0;
    rep(i, 0, n - 1)
    {
        cnt = 0;
        if(!visited[i])
            dfs(i);
        maxx = max(maxx, cnt);
        if(cnt == 2)
            cnt2++;
    }
    if(maxx == 1)
    {
        printf("3 ");
        ll res = 1LL * n * 1LL * (n - 1);
        res = res * 1LL * (n - 2);
        res /= 6;
        pl(res);
        pn;
    }
    else if(maxx == 2)
    {
        printf("2 ");
        ll res = 2 * 1LL * cnt2 * 1LL * (cnt2 - 1);
        res = res + cnt2 * 1LL * (n - 2 * cnt2);
        pl(res);
        pn;
    }
    else
    {
        printf("1 ");
        memset(col, -1, sizeof(col));
        ll res = 0;
        rep(i, 0, n - 1)
        {
            c0 = 0, c1 = 0;
            if(col[i] == -1)
            {
                isBipartite(i);
                res = res + 1LL * c0 * (c0 - 1) / 2;
                res = res + 1LL * c1 * (c1 - 1) / 2;
            }
        }
        // cout<<c0<<" "<<c1<<endl;
        // ll res = 1LL * c0 * (c0 - 1) / 2;
        // res = res + 1LL * c1 * (c1 - 1) / 2;
        pl(res);
        pn;
    }
    return 0;
}