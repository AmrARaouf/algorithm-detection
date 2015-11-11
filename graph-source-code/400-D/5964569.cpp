//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define PB push_back 
#define MP make_pair

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int MAX = 100001;
const int INF = 1000000000;

vii  adj[MAX];
int color[MAX];
int maxCol;
queue<int> q;



int segment[500];
int    type[500];
int K;
int res[500][500];

int getSegment(int v) {
  return ( upper_bound(segment, segment+K, v ) - segment) -1;
}

int Min(int a, int b) {
  return a<b?a:b;
}

void setDist(int v, int u, int val){
  int s1,s2;


  s1 = getSegment(v);
  s2 = getSegment(u);
  
  //printf("SetDist: %d@%d : %d@%d\n", v, s1, u, s2);
  res[s2][s1] = res[s1][s2] = Min(val, res[s1][s2] );
}

void bfs(int ver){

  if ( color[ver] ) return;

  int v, len;
  q.push( ver );
  
  maxCol++;
  while ( !q.empty() ) {
    v = q.front();q.pop();
    len = adj[v].size();

    color[v] = maxCol;

    for ( int i = 0; i<len; i++) {
      setDist( v, adj[v][i].first, adj[v][i].second );
      if ( color[ adj[v][i].first ] == 0 && adj[v][i].second == 0 )
        q.push( adj[v][i].first );
    }
  }
}

bool check(int n){
  int idx = 1;
  int clr;
  for ( int i = 0; i<K; i++){
    clr = color[idx];
    for (int j = 0; j<type[i]; j++ ) {
      if ( color[idx] != clr )
        return false;
      idx++;
    }
  }
  return true;
}

void floyd() {

  for ( int k=0; k<K; k++)
    for (int i=0; i<K; i++)
      for ( int j = 0; j<K; j++)
        if ( res[i][k] + res[k][j] < res[i][j] )
          res[i][j] = res[i][k] + res[k][j];
}


int main() {
  int n,m;
  int u,v,val;
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 0; i<K; i++)
    for ( int j = 0; j<K; j++)
      res[i][j] = INF;

  for ( int i = 0; i<K; i++)
    scanf("%d", &type[i]);
  segment[0] = 1;
  for ( int i = 1; i<K; i++)
    segment[i] = segment[i-1]+type[i-1];
  for ( int i = 0; i<m; i++) {
    scanf("%d%d%d", &u, &v, &val);
    adj[u].PB( MP(v,val) );
    adj[v].PB( MP(u,val) );
  }
  for ( int i = 1; i<=n; i++)
    bfs(i);

  if ( !check(n) ){
    printf("No\n");
    return 0;
  } 
 
  for ( int i = 0; i<K; i++)
    res[i][i] = 0;

  floyd();
  
  printf("Yes\n");
  for (int i = 0; i<K; i++) {
    for (int j = 0; j<K; j++)
      printf("%d ", res[i][j]>=INF? -1 : res[i][j]);
    printf("\n");
  }
  return 0;
}
