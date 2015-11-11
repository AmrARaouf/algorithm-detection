//Language: GNU C++


//============================================================================
// Name        : CPP.cpp
// Author      : Jose Carlos Gonzalez Fernandez
// Version     :
// Copyright   : Kaga2
// Description : Unlimited
//============================================================================

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#include <vector>
#include <limits>
#include <queue>
#include <cstdlib>
#include <map>
#include <math.h>
#include <limits>
#include <time.h>
#include <bitset>
#include <set>
#include <stack>
#include <complex>

using namespace std;
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define MP make_pair
#define PB push_back


#define MAXN 100005
vector<pair<int,int> > ady[MAXN];

set<int> lista[MAXN];
set<int>::iterator it;

ll D[MAXN];
const ll oo = 100000000000000LL;

bool marcas[MAXN];
int n,m,a,b,c;
priority_queue<pair<ll,int> > cola;
ll DISJTRA(){
	for(int i=0;i<n;i++) D[i] = oo;
	D[0] = 0;
	cola.push(MP(0,0));
	while(!cola.empty()){
		int v = cola.top().second; cola.pop();
		if (marcas[v]) continue;
		marcas[v] = 1;
		if (v == n-1) return D[v];

		int t = D[v];
		it = lista[v].lower_bound(t);
		if (*it == t){
			while (it != lista[v].end()){
				if (*it != t)
					break;
				t++;
				it++;
			}
		}

		for(int i=ady[v].size()-1;i>=0;i--){
			int u = ady[v][i].first;
			int p = ady[v][i].second;
			if (marcas[u]) continue;
			if (D[u] > t + p){
				D[u] = t + p;
				cola.push(MP(-D[u],u));
			}
		}
	}
	return -1;
}

int main(){

	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%d",&a,&b,&c);
		a--, b--;
		ady[a].PB(MP(b,c));
		ady[b].PB(MP(a,c));
	}

	for(int i=0;i<n;i++){
		scanf("%d",&m);
		while(m--){
			scanf("%d",&a);
			lista[i].insert(a);
		}
	}
	cout << DISJTRA() << endl;

	return 0;
}


