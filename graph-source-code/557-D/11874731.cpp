//Language: GNU C++


//Why can't I do these problems during the contest :(

#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ull unsigned long long int
#define maxN 100005
#define maxK 500
#define maxW 1005
#define pb push_back
#define mp make_pair
#define INF (((ll)1000000000) * ((ll)1000000000))
#define e 2.7182818284590452353602874
#define maxT 1000000
#define inf 0x7fffffff
#define inff 100000
#define ff first
#define ss second
#define MOD 1000000007
#define rep(i,N) for(int i=0;i<N;i++)
#define pii pair<int,int>
#define clear_array(A) memset(A,0,sizeof A)

ll nc3(ll n) {
	n=n*(n-1)*(n-2);
	return n/6;
}

vector<int> V[maxN];
int cc=1;
ll red[maxN],blue[maxN],color[maxN];
int size[maxN],vis[maxN];
bool bipartite[maxN];

int reverse(int color) {
	if(color==0) {
		blue[cc]++;
		return 1;
	}
	red[cc]++;
	return 0;
}

//color all nodes of bipartite graph
//graph is bipartite if chromatic number of graph is 2
bool bfs(int node) {
	vis[node]=1;
	color[node]=0;
	red[cc]++;
	size[cc]++;
	queue<int> Q;
	while(!Q.empty())
		Q.pop();
	Q.push(node);
	while(!Q.empty()) {
		node=Q.front();
		//cout<<"node is "<<node<<"\n";
			for(int i=0;i<V[node].size();i++) {
				int v=V[node][i];
				//cout<<"neighbor is "<<v<<"\n";
				if(color[v]==color[node]) {
					//cout<<"same color found \n";
					return false;
					}
				if(vis[v]==0) {
					//cout<<"visiting vertice "<<v<<"\n";
					size[cc]++;
					Q.push(v);
					vis[v]=1;
					color[v]=reverse(color[node]);
					}
			}
		Q.pop();
		}
	return true;
}



int main() {

cin.sync_with_stdio(0);
cin.tie(0);

ll n,m;
cin>>n>>m;

if(m==0) {
	cout<<3<<" "<<nc3(n)<<"\n";
	return 0;
	}


for(int i=1;i<=n;i++)
	V[i].clear();	//Always clear vector

for(int i=0;i<m;i++) {
	int a,b;
	cin>>a>>b;
	V[a].pb(b);
	V[b].pb(a);
}


//simple cycle of odd length

memset(bipartite,false,sizeof bipartite);
memset(color,-1,sizeof color);
for(int i=1;i<=n;i++)
	if(vis[i]==0) {
		bipartite[cc]=bfs(i);	//determine if ith component is bipartite
		//cout<<cc<<"th connected component is "<<bipartite[cc]<<"\n";
		cc++;
	}

//if component is bipartite with size>1 =>already odd cycle exists 
for(int i=1;i<=cc;i++)
	if(!bipartite[i] && size[i]>2) {
		cout<<"0 1\n";		//Add no edges in 0 ways
		return 0;
		}

ll ans=0;
int edges=-1;
for(int i=1;i<=cc;i++)
	if(bipartite[i] && size[i]>2) {
		edges=1;
		ans+=(red[i]*(red[i]-1))/2+(blue[i]*(blue[i]-1))/2;
		}

if(edges!=-1) {
	cout<<edges<<" "<<ans<<"\n";
	return 0;
	}

//final case when all components have less than 3 vertices
cout<<2<<" "<<m*(n-2)<<"\n";

return 0;
}
