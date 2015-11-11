//Language: GNU C++


#include<iostream>
#include<limits.h>
#include<map>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<fstream>
using namespace std;//miller rabin primality 7 set for 64 bit int {2, 325, 9375, 28178, 450775, 9780504, 1795265022}
#define abs(x) ((x)>0?(x):-(x))
#define M 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define tkint(n) scanf("%d",&n)
#define tkchar(ch) scanf("%c",&ch)
#define tklong(n) scanf("%llu",&n)
#define  ms0(s) memset(s,0,sizeof s)
vector<int> graph[2*100000+5];
vector<int>d;
int level[200000+5],child[200000+5],arr[200000+5];
lld tree[2*4*2*100000+5];
int n,l[2*100000+5],zero[2*4*2*100000+5],one[2*4*2*100000+5];
void dfs(int p,int v)
{
    d.ps(v);
    l[v]=d.size()-1;
    level[v]=level[p]^1;
    child[v]=1;
    for(int i=0;i<graph[v].size();++i)
    {
        int u=graph[v][i];
        if(u==p)continue;
        dfs(v,u);
        child[v]+=child[u];
    }
}
lld read(int idx){
    if(idx==0)return 0;
    lld sum = 0;
    while (idx <=n){
        sum += tree[idx];
        idx += (idx & -idx);
    }
    return sum;
}
void update(int idx ,lld val){
    while (idx >0){
        tree[idx] += val;
        idx -= (idx & -idx);
    }
}
int main()
{
    d.ps(0);
    int m,a,b,c,x;
    lld val;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>arr[i];
    for(int i=1;i<=n-1;++i)
    {
        cin>>a>>b;
        graph[a].ps(b);
        graph[b].ps(a);
    }
    dfs(0,1);
    while(m--)
    {
        cin>>c;
        if(c==1)
        {
            cin>>x>>val;
            if(level[x]==0)val*=-1;
            update(l[x]+child[x]-1,val);
            update(l[x]-1,-val);
        }
        else
        {
            cin>>x;
            cout<<arr[x]+read(l[x])*(level[x]==1?1:-1)<<endl;
        }
    }
}