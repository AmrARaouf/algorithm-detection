//Language: GNU C++


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int,int> par;
int n, m;


int main () {
	cin >> n >> m;
	vector< vector<bool> > t (n, vector<bool> (m, false));
	vector< vector<bool> > s (n, vector<bool> (m, false));
	vector< vector<int> > v (n*m, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			if (c == '^') v[m*(i-1)+j].push_back(m*i+j);
			else if (c == 'v') v[m*(i+1)+j].push_back(m*i+j);
			else if (c == '<') v[m*i+j-1].push_back(m*i+j);
			else if (c == '>') v[m*i+j+1].push_back(m*i+j);
			else t[i][j] = true;
		}
	}
	/*for (int i = 0; i < n ; ++i) {
		for (int j = 0; j < m; ++j) cout << v[i*m+j].size() << " ";
		cout << endl;
	}*/
	int maxim = 0;
	bool altre = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (not t[i][j]) continue;
			s[i][j] = true;
			for (int h = 0; h < v[i*m+j].size(); ++h) {
				int llarg = 0;
				queue <par> q;
				q.push(par(v[i*m+j][h],1));
				while (not q.empty()) {
					int a = q.front().first;
					int b = q.front().second;
					s[a/m][a%m] = true;
					if (v[a].size() == 0) {
						if (llarg < b) llarg = b;
					}
					else{
						for (int k = 0; k < v[a].size(); ++k) q.push (par(v[a][k],b+1));
					}
					q.pop();
				}
				if (llarg == maxim) {
					altre = true;
				}
				else if (llarg > maxim) {
					maxim = llarg;
					altre = false;
				}
			}
		}
	}
	int visitats = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visitats = visitats and s[i][j];
		}
	}
	if (visitats) {
		if (maxim == 0) cout << 0 << endl;
		else if (altre) cout << maxim * 2 << endl;
		else cout << maxim * 2 - 1 << endl;
	}
	else cout << -1 << endl;
	
	
}