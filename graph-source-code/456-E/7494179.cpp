//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int m,n,q;
int f[300005];
vector<int> edge[300005];
int len[300005];
int flag[300005] = {0};
int node,mx;

int find(int i)
{
    if(f[i] == i)
        return i;
    return f[i] = find(f[i]);
}

bool judge(int i, int j)
{
    if(find(i) == find(j))
        return true;
    return false;
}

void link(int i,int j)
{
    int p1 = find(i);
    int p2 = find(j);
    f[i] = p2;
    f[p1] = p2;
}

void dfs1(int x, int d)
{
    flag[x] = 1;
    if(mx < d)
    {
        mx = d;
        node = x;
    }
    for(int i = 0; i < edge[x].size(); i ++){
        if(!flag[edge[x][i]]){
            dfs1(edge[x][i],d+1);
        }
    }
}

void dfs2(int x,int d)
{
    flag[x] = 2;
    if(mx < d)
        mx = d;
    for(int i = 0; i < edge[x].size(); i ++){
        if(flag[edge[x][i]] == 1){
            dfs2(edge[x][i],d+1);
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1; i <= n; i ++){
        f[i] = i;
    }

    for(int i = 0; i < m; i ++){
        int a,b;
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);

        if(!judge(a,b))
            link(a,b);
    }

    for(int i = 1; i <= n; i ++){
        if(!flag[i]){
            mx = -1;
            dfs1(i,0);
            dfs2(node,0);
            len[find(i)] = mx;
        }
    }

    int x,y,z,len1,len2;
    while(q--){
        scanf("%d",&x);
        if(x == 1){
            scanf("%d",&y);
            printf("%d\n",len[find(y)]);
        }else{
            scanf("%d%d",&y,&z);
            if(!judge(y,z)){
                len1 = len[find(y)];
                len2 = len[find(z)];
                link(y,z);

                int t = max(len1,len2);
                len[find(y)] = max((len1+1)/2+(len2+1)/2+1,t);
            }
        }
    }
}
