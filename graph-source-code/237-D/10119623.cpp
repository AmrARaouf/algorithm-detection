//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define LL long long
#define maxn 100005
vector<int>g[maxn];
vector<int>fin[maxn];
int tot;
void dfs(int root,int fa,int id)
{
    for(int i=0;i<g[root].size();i++)
    {
        if(g[root][i]==fa)  continue;
        printf("2 %d %d\n",root,g[root][i]);
        fin[id].push_back(tot++);
        fin[tot-1].push_back(id);
        dfs(g[root][i],root,tot-1);
    }
}
void dfs(int root,int fa)
{
    for(int i=0;i<fin[root].size();i++)
    {
        if(fin[root][i]==fa)  continue;
        printf("%d %d\n",root,fin[root][i]);
        dfs(fin[root][i],root);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    printf("%d\n",n-1);
    tot=g[1].size()+1;
    for(int i=0;i<g[1].size();i++)  printf("2 1 %d\n",g[1][i]);
    for(int i=0;i<g[1].size();i++)  dfs(g[1][i],1,i+1);
    for(int i=1;i<g[1].size();i++)  fin[i].push_back(i+1);
    dfs(1,-1);
}
 		 		 				 		 	  		    		 		 	