//Language: MS C++


#include<stdio.h>
#include<iostream>
#include<sstream>
#include<queue>
#include<math.h>
#include<stdlib.h>
#include<stack>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
#include<time.h>
#include<set>
#include<vector>
#include<numeric>
#include<iomanip>
#include<bitset>
using namespace std;

#define All(a) a.begin(), a.end()
#define _2d(a,row,col,type) type**a=new type*[row]; for (int i=0;i<row;i++) a[i]=new type[col];
#define rep(i,n) for(int i=0;i<int(n);i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define repi(i,a,n) for(int i=int(a);i<int(n);i++)
#define clr(a, n) memset(a, n, sizeof(a));
#define scn(a,n) rep(i,n) cin>>a[i];
#define scn2(a,row,col) rep(i,row) rep(j,col) cin>>a[i][j];
#define prn(a,n) rep(i,n-1) cout<<a[i]<<" "; cout<<a[n-1]<<endl;
#define prn2(a,row,col) rep(i,row){rep(j,col-1) cout<<a[i][j]<<" "; cout<<a[i][col-1]<<endl;}
#define dri(x) scanf("%d",&(x))
#define drii(x,y) scanf("%d%d",&(x),&(y))
#define drl(x) scanf("%I64d",&(x))
#define drll(x,y) scanf("%I64d%I64d",&(x),&(y))
#define mp(a, b) make_pair(a, b)
#define Odd(x) x%2!=0
#define Even(x) x%2==0
#define Pi 3.14
#define INF 2000000000 // 2 billion

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, string> is;
typedef vector<pii> vii;

#define FilesX
#define TimeX

/*---------------------------*/

vector<vi > adj(26);
int vis[26];
vi topo;

bool dfs1(int i){
	vis[i] = 1;
	rep(j, adj[i].size()){
		if (vis[adj[i][j]] == 1) return true;
		if (vis[adj[i][j]] == 2) continue;
		if (dfs1(adj[i][j])) return true;
	}
	vis[i] = 2;
	return false;
}

void dfs(int i){
	vis[i] = true;
	rep(j, adj[i].size())
		if (!vis[adj[i][j]]) dfs(adj[i][j]);
	topo.push_back(i);
}

void solution(){
	int n;
	cin>>n;
	vs a(n);
	rep(i, n)
		cin>>a[i];
	rep(i, n-1){
		rep(j, min(a[i].length(), a[i+1].length()))
			if (a[i][j] != a[i+1][j]){
				adj[a[i][j] - 'a'].push_back(a[i+1][j] - 'a');
				break;
			}
	}
	rep(i, n-1){
		repi(j, i+1, n){
			if (a[i].length() > a[j].length() && a[i].substr(0, a[j].length()) == a[j]){
				cout<<"Impossible";
				return;
			}
		}
	}
	rep(i, 26){
		clr(vis, false);
		if (dfs1(i)) {cout<<"Impossible"; return;}
	}
	clr(vis, false);
	rep(i, 26){
		if (!vis[i]) dfs(i);
	}
	reverse(All(topo));
	rep(i, topo.size()) cout<<char(topo[i] + 'a');
	cout<<endl;
}

/*---------------------------*/
int main(){
	#ifdef Files
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	double beg=clock();

	ios::sync_with_stdio(false);
	solution();

	#ifdef Time
	cout << endl;
	double end=clock();
	printf("*** Total time = %.3f sec ***", (end - beg) / CLOCKS_PER_SEC);
	#endif
	return 0;
}