//Language: GNU C++


#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[2020];

int main()
{
	cin >>n;
	for(int i=0; i<n; i++)
		cin >>a[i+1];

	int ans=-1;
	for(int i=1; i<=n; i++)
	{
		int t=i,l=0;
		while(t!=-1)
		{
			t=a[t];
			l++;
		}
		ans=max(ans,l);
	}
	cout <<ans;

	return 0;
}

