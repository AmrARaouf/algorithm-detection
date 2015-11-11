//Language: GNU C++


#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define each(i,c) for(__typeof(c.begin()) i=c.begin();i!=c.end();i++)
#define pb push_back
#define mp make_pair
#define all(c) c.begin(),c.end()
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
const int inf=(int)1e9;
const double EPS=1e-9, INF=1e12;

int n, m, k;
set<int> e[100000], f[100000];
vi ans;

void rec(int c){
	ans.pb(c);
	if(e[c].size()){
		int n = *e[c].begin();
		each(i, e[c]) e[*i].erase(c);
		rec(n);
	}
	else{
		rep(i, ans.size()) if(f[c].count(ans[i])){
			cout << ans.size() - i << endl;
			for(int j = i; j < ans.size(); j++)
			cout << ans[j] + 1 << (j==ans.size()-1?"\n":" ");
			exit(0);
		}
	}
}

int main(){
	cin >> n >> m >> k;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		e[a].insert(b);
		e[b].insert(a);
	}
	rep(i, n) f[i] = e[i];
	rec(0);
	
	return 0;
}
