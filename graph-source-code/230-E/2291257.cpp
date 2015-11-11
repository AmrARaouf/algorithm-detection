//Language: MS C++



#include <iostream>
#include <tchar.h>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <set>

using namespace std;

int edgeCount[1000010];

int _tmain(int argc, _TCHAR* argv[])
{
#ifndef ONLINE_JUDGE
	freopen("D:\\Temp\\Codeforce\\142\\e.in","r",stdin);
	//freopen("e.out", "w",stdout);
#endif

/*	cout << 1000000 << " " << 1000000 << endl;
	set<pair<int, int>> edges;
	for (int i = 0; i < 1000000; i++)
	{
		pair<int, int> e;
		do
		{
			e = make_pair<int, int>(((long long)rand() * 1000000) / RAND_MAX,
			((long long)rand() * 1000000) / RAND_MAX);
			if (e.first > e.second)
				swap(e.first, e.second);
		}
		while (e.first == e.second || edges.find(e) != edges.end());
		edges.insert(e);
		cout << e.first << " " << e.second << endl;
	}*/

	int n, m;
	cin >> n >> m;
	memset(edgeCount, 0, sizeof(edgeCount));
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		//cin >> a >> b;
		edgeCount[a]++;
		edgeCount[b]++;
	}
	long long cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (edgeCount[i] > 0)
			cnt += (n - 1 - edgeCount[i]) * (long long)edgeCount[i];

	long long total = n * (long long)(n - 1) * (long long)(n -2) / 6;
	cout << (total - cnt / 2) << endl;
	return 0;
}

