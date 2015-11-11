//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define eps 1e-9
#define FOR(x, s, e) for(int x = (s); x < (e); ++x)
#define FORc(x, s, e, c) for(int x = (s); x < (e) && (c); ++x)
#define STEP(x, s, e, d) for(int x = (s); x < (e); x+=(d))
#define ROF(x, s, e) for(int x = (s); x >= (e); --x)
#define ROFc(x, s, e, c) for(int x = (s); x >= (e) && (c); --x)
#define vb vector<bool>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define ALL(X) X.begin(), X.end()

using namespace std;

struct tri{
	int x, y, z;
	tri(){}
	tri(int x, int y, int z):x(x),y(y),z(z){}
	bool operator==(const tri &S)const{
		return x==S.x&&y==S.y&&z==S.z;
	}
	bool operator<(const tri &S)const{
		return mp(x, mp(y, z)) < mp(S.x, mp(S.y, S.z));
	}
	bool operator>(const tri &S)const{
		return mp(x, mp(y, z)) > mp(S.x, mp(S.y, S.z));
	}
};

int main(int argc, char **argv){
	map<tri, bool> forbid;
	int N, M, K;
	cin >> N >> M >> K;
	vii E(M);
	int W[N][N];
	memset(W, 0, sizeof(W));
	FOR(i, 0, M){
		int x, y;
		cin >> x >> y;
		--x, --y;
		W[x][y] = W[y][x] = 1;
		E.pb(mp(x, y));
	}
	FOR(i, 0, K){
		int x, y, z;
		cin >> x >> y >> z;
		--x, --y, --z;
		forbid[tri(x, y, z)] = 1;
	}
	int d[N][N], res=1<<29, pre[N][N];
	FOR(i, 0, N) FOR(j, 0, N) d[i][j] = 1<<29, pre[i][j] = -1;
	d[0][0] = 0;
	priority_queue<tri, vector<tri>, greater<tri> > Q;
	Q.push(tri(0, 0, 0));
	int px, py;
	while (!Q.empty()){
		tri U = Q.top();
		Q.pop();
		if (U.z == N-1){
			if (res > U.x){
				res = min(U.x, res);
				px = U.y, py = U.z;
			}
			continue;
		}
		FOR(i, 0, N) if (W[U.z][i]){
			tri S(U.y, U.z, i);
			if (forbid.find(S) != forbid.end()) continue;
			S = tri(U.x+1, U.z, i);
			if (d[U.z][i] > U.x+1){
				d[U.z][i] = U.x+1;
				pre[U.z][i] = U.y;
				Q.push(S);
			}
		}
	}
	printf("%d\n", res==1<<29?-1:res);
	if (res != 1<<29){
		deque<int> stk;
		while (pre[px][py] != -1){
			stk.push_front(py+1);
			int pz = pre[px][py];
			py = px, px = pz;
		}
		stk.push_front(1);
		FOR(i, 0, stk.size()) printf("%d%c", stk[i], (i+1==stk.size())?'\n':' ');
	}
	return 0;
}
