//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<cstring>

using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) (int)(x).size()
#define SORT(x) sort((x).begin(),(x).end())
#define CLEAR(tab) memset(tab, 0, sizeof(tab))
#define REP(x, n) for(int x = 0; x < (n); x++)
#define FOR(x, b, e) for(int x = (b); x <= (e); x++)
#define FORD(x, b, e) for(int x = (b); x >= (e); x--)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define DEBUG(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

const int MAX_BUF_SIZE = 16384;
char BUFOR[MAX_BUF_SIZE];
int BUF_SIZE, BUF_POS;
char ZZZ;
#define GET(ZZZ){ZZZ='a';if(BUF_POS<BUF_SIZE)ZZZ=BUFOR[BUF_POS++];\
else if(!feof(stdin)){BUF_SIZE=fread(BUFOR,1,MAX_BUF_SIZE,stdin);\
ZZZ=BUFOR[0];BUF_POS=1;}}
#define GI(WW){do{GET(ZZZ);}while(!isdigit(ZZZ));WW=ZZZ-'0';\
while(1){GET(ZZZ);if(!isdigit(ZZZ))break;WW=WW*10+(ZZZ-'0');}}
#define GC(WW){do{GET(ZZZ);}while(!isalpha(ZZZ));WW=ZZZ;}

//FAST IO

typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MXN = 300010;
const int C = 262144;
const LL INF = (1LL << 62);

vector<PII> G[MXN];
int w[MXN];
int start, n, m;
LL dist[MXN];
int tree[MXN];
priority_queue< pair<LL, int> > Q;

int main() {
	scanf("%d %d", &n, &m);

	FOR(i, 1, m) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		G[a].PB(MP(b, i) );
		G[b].PB(MP(a, i) );
		w[i] = c;
	}

	scanf("%d", &start);
	
	FOR(i, 1, n)
		dist[i] = INF;
	dist[start] = 0;
	Q.push(MP(0, start) );

	while(!Q.empty() ) {
		pair<LL, int>  p1 = Q.top();
		Q.pop();

		LL d = -p1.F;
		int v = p1.S;
		
		if(d != dist[v])
			continue;

		FOREACH(it, G[v]) {
			int u = it -> F;
			int num = it -> S;

			if(dist[u] >= dist[v] + w[num]) {
				if(tree[u] == 0 || w[tree[u]] > w[num])
					tree[u] = num;
			}

			if(dist[u] > dist[v] + w[num]) {
				tree[u] = num;
				dist[u] = dist[v] + w[num];
				Q.push(MP(-dist[u], u) );
			}
		}
	}

	LL q = 0;
	FOR(i, 1, n)
		if(i != start)
			q += w[tree[i]];
	cout<<q<<endl;
	FOR(i, 1, n)
		if(i != start)
			printf("%d ", tree[i]);
	printf("\n");

	return 0;
}

