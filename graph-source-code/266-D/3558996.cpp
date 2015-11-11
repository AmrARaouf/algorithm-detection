//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long lld;
const int inf = 1000000000;
const int MAX_N  = 210;
int d[MAX_N][MAX_N];
int di[MAX_N][MAX_N];
int rk[MAX_N][MAX_N];
int n , m ,s1 ,s2;
void Floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) if(d[i][k]!=inf && d[k][j]!=inf &&(i!=j&&j!=k &&i!=k))
            {
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            //printf("i=%d j=%d %I64d\n",i,j,d[i][j]);
            }
}
void Find_Center()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)  rk[i][j] = j;
        for(int j=1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(d[i][rk[i][j]] > d[i][rk[i][k]])
                {
                    swap(rk[i][j],rk[i][k]);
                }
            }
        }
    }
    int ans = inf;
    s1 = - 1,s2 = -1;
    for(int u=1;u<=n;u++)
    {
        //if(d[u][rk[u][n]]==inf) while(1);
        if(d[u][rk[u][n]]*2<ans)
        {
            ans = d[u][rk[u][n]]*2;
            s1 = s2 = u;
        }
        for(int v=1;v<=n;v++) if(di[u][v]!=-1)
        {
            for(int cmp=n,i=n-1;i>=1;i--)
            {
                if(d[v][rk[u][i]] > d[v][rk[u][cmp]])
                {
                    int tmp = d[u][rk[u][i]]+d[v][rk[u][cmp]]+di[u][v];

                    if(tmp < ans )
                    {
                        ans = tmp;
                        s1 = u;
                        s2 = v;
                    }
                    cmp = i;
                }
            }
        }
    }
    if(ans<0||ans>=inf) while(1);
    //printf("s1=%d s2=%d\n",s1,s2);
    printf("%lf\n",(double)ans/2);
}
bool vis[MAX_N];
lld dis[MAX_N];
int pre[MAX_N];
int Q[2000010];
void spfa()
{
    fill(vis,vis+n+1,false);
    fill(dis,dis+n+1,inf);
    fill(pre,pre+n+1,-1);
    int head = 0, tail = 0 , tmp;
    vis[s1] = true;
    dis[s1] = 0;
    Q[++tail]=s1;
    if(s1!=s2)
    {
        Q[++tail]=s2;
        vis[s2]=true;
        dis[s2]=0;
        pre[s2]=s1;
    }
    while(head<tail)
    {
        int fr = Q[++head]; vis[fr] = false;
        for(int i=1;i<=n;i++) if(di[fr][i]!=-1){
            tmp = dis[fr] + di[fr][i];
            if(tmp < dis[i]) {
                dis[i] = tmp;
                pre[i] = fr;
                if(!vis[i]) {
                    vis[i] =true;
                    Q[++tail] = i;
                }
            }
        }
    }
}
void solve()
{
    Floyd();//puts("debug");
    Find_Center();
    
    spfa();
}
int main()
{
    int a , b , c;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        d[i][i] = 0;   
        for(int j=i+1;j<=n;j++)
        {
            d[i][j] = d[j][i] = inf;
        }
    }
    memset(di,-1,sizeof(di));
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a==b) while(1);
        if(a==b) continue;
        if(c<d[a][b])
        {
            d[a][b] = d[b][a] = c;
            di[a][b] = di[b][a] = c;
        }
    }
    solve();
    int cnt = 0;
    vector<pair<int,int> > ret;
    for(int i=1;i<=n;i++) if(pre[i]!=-1)
    {
        cnt++;
        if(i<pre[i])  ret.push_back(make_pair(i,pre[i]));
        else ret.push_back(make_pair(pre[i],i));
    }
    sort(ret.begin(),ret.end());
    /*for(int i=0;i<ret.size();i++)
    {
        printf("%d %d\n",ret[i].first,ret[i].second);
    }*/
    return 0;
}
/*
10 19
2 1
3 2
4 2
5 1
6 3
7 4
8 6
9 8
10 4
5 2
10 5
8 10
2 7
10 1
7 9
3 6
10 10
10 3
5 3
*/