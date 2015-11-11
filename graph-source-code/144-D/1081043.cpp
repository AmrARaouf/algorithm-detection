//Language: GNU C++


#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SZ(a) ((int)((a).size()))
#define REPSZ(i,v) REP(i,SZ(v))
#define ALL(a) (a).begin(),(a).end()
template<class T>void pv(T a,T b) {for(T i=a;i!=b;++i)cerr<<*i<<' ';cerr<<endl;}
typedef long long Int;
typedef vector<int> Vi;

int nextInt() {
  int x; scanf("%d", &x); return x;
}

typedef pair<int,int> pii;

const int MAX_N = (int) 1e5 + 10;

struct Edge {
  int id;
  int from, to, w;
};

vector< Edge > edge[MAX_N];

int N, M;
void main2() {
  N = nextInt();
  M = nextInt();
  int s = nextInt() - 1;
  REP(i, MAX_N) edge[i].clear();

  vector<Edge> org;
  REP(i, M) {
      int u = nextInt() - 1;
      int v = nextInt() - 1;
      if (u > v) swap(u, v);
      int w = nextInt();
      edge[u].push_back( (Edge){i, u, v, w} );
      edge[v].push_back( (Edge){i, v, u, w} );
      org.push_back( (Edge){i, u, v, w} );
  }
  int L = nextInt();

  const int inf = 1001001001;
  vector<int> memo(N, inf);

  set<int> ansV;
  vector<int> ansE1(M, -1);
  vector<int> ansE2(M, -1);
  
  
  priority_queue < pii > q;
  q.push( make_pair(0, s) );
  memo[s] = 0;

  for (; !q.empty(); ) {
      int dist = -q.top().first;
      int pos = q.top().second;

      q.pop();

      if (memo[pos] != dist) continue;
      if (dist == L) {
          ansV.insert(pos);
          continue;
      }
      if (dist > L) continue;

      for (int i = 0; i < (int)edge[pos].size(); i++) {
          const Edge &e = edge[pos][i];
          if (dist + e.w > L) {
              if (e.from < e.to) {
                  ansE1[e.id] = L - dist;
              } else {
                  ansE2[e.id] = L - dist;
              }
          }

          if (memo[e.to] > dist + e.w) {
              memo[e.to] = dist + e.w;
              q.push( make_pair(-memo[e.to], e.to) );
          }

      }
  }

  int ans = 0;
  ans += ansV.size();
  for (int i = 0; i < M; i++) {
      if (ansE1[i] != -1) {
          if (memo[org[i].to] + org[i].w - ansE1[i] < L)
              ansE1[i] = -1;
      }
      if (ansE2[i] != -1) {
          if (memo[org[i].from] + org[i].w - ansE2[i] < L)
              ansE2[i] = -1;
      }
      
      if (ansE1[i] != -1 && ansE2[i] != -1) {
          if (ansE1[i] + ansE2[i] == org[i].w) {
              ans++;
          } else if (ansE1[i] + ansE2[i] < org[i].w) {
              ans += 2;
          }
      } else if (ansE1[i] != -1 || ansE2[i] != -1)
          ans++;
  }
  cout << ans << endl;
}

int main() {
  for (;;) {
      main2();
      scanf(" ");
      if (feof(stdin)) break;
  }
  return 0;
}
