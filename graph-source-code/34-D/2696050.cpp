//Language: GNU C++


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<set>
using namespace std;
#define fp(i,a,b,c) for(i=a;i<b;i+=c)
#define fn(i,a,b,c) for(i=a;i>b;i-=c)
#define fs(i,a) for(i=0;i<a;i++)
#define sci(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d%d",&a,&b)
#define pf(a) printf("%d ",a)
#define pf2(a,b) printf("Case %d: %d\n",a,b)
#define MOD 1000000007

vector<int>mv[300000];
int nv[3000000];
int vis[100000]={0};
int n,r1,r2;

int dfs(int v,int p)
{
    if(vis[v]==1)
    return 0;
    vis[v]=1;

    nv[v]=p;

    for(int i=0;i<mv[v].size();i++)
    dfs(mv[v][i],v);
    return 0;

}
int main()
{
    cin>>n>>r1>>r2;
    r1--;
    r2--;
    int i=0;
    while(i<n)
    {
        if(i==r1)
       {
         i++;
         continue;
       }
        int a;
        cin>>a;
        a--;
        mv[i].push_back(a);
        mv[a].push_back(i);
        i++;
    }

    dfs(r2,-1);

    for(int i=0;i<n;i++)
    {
        if(i==r2)
        continue;
        cout<<nv[i]+1<<" ";

    }



    return 0;
}
