//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <climits>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,m,n) for(int i=(m); i<(n); i++)
#define repe(i,m,n) for(int i=(m); i<=(n); i++)
#define repl(i,m,n) for(long long i=(m); i<=(n); i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
typedef unsigned long long ull;
using namespace std;

int di[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dj[] = { 0, 1, -1, 1, -1, 0, 1, -1 };

char grid[10][10];
bool stat[10][10];
int nstat;
bool bfs() {
	queue<pii> q;
	q.push(mp(7,0));
	int lvl = 0; //to 8

	while (q.size()) {
		int siz = q.size();
		while (siz--) {
			if(lvl == 8) return 1;
			pii cur = q.front();
			q.pop();
			if(stat[cur.first][cur.second]) continue;
			for (int d = 0; d < 8; ++d) {
				int ni = cur.first + di[d];
				int nj = cur.second + dj[d];

				if (ni < 0 || ni >= 8 || nj < 0 || nj >= 8)
					continue;
				if (stat[ni][nj])
					continue;

				q.push(mp(ni,nj));
			}
			q.push(cur);
		}
		++lvl;
		for (int i = 7; i >= 0; --i) {
			for (int j = 7; j >= 0; --j) {
				if(stat[i][j]){
					stat[i][j] = 0;
					if(i < 7) stat[i+1][j]=1;
				}
			}
		}

	}
	return 0;
}
int main() {

	for (int i = 0; i < 8; ++i) {
		scanf("%s", grid[i]);
		for (int j = 0; grid[i][j]; ++j) {
			if (grid[i][j] == 'S')
				stat[i][j] = 1,nstat++;

		}
	}
	if(bfs()) cout<<"WIN";
	else cout<<"LOSE";

	return 0;
}
