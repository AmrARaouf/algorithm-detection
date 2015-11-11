//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<stack>

using namespace std;

int n;
vector<pair<int, int> > v[100001];
int parent[100001];
int depth[100001];

long long dp[2][100001];

long long cost(int node, int all) {
  long long &r = dp[all][node];
  if (r != -1LL) {
    return r;
  }
  long long sum = 0LL;
  long long maxCost = 0LL;
  int maxN = -1;
  int maxW = -1;
  long long maxDiff = 0LL;
  for (int i = 0; i < v[node].size(); ++i) {
    int val = v[node][i].first;
    int w = v[node][i].second;
    if (val == parent[node]) {
      continue;
    }
    long long c1 = cost(val, 1) + 2*w;
    long long c2 = cost(val, 0) + w;
    sum += c1;
    long long diff = c1-c2;
    if (diff > maxDiff) {
      maxDiff = diff;
      maxCost = c1;
      maxN = val;
      maxW = w;
    }
  }
  if (!all && maxN != -1) {
    long long c = cost(maxN, 0) + maxW;
    sum = sum - maxCost + c;
  }
  r = sum;
  return r;
}

int main()
{
  scanf ("%d", &n);
  int a,b,w;
  for (int i = 1; i < n; i++) {
    scanf ("%d %d %d", &a, &b, &w);
    a--;
    b--;
    v[a].push_back(make_pair(b, w));
    v[b].push_back(make_pair(a, w));
  }
  for (int i = 0; i < n; i++) {
    dp[0][i] = dp[1][i] = -1LL;
  }
  stack<int> s;
  s.push(0);
  parent[0] = -1;
  depth[0] = 0;
  int maxD = 0;
  while (!s.empty()) {
    int x = s.top();s.pop();
    for (int i = 0; i < v[x].size(); i++) {
      int t = v[x][i].first;
      if ( t == parent[x])
        continue;
      parent[t] = x;
      depth[t] = depth[x] + 1;
      if (maxD < depth[t]) {
        maxD = depth[t];
      }
      s.push(t);
    }
  }
  
  for (int i = maxD-5000; i >=0; i-= 5000) {
    for (int j = 0; j < n; j++) {
      if (depth[j] == i) {
        cost(j,0); cost(j, 1);
      }
    }
  }
  
  cout<<cost(0, 0) << endl;
  
  return 0;
}
