//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#define N 301100
using namespace std;
vector <int > g[N];
int n,m,a[N];
string ans="";
set<pair <int,int> >s;
int bad[N];
void f(int i)
{
	s.erase(make_pair(-bad[i],i));
	bad[i]=0;
	for (int j=0;j<g[i].size();j++) if (a[i]==a[g[i][j]]) bad[i]++;
	s.insert(make_pair(-bad[i],i));
}
int main()
{
cin>>n>>m;
for (int i=0;i<m;i++)
{
int x,y;
cin>>x>>y;
g[x-1].push_back(y-1);
g[y-1].push_back(x-1);
}
for (int i=0;i<n;i++) bad[i]=g[i].size();
for (int i=0;i<n;i++) s.insert(make_pair(-bad[i],i));
while (1)
{
	int x=(*s.begin()).second;
		if (bad[x]<=1) break;
	a[x]=1^a[x];
	f(x);
	for (int i=0;i<g[x].size();i++) f(g[x][i]);
}
for (int i=0;i<n;i++)
if (a[i])
ans+='1';
else ans+='0';
cout<<ans;


return 0;
}
