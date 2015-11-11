//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pll pair<long long, long long>
#define mp make_pair
#define mod 1000000007
#define pb push_back

int main()
{
	ios::sync_with_stdio(false);
	
	int n, m;
	
	cin>>n>>m;
	
	int precos[m];
	
	for(int i=0 ; i<m ; i++)
	{
		int a, b;
		
		cin>>a>>b;
		
		precos[i]=b;
	}
	
	sort(precos,precos+m);
	reverse(precos, precos+m);
	
	int maximo=0;
	long long aux;
	
	for(long long i=1 ; i<=m ; i++)
	{
		if((i-1)%2==0)
		{
			aux=(i*(i-1)/2)+1;
		}
		else
		{
			aux=(i*(i-1)/2)+i/2;
		}
		
		if(aux>n) break;
	
		maximo=i;
	}
	long long sum=0;
	
	for(int i=0 ; i<maximo ; i++)
		sum+=precos[i];
		
	cout<<sum<<endl;	
}
