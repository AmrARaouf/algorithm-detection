//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100000 + 10;
const int maxm = 100000 + 10;

struct Edge{
  int from, to, weight, id;
  bool operator < (const Edge& rhs) const{
      return weight < rhs.weight;
  }
};

struct E {
  int to, next, id;
};

int pa[maxn], ans[maxn];
Edge e[maxm];

int findset(int x){
    return pa[x] == x ? x : (pa[x] = findset(pa[x]));
}

struct Bridge {
  int m;
  int head[maxn];
  E edges[maxm * 2];
  int pre[maxn], dfs_clock;

  void init(int n) {
    m = dfs_clock = 0;
    for(int i = 1; i <= n; i ++) {
      head[i] = -1; pre[i] = 0;
    }
  }

  void AddEdge(int from, int to, int id) {
    edges[m].next = head[from];
    edges[m].to = to; edges[m].id = id;
    head[from] = m ++;
  }

  int dfs(int u, int fa) {
    int lowu = pre[u] = ++ dfs_clock;
    for(int i = head[u]; i != -1; i = edges[i].next) {
      int v = edges[i].to;
      if(!pre[v]) {
        int lowv = dfs(v, edges[i].id);
        lowu = min(lowu, lowv);
        if(lowv > pre[u]) {
          ans[edges[i].id] = 2;
        }
      }else if(edges[i].id != fa) {
        lowu = min(lowu, pre[v]);
      }
    }
    return lowu;
  }

};

Bridge br;

int N, M;
char res[][20] = {"none", "at least one", "any"};

void init() {
  for(int i = 1; i <= N; i ++) {
    pa[i] = i;
  }
}

void Pre(){
  init();
  for(int i = 0; i < M; i ++) {
    scanf("%d%d%d", &e[i].from, &e[i].to, &e[i].weight);
    e[i].id = i;
  }
  sort(e, e + M);
  br.init(N);
}

int main()
{
  while(scanf("%d%d", &N, &M) != EOF) {
    Pre();
    for(int i = 0; i < M; ) {
      int start = i;
      while(i < M && e[i].weight == e[start].weight) i ++;
      for(int j = start; j < i; j ++) {
        int u = e[j].from, v = e[j].to;
        int x = findset(u), y = findset(v);
        if(x != y) {
          br.AddEdge(x, y, e[j].id);
          br.AddEdge(y, x, e[j].id);
          ans[e[j].id] = 1;
        }
        else ans[e[j].id] = 0;
      }
      for(int j = start; j < i; j ++) {
        int x = findset(e[j].from), y = findset(e[j].to);
        if(x != y && !br.pre[x]) br.dfs(x, -1);
      }
      for(int j = start; j < i; j ++) {
        int u = e[j].from, v = e[j].to;
        int x = findset(u), y = findset(v);
        if(x != y) {
          pa[y] = x;
          br.head[x] = br.head[y] = -1;
          br.pre[x] = br.pre[y] = 0;
        }
      }
      br.m = br.dfs_clock = 0;
    }
    for(int i = 0; i < M; i ++) {
      printf("%s\n", res[ans[i]]);
    }
  }
  return 0;
}
