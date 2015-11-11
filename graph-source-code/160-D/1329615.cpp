//Language: GNU C++


#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

//bool used2[100002];
int used2[100002];
template <int N> struct LinkingCuttingTree {
	struct node {
		int pcost, ncost, mx, jump, pnum, nnum, jnum, mark;
		bool rev;
		node *l, *r, *p, *path;
	};
	
	typedef node * pnode;
	node tr[N + 1];
	const pnode pNull;
	pnode tmp[N + 1];

	LinkingCuttingTree() : pNull(tr + N) {
		tr[N].pcost = tr[N].ncost = tr[N].mx = tr[N].jump = -2000000000;
		tr[N].jnum = tr[N].pnum = tr[N].nnum = -1;
	}

	inline void upd(pnode v) {
		if (v == pNull) return;
		v->mx = max(v->l->mx, v->r->mx);
		if (v->pcost > v->mx) v->mx = v->pcost;
		if (v->ncost > v->mx) v->mx = v->ncost;
		v->l->p = v; v->r->p = v;
	}
	inline void push(pnode v) {
		if (v == pNull) return;
		if (v->rev) {
			v->l->rev ^= 1;
			v->r->rev ^= 1;
			v->rev = 0;
			swap(v->l, v->r);
			swap(v->pcost, v->ncost);
			swap(v->pnum, v->nnum);
		}
		if (v->mark < INF) {
			if (v->pnum != -1) used2[v->pnum] = min(used2[v->pnum], v->mark);
			if (v->nnum != -1) used2[v->nnum] = min(used2[v->nnum], v->mark);
			v->l->mark = min(v->l->mark, v->mark); v->r->mark = min(v->r->mark, v->mark);
			v->mark = INF;
		}
	}
	inline void rotate(pnode v) {
		if (v == pNull || v->p == pNull) return;
		pnode f = v->p;
		if (f->l == v) {
			pnode old = v->r;
			v->r = f;
			f->l = old;
			v->path = f->path; v->jump = f->jump; v->jnum = f->jnum;
			v->p = f->p;
			if (f->p->l == f) f->p->l = v; else
			f->p->r = v;
			upd(f); upd(v);
		} else {
			pnode old = v->l;
			v->l = f;
			f->r = old;
			v->p = f->p;
			v->path = f->path; v->jump = f->jump; v->jnum = f->jnum;
			if (f->p->l == f) f->p->l = v; else
			f->p->r = v;
			upd(f); upd(v);
		}
	}
	inline void splay(pnode v) {
		if (v == pNull) return;
		int k = 0;
		pnode q = v;
		while (q != pNull) {
			tmp[k++] = q;
			q = q->p;
		}
		FORD(i, k - 1, 0) {
			push(tmp[i]);
		}
		while (v->p != pNull) {
			if (v->p->p == pNull) {
				rotate(v);
				break;
			}
			if ((v->p->p->l == v->p->p) == (v->p->l == v)) {
				rotate(v->p);
				rotate(v);
			} else {
				rotate(v);
				rotate(v);
			}
		}
	}
	inline void expose(pnode v) {
		pnode root = pNull;
		while (v != pNull) {
			splay(v);
			if (v->r != pNull) {
				pnode w = v->r;
				v->r = w->p = pNull;
				push(w);
				while (w->l != pNull) {
					w = w->l;
					push(w);
				}
				splay(w);
				w->path = v; w->jump = w->pcost; w->pcost = -2 * INF; 
				v->ncost = -2 * INF; 
				w->jnum = w->pnum; w->pnum = -1;
				v->nnum = -1;
				upd(v);
			}
			v->r = root; root->pcost = root->jump; v->ncost = root->jump; 
			root->pnum = root->jnum; v->nnum = root->jnum;
			upd(root); upd(v);
			root = v;
			push(root);
			while (root->l != pNull) {
				root = root->l;
				push(root);
			}
			splay(root);
			v = v->path;
		}
	}
	inline void makeRoot(pnode v) {
		expose(v); splay(v);
		v->rev = 1;
		push(v);
	}
	inline void link(pnode v1, pnode v2, int w, int num) {
		makeRoot(v1);
		v1->path = v2; v1->jump = w; v1->jnum = num;
	}
	inline void cut(pnode v1, pnode v2) {
		makeRoot(v1); expose(v1);
		splay(v2); v2->path = pNull;
	}
};

int a,b,c,d,i,j,n,m,k;
LinkingCuttingTree<100000> q;
int pr[100001], rn[100001];
pii ed[100001], ee[100001];
int used[100001];
int p(int v) {
	if (pr[v] == -1) return v; else
	return pr[v] = p(pr[v]);
}
inline bool un(int a, int b) {
	a = p(a); b = p(b);
	if (a == b) return 0;
	if (rn[a] <= rn[b]) {
		pr[a] = b;
		if (rn[a] == rn[b]) ++rn[b];
	} else {
		pr[b] = a;
	}
	return 1;
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%d%d", &n, &m);
	memset(pr, -1, sizeof(pr));
	rept(i, m) {
		scanf("%d%d%d", &a, &b, &c); --a; --b;
		ee[i] = mp(a, b);
		ed[i] = mp(c, i);
	}
	rept(i, n) {
		q.tr[i].l = q.tr[i].r = q.tr[i].p = q.tr[i].path = q.pNull;
		q.tr[i].pcost = q.tr[i].ncost = q.tr[i].mx = -2 * INF;
		q.tr[i].pnum = q.tr[i].nnum = -1;
	}
	sort(ed, ed + m);
	rept(i, m) {
		a = ee[ed[i].y].x, b = ee[ed[i].y].y;
		if (un(a, b)) {
			q.link(q.tr + a, q.tr + b, ed[i].x, ed[i].y);
			used[ed[i].y] = 1;
		}
	}
	
	memset(used2, 63, sizeof(used2));
	rept(i, m) {
		if (used[ed[i].y]) continue;
		a = ee[ed[i].y].x, b = ee[ed[i].y].y;
		q.makeRoot(q.tr + a);
		q.expose(q.tr + b);
		q.splay(q.tr + b);
		if (q.tr[b].mx == ed[i].x) {
			used[ed[i].y] = 1;
			used2[ed[i].y] = ed[i].x;
			q.tr[b].mark = ed[i].x;
			q.push(q.tr + b);
		}
	}

	rept(i, n) {
		q.splay(q.tr + i);
	}

	rept(i, m) {
		if (used2[ed[i].y] == ed[i].x) used[ed[i].y] = 2;
	}

	rept(i, m) {
		if (used[i] == 1) printf("any\n"); else
		if (used[i]) printf("at least one\n"); else
		printf("none\n");
	}
}
