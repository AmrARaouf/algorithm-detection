//Language: GNU C++0x


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
#define F first
#define S second
#define gcd(a,b) __gcd(a,b)

#define mod int(1e9 +7)
#define MAX int(1e5 + 10)

#define si(a) scanf("%d",&a);

#define VI vector<int>
#define VL vector<LL>
#define VS vector<string>
#define VC vector<char>

LL powmod(LL a,int b,int n){LL rm=1;while (b){if (b % 2) { rm = (rm * a) % n; }a = (a * a) % n;b /= 2;}return rm;}

std::vector<ii> edge[MAX];
int sz[MAX]={0},n,m,Source,u,v,w,l;
LL dp[MAX];
priority_queue<pair<LL,int>,vector <pair<LL,int> > > Heap;
bool Visited[MAX];

int main()
{
	SET(dp);
	memset(Visited,false,sizeof(Visited));
	cin >> n >> m >> Source;
	rep(i,m){
		si(u);si(v);si(w);
		edge[u].pb(mp(v,w));
		edge[v].pb(mp(u,w));
		sz[v]++; sz[u]++;
	}
	cin>>l;
	dp[Source] = 0;
	Heap.push(mp(0,Source));

	int vertex;
	while(1){
		vertex = -1;
		while( !Heap.empty()){
			if( Visited[Heap.top().S] == false ){
				vertex = Heap.top().S;
				Heap.pop();
				break;
			}
			Heap.pop();
		}
		if(vertex == -1) break;
		Visited[vertex] = true;
		for(int j=0;j<sz[vertex];++j){
			if(dp[edge[vertex][j].F] != -1) dp[edge[vertex][j].F] = min(dp[edge[vertex][j].F], edge[vertex][j].S + dp[vertex]);
			else dp[edge[vertex][j].F] = edge[vertex][j].S + dp[vertex];
			Heap.push(mp(-dp[edge[vertex][j].F],edge[vertex][j].F));
		}
	}


	int ans = 0,x1,x2;
	memset(Visited,false,sizeof(Visited));
	for(int i=1;i<=n;++i){
		if(dp[i] == l) Visited[i] = true;
		for(int j=0;j<sz[i];++j){
				x1 = x2 = -1;
				if(l>dp[i]){
					x1 = l - dp[i];
					if( x1 < edge[i][j].S){
						if(x1 + dp[i] <= dp[edge[i][j].F]+edge[i][j].S-x1){

						}
						else x1 = -1;
					}
					else x1 = -1;
				}
				if(l>dp[edge[i][j].F]){
					x2 = l - dp[edge[i][j].F];
					if( x2 < edge[i][j].S){
						if(x2 + dp[edge[i][j].F] <= dp[i] +edge[i][j].S-x2){
						}
						else x2 = -1;
					}
					else x2 =-1;
				}
				if(x1 != -1) ans++;
				if(x2 !=-1 && x1!=edge[i][j].S-x2) ans++;
				
		}
	}
	ans/=2;
	for(int i=1;i<=n;++i) ans += (Visited[i] == true);
	cout<<ans<<endl;
	return 0;
}











