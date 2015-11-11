//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define f first
#define s second
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair < int, int>
#define forit (it , a) for( (__typeof(a.begin())::iterator it = a.begin(); it!=a.end(); it++)


using namespace std;
int const maxn = (int)1e2 + 111;
int const inf = (1<<30) - 1;

int d[maxn], phi[maxn], from[maxn], flow[maxn];
bool used[maxn];
int s, t;
int n;
int a[26];

struct edge {
	int from, to, c, f, cost;
	edge(){
		from = to = c = f = cost = 0;
	}
	edge ( int ffrom, int tto, int cc, int ff, int ccost){
		from = ffrom; 
		to = tto; 
		c = cc; 
		f = ff; 
		cost = ccost;
	}
}e[100*2 + 100*26*2 + 26*2 + 1];
int esz;
vector < int > g[maxn];

void addEdge(int from, int to, int c, int f, int cost){
	e[esz++] = edge(from,to,c,f,cost);
	g[from].pb(esz-1);
}


void process(string S, int x, int num){
	memset ( a, 0, sizeof(a));
	for (int i=0;i<S.length();i++)
		a[S[i]-'a']++;
	addEdge(s,num,x,0,0);
	addEdge(num,s,0,0,0);
	for (int i=0;i<26;i++){
		addEdge(num,n+i+1,a[i],0,num);
		addEdge(n+i+1,num,0,0,-num);
	}
}

void doIt(string tt){
	memset ( a, 0, sizeof(a));
	for (int i=0;i<tt.length();i++){
		a[tt[i]-'a']++;
	}
	for (int i=0;i<26;i++){
		addEdge(n+i+1,t,a[i],0,0);
		addEdge(t,n+i+1,0,0,0);
	}
}
void infinity(){
	for (int i=0;i<maxn;i++)
		d[i] = inf;
	d[s] = 0;
}

bool Dijkstra(){
	memset ( flow, 0, sizeof(flow));
	memset ( used, 0, sizeof(used));
	memset ( from, 0, sizeof(from));
	infinity();
	flow[s] = inf;

	while ( true ){
		int mini = inf;
		int u = -1;
		for (int i=s;i<=t;i++){
			if ( !used[i] && d[i] < mini){
				mini = d[i];
				u = i;
			}
		}
		if ( u == -1)break;
		used[u] = true;
		for (int i=0;i<g[u].size();i++){
			int id = g[u][i];
			edge E = e[id];
			int v = E.to;
			if ( E.c - E.f > 0 && d[u] + E.cost + phi[u] - phi[v] < d[v]){
				d[v] = d[u] + E.cost + phi[u] - phi[v];
				from[v] = u;
				flow[v] = min(flow[u], E.c - E.f);
			}
		}
	}
	for (int i=s;i<=t;i++)
		phi[i] += d[i];
	return (flow[t]!=0);
}

int main (){
	#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	#endif

	string T;
	cin >>T;
	cin >>n;

	s = 0, t = n + 26 + 1;

	for (int i=1;i<=n;i++){
		string ss; int x;
		cin >>ss>>x;
		process(ss,x,i);
	}

	doIt(T);

	while ( Dijkstra()){
		int v = t;

		while ( v != s){
			int u = from[v];
			for (int i=0;i<g[u].size();i++){
				int id = g[u][i];
				int to = e[id].to;
				if ( to == v){
					e[id].f += flow[t];
					e[id^1].f -= flow[t];
				}
			}
			v = u;
		}	
	}

	ll ans = 0;
	int sum = 0;
	for (int i=0;i<esz;i++){
		if ( e[i].f > 0){                                  
			ans += e[i].f * e[i].cost;
		}
		if ( e[i].to == t ){ 
			sum += e[i].f;
		}
	}
	int tz = T.length();
	if ( sum != tz){
		cout <<-1<<endl;
		return 0;
	}
	cout <<ans<<endl;


	return 0;
}





