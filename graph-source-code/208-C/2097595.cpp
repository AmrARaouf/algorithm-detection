//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<cctype>
#include<cmath>
using namespace std;
const __int64 AAinf = 1000111222;
const __int64 N = 105;
__int64 n,m;
__int64  G[N][N];
__int64 mindis[N];
bool vis[N];
__int64 cnt[N];
void dij()
{
    __int64 i,t,mindd;
    for(i=1; i <= n; i++)
    {
        mindis[i] = (i==1 ? 0 : AAinf);
        vis[i] = false;
    }
    cnt[1] = 1;
    while(3)
    {
        mindd = AAinf;
        for(i=1; i <= n; i++)
            if(!vis[i] && mindd > mindis[i])
                mindd = mindis[t=i];
        if(mindd == AAinf)
            break;
        vis[t] = true;
        for(i=1; i <= n; i++)
            if(!vis[i])
                if(mindis[i] > mindd+G[t][i])
                {
                    mindis[i] = mindd+G[t][i];
                    cnt[i] = cnt[t];
                }
                else if(mindis[i] == mindd+G[t][i])
                    cnt[i] += cnt[t];
    }
///    for(i=1; i <= n; i++)
///        printf("cnt[%I64d]=%I64d\n", i,cnt[i]);
}
__int64 NUM[N][2];
__int64 DFS00(__int64 st,__int64 id)
{
    if(st == n)
        return 1;
    if(vis[st])
        return NUM[st][id];
    vis[st] = true;
    __int64 i;
    for(i=1; i <= n; i++)
        if(G[st][i]==1 && mindis[st]+1==mindis[i])
            NUM[st][id] += DFS00(i, id);
    return NUM[st][id];
}
__int64 DFS22(__int64 en,__int64 id)
{
    if(en == 1)
        return 1;
    if(vis[en])
        return NUM[en][id];
    vis[en] = true;
    __int64 i;
    for(i=1; i <= n; i++)
        if(G[en][i]==1 && mindis[i]+1==mindis[en])
            NUM[en][id] += DFS22(i, id);
    return NUM[en][id];
}
void cyh()
{
    dij();
    memset(NUM, 0, sizeof NUM);
    memset(vis, false, sizeof vis);  DFS00(1, 0);
    memset(vis, false, sizeof vis);  DFS22(n, 1);
    __int64 i;
    __int64 tt=0;
    for(i=1; i <= n; i++)
    {
 ///       printf("NUM[%I64d][0]=%I64d   %I64d\n", i,NUM[i][0], NUM[i][1]);
        if(i==1 || i==n)
        {
            if(tt < NUM[i][0]+NUM[i][1])
                tt = NUM[i][0]+NUM[i][1];
        }
        else if(NUM[i][0]*NUM[i][1])
        {
            if(tt < 2*(NUM[i][0]*NUM[i][1]) )
                tt = 2*(NUM[i][0]*NUM[i][1]);
        }
 ///       printf("tt=%I64d\n", tt);
    }
    printf("%.12lf\n", 1.00*tt/cnt[n]);
}
int main()
{
///    freopen("data.in", "r", stdin);
    __int64 i,j;
    __int64 st,en;
    while(cin >> n >> m)
    {
        for(i=1; i <= n; i++)
            for(j=1; j <= n; j++)
                G[i][j] = AAinf;
        while(m--)
        {
            scanf("%I64d %I64d", &st,&en);
            if(st-en)
                G[st][en] = G[en][st] = 1;
        }
        cyh();
    }
    return 0;
}
