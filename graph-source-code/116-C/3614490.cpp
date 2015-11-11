//Language: GNU C++


using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

const int MAXN = 2005;
vector <int> g[MAXN];
int in[MAXN];

//Returns the number of nodes in the largest chain that starst at u
int dfs(int u){
	int best = 1;
	for (int i = 0; i < g[u].size(); ++i){
		int v = g[u][i];
		best = max(best, 1 + dfs(v));
	}
	return best;
}

int main(){
	int n;
	while (cin >> n){
		for (int i = 0; i < n; ++i){
			g[i].clear();
			in[i] = 1;
		}
		
		for (int i = 0; i < n; ++i){
			int pi; cin >> pi;
			if (pi == -1) in[i] = 0; //I dont have a direct boss
			else g[pi-1].push_back(i); //Link my direct boss to me
		}
		
		int best = 0;
		for (int i = 0; i < n; ++i){
			if (in[i] == 0) best = max(best, dfs(i));
		}
		
		cout << best << endl;
		
	}
    return 0;
}
