//Language: GNU C++


//Author Zach J. Wheeler

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <bitset>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <complex>
#include <limits>

#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define FOR(i,a,n) for(int i=a; i < (n); ++i) 
#define REP(i, n) FOR(i,0,n) 
#define FE(i, v) for(int i=0; i < (int)(v).size(); ++i) 
#define IT(v) typeof((v).begin())
#define FI(it, v) for(IT(v) it = (v).begin(); it != (v).end(); ++it) 
#define ALL(v) (v).begin(), (v).end()

#define DEBUG(x) cerr << #x ": " << (x) << endl

typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back

typedef long long lint;


int main() {
	int n,k;
	cin >> n >> k;
	vector<vector<pair<int, lint> > > G(n);
	int a=n-1;
	lint sum=0;
	REP(i,n-1) {
		REP(j,a) {
			int x;
			scanf("%d",&x);
			if(x >= 0) {
				G[i].pb(mp(j+i+1,x));
				G[j+i+1].pb(mp(i,x));
				sum+=x;
			}
		}
		--a;
	}
	
	double avg=0;
	if((k==1 && !(n&1))) {
		REP(i,n) {
			if(G[i].size() != 1)
				throw "!!";
			
			avg+=G[i].front().second;
		}
		avg/=n;
	} else if(k==n-1) {
		avg=2*sum;
		avg/=n;
	} else if((n&1) && k==2) {
		int hub=-1;
		REP(i,n) {
			if((int)G[i].size() != 2 && (int)G[i].size() != (n-1)) {
				DEBUG(G[i].size());
				DEBUG(i);
				throw "!!";
			}
			if(hub != -1 && (int)G[i].size() == (n-1))
				throw "!!";
			
			if((int)G[i].size() == (n-1))
				hub = i;
		}
		FE(i,G[hub]) {
			avg += (n-2)*G[hub][i].second;
		}
		FE(i,G) {
			if(i==hub)
				continue;
			FE(j,G[i]) {
				avg+=G[i][j].second;
			}
		}
		
		avg/= (n*(n-1)/2);
	} else {
		throw "tantrum";
	}
	
	//DEBUG(avg);
	
	cout << (long long)(avg+1e-9) << endl;
	
	return 0;
}

