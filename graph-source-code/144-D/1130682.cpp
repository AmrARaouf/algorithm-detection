//Language: GNU C++


//In the Name of God the Most Beneficent the Most Merciful
//Kourosh

#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define show(x) cerr<<((#x))<<" "<<((x))<<endl
const long long INF = 1LL << 60, MAX = 1000 * 100+1000;
vector <int> adj[MAX], w[MAX];
long long d[MAX];


struct cmp
{
	bool operator ()(int a, int b)
	{
		if (d[a] == d[b])
			return a < b;
		return d[a] < d[b];
	}
};
set <int, cmp> me;
int main()
{
	int n, m, s, L;
	int t1, t2, w_;
	cin >> n >> m >> s;
	s--;
	for (int i = 0; i < m; i++)
	{
		cin >> t1 >> t2 >> w_;
		t1--;
		t2--;
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
		w[t1].push_back(w_);
		w[t2].push_back(w_);		
	}
	cin >> L;
	for (int  i = 0; i < n; i++)
		d[i] = INF;
	d[s] = 0;
	me.insert(s);
	while(!me.empty())
	{
		int tmp = *me.begin();
		me.erase(tmp);
		for (int i = 0; i < adj[tmp].size(); i++)
		{
			int t = adj[tmp][i];
			if (d[t] > d[tmp] + w[tmp][i])
			{
				me.erase(t);
				d[t] = d[tmp] + w[tmp][i];
				me.insert(t);
			}
		}
	}
	for (int i=0;i<n;i++)
		cerr<<d[i]<<" ";
	cerr<<endl;
	int res = 0, t = 0;
	for (int i = 0; i < n; i++)
		if (d[i] == L)
			res++;
	show(res);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < adj[i].size(); j++)
		{
			int u=adj[i][j];
			if ((d[i] < L) && d[i] + w[i][j] > L && d[u] + (w[i][j] - (L - d[i])) >= L)
			{
				if (d[u] + (w[i][j] - (L - d[i])) == L)
					t++;
				res++;
			}
		}
	show(res);
	show(t);	
	cout << res - t / 2 << endl;
	//system("pause");
	{char _; cin>>_;}
	return 0;
}
