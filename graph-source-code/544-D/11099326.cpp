//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;

#define LS 2*i
#define RS 2*i+1
#define UP(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define LL long long
#define N 5005
#define MOD 19999997
#define INF 0x3f3f3f3f
#define EXP 1e-8
const double Pi = acos(-1.0);

vector<int> G[N];
int dis[N][N],n,m;
int vis[N];
int s1,s2,t1,t2,d1,d2;

int main()
{
    int i,j,k,x,y;
    cin>>n>>m;
    UP(i,1,m)
    {
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cin>>s1>>t1>>d1>>s2>>t2>>d2;
    MEM(dis,0);
    UP(i,1,n)
    {
        queue<int> Q;
        MEM(vis,0);
        vis[i] = 1;
        Q.push(i);

        W(!Q.empty())
        {
            int u = Q.front(),v;
          //  printf("1 %d\n",u);
            Q.pop();
           // UP(j,0,G[u].size()-1)
           for(j = 0;j<G[u].size();j++)
            {
                v = G[u][j];
           // printf("2 %d\n",j);
                if(vis[v]) continue;
                vis[v] = 1;
                dis[i][v] = dis[i][u]+1;
                Q.push(v);
            }
        }
    }
    if(dis[s1][t1]>d1||dis[s2][t2]>d2)
    {
        printf("-1\n");
        return 0;
    }
    int ans = dis[s1][t1]+dis[s2][t2];
    UP(i,1,n)
    {
        UP(j,1,n)
        {
            if(dis[s1][i]+dis[i][j]+dis[j][t1]<=d1&&dis[s2][i]+dis[i][j]+dis[j][t2]<=d2)
                ans=min(ans,dis[s1][i]+dis[i][j]+dis[j][t1]+dis[s2][i]+dis[j][t2]);
            if(dis[s1][i]+dis[i][j]+dis[j][t1]<=d1&&dis[t2][i]+dis[i][j]+dis[j][s2]<=d2)
                ans=min(ans,dis[s1][i]+dis[i][j]+dis[j][t1]+dis[t2][i]+dis[j][s2]);
        }
    }
    printf("%d\n",m-ans);

    return 0;
}
