//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 2005
using namespace std;
bool G[N][N];
int n;
int pre[N];
int mx;
void dfs(int t,int dep)
{    bool tag=0;
    for(int i=1;i<=n;i++)
       if(G[t][i])
       {
           dfs(i,dep+1);
           tag=1;
       } 
      if(!tag)
      {
          mx=max(mx,dep);
      }
}              
int main()
{
    int i,j;
    memset(G,0,sizeof(G));
    cin>>n;
    for(i=1;i<=n;i++)
    {
          cin>>pre[i];
          if(pre[i]!=-1)
            G[pre[i]][i]=1;
    }
    mx=0;
    for(i=1;i<=n;i++)
       if(pre[i]==-1)
       dfs(i,0);
     cout<<mx+1<<endl;
    // while(1);
     return 0;
 }  
 /*
 5
 -1
 1
 2
 1
 -1
 */          



