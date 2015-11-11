//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

#define pb push_back

using namespace std;

long long n, m, ans;
vector<int> vec;
int q, w;

void read() {
	cin >> n >> m;
	for(int i = 0; i < m; i ++) {
		scanf("%d %d", &q, &w);
		vec.pb(w);
	}
}

long long calc(long long k) {
	long long ret = 1 + (k * (k - 1)) / 2;
	if(k % 2 == 0) ret += (k - 2) / 2;
	return ret;
}

void solve() {
	sort(vec.rbegin(), vec.rend());
	
	while(calc((int)vec.size()) > n)
		vec.pop_back();
	
	for(int i = 0; i < (int)vec.size(); i ++)
		ans += vec[i];
	
	cout << ans << endl;
}

int main()
{
	read();
	solve();

    return 0;
}
