//Language: GNU C++


#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <cassert>
#include <stack>
#include <queue>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

#define FORALL(i,a,b) for (int i = (a); i <= (b); i++)
#define FOR(i,n) for (int i=0;i<n;i++)
#define FORB(i,a,b) for (int i = (a); i >= (b); i--)
#define FORIN(it,type,b) for(type::iterator it = (b).begin(); it != (b).end(); it++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;

#define in cin
#define out cout

#define MAXN 100010
vector<int> E[MAXN];
vector<int> D[MAXN];

int F[MAXN]; //type

bool twospec[MAXN];
bool onespec[MAXN];

int main()
{
	int N,M;
	in >> N >> M;
	
	FOR(i,N) in >> F[i];
	FOR(j,M){
		int a,b;
		scanf("%d %d\n", &a, &b);
		//in >> a >> b;
		a--;b--;
		E[a].pb(b);
		D[b].pb(a);
	}
	
	memset(twospec,false,sizeof(twospec));
	memset(onespec,false,sizeof(onespec));
	
	//find all 2spec nodes
	queue<int> Q;
	FOR(i,N) if (F[i] == 2){Q.push(i);}
	while(!Q.empty()){
		int i = Q.front();Q.pop();
		//cout << i << endl;
		if (twospec[i]) continue;
		twospec[i] = true;
		
		int numD = D[i].size();
		FOR(x,numD){
			int j = D[i][x];
			if (twospec[j]) continue;
			if (F[i] == 1) continue;
			
			Q.push(j);
		}
	}
	
	//find all 1spec nodes
	assert(Q.empty());
	FOR(i,N) if (F[i] == 1) Q.push(i);
	while(!Q.empty()){
		int i = Q.front();Q.pop();
		if (onespec[i]) continue;
		onespec[i] = true;
		
		int numE = E[i].size();
		FOR(x,numE){
			int j = E[i][x];
			if (onespec[j]) continue;
			Q.push(j);
		}
	}
	
	//FOR(i,N) cout << onespec[i] << endl;
	//FOR(i,N) cout << twospec[i] << endl;
	
	FOR(i,N){
		if (onespec[i] && twospec[i]) cout << 1 << endl;
		else cout << 0 << endl;
	}
}









