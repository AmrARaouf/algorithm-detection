//Language: GNU C++


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define NMAX 3000+5
#define INF 999999999
#define pb push_back

int d[NMAX][NMAX];

int main ()
{
  int n, m;
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(i!=j)
        d[i][j]=INF;
  int a, b;
  vector <int> v[n];
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    a--;
    b--;
    v[a].pb(b);
    v[b].pb(a);
  }
  queue <int> bfs;
  int aux;
  for(int i=0;i<n;i++)
  {
    bfs.push(i);
    while(!bfs.empty())
    {
      aux=bfs.front();
      bfs.pop();
      for(int j=0;j<v[aux].size();j++)
        if(d[i][v[aux][j]]==INF)
        {
          d[i][v[aux][j]]=d[i][aux]+1;
          bfs.push(v[aux][j]);
        }
    }
  }
  int s0, s1, t0, t1, l0, l1;
  cin>>s0>>t0>>l0>>s1>>t1>>l1;
  s0--;
  t0--;
  s1--;
  t1--;
  int ans=m+1;
  if(d[s0][t0]<=l0 and d[s1][t1]<=l1) ans=d[s0][t0]+d[s1][t1];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
      if(d[s0][i]+d[i][j]+d[j][t0]<=l0 and d[s1][i]+d[i][j]+d[j][t1]<=l1)
        ans=min(ans, d[s0][i]+d[j][t0]+d[s1][i]+d[j][t1]+d[i][j]);
      if(d[t0][i]+d[i][j]+d[j][s0]<=l0 and d[s1][i]+d[i][j]+d[j][t1]<=l1)
        ans=min(ans, d[t0][i]+d[j][s0]+d[s1][i]+d[j][t1]+d[i][j]);
    }
  if(ans>m)
    cout<<-1<<endl;
  else
    cout<<m-ans<<endl;
}