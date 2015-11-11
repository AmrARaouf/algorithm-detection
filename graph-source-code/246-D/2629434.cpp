//Language: GNU C++


#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>
#include <queue>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <complex>
#include <utility>

using namespace std;

#define FORALL(i,a,b) for (int i = (a); i <= (b); i++)
#define FOR(i,n) for (int i=0;i<n;i++)
#define FORB(i,a,b) for (int i = (a); i >= (b); i--)
#define FORIN(it,type,b) for(type::iterator it = (b).begin(); it != (b).end(); it++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld; 

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define in cin
#define out cout
#define dout if(true) cout

#define MAXN 100010
vector<int> E[MAXN];
set<int> V[MAXN];
bool exists[MAXN];

int C[MAXN];

int main()
{
	int N,M;
	in >> N >> M;
	FORALL(i,1,N) in >> C[i], exists[C[i]] = true;
	int a,b;
	FOR(j,M){
		scanf("%d%d",&a,&b);
		E[a].pb(b);
		E[b].pb(a);
	}
	
	FORALL(i,1,N){
		int numE = E[i].size();
		FOR(x,numE){
			int j = E[i][x];
			if (C[j] != C[i]) V[C[i]].insert(C[j]);
		}
	}
	
	int best = -1;
	FORALL(k,1,100000){
		if (!exists[k]) continue;
		if (best == -1 || V[k].size() > V[best].size()) best = k;
	}
	cout << best << endl;
}