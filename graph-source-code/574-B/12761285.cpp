//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <set>
#include <vector>

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector <vector <int> > v (n, vector <int> (n, 0));
	vector <int> p (n, 0);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		v[x][y] = 1;
		v[y][x] = 1;
		p[x]++;
		p[y]++;
	}
	int t = 10000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1) {
				for (int k = j + 1; k < n; k++) {
					if ((v[i][k] == 1) && (v[j][k] == 1)) {
						
						int r = p[i] + p[j] + p[k] - 6;
						// for (int s = 0; s < n; s++) {
						// 	r += v[i][s] + v[j][s] + v[k][s];
						// }
						// r -= 6;
						t = min (t, r);
					}
				}
			}
		}
	}
	if (t == 10000) {
		cout << "-1" << endl;
	}
	else {cout << t << endl;}
	//rm a.out; g++ A.cpp; ./a.out
}