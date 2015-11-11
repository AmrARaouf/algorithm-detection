//Language: GNU C++


#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define ll long long

map <string, ll> d;
ll k, res1, res2;
pair<ll, ll> down[100005];
vector <int> a[100005], b[100005], q, tsort;
bool used[100005], used_t[100005];

void correct(string &s, ll &ans, ll &sz) {
	sz = s.size();
	ans = 0;
	for(int i = 0; i < sz; i++) {
		if('a' <= s[i] && s[i] <= 'z')
			s[i] -= ('a' - 'A');
		if(s[i] == 'R')
			ans++;
	}
}

void dfs(int v) {
	int m = a[v].size();
	used[v] = 1;
	for(int i = 0; i < m; i++) {
		int go = a[v][i];
		if(!used[go]) 
			dfs(go);
		if(down[v].f > down[go].f || (down[v].f == down[go].f && down[v].s > down[go].s))
			down[v] = down[go];
	}
}

void dfs_t(int v) {
	int m = a[v].size();
	used_t[v] = 1;
	for(int i = 0; i < m; i++) {
		int go = a[v][i];
		if(!used_t[go]) 
			dfs_t(go);
		if(down[v].f > down[go].f || (down[v].f == down[go].f && down[v].s > down[go].s))
			down[v] = down[go];
	}
	tsort.push_back(v);
}


int main() {

//	freopen("in.txt", "r", stdin);

	ll n, m, z1, z2, l1, l2, go, to, v;
	string s, x, y;
	
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> s;
		correct(s, z1, l1);
		if(d[s] == 0)
			v = d[s] = ++k;
		else
			v = d[s];
			
		down[v] = mp(z1, l1);
		q.push_back(v);
	}

	cin >> m;

	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		correct(x, z1, l1), correct(y, z2, l2);

		if(d[x] == 0)  
			d[x] = ++k;
		if(d[y] == 0)
			d[y] = ++k;

		go = d[x];
		to = d[y];
	
		a[go].push_back(to);
		b[to].push_back(go);
		down[go] = mp(z1, l1);
		down[to] = mp(z2, l2);
	}

	for(int i = 0; i < n; i++) {
		v = q[i];
		if(!used_t[v])
			dfs_t(v);
	}
	m = tsort.size();

	for(int i = 0; i < m; i++)
		if(!used[tsort[i]])
			dfs(tsort[i]);
	memset(used, 0, sizeof(used));
		

	for(int i = 0; i < n; i++) {
		v = q[i];
		if(!used[v])
			dfs(v);
		res1 += down[v].f;
		res2 += down[v].s;
	}

	cout << res1 << " " << res2;
	
	return 0;
}
