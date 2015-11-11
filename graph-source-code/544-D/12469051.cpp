//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define md int(3000+100)
#define modul int(1e9+7)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
typedef long long ll;
int n;
ll m;
vector<int> a[md];
int c[md][md];
int q[2*md];
int s[5],t[5],l[5];
void bfs(int node)
{
    c[node][node]=0;
    int l=0,r=1;
    q[r]=node;
    while (l<r)
    {
        l++;
        int x=q[l];
        FOR(i,0,a[x].size()-1)
        {
            int y=a[x][i];
            if (c[node][y]>c[node][x]+1)
            {
                c[node][y]=c[node][x]+1;
                r++;
                q[r]=y;
            }
        }
    }
}
int main()
{
    //freopen("inp.txt","r",stdin);
    scanf("%d%I64d",&n,&m);
    FOR(i,1,m)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    memset(c,63,sizeof(c));

    FOR(i,1,n)
        bfs(i);
    FOR(i,1,2)
    scanf("%d%d%d",&s[i],&t[i],&l[i]);
    ll res=-1;
    if (c[s[1]][t[1]]<=l[1] && c[s[2]][t[2]]<=l[2])
        res=max(res,m-c[s[1]][t[1]]-c[s[2]][t[2]]);
    else
    {
        cout<<-1<<endl;
        return 0;
    }
    FOR(v,1,n)
    FOR(u,1,n)
    {
        if (c[s[1]][u]+c[v][t[1]]<=l[1]-c[u][v] && c[s[2]][u]+c[v][t[2]]<=l[2]-c[u][v])
        {
            res=max(res,m-c[u][v]-c[s[1]][u]-c[v][t[1]]-c[s[2]][u]-c[v][t[2]]);
        }
        if (c[s[1]][u]+c[v][t[1]]<=l[1]-c[u][v] && c[s[2]][v]+c[u][t[2]]<=l[2]-c[u][v])
        {
            res=max(res,m-c[u][v]-c[s[1]][u]-c[v][t[1]]-c[s[2]][v]-c[u][t[2]]);
        }
        if (c[s[1]][v]+c[u][t[1]]<=l[1]-c[u][v] && c[s[2]][u]+c[v][t[2]]<=l[2]-c[u][v])
        {
            res=max(res,m-c[u][v]-c[s[1]][v]-c[u][t[1]]-c[s[2]][u]-c[v][t[2]]);
        }
        if (c[s[1]][v]+c[u][t[1]]<=l[1]-c[u][v] && c[s[2]][v]+c[u][t[2]]<=l[2]-c[u][v])
        {
            res=max(res,m-c[u][v]-c[s[1]][v]-c[u][t[1]]-c[s[2]][v]-c[u][t[2]]);
        }
    }
    cout<<res<<endl;
}
