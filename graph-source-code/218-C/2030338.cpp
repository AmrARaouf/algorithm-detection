//Language: MS C++


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <utility>
#include <deque>
#include <list>
#include <string>
#include <cassert>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define forl(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (ll i=ll(a); i<=ll(b); ++i)

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()

#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define ll long long
#define ld long double
#define pii pair <int,int>
#define sz(a) (int)(a).size()
#define np next_permutation
#define ull unsigned long long

const int INF = (int)1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

bool ineedoutputfile = false;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
} 

ll lcm (ll a, ll b) {
	return (a*b)/gcd(a,b);
}

bool ispal (string s) {
	for(int i=0; i<(s.size())/2; i++)
		if (s[i]!=s[s.size()-i-1])
			return false;
	return true;
}

ll getlen(ll t) {
	ll dl = 0;
	while (t > 0) {
		t/=10; dl ++;
	}
	return dl;
}
bool used[200];
pair<int, int> d[200];
int n;
void dfs(int s) {
	if (used[s])
		return;
	used[s] = true;
	forn(i, n) 
		if (d[i].first == d[s].first || d[s].second == d[i].second)
			dfs(i);
}
int main () {

#ifdef LocalHost
	if (0) freopen("input.txt","rt",stdin);
	if (ineedoutputfile)
		freopen("output.txt","wt",stdout);
#endif
	cin >> n;
	forn(i, n) 
		cin >> d[i].first >> d[i].second;
	int cnt = 0;
	forn(i, n) 
		if (!used[i])
			dfs(i), cnt++;
	cout << cnt - 1;
}