//Language: MS C++


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<int, set<int> > cn;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m; cin >> n >> m;
	vector<int> c(n);
	set<int> cc, curc;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		cc.insert(c[i]);
	}


	vector<vector<int> > g(n, vector<int> ());
	for (int i = 0; i < m; ++i) {
		int p, q;
		cin >> p >> q;
		--p; --q;
		g[p].push_back(q);
		g[q].push_back(p);
		curc.insert(c[q]);
		curc.insert(c[p]);
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			if (c[g[i][j]] != c[i])
				cn[c[i]].insert(c[g[i][j]]);
		}
	}

	int nc = -1, be = -1;
	for (map<int, set<int> >::iterator i = cn.begin(); i != cn.end(); ++i) {
		if (
			( (int(i->second.size()) > be) || ((int(i->second.size()) == be) && (nc > i->first)) ) 
			&& curc.count(i->first)
		   )

			be = int((i->second).size()), nc = i->first;
	}

	if (nc == -1)
		cout << *min_element(c.begin(), c.end());
	else
		cout << nc;
	return 0;
}