//Language: GNU C++


#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <complex>
#include <cassert>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>

using namespace std;

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
template<typename X> inline void print(const X& a,int N) {cout<<endl;for(int i=0;i<N;i++)cout<<a[i]<<" ";cout<<endl;}
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pp;
typedef pair<ld, ld> ppld;
typedef unsigned long long ull;
#define FOR(i, n) for(int i = 0; i < int(n); i++)
#define FOR1(i, n) for(int i = 1; i <= int(n); i++)
#define FORD(i, n) for(int i = int(n-1); i >= 0; i--)
#define FORAB(i, a, b) for(int i = int(a); i <= int(b); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
#define mp make_pair
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define getcx getchar_unlocked
#define getmid(a,b) (a+(b-a)/2)
#define FORTR(it, container) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
const int MAXINT = numeric_limits<int>::max();
const int MININT = numeric_limits<int>::min();
const ll MAXINT_64 = numeric_limits<ll>::max();
const ll MININT_64 = numeric_limits<ll>::min();
const ld PI = ld(3.1415926535897932384626433832795);

vector<pair<int,int> > adj[111];
vector<int> visited(111,0);

bool dfs(int node, int v, int parent, int color){
	if(node == v){
		return true;
	}
	visited[node] = 1;
	FOR(i,adj[node].size()){
		int child = adj[node][i].first;
		int color_edge = adj[node][i].second;
		if(!visited[child] and color_edge == color){
			if(dfs(child, v, node, color) == 1)
				return true;
		}
	}
	return false;
}

int main(){
    ios::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    FOR(i,m){
    	int u,v,c; cin>>u>>v>>c;
    	u--; v--;
    	adj[u].pb(mp(v,c));
    	adj[v].pb(mp(u,c));
    }
    int q; cin>>q;
    while(q--){
    	int u,v;
    	cin>>u>>v;
    	u--; v--;
    	int answer = 0;
    	for(int color=1;color<=100;color++){
    		FOR(i,n+1)
    			visited[i] = 0;
    		answer += dfs(u, v, -1, color)?1:0;
    	}
    	cout<<answer<<endl;
    }
    return 0;
}
