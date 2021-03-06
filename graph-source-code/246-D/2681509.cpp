//Language: GNU C++


#include <iostream>
#include <set>
using namespace std;

#define Size(x) ((int)x.size())
#define sz 100005
int c[sz];
bool b[sz];
set<int> s[sz];

int main()
{
	int n,m,i,j;
	cin>>n>>m;

	for(i=1;i<=n;i++)
	{
		cin>>c[i];
		b[c[i]]=true;
	}

	while(m--)
	{
		cin>>i>>j;
		if(c[i]==c[j]) continue;
		s[c[i]].insert(c[j]);
		s[c[j]].insert(c[i]);
	}

	for(i=1,j=0;i<=100000;i++)if(b[i])
	{
		if(!j || Size(s[j])<Size(s[i])) j=i;
	}

	while(!j);
	cout<<j<<endl;

	return 0;
}
