//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=1;i<=(n);i++)

int N, M, S, E, to;
int a, b; long long w;

long long cS[100005], cE[100005], e, targ;
bool seenS[100005], seenE[100005], mult[100005];

vector<pair<int, long long>> adj[100005], rev[100005];

vector<int> tadj[100005];

struct edge {
	int a, b;
	long long w;
} m[100005];

struct state {
	int nd;
	long long cost;
	bool operator < (const state &o) const {
		return cost > o.cost;
	}
} t;

priority_queue<state> pq;

int par[100005], topar[100005], id[100005], lo[100005], ind;

bool bridge[100005];

void go (int i) {
	int myp = par[i];
	id[i] = lo[i] = ++ind;
	for(int j : tadj[i]) {
		int TO = (m[j].a == i ? m[j].b : m[j].a);
		if(TO == par[i]) par[i] = -1;
		else if(!id[TO]) {
			par[TO] = i;
			topar[TO] = j;
			go(TO);
			lo[i] = min(lo[i], lo[TO]);
		} else {
			lo[i] = min(lo[i], id[TO]);
		}
	}
	if(myp != 0 && lo[i] == id[i]) {
		bridge[topar[i]] = 1;
	}
}


int main () {
	scanf("%d %d %d %d", &N, &M, &S, &E);
	fo(i, N) cS[i] = cE[i] = 1e18;
	fo(i, M) {
		scanf("%d %d %lld", &a, &b, &w);
		adj[a].push_back({b, w});
		rev[b].push_back({a, w});
		m[i] = {a, b, w};
	}
	pq.push({S, 0}), cS[S] = 0;
	while (pq.size()) {
		t = pq.top(), pq.pop();
		if(seenS[t.nd]) continue;
		seenS[t.nd] = 1;
		for(auto k : adj[t.nd]) {
			e = t.cost + k.second;
			to = k.first;
			if(cS[to] > e) {
				cS[to] = e;
				mult[to] = 0;
				pq.push({to, e});
			} else if(cS[to] == e) {
				mult[to] = 1;
			}
		}
	}
	pq.push({E, 0}), cE[E] = 0;
	while (pq.size()) {
		t = pq.top(), pq.pop();
		if(seenE[t.nd]) continue;
		seenE[t.nd] = 1;
		for(auto k : rev[t.nd]) {
			e = t.cost + k.second;
			to = k.first;
			if(cE[to] > e) {
				cE[to] = e;
				pq.push({to, e});
			}
		}
	}
	targ = cS[E] - 1;
	fo(i, M) {
		a = m[i].a, b = m[i].b, w = m[i].w;
		e = cS[a] + cE[b] + w;
		if(e == cS[E]) {
			tadj[a].push_back(i);
			tadj[b].push_back(i);
		}
	}
	go(S);
	fo(i, M) {
		a = m[i].a, b = m[i].b, w = m[i].w;
		e = cS[a] + cE[b] + w;
		if(e == cS[E]) {
			if(bridge[i]) {
				puts("YES");
				continue;
			}
		}
		long long dif = e - targ;
		if(w - dif >= 1) printf("CAN %lld\n", dif);
		else puts("NO");
	}
	return 0;
}
