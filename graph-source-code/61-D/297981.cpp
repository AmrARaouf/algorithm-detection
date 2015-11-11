//Language: MS C++


// Codeforces Beta Round #57 D.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	static int len[100000];
	int n;
	while(cin >> n){
		vector< vector< pair<int,int> > > g(n);
		long long res = 0;
		for(int i=0;i<n-1;i++){
			int a, b, w; scanf("%d %d %d", &a, &b, &w);
			g[a-1].push_back(make_pair(b-1, w));
			g[b-1].push_back(make_pair(a-1, w));
			res += 2*w;
		}
		memset(len, -1, sizeof(len));
		queue<int> qu; qu.push(0); len[0] = 0;
		while(!qu.empty()){
			int v = qu.front(); qu.pop();
			for(int i=0;i<g[v].size();i++){
				int u = g[v][i].first;
				if(len[u]!=-1) continue;
				len[u] = len[v] + g[v][i].second;
				qu.push(u);
			}
		}
		int m = 0;
		for(int i=0;i<n;i++) m = max(m, len[i]);
		cout << res-m << endl;
	}
}