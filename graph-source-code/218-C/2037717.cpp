//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define mp make_pair
#define pb push_back
#define F first
#define S second

using namespace std;

int n;
int x[1000],y[1000];

bool used[1000];

int m=0;

void dfs(int v){
	used[v]=1;
	for(int i=1;i<=n;i++)
		if( (x[i]==x[v] || y[i]==y[v]) && !used[i] ){
			dfs(i);
			m++;
		}
}

int main(){
//	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> x[i] >> y[i];
	
	for(int i=1;i<=n;i++)
		if(!used[i])dfs(i);
	
	cout<<n-1-m;
	

}




















