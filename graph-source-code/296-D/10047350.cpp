//Language: GNU C++


//In the name of God

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <cstdio>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define lol long long
const int MAXN=510;
lol dis[MAXN][MAXN],a[MAXN],ans[MAXN];


int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>dis[i][j];
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=n;i>0;i--)
    {
      for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
	  dis[a[j]][a[k]]=min(dis[a[j]][a[k]],dis[a[j]][a[i]]+dis[a[i]][a[k]]);
      for(int j=i;j<=n;j++)
	for(int k=i;k<=n;k++)
	  ans[i]+=dis[a[j]][a[k]];      
    }
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}
