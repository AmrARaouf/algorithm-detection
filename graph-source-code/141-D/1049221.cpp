//Language: GNU C++


#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <cstring>
 
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <list>
 
#include <sstream>
#include <iostream>
#include <iomanip>
 
using namespace std;
 
typedef long long int64;
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define fore(i, a, n) for(int i = a; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) (a).size()
#define all(a) a.begin(), a.end()
#define LD (long double)
#define VI vector<int>
#define iss istringstream //>>
#define MAX 201000
 
const long double EPS = 1E-9;
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double PI = 2 * acos(.0);

int n, l, cont = 2;
int64 resp[MAX];
int path[MAX];
int flag[MAX];
vector< pair<int, int > > gr[MAX];
vector< pair<int, int > > idt[MAX];
map<int, int> mapa;

int64 DJ(int source, int target){
	forn(i, MAX) resp[i] = INF64;
	memset(path, -1, sizeof(path));
	memset(flag, -1, sizeof(flag));
	resp[source] = 0;
	priority_queue < pair < int, int64 > > cola;
	cola.push(mp (-resp[source], source));
	while(cola.size()){
		int nodo = cola.top().sc;
		cola.pop();
		if(nodo == target) return resp[nodo];
		forn(i, sz(gr[nodo])){
			//cout << nodo << " " << gr[nodo][i].sc << " + " << resp[nodo] << " "  << resp[gr[nodo][i].fs] << " " << gr[nodo][i].fs<< endl;
			if(gr[nodo][i].sc + resp[nodo] < resp[gr[nodo][i].fs]){
				resp[gr[nodo][i].fs] = gr[nodo][i].sc + resp[nodo];
				path[gr[nodo][i].fs] = nodo;
				if(idt[nodo][i].sc != -1) flag[gr[nodo][i].fs] = idt[nodo][i].sc;
				else flag[gr[nodo][i].fs] = -1;
				cola.push(mp( - resp[gr[nodo][i].fs], gr[nodo][i].fs));
			} 
		}
	}
	return -1;
}
int ss;
int conta = 0;
void countPath(int x){
	if(x == ss) return;
	countPath(path[x]);
	if(flag[x] != -1) conta++;
	return;
}
void printPath(int x){
	if(x == ss) return;
	printPath(path[x]);
	if(flag[x] != -1) cout << flag[x] << " ";
	return;
}
int main(){
	cin >> n >> l;
	int x, d, t, pp, fromA, toB;
	set<int> posi;
	cont = 1;
	forn(i, n){
		cin >> x >> d >> t >> pp;
		if( x - pp < 0 ) continue;
		if(mapa[ x - pp] == 0) mapa[x - pp] = cont++;
		if(mapa[x + d] == 0) mapa[x + d] = cont++;
		fromA = mapa[x - pp];
		toB = mapa[x + d]; 
		gr[fromA].pb( mp ( toB, t + pp));
		idt[fromA].pb(mp ( toB , i + 1));
		posi.insert(x - pp);
		posi.insert(x + d);
	}
	//cout << cont << endl;
	posi.insert(0);
	posi.insert(l);
	set<int>::iterator p = posi.begin();
	set<int>::iterator pm = p;
	int n = sz(posi);
	int ind = 0;
	if(mapa[0] == 0) mapa[0] = cont++;
	if(mapa[l] == 0) mapa[l] = cont++;
	//cout << cont << " " << mapa[0] << endl;
	while(p != posi.end()){
		fromA = mapa[*p];
		if(ind != 0){
			pm = p;
			pm--;
			d = mapa[*(pm)];
			gr[fromA].pb(mp(d, *p - *(pm)));
			idt[fromA].pb(mp(d, -1));
		}
		if(ind != n -1 ){
			pm = p;
			pm++;
			d = mapa[*(pm)];
			gr[fromA].pb(mp(d, *(pm) - *p));
			idt[fromA].pb(mp(d, -1));
		}
		ind++;
		p++;
	}
	int source = mapa[0];
	int target = mapa[l];	
	mapa.clear();
	cout << DJ(source, target) << endl;
	ss= source;
	countPath(target);
	cout << conta << endl;
	if(conta > 0) {
		printPath(target);
		cout << endl;
	}
	return 0;
}
