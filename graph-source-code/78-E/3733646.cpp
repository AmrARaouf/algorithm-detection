//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

#define INFINITE 1000000000
#define OPPOSITE(x) ((((x) - 1) ^ 1) + 1)
#define MIN(a,b)((a)<(b)?(a):(b))
#define MAXM 1000000
#define MAXN 500

using namespace std;
typedef long long ll;

int g[MAXN] , cur[MAXN] , end[MAXM] , c[MAXM] , tot = 0 , next[MAXM];
int a[MAXN];
int pre[MAXN];
int sumd[MAXN] , d[MAXN] ;
bool visit[MAXN] ;
int S , T  ;

void addedge(int x , int y , int flow)
{
    ++tot ;
    next[tot] = g[x] ;
    g[x] = tot ;
    end[tot] = y ;
    c[tot] = flow ;
    ++tot ;
    next[tot] = g[y] ;
    g[y] = tot ;
    end[tot] = x ;
    c[tot] = 0 ;
}
int Sap()
{
    memset(sumd,0,sizeof(sumd));
    int u,now,tmp,flow = 0;
    int v = T + 1 ;
    a[u=S] = INFINITE ;
    for(int i = 0 ; i < v; i++)
        cur[i] = g[i];
    for (int i = S ; i <= T; i++) visit[i]=0;
    queue<int> q;
    d[T]=0;
    sumd[d[T]]++ ;
    visit[T]=1;
    q.push(T);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int mark = g[u] ; mark > 0 ; mark = next[mark])
        {
            int v = end[mark] ;
            if (visit[v]) continue ;
            d[v] = d[u] + 1 ;
            visit[v] = 1 ;
            sumd[d[v]]++ ;
            q.push(v) ;
        }
    }
    while (d[S] < v)
    {
        for (now = cur[u]; now; now = next[now])
            if (c[now] && d[u] == d[end[now]] + 1)
                break;
        if (now)
        {
            tmp = end[now];
            a[tmp] = MIN(a[u], c[now]);
            cur[u] = pre[tmp] = now;
            if ((u = tmp) == T)
            {
                flow += (tmp = a[T]);
                do
                {
                    c[pre[u]] -= tmp;
                    c[OPPOSITE(pre[u])] += tmp;
                    u = end[OPPOSITE(pre[u])];
                }
                while (u != S);
                a[S] = INFINITE;
            }
        }
        else
        {
            if ((-- sumd[d[u]]) == 0)
                break;
            d[u] = v;
            cur[u] = g[u];
            for (now = g[u]; now; now = next[now])
                if (c[now] && d[u] > d[end[now]] + 1)
                    d[u] = d[end[now]] + 1, cur[u] = now;
            sumd[d[u]] ++;
            if (u != S)
                u = end[OPPOSITE(pre[u])];
        }
    }
    return flow;
}

char s[MAXN][MAXN] , t[MAXN][MAXN] ;
int n , tt ;
vector<int> e[MAXN] ;
int getpoint(int x,int y)
{
    return x*n+y;
}
int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};
int dd[101][101],fire;
bool inside(int x,int y)
{
    return (x>=0&&x<n&&y>=0&&y<n);
}
bool infect[101] ;
int inf[101] ;
bool vis[101];
bool check(int u,int v){
    memset(vis,false,sizeof(vis));
    queue< pair<int,int> > q;
    if (u==v) return true;
    q.push(make_pair(u,0)); vis[u]=true;
    while (!q.empty()){
        int x=q.front().first,t1=q.front().second; q.pop();
        if (t1>=tt) continue;
        for (int i=0;i<e[x].size();i++){
            int y=e[x][i];
            if (!vis[y]){
                if (y==v) return true;
                if (t1+1<inf[y])
                {
                    q.push(make_pair(y,t1+1));
                }
                vis[y]=true;
            }
        }
    }
    return false;
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&tt);
    for (int i=0; i<n; i++)
        scanf("%s",s[i]);
    for (int i=0; i<n*n; i++) e[i].clear();
    memset(dd,0x3F,sizeof(dd));
    for (int i=0; i<n*n; i++) dd[i][i]=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            if ((s[i][j]>='0'&&s[i][j]<='9')||s[i][j]=='Z')
            {
                for (int k=0; k<4; k++)
                {
                    int ni=i+dx[k],nj=j+dy[k];
                    if (inside(ni,nj) && ((s[ni][nj]>='0'&&s[ni][nj]<='9')||s[ni][nj]=='Z'))
                    {
                        dd[getpoint(i,j)][getpoint(ni,nj)]=1;
                        e[getpoint(i,j)].push_back(getpoint(ni,nj));
                    }
                }
            }
        }
    int m=n*n;
    for (int k=0; k<m; k++)
        for (int i=0; i<m; i++)
            for (int j=0; j<m; j++)
                dd[i][j]=min(dd[i][k]+dd[k][j],dd[i][j]);
    for (int i=0; i<n; i++)
        scanf("%s",t[i]);
    vector< pair<int,int> > l1,l2;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (s[i][j]=='Z')
            {
                fire=getpoint(i,j);
            }
            else if (s[i][j]>='1' && s[i][j]<='9')
                l1.push_back(make_pair(getpoint(i,j),s[i][j]-'0'));

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (t[i][j]=='Z')
            {
                fire=getpoint(i,j);
            }
            else if (t[i][j]>='1' && t[i][j]<='9')
                l2.push_back(make_pair(getpoint(i,j),t[i][j]-'0'));

    S=0;
    T=l1.size()+l2.size()+1;
    for (int i=S; i<=T; i++) g[i]=0;
    tot=0;
    queue<int> q;
    memset(inf,0x3F,sizeof(inf));
    memset(vis,false,sizeof(vis));
    inf[fire]=0;vis[fire]=true;q.push(fire);
    while (!q.empty()){
        int u = q.front() ; q.pop();
        for (int i=0;i<e[u].size();i++){
            int v=e[u][i];
            if (!vis[v]){
                vis[v]=true;
                inf[v]=inf[u]+1;
                q.push(v);
            }
        }
    }
    for (int i=0; i<l1.size(); i++)
    {
        // i+1
        int u = l1[i].first;
        for (int j=0; j<l2.size(); j++)
        {
            // j+1
            int v = l2[j].first;
            if (dd[u][v]<=tt && dd[u][v]<=dd[fire][v] && check(u,v))
            {
                addedge(i+1,j+1+l1.size(),INFINITE) ;
            }
        }
    }
    for (int i=0; i<l1.size(); i++)
        addedge(S,i+1,l1[i].second);
    for (int i=0; i<l2.size(); i++)
        addedge(i+1+l1.size(),T,l2[i].second);
    cout<<Sap()<<endl;
    return 0;
}

			  	 					 		  	 			 		