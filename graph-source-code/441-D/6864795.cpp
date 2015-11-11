//Language: GNU C++0x


#include <iostream>
#include <vector>
using namespace std;
vector<int> p;
int n;
int f() {
	int cnt = 0;
	vector<bool> usd(n);
	for (int i = 0; i < n; ++i) {
		if (!usd[i]) {
			++cnt;
			usd[i] = true;
			int j = p[i];
			while (!usd[j]) {
				usd[j] = true;
				j = p[j];
			}
		}
	}
	return n - cnt;
}
int main() {
	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
	}
	int m;
	cin >> m;
	if (f() == m) {
		cout << 0 << endl;
		return 0;
	}
	if (f() > m) {
		int x = f();
		cout << x - m << endl;
		for (int i = 0; i < x - m; ++i) {
			vector<bool> usd(n);
			int j = 0;
			while (j == p[j])
				++j;
			usd[j] = true;
			int t = p[j];
			while (!usd[t]) {
				usd[t] = true;
				t = p[t];
			}
			int i1 = 0;
			while (!usd[i1])
				++i1;
			int i2 = i1 + 1;
			while (!usd[i2])
				++i2;
			swap(p[i1], p[i2]);
			cout << i1 + 1 << ' ' << i2 + 1 << ' ';
		}
		return 0;
	}
	if (f() < m) {
		int x = f();
		cout << m - x << endl;
		for (int i = 0; i < m - x; ++i) {
			vector<int> usd(n);
			int j1 = 0;
			int i1 = j1;
			while (usd[j1] != 1) {
				usd[j1] = 1;
				j1 = p[j1];
			}
			int j2 = 0;
			while (usd[j2] == 1)
				++j2;
			int i2 = j2;
			swap(p[i1], p[i2]);
			cout << i1 + 1 << ' ' << i2 + 1 << ' ';
		}
	}
}