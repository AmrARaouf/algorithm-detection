//Language: GNU C++


/* Author : RISHAV GOYAL */

#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define UL unsigned long long int

#define imax INT_MAX
#define imin INT_MIN
#define LLmax LLONG_MAX
#define LLmin LLONG_MIN

#define FOR(i,a,b) for(int i= (int)a; i<= (int)b; i++)
#define rep(i,n) for(int i= int(1); i<= (int)n; i++)
#define FORd(i,a,b,d) for(int i=(int)a; i<= (int)b; i+=(int)d)

#define pr() printf("Reached here 1...\n");
#define pr1() printf("Reached here 2...\n");

#define CLR(a) memset(a,0,sizeof(a));
#define SET(a) memset(a,-1,sizeof(a));

#define str strlen
#define pb(x) push_back(x)
#define mp make_pair
#define ii pair<int,int>
#define ll pair<LL,LL>

#define F first
#define S second
#define gcd(a,b) __gcd(a,b)

#define mod int(1e9 + 7)
#define MAX int(1e5 + 10)

#define si(a) scanf("%d",&a);

#define VI vector<int>
#define VL vector<LL>
#define VS vector<string>
#define VC vector<char>

LL powmod(LL a,int b,int n){LL rm=1;while (b){if (b % 2) { rm = (rm * a) % n; }a = (a * a) % n;b /= 2;}return rm;}

set<ii> myset;
std::vector<ii> edge[MAX];
VI coming[MAX];
int dp[MAX],sz[MAX]={0},visited[MAX]={0};
int main()
{
	SET(dp);
	int n,m,u,v,c,q,k[MAX];
	cin >> n >> m;
	rep(i,m){
		cin >> u >> v >> c;
		edge[u].pb(mp(v,c));
		edge[v].pb(mp(u,c));
		sz[u]++; sz[v]++;
	}
	for(int i = 1; i<=n;++i){
		cin >> k[i];
		for(int j=0;j<k[i];++j){
			si(q); 
			coming[i].pb(q);
		}
	}
	myset.insert(mp(0,1));

	dp[1] = 0;
	while(1){

		ii tmp ;
		int id = -1,tm ;
		while(!myset.empty()){
			tmp = (*myset.begin());
			
			if( visited[tmp.S] == 0 ) {
				tm = tmp.F;
				id = tmp.S;
				break;
			}
			myset.erase(myset.find(tmp));
		}
		if(id==-1) break;
		myset.erase(myset.find(tmp));

		dp[id] = tm;
		for(int j=0;j<k[id];++j){
			if(coming[id][j]<tm) continue;
			if( tm != coming[id][j] ) break;
			tm++;
		}
		
		visited[id] = 1;
		for(int j = 0; j< sz[id];++j){
			int id2 = edge[id][j].F;
			if( !visited[id2] && (dp[id2]==-1 || dp[id2]>tm+edge[id][j].S)) {
				dp[id2]=tm+edge[id][j].S;
				myset.insert(mp(dp[id2],id2));
			}
		}
	}
	cout << dp[n] << endl;

	return 0;
}
















