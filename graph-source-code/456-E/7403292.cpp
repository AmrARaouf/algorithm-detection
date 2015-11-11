//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct node
{
    int dest,next;
}Node;
Node e[600010];
int pre[300010],len,maxlen,source,N,M,Q,father[300010],dp[300010],rx,ry,t;
void addedge(int u,int v)
{
    e[++len].dest = v;  e[len].next = pre[u];   pre[u] = len;
}
void dfs1(int x,int y,int z)
{
    if (z > maxlen) {   maxlen = z; source = x; }
    for (int i = pre[x] ; i ; i = e[i].next)
    {
        if (e[i].dest == y) continue;
        dfs1(e[i].dest,x,z+1);
    }
}
void dfs2(int x,int y,int z)
{
    father[x] = source;
    dp[x] = z;
    for (int i = pre[x] ; i ; i = e[i].next)
    {
        if (e[i].dest == y) continue;
        dfs2(e[i].dest,x,z+1);
        if (dp[e[i].dest] > dp[x])  dp[x] = dp[e[i].dest];
    }
}
int find(int x)
{
    return father[x] == x ? x:father[x] = find(father[x]);
}
void merge(int x,int y)
{
    int temp1 = find(x),temp2 = find(y);
    if (temp1 == temp2) return;
    if (dp[temp1] > dp[temp2])
    {
        father[temp2] = temp1;
        dp[temp1] = max(dp[temp1],(dp[temp2]+1)/2+(dp[temp1]+1)/2+1);
    }
    else
    {
        father[temp1] = temp2;
        dp[temp2] = max(dp[temp2],(dp[temp2]+1)/2+(dp[temp1]+1)/2+1);
    }
    //printf("!!!%d %d %d %d\n",temp1,temp2,dp[temp1],dp[temp2]);
}
int main()
{
    scanf("%d %d %d",&N,&M,&Q);
    for (int i = 1 ; i <= N ; i++)  father[i] = i;
    for (int i = 0 ; i < M ; i++)
    {
        scanf("%d %d",&rx,&ry);
        addedge(rx,ry);
        addedge(ry,rx);
    }
    for (int i = 1 ; i <= N ; i++)
        if (father[i] == i) {   source = -1; maxlen = -1;   dfs1(i,i,0);    dfs2(source,source,0);  }
//    for (int i = 1 ; i <= N ; i++)
//        printf(">>>%d %d %d\n",i,father[i],dp[i]);
    for (int i = 0 ; i < Q ; i++)
    {
        scanf("%d",&t);
        if (t == 1)
        {
            scanf("%d",&rx);
            int temp = find(rx);
            printf("%d\n",dp[temp]);
        }
        else
        {
            scanf("%d %d",&rx,&ry);
            merge(rx,ry);
        }
    }
    return 0;
}
