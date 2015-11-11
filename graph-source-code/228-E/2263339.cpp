//Language: GNU C++


#include<iostream>
#include<cstdlib>
#include<vector>
#include<climits>
#include<cctype>
#include<map>
#include<list>
#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<cmath>
#include<queue>
#include<fstream>
#include<sstream>
#include<set>
#include<iomanip>
#include<bitset>
#include<ctime>
#define L long long int
#define LD long double
#define pi 3.141592653589793238462643383
#define M 1000000007

using namespace std;

int vis[100],nas[100],g[100][100],a[100][100],es[10000],ee[10000];
int n,m;

void dfs(int v,int as)
{
     if(vis[v]==1)
     return;
     nas[v]=as;
     vis[v]=1;
     for(int i=0;i<n;i++)
     {
                               if(g[v][i]==1&&vis[i]==0)
                               {
                                                         if(a[v][i]==1)
                                                         {
                                                                       if(as==1)
                                                                       dfs(i,1);
                                                                       else
                                                                       dfs(i,0);
                                                         }
                                                         else
                                                         {
                                                                       if(as==1)
                                                                       dfs(i,0);
                                                                       else
                                                                       dfs(i,1);
                                                         }
                               }
     }
}

int main()
{
    int t=100,i,j,a1,b1,c,ans;
    while(cin>>n)
    {
              cin>>m;
              for(i=0;i<m;i++)
              {
                              cin>>a1>>b1>>c;
                              es[i]=a1-1;
                              ee[i]=b1-1;
                              g[a1-1][b1-1]=1;
                              g[b1-1][a1-1]=1;
                              a[a1-1][b1-1]=c;
                              a[b1-1][a1-1]=c;
              }
              for(i=0;i<n;i++)
              {
                              vis[i]=0;
                              nas[i]=0;
              }
              for(i=0;i<n;i++)
              {
                              if(vis[i]==0)
                              dfs(i,0);
              }
              //for(i=0;i<n;i++)
              //cout<<nas[i]<<"\n";
              for(i=0;i<m;i++)
              {
                              if(a[es[i]][ee[i]]==1&&(nas[es[i]]^nas[ee[i]])==0)
                              continue;
                              else if(a[es[i]][ee[i]]==0&&(nas[es[i]]^nas[ee[i]])==1)
                              continue;
                              else
                              break;
              }
              if(i==m)
              {
                      ans=0;
                      for(i=0;i<n;i++)
                      if(nas[i]==1)
                      ans++;
                      cout<<ans<<"\n";
                      for(i=0;i<n;i++)
                      if(nas[i]==1)
                      cout<<i+1<<" ";
                      continue;
              }
              for(i=0;i<n;i++)
              {
                              vis[i]=0;
                              nas[i]=0;
              }
              for(i=0;i<n;i++)
              {
                              if(vis[i]==0)
                              dfs(i,1);
              }
              //for(i=0;i<n;i++)
              //cout<<nas[i]<<"\n";
              for(i=0;i<m;i++)
              {
                              if(a[es[i]][ee[i]]==1&&(nas[es[i]]^nas[ee[i]])==0)
                              continue;
                              else if(a[es[i]][ee[i]]==0&&(nas[es[i]]^nas[ee[i]])==1)
                              continue;
                              else
                              break;
              }
              if(i==m)
              {
                      ans=0;
                      for(i=0;i<n;i++)
                      if(nas[i]==1)
                      ans++;
                      cout<<ans<<"\n";
                      for(i=0;i<n;i++)
                      if(nas[i]==1)
                      cout<<i+1<<" ";
                      continue;
              }
              
              cout<<"Impossible\n";
    }
    return 0;
}
