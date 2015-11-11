//Language: GNU C++


#include <cstdio>
#include <queue>
#include <cstring>
#include <functional>
#include <algorithm>
const int N = 100010;
std::pair<int,int> d[N];
int dis[N];
int degree[N];
int totEdge;
int edge[1000010][2];
void add(int a,int b) {
  edge[totEdge][0] = a;
  edge[totEdge++][1] = b;
}
void print() {
  printf("%d\n",totEdge);
  for(int i = 0; i < totEdge; i++) {
    printf("%d %d\n",edge[i][0],edge[i][1]);
  }
}
int main() {
  int n, k;
  scanf("%d%d",&n,&k);
  for(int i = 1; i <= n; i++) {
    scanf("%d",&d[i].first);
    d[i].second = i;
    dis[i] = d[i].first;
  }
  std::sort(d + 1, d + n + 1);
  int origin = d[1].second;
  if(d[1].first != 0) {
    return puts("-1"), 0;
  }
  if(d[2].first == 0) {
    return puts("-1") , 0;
  }
  std::queue<int> Queue;
  Queue.push(origin);
  int now = 0;
  int j = 2;
  for(int i = 2; i <= n; i++) {
    int sz = Queue.size(), it = 0;
    while(++it <= sz && j <= n) {
      int front = Queue.front(); Queue.pop();
      while(j <= n && degree[front] < k && d[j].first == now + 1) {
        add(front, d[j].second);
        ++degree[front];
        ++degree[d[j].second];
        Queue.push(d[j].second);
        j ++;
      }
    }
    if(j <= n && d[j].first != now + 2) {
      return puts("-1") , 0;
    }
    while(++it <= sz) {
      Queue.pop();
    }
    now ++;
  }
  print();
  return 0;
}
