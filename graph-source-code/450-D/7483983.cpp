//Language: GNU C++


#include <iostream>
#include <ctype.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <memory>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <list>
#include <string>
#include <climits>
#include <map>
#include <set>
#include <sstream>
#include <valarray>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define setZero(a) memset(a,0,sizeof(a))
#define setNeg(a) memset(a,-1,sizeof(a))
#define setVal(a,v) memset(a,v,sizeof(a))
#define setArrVal(a,v,n) memset(a,v,(sizeof(a)/sizeof(a[0]))*n )
#define fa(i,n) for(int i=0;i<n;i++)
#define print(arr,n,str) {printf("%s : [ ",str); fa(_i,n){ printf("%lld ",arr[_i]); } printf("]\n");}
#define mod(n,m) ((n%m)+m)%m
#define pb(n) push_back(n)
#define mp(n,m) make_pair(n,m)
#define dbg(n) printf("Debug %d\n",n)
#define debg(s,n) printf("%s : %d\n",s,n)
#define ln printf("\n")
using namespace std;

int d2x[]={1,-1,0,0,1,-1,1,-1};
int d2y[]={0,0,1,-1,1,-1,-1,1};

int d3x[]={1,-1,0,0,0,0};
int d3y[]={0,0,1,-1,0,0};
int d3z[]={0,0,0,0,1,-1};

typedef long long ll ;

struct edge{
    ll from , to , w ;
    bool train ;
    bool used ;
    edge( ll from , ll to , ll w , bool train ):from(from),to(to),w(w),train(train){}
    bool operator < ( const edge & e ) const {
        return w > e.w ;
    }
};

typedef unsigned long long llu ;
typedef vector<int> vi ;
typedef vector<vi> vii ;
typedef vector<edge> ve ;
typedef vector<ve> vee ;
const double EPS = (1e-9);
const ll OO = 1e10;

int n , m , k ;
int cnt = 0 ;
vee adj ;
vector<ll> dist ;
bool visited[100005];

void disjkstra( int src );

int main()
{
    scanf("%d%d%d",&n,&m,&k);

    setVal( visited , true );
    adj = vee(n+1);
    dist = vector<ll>(n+1,OO);

    ll from , to , cost ;

    fa(i,m){
        scanf("%lld%lld%lld",&from,&to,&cost);
        adj[from].pb( edge( from , to , cost , false ) );
        adj[to].pb( edge( to , from , cost , false ) );
    }

    fa(i,k){
        scanf("%lld%lld",&to,&cost);
        adj[1].pb( edge( 1 , to , cost , true ) );
    }

    disjkstra(1);

    for(int i=2 ; i<=n ; ++i) if( visited[i] )++cnt ;

    cout<<k-cnt<<endl;

    return 0;
}

void disjkstra( int src )
{
    dist[src]=0;

    priority_queue<edge> q ;
    q.push( edge( -1 , src , 0 , false ) );

    while( !q.empty() ){
        edge e = q.top(); q.pop();

        if( e.w > dist[e.to] ){
            continue ;
        }

        fa(i,sz(adj[e.to])){

            edge ne = adj[e.to][i];

            if( dist[ne.to] > dist[ne.from] + ne.w ){

                visited[ ne.to ] = ne.train ;

                ne.w = dist[ne.to] = dist[ne.from] + ne.w ;
                q.push(ne);
            }
            else if(  dist[ne.to] == dist[ne.from] + ne.w ){
                visited[ ne.to ] = visited[ ne.to ] && ne.train ;
            }
        }
    }
}
