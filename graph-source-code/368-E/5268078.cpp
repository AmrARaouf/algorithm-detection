//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,q[1500000],w[1500000];
int ll;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	scanf("%d%d",&q[i],&w[i]);
	sort(w+1,w+1+m);
	for (int i=1;i<=n;i++)
	{
		int k;
		
		if (i%2==1) k=(i-1)/2+1+(i-1)/2*(i-1);
		if (i%2==0) k=(i/2)+(i/2)*(i-1);
		ll=i;
		if (k>n) 
		{
			ll=i-1;
			break;
		}
	}
	if (ll>m) ll=m;
	//cout<<ll<<endl;
	long long ans=0;
	for (int i=m;i>=m-ll+1;i--)
	ans+=w[i];
	
	cout<<ans<<endl;
	
	return 0;
}
