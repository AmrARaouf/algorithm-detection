//Language: GNU C++


#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<fstream>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#define maxn 500+5
#define INF 0x7FFFFFFF
using namespace std;
typedef long long ll;
typedef pair<int ,int >P;
int X[maxn];
int n,m;

int main()  
{  	
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;++i)
		cin>>X[i];
		int a,b,v;double ans=0;
		while(m--)
		{
			cin>>a>>b>>v;
			if((X[a]+X[b])*1.0/v>ans)
			ans=(X[a]+X[b])*1.0/v;
		}
		//printf("%.15lf\n",ans);
		cout<<fixed<<setprecision(15)<<ans<<endl;
	}
	
	
	
	
	
  	return 0;	
}


  	

