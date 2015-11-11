//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define snuke(it,x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++ it)

const int N = 500000 + 5;
std::set<std::pair<int,int> > edges;
std::vector<std::vector<int> > answer;
int n,m,dsu[N];

int Find(int x) { return dsu[x]==x ? x : dsu[x] = Find(dsu[x]); }

bool exist(int a,int b) {
  if (a>b) std::swap(a,b);
  return edges.find(std::make_pair(a,b)) != edges.end();
}

int main() {
  scanf("%d%d",&n,&m);
  for (int i = 0; i < m; ++ i) {
    int a,b;
    scanf("%d%d",&a,&b);
    if (a>b) std::swap(a,b);
    edges.insert(std::make_pair(a,b));
  }
  for (int i = 1; i <= n + 1; ++ i) {
    dsu[i] = i;
  }
  for (int s = 1; s <= n; s = Find(s+1)) {
    dsu[s] = s + 1;
    std::queue<int> queue;
    queue.push(s);
    std::vector<int> group;
    while (!queue.empty()) {
      int u = queue.front(); queue.pop();
      group.push_back(u);
      for (int v = Find(1); v <= n; v = Find(v+1)) {
        if (!exist(u,v)) {
          queue.push(v);
          dsu[v] = v + 1;
        }
      }
    }
    answer.push_back(group);
  }
  printf("%d\n",(int)answer.size());
  snuke(it,answer) {
    printf("%d",(int)it->size());
    snuke(itt,*it) {
      printf(" %d",*itt);
    }
    puts("");
  }
  return 0;
}
