//Language: GNU C++



// (c) agaurav77
#include <iostream>
#include <map>          // find(), clear()
#include <vector>       // push_back(), pop_back(), front(), back()
#include <list>         // push_back(), pop_back(), front(), back() --- SEQUENTIAL ACCESS
#include <queue>        // push(), pop(), front(), back()
#include <utility>      // make_pair()
#include <algorithm>    // sort()
#include <cmath>
#include <cstdio>
#include <cstdlib>      // malloc()
#include <sstream>
#include <string>
#include <cstring>
#define mp make_pair
#define pb push_back
using namespace std;

#define t(N) scanf("%d", &N);
#define f(i,a,b) for(int i=a;i <= b; ++i)
#define str string
#define ll long long 
#define inMap(a,b) (a.find(b) != a.end())

// max limit
// d[i][j] is the number of edges between vertices (i, j)
// through the shortest path
int d[3005][3005];

// adjacency matrix
vector<int> adj[3005];

int main() {
  // set d[i][j] to -1 for every case
  memset(d, -1, sizeof(d));

  // take number of vertices
  int n;
  cin >> n;

  // take number of edges
  int m;
  cin >> m;

  // take undirected edges from input
  f(i, 1, m) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    adj[tmp1-1].pb(tmp2-1);
    adj[tmp2-1].pb(tmp1-1);
  }

  // run a bfs and update the number of edges
  // for every vertex pair (i, j)
  // do this for every vertex
  f(i, 0, n-1) {
    // bfs for node i
    queue<int> Q;
    Q.push(i);
    d[i][i] = 0;
    while (Q.empty() == false) {
      int tp = Q.front();
      Q.pop();
      
      // for every node adjacent to tp
      // go and update its d[tp][node]
      vector<int>::iterator j;
      for (j = adj[tp].begin(); j != adj[tp].end(); ++j) {
        int node = *j;
        if (d[i][node] == -1) {
          d[i][node] = d[i][tp]+1;
          Q.push(node);
        }
      }
    }
  }
  // done computing all d[i][j] necessary

  // take a1, b1, d1
  int a1, b1, d1;
  cin >> a1 >> b1 >> d1;
  
  // take a2, b2, d2
  int a2, b2, d2;
  cin >> a2 >> b2 >> d2;

  // make a1, a2, b1, b2 0-indexed
  a1--;a2--;b1--;b2--;

  // declare ans to be inf
  // since at most m edges can be traversed for any travel from (i, j)
  // let us have ans greater than m
  int ans = m+1;

  // run normally
  // for all possible pairs (i, j) that may be shared
  f(i, 0, n-1) {
    f(j, 0, n-1) {
      if (d[a1][i]+d[i][j]+d[j][b1] <= d1 && d[a2][i]+d[i][j]+d[j][b2] <= d2) {
        ans = min(ans, d[a1][i]+d[a2][i]+d[i][j]+d[j][b1]+d[j][b2]);
      }
    }
  }

  // run for swapped a1, b1
  swap(a1, b1);
  f(i, 0, n-1) {
    f(j, 0, n-1) {
      if (d[a1][i]+d[i][j]+d[j][b1] <= d1 && d[a2][i]+d[i][j]+d[j][b2] <= d2) {
        ans = min(ans, d[a1][i]+d[a2][i]+d[i][j]+d[j][b1]+d[j][b2]);
      }
    }
  }
  swap(a1, b1);

  // run for swapped a2, b2
  swap(a2, b2);
  f(i, 0, n-1) {
    f(j, 0, n-1) {
      if (d[a1][i]+d[i][j]+d[j][b1] <= d1 && d[a2][i]+d[i][j]+d[j][b2] <= d2) {
        ans = min(ans, d[a1][i]+d[a2][i]+d[i][j]+d[j][b1]+d[j][b2]);
      }
    }
  }
  swap(a2, b2);

  // run for both swapped
  swap(a1, b1);
  swap(a2, b2);
  f(i, 0, n-1) {
    f(j, 0, n-1) {
      if (d[a1][i]+d[i][j]+d[j][b1] <= d1 && d[a2][i]+d[i][j]+d[j][b2] <= d2) {
        ans = min(ans, d[a1][i]+d[a2][i]+d[i][j]+d[j][b1]+d[j][b2]);
      }
    }
  }
  swap(a1, b1);
  swap(a2, b2);
  

  // check for direct non shared paths
  if (d[a1][b1] <= d1 && d[a2][b2] <= d2) {
    ans = min(ans, d[a1][b1]+d[a2][b2]);
  }
  if (d[a1][b1] <= d1 && d[b2][a2] <= d2) {
    ans = min(ans, d[a1][b1]+d[b2][a2]);
  }
  if (d[b1][a1] <= d1 && d[a2][b2] <= d2) {
    ans = min(ans, d[b1][a1]+d[a2][b2]);
  }
  if (d[b1][a1] <= d1 && d[b2][a2] <= d2) {
    ans = min(ans, d[b1][a1]+d[b2][a2]);
  }

  // if nothing affected ans from the previous value (m+1)
  // something is wrong
  // possibly no path then
  if (ans > m) {
    ans = -1;
  } else {
    ans = m-ans;
  }
  // because you have to find the max number of edges to delete
  // thats the total edges - (min number of edges to keep)

  cout << ans << endl;

  return 0;
}
 

