//Language: GNU C++


#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <deque>
#include <bitset>
#include <cctype>
#include <utility>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) For(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) For(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = (int) fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
    v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
    while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}

typedef pair<int, int> II;

const ld PI = acos(ld(-1.0));
const ld eps = 1e-9;

const int inf = (int)1e9 + 5;
const ll linf = (ll)1e17 + 5;
int dr[4] = {-2, -2, +2, +2};
int dc[4] = {+2, -2, +2, -2};
const ll mod = 1000000007;
const ll MAX = 1000000000;
#define maxn 200005
#define maxv 5005

int n, m, u, v, p, q, c;
int dad[maxn];
ll f[maxn];
vector<int> V[maxn];
int have[maxn];
vector<II> res;
set<II> SS;

int getdad(int u){
	if(dad[u] == u) return u;
	return dad[u] = getdad(dad[u]);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("in.txt","r",stdin);
//    freopen("dice.in","r",stdin);
//    freopen("dice.in","w",stdout);
    cin >> n >> m >> p >> q;
    For(i, 1, n) dad[i] = i;
    For(i, 1, m){
    	cin >> u >> v >> c;
    	SS.insert(mp(u, v));
    	SS.insert(mp(v, u));
    	int du = getdad(u);
    	int dv = getdad(v);
    	if(du == dv){
    		f[du] += c;
    		continue;
    	}
    	if(du > dv) swap(du, dv);
    	f[du] += f[dv] + c;
    	f[dv] = 0;
    	dad[dv] = du;
//    	cout << du << " " << dv << endl;
    }

    set<pair<ll, int> > S;
    set<pair<ll, int> >::iterator it;
    ms(have, 0);
    For(i, 1, n){
    	have[getdad(i)] = 1;
    }

    For(i, 1, n) if(have[i]){
    	S.insert(mp(f[i], i));
    }
    if(sz(S) < q){
    	cout << "NO" << endl;
    	return 0;
    }

    while(p > 0){
    	if((int)S.size() == q){
    		break;
    	}

		it = S.begin();
		pair<ll, int> P1 = *it;
		S.erase(it);
		it = S.begin();
		pair<ll, int> P2 = *it;
		S.erase(it);
		ll add = min(P1.fi + P2.fi + 1, MAX);
		u = P1.se; v = P2.se;
		if(u > v) swap(u, v);
		res.pb(mp(u, v));
		f[u] += f[v] + add;
		S.insert(mp(f[u], u));
		p--;
    }
    if((int)S.size() > q){
    	cout << "NO" << endl;
    	return 0;
    }

    if(p > 0 && !sz(SS) && !sz(res)){
    	cout << "NO" << endl;
    	return 0;
    }

    while(p > 0){
    	if(sz(res)){
    		res.pb(res[0]);
    	}
    	else {
    		II P = *SS.begin();
    		res.pb(P);
    	}
    	p--;
    }

    cout << "YES\n";
    Rep(i, sz(res)){
    	cout << res[i].fi << " " << res[i].se << "\n";
    }

    return 0;

}
