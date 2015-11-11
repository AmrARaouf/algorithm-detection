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
#include<list>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define LL long long
#define maxn 405
map<long long,bool>mp;
vector<int>g[500005];
vector<int>fin[500005];
bool v[500005]={0};
int tot=0;
int n,m;
int a[500005];
int r[500005];
int l[500005];
bool ok(int a,int b)
{
    int l=0,r=g[a].size()-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(g[a][mid]==b)    return 1;
        if(g[a][mid]<b)
            l=mid+1;
        else if(g[a][mid]>b)
            r=mid-1;
    }
    return 0;
}
void bfs(int root)
{
    queue<int>q;
    q.push(root);
    v[root]=tot;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=r[0];i<=n;i=r[i])
        {
            int temp=i;
            if(v[temp]||ok(now,temp))  continue;
            v[temp]=tot;
            r[l[i]]=r[i];
            l[r[i]]=l[i];
            fin[tot].push_back(temp);
            q.push(temp);
        }
    }
}
int main()
{
    mp.clear();
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
    {
        a[i]=i;
        r[i]=i+1;
        l[i]=i-1;
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)   sort(g[i].begin(),g[i].end());
    for(int i=1;i<=n;i++)
    {
        if(v[i])    continue;
        tot++;
        fin[tot].push_back(i);
        bfs(i);
    }
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++)
    {
        printf("%d",fin[i].size());
        for(int j=0;j<fin[i].size();j++)    printf(" %d",fin[i][j]);
        printf("\n");
    }
}
  		  	 	   	 			  		  		 					