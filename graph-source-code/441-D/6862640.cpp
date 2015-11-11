//Language: GNU C++


#pragma comment (linker,"/stack:102400000,102400000")
#include <cstdio>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <set>

using namespace std;

#define ll long long
#define ls root << 1
#define rs root << 1 | 1
#define lson l, mid, ls
#define rson mid + 1, r, rs
#define PR pair<int, int>
#define sqr(x) ((x) * (x))

int f_abs(int x) {return x < 0 ? -x : x;}
int lowbit(int x) {return (x & -x);}
int f_max(int a, int b) {return a > b ? a : b;}
int f_min(int a, int b) {return a < b ? a : b;}
int gcd(int a, int b) {while(int t = a % b) a = b, b = t; return b;}
bool isdig(char ch) {return ch >= '0' && ch <= '9';}
bool isup(char ch) {return ch >= 'A' && ch <= 'Z';}
bool islow(char ch) {return ch >= 'a' && ch <= 'z';}
void swap(int& a, int& b) {int t = a; a = b; b = t;}

const int inf = 0x7fffffff;
const int mod = 1000000007;
const int N = 3003;
int n, m, k, to[N];
bool  vis[N];

void init() {}

void get_data() {
	for(int i = 1; i <= n; ++i)
		cin >> to[i];
	cin >> m;
}

void Loop(int v) {
	for(; !vis[v]; v = to[v])
		vis[v] = true;
}

void solve() {
	int i, j;
	k = 0;
	memset(vis, false, sizeof(vis));
	for(i = 1; i <= n; ++i) {
		if(!vis[i]) {
			k++;
			Loop(i);
		}
	}
	memset(vis, false, sizeof(vis));
	m = n - m;
	cout << f_abs(k - m) << endl;
	if(m < k) {
		Loop(1);
		for(i = 2; i <= n && k > m; ++i) {
			if(!vis[i]) {
				cout << 1 << ' ' << i << ' ';
				Loop(i); --k;
				swap(to[1], to[i]);
			}
		}
		cout << endl;
	}
	if(m > k) {
		for(i = 1; i <= n && m > k; i += (to[i] == i)) {
			int minv = n + 1;
			for(j = to[i]; j != i; j = to[j]) {
				if(j > i)
					minv = f_min(minv, j);
			}
			if(minv == n + 1) continue;
			cout << i << ' ' << minv << ' ';
			k++;
			swap(to[i], to[minv]);
		}
		cout << endl;
	}
}

int main() {
	while(cin >> n) {
		init();
		get_data();
		solve();
	}
	return 0;
}
	 	      		 		 			    		