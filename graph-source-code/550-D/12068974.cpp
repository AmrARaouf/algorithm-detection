//Language: GNU C++


#include<cstdio>
#include<algorithm>
#include<map>
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#define N 100010
#define M 1010
#define P 1000000007
using namespace std;
int n,i,j,p;
int main()
{
	cin>>n;
	if (n%2==0)
	{
		cout<<"NO";
		return 0;
	}
	else
	{
		cout<<"YES"<<endl;
		if (n==1)
		{
			cout<<2<<" "<<1<<endl<<1<<" "<<2;
			return 0;
		}
		cout<<(n+1)*2+2<<" "<<(n+1)*n+n<<endl;
		cout<<(n+1)*2+1<<" "<<(n+1)*2+2<<endl;
		for (i=1;i<=n-1;i++)
		{
			p=p+2;
			cout<<(n+1)*2+1<<" "<<i<<endl;
			cout<<(n+1)*2+2<<" "<<n+1+i<<endl;
		}
		for (i=1;i<=n+1;i++)
		for (j=i+1;j<=n+1;j++)
		{
			if ((i%2==1)&&(i<n)&&(i+1==j)) continue;
			p=p+2;
			cout<<i<<" "<<j<<endl;
			cout<<n+1+i<<" "<<n+1+j<<endl;
		}
	}
}
 			    	    	  	    		 	 	  		