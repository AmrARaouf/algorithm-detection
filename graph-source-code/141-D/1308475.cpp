//Language: GNU C++


using namespace std;
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cmath>
#include<cstring>
#include<map>
#include<set>

typedef long long LL;
typedef vector<int> VI; typedef vector<VI> VVI;
typedef vector<bool> VB; typedef vector<VB> VVB;
typedef pair<int,int> pii; typedef vector<pii> VII;
#define IA(v) (v).begin()
#define IB(v) (v).end()
#define ALL(v) IA(v),IB(v)
#define REP(i, n) for (int i (0); i < (n); i ++)
#define FORIT(a,b, it) for(__typeof(b)it(a);it!=b;++it)
#define FOREACH(v, it) FORIT(IA(v),IB(v),it)
#define len(v) ((int)(v).size())
#define append push_back
#define _ make_pair
#define fi first
#define se second
#define add insert
#define remove erase
const int inf (1010101010);

int n; LL L;
struct brug { LL x, d, t, p; };
vector<brug> objs;

struct edge { int y, lbl; LL wt; };
edge ee[701005];
int ne (0);

VVI adj (701005);
LL d[701005];
int predv[701005], prede[701005];

void dijkstra(int s)
{
	d[s] = 0, predv[s] = -1, prede[s] = -1;
	set<pii> se; se.add(_(d[s], s));
	while (len(se))
	{
		int x ((*IA(se)).se);
		se.remove(IA(se));
		FOREACH(adj[x], it)
		{
			edge & e (ee[*it]);
			int y (e.y), label (e.lbl);
			LL wt (e.wt);
			
			if (d[x] + wt < d[y])
			{
				se.remove(_(d[y], y));
				d[y] = d[x] + wt;
				predv[y] = x, prede[y] = label;
				se.add   (_(d[y], y));
			}
		}
	}
}

VI pts; map<int, int> loc;
void ae(int x1, int x2, LL wt, int label)
{
	int id1 (loc[x1]), id2 (loc[x2]);
	edge e = {id2, label, wt};
	ee[ne] = e;
	adj[id1].append(ne);
	ne ++;
}

main()
{
	cin >> n >> L;
	pts.append(0), pts.append(L);
	REP(i, n)
	{
		int x, d, t, p; cin >> x >> d >> t >> p;
		brug br = {x, d, t, p};
		objs.append(br);
		pts.append(x - p), pts.append(x + p), pts.append(x + d);
	}
	sort(ALL(pts)); pts.remove(unique(ALL(pts)), IB(pts));
	REP(i, len(pts)) loc[pts[i]] = i;
	
	REP(i, n)
	{
		brug & br (objs[i]);
		int x (br.x), d (br.d), t (br.t), p (br.p);
		ae(x - p, x + d, p + t, i);
	}
	REP(i, len(pts) - 1)
	{
		ae(pts[i], pts[i + 1], pts[i + 1] - pts[i], -1);
		if (pts[i] >= 0) ae(pts[i + 1], pts[i], pts[i + 1] - pts[i], -1);
	}
	int s (loc[0]), t (loc[L]);
	REP(i, len(pts)) d[i] = 10101010101010LL;
	dijkstra(s);
	cout << d[t] << endl;
	VI bridges;
	for (int x (t); x != (s); x = predv[x])
	{
		if (prede[x] >= 0) bridges.append(prede[x]);
	}
	reverse(ALL(bridges));
	cout<<len(bridges)<<endl;
	FOREACH(bridges, it)
	{
		int br (*it);
		if(it!=IA(bridges))cout<<" ";
		cout<<(1+(*it));
	}
	cout<<endl;
}
