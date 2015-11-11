//Language: GNU C++


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int max_n = 100110;
vector<int>adj[max_n];
vector<int>adj1[max_n];
int d[max_n];
int perm[max_n];
int h[max_n];
int p[max_n];
pair<int,int>e[max_n];
bool mark[max_n];
int ans[max_n];
const int inf = 100000000;
int n,m;
bool f(const int &A,const int &B)
{
    return d[A]<d[B];
}
void init()
{
    for(int i=1;i<=n;i++)
        p[i] = i;
}
int find(int v)
{
    if(v!=p[v])
        p[v] = find(p[v]);
    return p[v];
}
void uni(int u,int v)
{
    u = find(u);
    v = find(v);
    if(u==v)
        return;
    if(h[u]<h[v])
        p[u] = v;
    else 
    {
        if(h[u]==h[v])
            h[u]++;
        p[v] = u;
    }
}
int dfs(int v,int pos1)
{
    mark[v] = true;
    int min1 = inf;
    for(int i=0;i<adj[v].size();i++)
    {
        int u =adj[v][i];
        int pos = adj1[v][i];
        if(u==v)
        {
            ans[pos] = 3;
        }
        else if(mark[u]&&pos!=pos1)
        {
            ans[pos] = 2;
            min1 = min(min1,h[u]);
        }
        else if(!mark[u])
        {
            h[u] = h[v]+1;
            min1 = min(dfs(u,pos),min1);
        }
    }
    if(pos1!=-1)
    {
        if(min1<h[v])
            ans[pos1] = 2;
        else 
            ans[pos1] = 1;
    }
    return min1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++)
    {
        perm[i] = i;
        cin>>e[i].first>>e[i].second>>d[i];
    }
    sort(perm,perm+m,f);
    for(int i=0;i<m;i++)
    {
        int tmp = i;
        while(d[perm[tmp]]==d[perm[i]]&&tmp<m)
        {
            int pos = perm[tmp];
            int u = e[pos].first;
            int v = e[pos].second;
            int u1 = find(u);
            int v1 = find(v);
            adj[v1].push_back(u1);
            adj[u1].push_back(v1);
            adj1[u1].push_back(pos);
            adj1[v1].push_back(pos);
            tmp++;
        }
        tmp = i;
        while(d[perm[tmp]]==d[perm[i]]&&tmp<m)
        {
            int pos = perm[tmp];
            int u = e[pos].first;
            u = find(u);
            if(!mark[u])
            {
                dfs(u,-1);
            }
            tmp++;
        }
        tmp = i;
        while(d[perm[tmp]]==d[perm[i]]&&tmp<m)
        {
            int pos = perm[tmp];
            int u = e[pos].first;
            int v = e[pos].second;
            u = find(u);
            v = find(v);
            adj[u].clear();
            adj[v].clear();
            adj1[u].clear();
            adj1[v].clear();
            mark[u] = mark[v] =  false;
            h[v] = h[u] = 0;
            tmp++;
        }
        tmp = i;
        while(d[perm[tmp]]==d[perm[i]]&&tmp<m)
        {
            int pos = perm[tmp];
            int v = e[pos].first;
            int u = e[pos].second;
            uni(u,v);
            tmp++;
        }
        i = tmp-1;
    }
    for(int i=0;i<m;i++)
    {
        if(ans[i]==1)
            cout<<"any"<<endl;
        else if(ans[i]==2)
            cout<<"at least one"<<endl;
        else if(ans[i]==3)
            cout<<"none"<<endl;
    }
    return 0;
}
