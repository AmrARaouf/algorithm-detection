//Language: MS C++




#define _CRT_SECURE_NO_DEPRECATE 
#pragma comment(linker, "/STACK:66777216")
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <string>
using namespace std;

typedef unsigned long long ll;
//typedef long long ll;
#define mk make_pair
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define fornn(i, q, n) for(ll i = (ll)q; i < (ll)n; i++)
#define times clock() * 1.0 / CLOCKS_PER_SEC

const ll inf = 1e15 + 7;
const ll dd = 5e5 + 7;
const ll mod = 1e9 + 7;
const ll p1 = 131797;
const ll p2 = 435493969;
struct pe{
	pair<ll, ll> a;
	pe(ll _x, ll _y){
		pair<ll, ll> t;
		t.first = _x, t.second = _y;
		a = t;
	}
	bool  operator<(const pe &b)const{
		return a < b.a;
	}
};
vector<pair<pe, ll> > S;
vector<ll> D1(1, 1), D2(1, 1);
map<pe, int> Q;
int in = 0;
vector<int> P[dd];
vector<ll> C;
void ok(string &s){
	forn(j, s.size())
		if (s[j] >= 'A' && s[j] <= 'Z')
			s[j] -= 'A';
		else
			s[j] -= 'a';
}

pe get(string &s){
	ll a, b;
	a = b = 0;
	forn(j, s.size())
		a += D1[j] * (s[j] + 1), b = (b + (D2[j] * (s[j] + 1)) % mod) % mod;
	return pe(a, b);
}

vector<ll> omn;
int ti[dd], ta = 1, cu;
void dfs(int v){
	if(ti[v] == ta)
		return;
	omn[v] = min(omn[v], C[v]);
	ti[v] = ta;
	forn(i, P[v].size()){
		int u = P[v][i];
		dfs(u);
		omn[v] = min(omn[v], omn[u]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	srand(time(0));

	D1.reserve(dd + 5), D2.reserve(dd + 5),	S.reserve(dd);
	forn(i, dd)
		D1.push_back(D1.back() * p1), D2.push_back((D2.back() * p2) % mod);
	int m, n;
	string s, t;
	cin>>m;
	forn(i, m){
		cin>>s;
		ll a = 0;
		forn(j, s.size())
			if(s[j] == 'r' || s[j] == 'R')
				a += dd;
		ok(s);
		S.push_back(mk(get(s), a + s.size()));
	}
	cin>>n;
	forn(i, n){
		cin>>s>>t;
		ll a, b;
		a = s.size();
		b = t.size();
		forn(j, s.size())
			if(s[j] == 'r' || s[j] == 'R')
				a += dd;
		forn(j, t.size())
			if(t[j] == 'r' || t[j] == 'R')
				b += dd;
		ok(s), ok(t);
		pe q = get(s), w = get(t);
		if(Q.find(q) == Q.end())
			Q[q] = in++, C.push_back(a);
		if(Q.find(w) == Q.end())
			Q[w] = in++, C.push_back(b);
		P[Q[q]].push_back(Q[w]);
	}
	omn.resize(in, inf);
	forn(i, in)
		dfs(i);
	ta++;
	forn(i, in)
		dfs(i);
	ta++;
	forn(i, in)
		dfs(i);
	ll resa = 0, resb = 0;
	forn(i, m){
		if(Q.find(S[i].first) == Q.end())
			resa += S[i].second % dd, resb += S[i].second / dd;
		else{
			int v = Q[S[i].first];
			resa += min(omn[v], S[i].second) % dd, resb += min(omn[v], S[i].second) / dd;
		}
	}
	cout<<resb<<' '<<resa;
}