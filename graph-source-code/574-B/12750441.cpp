//Language: GNU C++


//In the Name of God

#include<iostream>

using namespace std;

const int inf=1e9+7;
int n,m,v[4040],u[4040],d[4040],ans;
bool mark[4001][4001];

int main()
{
  ans=inf;
  cin>>n>>m;
  for(int i=0;i<m;i++)
    {
      cin>>v[i]>>u[i];
      d[u[i]]++;
      d[v[i]]++;
      mark[u[i]][v[i]]=mark[v[i]][u[i]]=true;
    }
  for(int i=0;i<m;i++)
    for(int j=1;j<=n;j++)
      if(j!=v[i] && j!=u[i] && mark[j][v[i]] && mark[j][u[i]])
	ans=min(d[v[i]]+d[u[i]]+d[j]-6,ans);
  if(ans<inf)
    cout<<ans<<endl;
  else
    cout<<-1<<endl;
  return 0;
}
