//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

typedef     long long       LL;
typedef     pair<int, int>  pii;
typedef     pair<LL, LL>    pll;
typedef     pair<pii,pii>   ppi;
typedef     vector<int>     vi;
typedef     vector<vi>      vvi;
typedef     vector<LL>      vl;
typedef     vector<vl>      vvl;
typedef     vector<string>  vs;
typedef     vector<pii>     vii;

double      EPS = 1e-9;
int         INF = 2000000000;
long long   INFF = 8000000000000000000LL;
double      PI = acos(-1);
int         dx[8] = {-1,0,0,1,-1,-1,1,1};
int         dy[8] = {0,1,-1,0,-1,1,-1,1};


#define     fi      first
#define     se      second
#define     mp      make_pair
#define     pb      push_back
#define     SIZE(v)         (int)v.size()
#define     ALL(v)          v.begin(),v.end()
#define     ALLA(arr,sz)    arr,arr+sz
#define     SORT(v)         sort(ALL(v))
#define     SORTA(arr,sz)   sort(ALLA(arr,sz))
#define     SQR(x)          ((x) * (x))
#define     FOR(i,s,e)      for(int (i) = (s); (i) <  (e); ++(i))
#define     FORE(i,s,e)     for(int (i) = (s); (i) <= (e); ++(i))
#define     FORD(i,e,s)     for(int (i) = (e); (i) >= (s); --(i))
#define     REP(i,n)        FOR(i,0,n)
#define     REPE(i,n)       FORE(i,1,n)
#define     REPD(i,n)       FORD(i,n,1)
//=== End of NNN template ===/

const int Nmax = 3003;

vector<int> adjOf[Nmax];
int dist[Nmax][Nmax];

int n, m;
unsigned int s1,t1,l1, s2, t2,l2;
set<pair<int, int> > Path1, Path2;

void readInput(){
	REP(i,Nmax) adjOf[i].clear();
	cin >>n>>m;
	int u,v;
	REP(i,m){
		cin >>u>>v;
		adjOf[u].pb(v);
		adjOf[v].pb(u);
	};

	cin >>s1>>t1>>l1;
	cin >>s2>>t2>>l2;

	//reset:
	REP(i, Nmax) REP(j, Nmax) dist[i][j] = INF;
};


void BFS(int s){	

	bool Visited[Nmax]; REP(i, Nmax) Visited[i] = false;
	Visited[s] = true;
	dist[s][s] = 0;

	queue<int> Que;
	Que.push(s);

	int u,v;
	while(!Que.empty()){
		u = Que.front(); Que.pop();
		REP(iv, adjOf[u].size()){
			v = adjOf[u][iv];
			if (Visited[v]) continue;
			dist[s][v] = dist[s][u] +1;
			Que.push(v);
			Visited[v] = true;
		};
	};
};


int solve(){
	FORE(u, 1, n) BFS(u);
	if (dist[s1][t1] >l1 or dist[s2][t2] >l2) return -1;

	int ans = INF;
	int p1, p2;
	REP(x,2){
		swap(s1,t1);
		FORE(i,1,n) FORE(j,1,n){
			p1 = dist[s1][i] + dist[i][j] + dist[j][t1];
			p2 = dist[s2][i] + dist[i][j] + dist[j][t2];
			if (p1<=l1 and p2 <=l2) ans = min(ans, p1+p2-dist[i][j]);
		};
	}
	
	ans = min(ans, dist[s1][t1] + dist[s2][t2]);

	if (ans >m) return -1;
	else return m - ans;

};

int main(){
	readInput();
	cout <<solve()<<endl;
	return 0;
};
