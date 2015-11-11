//Language: GNU C++


//In the Name of God

#include<iostream>
#include<vector>
#include <cstdlib>
using namespace std;
const int MAXN=1e5+10;
bool mark[MAXN];
long long dis[MAXN];
vector <pair<int,int> > b[MAXN];

int Bro(int v,int d)
{
  mark[v]=true;
  dis[v]=d;
  for(int i=0;i<b[v].size();i++)
    if(mark[b[v][i].first]==false)
      Bro(b[v][i].first,d+b[v][i].second);
}

int main()
{
  long long ans=0,c[3],a;
  cin>>a;
  for(int i=1;i<a;i++)
    {
      cin>>c[0]>>c[1]>>c[2];
      b[c[0]].push_back(make_pair(c[1],c[2]));
      b[c[1]].push_back(make_pair(c[0],c[2]));
      ans+=c[2];
    }
  ans=ans*2;
  int m=0;
  Bro(1,0);
  for(int i=1;i<=a;i++)
    {
      if(dis[i]>m)
	{
	  m=dis[i];
	}
    }
  ans-=m;
  cout<<ans;

  return 0;
}
