//Language: GNU C++


/*
ID: azhai1
LANG: C++
TASK: ski_base
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N_MAX = 100032;
const int MOD = 1000000009;

int N;
int M;
vector<int> edges[N_MAX];

int markers[N_MAX];
vector<int> components[N_MAX];

void init();

void fuse(int a, int b) {
  if (components[a].size() > components[b].size()) {
    fuse(b, a);
    return;
  }

  for (int i = 0; i < components[a].size(); i++) {
    markers[components[a][i]] = b;
    components[b].push_back(components[a][i]);
  }
}

int main() {
  init();

  int count = 1;
  for (int i = 0; i < M; i++) {
    int start, end;
    cin >> start >> end;
    start--; end--;

    if (markers[start] == markers[end]) {
      count *= 2;
      count %= MOD;
    } else {
      fuse(markers[start], markers[end]);
    }
    cout << count - 1 << '\n';
  }

  return 0;
}

void init() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    markers[i] = i;
    components[i].push_back(i);
  }
}

