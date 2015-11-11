//Language: GNU C++


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define MOD ((long long)(1000000007LL))

class junc_t {
	public:
	int pr;
	bool used1, used2;
	junc_t() : used1(false), used2(false) {}
};
vector<junc_t> j;
vector<vector<int> > gr, grr;

vector<int> order, comp;

//~ void rdfs1(int src) {
	//~ j[src].used1 = true;
	//~ for(size_t i = 0; i < gr[src].size(); ++i)
		//~ if(!j[gr[src][i]].used1)
			//~ rdfs1(gr[src][i]);
	//~ order.push_back(src);
//~ }
//~ 
//~ void rdfs2(int src) {
	//~ j[src].used2 = true;
	//~ comp.push_back(src);
	//~ for(size_t i = 0; i < grr[src].size(); ++i)
		//~ if(!j[grr[src][i]].used2)
			//~ rdfs2(grr[src][i]);	
//~ }

void dfs1(int src) {
	stack<int> st;
	st.push(src);
	while(!st.empty()) {
		int u = st.top(); st.pop();

		if(u >= 0) {
			if(j[u].used1) continue;
			j[u].used1 = true;
			st.push((-u)-1);
			for(size_t i = 0; i < gr[u].size(); ++i) {
				int v = gr[u][i];
				if(!j[v].used1) st.push(v);
			}
		} else {
			int z = -(u+1);
			//~ cerr << "z = " << z << endl;
			// /*SEGFAULT*/ if(j[z].used1) continue;
			//~ cerr << "order.push_back(" << z << ")\n";
			order.push_back(z);
		}
	}
}

void dfs2(int src) {
	if(j[src].used2) return;
	stack<int> st;
	st.push(src);
	while(!st.empty()) {
		int u = st.top(); st.pop();

		if(j[u].used2) continue;

		j[u].used2 = true;
		comp.push_back(u);
		for(size_t i = 0; i < grr[u].size(); ++i) {
			int v = grr[u][i];
			if(!j[v].used2) st.push(v);
		}
	}
}

int main() {
	int n, m;
	cin >> n;
	j = vector<junc_t>(n);
	for(int i = 0; i < n; ++i) cin >> j[i].pr;

	cin >> m;
	gr.assign(n, vector<int>());
	grr.assign(n, vector<int>());

	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		gr[a-1].push_back(b-1);
		grr[b-1].push_back(a-1);
	}
	
	long long price = 0;
	long long var = 1;
	
	for(int i = 0; i < n; ++i)
		if(!j[i].used1)
			dfs1(i);

	for(int k = 0; k < n; ++k) {
		int u = order[n-1-k];
		if(!j[u].used2) {
			dfs2(u);
			
			//~ cout << "Cycle: ";
			//~ for(size_t i = 0; i < comp.size(); ++i)
				//~ cout << (comp[i]+1) << " ";
			//~ cout << "\n";

			long long min_pr = 1000000001;
			long long min_n = 0;
			for(size_t i = 0; i < comp.size(); ++i) {
				int pr = j[comp[i]].pr;
				if(pr < min_pr) {
					min_n = 1;
					min_pr = pr;
				} else if(pr == min_pr) {
					min_n++;
				}
			}
			price += min_pr;
			var = (var * (min_n % MOD)) % MOD;
		}
		comp.clear();
	}
		
	cout << price << " " << var;
	
	return 0;
}
