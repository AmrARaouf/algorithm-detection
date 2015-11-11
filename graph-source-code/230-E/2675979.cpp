//Language: GNU C++


//In the name of God
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN=1e6+100;
int mark[MAXN];
vector<int> adj[MAXN];

int main()
{
  long long sum=0;
  int n,m;
  scanf("%d%d",&n,&m);
  while(m--)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  for(int u=1;u<=n;++u)
    {
      long long deg=adj[u].size();
      sum+=deg*(deg-1); //Alice
      long long bdeg=n-1-deg;
      sum+=bdeg*(bdeg-1); //Bob
      sum-=deg*bdeg;
    }
  cout<<sum/6<<endl;
  return 0;
}
