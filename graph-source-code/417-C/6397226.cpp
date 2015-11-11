//Language: GNU C++0x


#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <vector>

#if LOCAL
	#define DO_NOT_SEND
#endif

typedef long long LL;

int IntMaxVal = (int) 1e20;
int IntMinVal = (int) -1e20;
LL LongMaxVal = (LL) 1e20;
LL LongMinVal = (LL) -1e20;

#define FOR(i, a, b) for(int i = a; i < b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)

#define minimize(a, b) { a = min(a, b); }
#define maximize(a, b) { a = max(a, b); }

#define all(v) v.begin(),v.end()

using namespace std;

#define next(type, i) type i; cin >> i;
template<typename T> struct argument_type;
template<typename T, typename U> struct argument_type<T(U)> { typedef U type; };
#define nextVector(t, v, size) vector< argument_type<void(t)>::type > v(size); { for (int i = 0 ; i < size ; i++) cin >> v[i]; }

#define range(name, start, count) vector<int> name(count); { for (int i = 0 ; i < count ; i++) name[i] = i + start; }

#define endl '\n';
template <typename T1, typename T2> istream& operator >>(istream& is, pair<T1, T2>& s) { is >> s.first >> s.second; return is; }
template <typename T> ostream& operator << (ostream& os, vector<T> &v) { for (int i = 0 ; i < v.size() ; i++) os << v[i] << endl; os << endl; return os; }
template <typename T1, typename T2> ostream& operator <<(ostream& s, pair<T1, T2>& t) { s << t.first << ' ' << t.second; return s; }

int main() {
	srand (time(NULL));
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	
		next(int, n);
	next(int, k);
	
	int x = 2 * k;
	if (x > n - 1) {
		cout << -1;
		return 0;
	}
	
	vector<pair<int, int> > games;
	games.reserve(n * x);

	vector<bool> visited(n + 1);	
	FOR (i, 1, k + 1) {
		visited.assign(n + 1, false);
		FOR (start, 1, n + 1) if (!visited[start]) {
			int nxt = start + i;
			int cur = start;
			do {
				games.push_back(make_pair(cur, nxt));
				cur = nxt;
				nxt = (cur + i - 1) % n + 1;
				visited[cur] = true;
			} while (cur != start);
		}
	}
	
	cout << games.size() << endl;
	cout << games;
}