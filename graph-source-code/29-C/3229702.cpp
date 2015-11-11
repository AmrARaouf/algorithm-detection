//Language: GNU C++0x




#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> PI;

int n,m;

map<int, vector<int> > mp;

void solve()
{
	cin>>n;

	int a,b;
	for (int i = 0; i < n; i++)
	{
		cin>>a>>b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}

	int s = -1;
	for (auto it=mp.begin(); it !=mp.end(); ++it)
		if (it->second.size() == 1)
		{
			s = it->first;
			break;
		}

	int prev = -1;
	for (int i = 0; ; i++)
	{
		cout << s << " ";
		if (i==n) break; 
		int k = s;
		s = (mp[s][0] == prev ? mp[s][1] : mp[s][0]);
		prev = k;
	}
	cout << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
