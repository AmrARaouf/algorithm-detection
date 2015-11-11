//Language: GNU C++


#include "iostream"
#include "set"
#include "algorithm"
#include "cstdio"

#define ll long long

using namespace std;
int s[1000000];
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	ll r1 = (ll) (n - 1) * (n - 2) * n / 6;
	ll r2 = 0;
	
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		//cin >> a >> b;
		a--; b--;
		//int same = 0;
		//set<int> sa, sb;
		// if (s[a].size() < s[b].size()) {
		// 	sa = s[a];
		// 	sb = s[b];
		// } else {
		// 	sa = s[b];
		// 	sb = s[a];
		// }
		// set<int>::iterator it;
		// for ( it=sa.begin() ; it != sa.end(); it++ )
  //   		same += sb.count(*it);
    	//r2 += same;
    	r1 += -(n-2);// - same;
    	r1 += s[a];
    	r1 += s[b];
    	//cout << - n + 2 - same << ' '  << r1 << endl;
    	s[a]++;
    	s[b]++;
	}
	cout << r1 + r2 << endl;
	return 0;
}