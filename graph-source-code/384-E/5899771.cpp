//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <ctime>
#include <sstream>
#include <stack>
#include <queue>

#define PB push_back
#define MP make_pair
#define all(v) v.begin(), v.end()
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, b, a) for (int i = b; i > a; i--)
#define Si(a) scanf("%d", &(a))
#define SZ size()
#define F first
#define S second
#define B begin()
#define E end()

#define MOD 1000000007

using namespace std;

typedef unsigned long long int ull;
typedef long long int lli;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <typename T>
T power(T a, int n, int mod)
{
	T res = 1;
	while (n) {
		if (n % 2 == 1) res = (res * a) % mod;
		n /= 2;
		a = (a * a) % mod;
	}
	return res;
}

struct node {
	int height;
	int newName;
	int val;
	vector<int> next;
	int negb, nege, posb;
};

node arr[200009];
int counter = 1;

void calcHeight(int i, int h)
{
	arr[i].height = h;
	for (int j = 0; j < arr[i].next.SZ; j++) {
		calcHeight(arr[i].next[j], h+1);
	}
	return;
}

void assignNamesDfs(int i, int flag)
{
	for (int j = 0; j < arr[i].next.SZ; j++) {
		assignNamesDfs(arr[i].next[j], flag);
	}
	if (arr[i].height % 2 == flag) arr[i].newName = counter++;
}

void assignRanges(int idx)
{
	if (arr[idx].next.SZ == 0) {
		arr[idx].posb = arr[idx].newName;
		arr[idx].negb = -1;
		arr[idx].nege = -1;
		return;
	}
	int x = -1;
	for (int j = 0; j < arr[idx].next.SZ; j++) {
		assignRanges(arr[idx].next[j]);
		if (x == -1) x = arr[ arr[idx].next[j] ].negb;
	}

	arr[idx].posb = (x == -1 ? arr[idx].newName : x);
	arr[idx].negb = arr[ arr[idx].next[0] ].posb;
	arr[idx].nege = arr[ arr[idx].next.back() ].newName;

	return;
}

lli tree[200006] = {0};	
int n;

void updatePoint(int x, int v)
{
	if (x <= 0) return;
	while (x <= n) {
		tree[x] += v;
		x += (x & -x);
	}
}

void updateRange(int x, int y, int v)
{
	//cout << "Update Range called for: " << x << " " << y << " by " << v << endl;
	updatePoint(x, v);
	updatePoint(y+1, -v);
	//cout << "Update Range called for: " << x << " " << y << "  Done" << endl;
}

int sumUpto(int i)
{
	int ans = 0;
	if (i < 0) return 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main()
{
	int m, x, y;

	cin >> n >> m;
	For  (i, 1, n+1) {
		// arr[i] = new node();
		cin >> arr[i].val;
	}

	For (i, 1, n) {
		cin >> x >> y;
		arr[x].next.PB(y);
	}

	calcHeight(1, 0);
	assignNamesDfs(1, 0);
	assignNamesDfs(1, 1);

	assignRanges(1);

	while (m--) {
		cin >> x;
		if (x == 1) {
			cin >> x >> y;
			updateRange(arr[x].posb, arr[x].newName, y);
			updateRange(arr[x].negb, arr[x].nege, -y);
		}
		else {
			cin >> x;
			cout << sumUpto(arr[x].newName) + arr[x].val << endl;
		}
	}
	return 0;
}
