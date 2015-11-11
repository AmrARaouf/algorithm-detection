//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

typedef unsigned long long ull;

class Graph
{
public:
	int n;
	int el;
	vector<int> fe;
	vector<int> ne;
	vector<int> nv;
	void build(int n, int m)
	{
		fe.resize(n + 1);
		ne.resize(m + 2);
		nv.resize(m + 2);
		this->n = n;
		el = 1;
	}
	void add1(int L, int R)
	{
		++el;
		ne[el] = fe[L];
		fe[L] = el;
		nv[el] = R;
	}
	void add2(int L, int R)
	{
		add1(L, R);
		add1(R, L);
	}
	
	vector<bool> visit;
	
	vector<vector<int> > connect;
	void dfsCon(int x)
	{
		visit[x] = 1;
		connect.back().push_back(x);
		for (int i = fe[x]; i; i = ne[i]) if (!visit[nv[i]])
			dfsCon(nv[i]);
	}
	void buildConnect() // 连通块
	{
		visit.assign(n + 1, 0);
		for (int i = 1; i <= n; ++i) if (!visit[i]) {
			connect.push_back(vector<int>(0));
			dfsCon(i);
		}
	}
	
	vector<int> color; // {0, 1}
	bool dye(int x, int c)
	{
		if (visit[x])
			return color[x] == c;
		
		visit[x] = 1;
		color[x] = c;
		for (int i = fe[x]; i; i = ne[i])
			if (!dye(nv[i], c ^ 1))
				return false;
		return true;
	}
	bool dyeAll()
	{
		visit.assign(n + 1, 0); // CAM! assign() 跟 resize() 的区别要注意!
		color.resize(n + 1);
		for (int i = 0; i < connect.size(); ++i)
			if (!dye(connect[i][0], 1))
				return false;
		return true;
	}
	
	void exec()
	{
		int n, m;
		scanf("%d%d", &n, &m);
		
		// t = 3
		if (m == 0) {
			cout << "3 " << (ull)n * (n - 1) / 2 * (n - 2) / 3 << endl; // 怕爆ull...
			return;
		}
		
		build(n, m * 2); // *2写在这里哦!
		for (int i = 0; i < m; ++i) {
			int L, R;
			scanf("%d%d", &L, &R);
			add2(L, R);
		}
		
		buildConnect();
		
		// t = 0
		if (!dyeAll()) {
			printf("0 1\n");
			return;
		}
		
		// t = 1
		ull ans = 0;
		for (int i = 0; i < connect.size(); ++i) {
			int cnt[2] = {};
			for (int j = 0; j < connect[i].size(); ++j)
				++cnt[color[connect[i][j]]];
			for (int j = 0; j <= 1; ++j)
				if (cnt[j] >= 2)
					ans += (ull)cnt[j] * (cnt[j] - 1) / 2;
		}
		if (ans) {
			cout << "1 " << ans << endl;
			return;
		}
		
		// t = 2
		for (int i = 0; i < connect.size(); ++i)
			if (connect[i].size() == 2) {
				ans += n - 2;
			}
		if (ans) {
			cout << "2 " << ans << endl;
			return;
		}
		
	}
} G;

int main()
{
	G.exec();
	return 0;
}
