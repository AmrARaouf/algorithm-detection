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

#define edge pair<int,int>

map< edge , int > ord;
vector<edge> edges;

vector<int> adj[200000];

int n;

int main(){
	cin >> n;
	cout<<n-1<<endl;
	for(int i=1;i<n;i++){
		int a,b;
		cin >> a >> b;
		edges.pb(mp(a,b));
		ord[mp(a,b)]=ord[mp(b,a)]=i;
		adj[a].pb(b);
		adj[b].pb(a);
		cout<<"2 "<<a<<" "<<b<<endl;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<adj[i].size()-1;j++)
			cout<<ord[mp(i,adj[i][j])]<<" "<<ord[mp(i,adj[i][j+1])]<<endl;
	
	
}




















