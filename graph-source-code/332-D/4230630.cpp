//Language: MS C++


#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define RPA(i,s,e) for(int i=s; i<=e; i++)
#define RPD(i,s,e) for(int i=s; i>=e; i--)
#define PB(a) push_back(a)
#define MP(i,s) make_pair(i,s)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()
#define CHMAX(a,b) a=max(a,b);
#define CHMIN(a,b) a=min(a,b);
#define PRT(a) cout << (a) << endl
#define PRT2(a,b) cout << (a) << " " << (b) << endl
#define PRT3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl

typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> P;

const int INF = 1 << 30;
const int MAX_V = 2020;
LL G[MAX_V][MAX_V];
int N,K,C;
bool iscmp;
LL sum;

LL chk1(int s, int& pair) {
	int cnt = 0;
	int idx = 0;
	REP(i,N) {
		if(i == s) continue;
		if(G[i][s] >= 0) {
			cnt++;
			idx = i;
		}
	}
	
	if(cnt != 1) return 0;
	pair++;
	return G[idx][s];
}

LL chk2(int s, int& pair) {
	VI v;
	REP(i,N) {
		if(i == s) continue;
		if(G[i][s] >= 0) v.PB(i);
	}

	LL cost = 0;
	REP(i,SZ(v)) {
		RPA(j,i+1,SZ(v)-1) {
			cost += G[v[i]][s] + G[v[j]][s];
			pair++;
		}
	}
	return cost;
}

void solve() {
	LL cost = 0;
	if(K >= 3) {
		cost = iscmp ? 2 * sum / N : 0;
	} else {
		int pair = 0;
		REP(i,N) {
			if(K == 1) {
				cost += chk1(i, pair);
			} else if(K == 2) {
				cost += chk2(i, pair);
			}
		}
		cost = cost / pair;
	}
	printf("%I64d\n", cost);
}

void coding() {
	while(scanf("%d%d",&N,&K)!=EOF) {
		iscmp = true;
		sum = 0;
		REP(i,N-1) {
			RPA(j,i+1,N-1) {
				scanf("%d",&C);
				G[i][j] = G[j][i] = C;
				sum += C;
				if(C == -1) iscmp = false;
			}
		}
		solve();
	}
}

// #define _LOCAL_TEST

int main() {
#ifdef _LOCAL_TEST
	clock_t startTime = clock();
	freopen("a.in", "r", stdin);
#endif

	coding();

#ifdef _LOCAL_TEST
	clock_t elapsedTime = clock() - startTime;
	cout << endl;
	cout << (elapsedTime / 1000.0) << " sec elapsed." << endl;
	cout << "This is local test" << endl;
	cout << "Do not forget to comment out _LOCAL_TEST" << endl << endl;
#endif
}
