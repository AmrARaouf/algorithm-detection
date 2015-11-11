//Language: GNU C++


/*#include <cstdio>
#include <queue>
#include <vector>
#include <bitset>

using namespace std;

#define rint register int
#define pb push_back
#define mp make_pair
#define f first
#define ff first.first
#define fs first.second
#define s second
#define i64 long long

typedef pair < pair < int , long long > , int > HeapP;
typedef pair <  int , long long > P;
const int MAX = 100014;
const char IN[]="D.in";
const char OUT []= "D.out";
const int NEFACUT = -1 ;

i64 dist[MAX];
int n,k;
bitset <MAX> used;

vector <P> gr[MAX];
vector <P> tren;
struct cmp{
    bool operator()(const HeapP &a,const HeapP &b){
        return (a.fs>b.fs);
    }
};
priority_queue < HeapP , vector < HeapP > , cmp > h;

void dijkstra()
{
    h.push(mp(mp(1,0),0));
    for ( rint i = 1 ; i <= n ; ++ i )
        dist[i]=NEFACUT;
    while( !h.empty( ) ){
        HeapP fata = h.top();
        h.pop();
        if( dist[fata.ff] != NEFACUT )
            continue;
        dist[fata.ff]=fata.fs;
        if( fata.s )
            used[fata.s]=1;
        for( rint i = 0 ; i < (int)gr[fata.ff].size( ) ; ++ i ){
            P graf = gr[fata.ff][i];
            h.push( mp ( mp( graf.f , graf.s+fata.fs ) , 0 ) );
        }
        if( fata.ff == 1 )
            for( rint i = 0 ; i < (int) tren.size( ) ; ++ i ){
                P vagon = tren[i];
                h.push( mp ( mp ( vagon.f, vagon.s+fata.fs ) , i + 1 ) );
            }

    }
}
int main( )
{
    int m;
    //freopen( IN , "r" , stdin );
    //freopen( OUT , "w" , stdout );
    scanf( "%d %d %d ", &n , &m , &k );
    for( ; m ; --m ){
        int x,y;
        i64 z;
        scanf( "%d %d %I64d ", &x , &y , &z );
        gr[x].pb(mp(y,z));
        gr[y].pb(mp(x,z));
    }
    for( rint i = 1 ; i <= k ; ++ i ){
        int dest;
        i64 cost;
        scanf( "%d %I64d ", &dest , &cost );
        tren.pb(mp(dest,cost));
    }
    dijkstra();
    i64 ans = 0 ;
    for( rint i = 1 ; i <= k ; ++ i )
        ans = ans + ( used[i]!=1 );
    printf("%I64d\n",ans);
}
*/
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<functional>
#include<map>
#include<cstring>
#include<iostream>
#define pii pair<long long int,int>
#define tpi pair< pair<long long int,int> , int>
#define d first.first
#define idx first.second
#define mp(a,b) make_pair(a,b)
using namespace std;
vector <pii> graph[100005];
vector <pii> trains;
int n,m,k;
long long dist[100005];
bool used[100005];
void dijsktra() {
	priority_queue <tpi,vector<tpi> , greater<tpi> > pq;
	pq.push(mp(mp(0,1),0));
	int i,j,u,v;
	tpi w;
	pii w1;
	memset(dist,-1,sizeof(dist));
	memset(used,false,sizeof(used));
	while (!pq.empty()) {
		w=pq.top(); pq.pop();
		if (dist[w.idx]!=-1) {
            assert(dist[w.idx]<=w.d);
            continue;
		}
		dist[w.idx]=w.d;
		if (w.second !=0) used[w.second]=true;
		for (i=0;i<graph[w.idx].size();i++) {
			w1=graph[w.idx][i];
			pq.push(mp(mp(w1.first+w.d,w1.second),0));
		}
		if (w.idx==1) {
			for (i=0;i<trains.size();i++) {
				w1=trains[i];
				pq.push(mp(mp(w1.first+w.d,w1.second),i+1));
			}
		}
	}
}

int main() {
	scanf("%d %d %d",&n,&m,&k);
	long long j;
	int i,u,v;
	long long ans=0;
	for (i=0;i<m;i++) {
		scanf("%d %d",&u,&v);
		cin >> j;
		graph[u].push_back(mp(j,v));
		graph[v].push_back(mp(j,u));
	}
	for (i=0;i<k;i++) {
		scanf("%d",&u);
		cin>>j;
		trains.push_back(mp(j,u));
	}
	dijsktra();
	for (i=1;i<=k;i++) {
		if (used[i]==false) ans+=1;
	}
	cout<<ans<<endl;
	return 0;
}

