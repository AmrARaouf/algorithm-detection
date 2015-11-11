//Language: GNU C++


//In The Name Of ALLAH

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>

using namespace std ;

const int MAXM = 100000+10 ;

vector <int> G[MAXM] ;
vector <int> GR ;
bool M[MAXM],f ;

int main()
{
	int n,m,a,b,dr[MAXM],t=0 ;
	
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b ;
		G[a].push_back(b) ;
		G[b].push_back(a) ;
	}
	for(int i=1;i<=n;i++)
		dr[i]=(int)G[i].size() ;
	
	while(!f)
	{
		GR.clear() ;
		for(int i=1;i<=n;i++)
			if(dr[i]==1)
				GR.push_back(i) ;	
		for(int i=0;i<(int)GR.size();i++)
		{
			M[GR[i]]=1 ;
			dr[GR[i]]=0 ;
			for(int j=0;j<(int)G[GR[i]].size();j++)
				if(!M[G[GR[i]][j]])
					dr[G[GR[i]][j]]-- ;
		}	
		if((int)GR.size()==0)
			f=1;
		else
			t++;
	}
	
	cout<<t;
	cin>> n ;
	return 0 ;
}
