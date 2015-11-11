//Language: GNU C++


#include <bits/stdc++.h>

#define ALL(v) v.begin(), v.end()
#define REP(i, a, b) for(int i = a; i < b; i++)
#define REPD(i, a, b) for(int i = a; i > b; i--)
#define REPLL(i, a, b) for(ll i = a; i < b; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define FORLL(i, a, b) for(ll i = a; i <= b; i++)
#define INF 1000000001

#define vit vector<int>::iterator
#define sit set<int>::iterator
#define vi vector<int>
#define vpii vector<pii >

#define ll long long
#define ld long double

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pld pair<ld, ld>
#define st first
#define nd second

#define EPS 1e-9
#define PI acos(-1.0)
#define MAXN 100008

using namespace std;

int z, n, m, a, b, c;

vector< pair<int, pii> > nbs[MAXN];
pii dist[MAXN];
int prv[MAXN];

void dijkstra(pii dist[], vector< pair<int, pii> > nbs[], int s) {
    priority_queue< pii, vector< pair<pii, int> >, greater<pair<pii, int> > > pq;
    pq.push(mp(mp(0, 0), s));
    REP(i, 0, n) dist[i] = mp(INF, INF);
    dist[s] = mp(0, 0);
    while(!pq.empty()) {
        pair<pii, int> c = pq.top(); pq.pop();
        if(c.st > dist[c.nd]) continue;
        REP(i, 0, nbs[c.nd].size()) {
            int nb = nbs[c.nd][i].st;
            pii dnb = nbs[c.nd][i].nd;
            dnb.st += dist[c.nd].st;
            dnb.nd += dist[c.nd].nd;
            if(dnb < dist[nb]) {
                dist[nb] = dnb;
                prv[nb] = c.nd;
                pq.push(mp(dist[nb], nb));
            }
        }
    }
}

set<pii > rep;
vpii edges;
set<pii > bad, ok;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	REP(i, 0, m) {
        cin >> a >> b >> c;
        --a; --b;
        nbs[a].pb(mp(b, mp(1, 1-c)));
        nbs[b].pb(mp(a, mp(1, 1-c)));
        if(c == 0) {
            bad.insert(mp(a, b));
            bad.insert(mp(b, a));

        }
        edges.pb(mp(a,b));
	}
	dijkstra(dist, nbs, 0);
	int v = n-1;
	while(v != 0) {
        if(bad.count(mp(prv[v], v))) {
            rep.insert(mp(prv[v], v));
        }
        ok.insert(mp(prv[v], v));
        ok.insert(mp(v, prv[v]));
        v = prv[v];
	}
	vector< pair< pii, int > > res;
	REP(i, 0, m) {
        a = edges[i].st;
        b = edges[i].nd;
        if(ok.count(mp(a, b))) {
            if(bad.count(mp(a, b))) res.pb(mp(mp(a, b), 1));
        }
        else {
            if(!bad.count(mp(a, b))) res.pb(mp(mp(a, b), 0));
        }

	}
	cout << res.size() << endl;
	REP(i, 0, res.size()) cout << 1+res[i].st.st << " " << 1+res[i].st.nd << " " << res[i].nd << endl;

    return 0;
}


