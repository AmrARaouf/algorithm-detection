//Language: MS C++


#pragma comment(linker,"/STACK:300000000")
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4800)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <deque>
#include <bitset>
#include <numeric>
#include <ctime>
#include <queue>
#include <hash_map>

using namespace std;
using namespace stdext;

#define show(x) cout << #x << " = " << (x) << endl;
void showTime() { cerr << (double)clock()/CLOCKS_PER_SEC << endl; }
#define fori(i,n) for(int i = 0; i < (n); i++)
#define forab(i,a,b) for(int i = (a); i <= (b); i++)
#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()
const double pi = 3.1415926535897932384626433832795;
template<class T> T abs(const T &a) { return a >= 0 ? a : -a; };
template<class T> T sqr(const T &x) { return x * x; }
typedef pair<int,int> ii;
typedef long long ll;
///////////////////////////////////////

//vector<vector<int> > g;
int c[200][200];
int f[200][200];

int cf(int x, int y)
{
	return c[x][y]-f[x][y];
}

string s;
int n;
int last;
bool visited[200];

bool dfs(int k, vector<int> &path)
{
	visited[k] = true;
	path.push_back(k);

	if(k == last)
		return true;

	fori(to,last+1)
	{
		if(cf(k,to) > 0 && !visited[to])
		{
			if(dfs(to,path))
				return true;
		}
	}

	path.pop_back();
	return false;
}

bool hasPath(vector<int> &path)
{
	path.clear();
	memset(visited,0,sizeof(visited));
	return dfs(0,path);
}

void maxFlow()
{
	vector<int> path;
	while(hasPath(path))
	{
		int mi = int(1e9);
		fori(i,sz(path)-1)
			mi = min(mi,cf(path[i],path[i+1]));
		cerr << mi << endl;
		fori(i,sz(path)-1)
		{
			f[path[i]][path[i+1]] += mi;
			f[path[i+1]][path[i]] -= mi;
		}
	}
}

int main()
{
#ifdef TEDDY_BEARS
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
	//freopen(FILENAME".in","r",stdin);
    //freopen(FILENAME".out","w",stdout);
#endif
	cin >> s >> n;
	last = n+27;
	fori(i,sz(s))
		c[n+s[i]-'a'+1][last]++;
	fori(i,n)
	{
		cin >> s;
		cin >> c[0][i+1];
		fori(j,sz(s))
			c[i+1][n+s[j]-'a'+1]++;
		maxFlow();
	}
	fori(i,26)
		if(cf(n+i+1,last) != 0)
		{
			cout << -1;
			exit(0);
		}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += i*f[0][i];
	cout << ans;
}