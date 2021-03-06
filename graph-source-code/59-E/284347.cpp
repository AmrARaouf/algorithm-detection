//Language: GNU C++


#include <cstdio>
#include <queue>
#include <set>

using namespace std;

#define NN 3076
vector<int> adj[NN];
vector<int> ans;
int p[NN][NN], v[NN][NN];
set<long long> f;
int n, m, k;

bool isForbid(int a, int b, int c) {
	return f.count(a*100000000LL + b*10000LL + c) > 0;
}

void buildAns(int b, int c) {
	int a = p[b][c];
	if(a != -1) buildAns(a, b);
	ans.push_back(c);
}

int main(void) {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b), adj[b].push_back(a);
	}
	for(int i = 0; i < k; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		f.insert(a*100000000LL + b*10000LL + c);
	}

	queue< pair<int, int> > q;
	q.push(make_pair(0, 1));
	v[0][1] = 1, p[0][1] = -1;
	while(!q.empty() && ans.size() == 0) {
		int a = q.front().first, b = q.front().second; q.pop();
		
		if(b == n) buildAns(a, b);
		
		for(int i = 0; i < (int)adj[b].size(); i++) {
			int c = adj[b][i];
			if(!isForbid(a, b, c) && !v[b][c]) {
				v[b][c] = 1, p[b][c] = a;
				q.push(make_pair(b, c));
			}
		}
	}

	if((int)ans.size() == 0) printf("-1\n");
	else {
		printf("%d\n", (int)ans.size()-1);
		for(int i = 0; i < (int)ans.size(); i++) {
			if(i) printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}

	return 0;
}
