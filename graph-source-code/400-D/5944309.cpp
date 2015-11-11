//Language: GNU C++


#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+5;

int n,m,k,u,v,l;
int a[505],b[505];
int begin[maxn],end[maxn*2],len[maxn*2],next[maxn*2],kk;
int ans[505][505];

void insert(const int &u,const int &v,const int &l)
{
    end[kk]=v;
    len[kk]=l;
    next[kk]=begin[u];
    begin[u]=kk++;
}

queue<int> Q;
int dis[505];
bool in[505];

void spfa(const int &x)
{
    while(!Q.empty())Q.pop();
    memset(dis,-1,sizeof(dis));
    memset(in,0,sizeof(in));
    dis[x]=0;
    Q.push(x);
    in[x]=1;
    while(!Q.empty())
    {
        u=Q.front();
        in[u]=0;
        Q.pop();
        for(int i=begin[u]; i!=-1; i=next[i])
        {
            v=end[i];
            if(dis[v]==-1||dis[v]>dis[u]+len[i])
            {
                dis[v]=dis[u]+len[i];
                if(!in[v])
                {
                    Q.push(v);
                    in[v]=1;
                }
            }
        }
    }
    for(int i=0; i<k; i++)
    {
        ans[x][i]=dis[i];
    }
}

int f[maxn];

int set[maxn];

void ini()
{
    for(int i=1; i<=n; i++)
        set[i]=i;
}

int find(const int &x)
{
    if(x==set[x])return x;
    return set[x]=find(set[x]);
}

void add(const int &u,const int &v)
{
    set[find(u)]=find(v);
}

int main()
{
    bool flag=true;
    kk=0;
    scanf("%d%d%d",&n,&m,&k);
    int x;
    for(int i=0,r=0; i<k; i++)
    {
        scanf("%d",&x);
        a[i]=r+1;
        b[i]=r+x;
        for(int j=a[i]; j<=b[i]; j++)
            f[j]=i;
        r+=x;
    }
    memset(begin,-1,sizeof(begin));
    ini();
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d",&u,&v,&l);
        if(l==0)
        {
            add(u,v);
        }
        insert(f[u],f[v],l);
        insert(f[v],f[u],l);
    }
    for(int i=0; i<k; i++)
        for(int j=a[i]; j<=b[i]; j++)
            if(find(j)!=find(a[i]))
            {
                //printf("%d,%d:%d,%d\n",j,a[i],find(j),find(a[i]));
                flag=false;
            }
    for(int i=0; i<k; i++)
        spfa(i);
    if(!flag)puts("No");
    else
    {
        puts("Yes");
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++)
                printf("%d ",ans[i][j]);
            puts("");
        }
    }
    return 0;
}
