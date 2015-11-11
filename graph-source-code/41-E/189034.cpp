//Language: MS C++


#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > ans;
int n;

int main()
{
	cin >> n;

	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j += 2)
			ans.push_back(pair<int, int>(i, j));

	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << endl;

	return 0;
}

