//Language: GNU C++


#include <bits/stdc++.h>

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(i, c) for(typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
#define inf 10000009

using namespace std;

int n, e, a, b, ans;

int d[3009][3009];

int s[3], t[3], l[3];

vector <int> E[3009];

queue <int> q;

int main()
{
	cin >> n >> e;
	
	for (int i = 1; i <= e; i++) {
		cin >> a >> b;
		
		E[a].pb(b);
		E[b].pb(a);
	}
	
	ans = e+1;
	for (int i = 0; i < 2; i++)
		cin >> s[i] >> t[i] >> l[i];
	
	fill(d[0], d[3009], inf);
	
	for (int i = 1; i <= n; i++) {
		q.push(i);
		
		d[i][i] = 0;
		
		while (!q.empty()) {
			int node = q.front();
			
			q.pop();
			for (int h = 0; h < E[node].size(); h++) {
				int to = E[node][h];
				if (d[i][to] > d[i][node]+1)
					d[i][to] = d[i][node]+1, q.push(to);
			}
		}
	}
	
	for (int i = 0; i < 2; i++)
	{
		swap(s[0], t[0]);
		
		for (int h = 1; h <= n; h++)
		{
			for (int j = 1; j <= n; j++)
			{
				int v[] = {d[s[0]][h] + d[h][j] + d[j][t[0]], d[s[1]][h] + d[h][j] + d[j][t[1]]};
				
				if (v[0] <= l[0] && v[1] <= l[1])
					ans = min(ans, v[0]+v[1]-d[h][j]);
			}
		}
	}
	
	if (d[s[0]][t[0]] <= l[0] && d[s[1]][t[1]] <= l[1])
		ans = min(ans, d[s[0]][t[0]] + d[s[1]][t[1]]);
	
	cout << (ans > e ? -1 : e-ans);
}
