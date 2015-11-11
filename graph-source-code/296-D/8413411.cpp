//Language: GNU C++


#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define rofeach(i,x) for(rtype(x)i=x.rbegin();i!=x.rend();i++)
#define foreach(i,x) for(type(x)i=x.begin();i!=x.end();i++)
#define dbgs(x) cerr << (#x) << " --> " << (x) << ' '
#define dbg(x) cerr << (#x) << " --> " << (x) << endl
#define FOR(ii,aa,bb) for(int ii=aa;ii<=bb;ii++)
#define ROF(ii,aa,bb) for(int ii=aa;ii>=bb;ii--)
#define type(x) __typeof(x.begin())
#define rtype(x) __typeof(x.rbegin())
#define pii pair< int,int >
#define mod 1000000007
#define inf 1000000000
#define ll long long
#define pb push_back
#define mp make_pair
#define nd second
#define st first
#define endl '\n'

const int N = 1e5+5;
const int MAX = 1e9+5;

int sp[505][505],ans,q[505],i,j,k,n,m;

stack< ll > S;

int main(){

	scanf("%d",&n);

	FOR(i,1,n)
		FOR(j,1,n)
			scanf("%d",&sp[i][j]);

	FOR(i,1,n) scanf("%d",&q[n-i+1]);

	FOR(k,1,n){

		FOR(i,1,n)
			FOR(j,1,n)
				sp[q[i]][q[j]]=min(sp[q[i]][q[j]],sp[q[i]][q[k]]+sp[q[k]][q[j]]);
		
		ll ans=0;

		FOR(i,1,k)
			FOR(j,1,k)
				ans+=sp[q[i]][q[j]];
		
		S.push(ans);

	}

	while(!S.empty()){ cout << S.top() << ' '; S.pop(); }

	return 0;
}
