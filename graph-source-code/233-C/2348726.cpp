//Language: MS C++


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int k;
	cin >>k;
	int ans=0;
	vector <vector <int> > g(100,vector <int>(100));
	while (k){
		if (k==1){
			g[ans][ans+1]=1;
			g[ans][ans+2]=1;
			g[ans+1][ans]=1;
			g[ans+1][ans+2]=1;
			g[ans+2][ans]=1;
			g[ans+2][ans+1]=1;
			break;
		}
		if (k==2){
			g[ans][ans+1]=1;
			g[ans][ans+2]=1;
			g[ans+1][ans]=1;
			g[ans+1][ans+2]=1;
			g[ans+2][ans]=1;
			g[ans+2][ans+1]=1;
			g[ans+2][ans+3]=1;
			g[ans+3][ans+2]=1;
			g[ans+1][ans+3]=1;
			g[ans+3][ans+1]=1;
			break;
		}
		if (k==3){
			g[ans][ans+1]=1;
			g[ans][ans+2]=1;
			g[ans+1][ans]=1;
			g[ans+1][ans+2]=1;
			g[ans+2][ans]=1;
			g[ans+2][ans+1]=1;
			g[ans+2][ans+3]=1;
			g[ans+3][ans+2]=1;
			g[ans+1][ans+3]=1;
			g[ans+3][ans+1]=1;
			g[ans+2][ans+4]=1;
			g[ans+4][ans+2]=1;
			g[ans+3][ans+4]=1;
			g[ans+4][ans+3]=1;
			break;
		}
		int c=3;
		while (c*(c-1)*(c-2)/6<=k)
			++c;
		--c;
		for (int i=ans; i<ans+c; ++i)
			for (int j=i+1; j<ans+c; ++j){
				g[i][j]=1;
				g[j][i]=1;
			}
		k-=c*(c-1)*(c-2)/6;
		if (k){
			int t=2;
			while (t*(t-1)/2<=k)
				++t;
			--t;
			for (int i=ans; i<ans+t; ++i){
				g[i][ans+c]=1;
				g[ans+c][i]=1;
			}
			++ans;
			k-=t*(t-1)/2;
		}
		ans+=c;
	}
	cout <<100 <<endl;
	for (int i=0; i<100; ++i){
		for (int j=0; j<100; ++j)
			cout <<g[i][j];
		cout <<endl;
	}
	return 0;
}