//Language: GNU C++0x


#include <iostream>
#include <cstdio>

using namespace std;

#define WIDTH (32)
#define NNODES (3*WIDTH+3) // Dummy 0 node
#define join(i, j) (adj[i][j] = 'Y', adj[j][i] = 'Y')

int main() {
  char adj[NNODES][NNODES];
  for (int i = 0; i < NNODES; i++)
    for (int j = 0; j < NNODES; j++)
      adj[i][j] = 'N';

  join(1, 3);
  join(1, 4);
  join(NNODES-1, 2);

  for (int i = 0; i < WIDTH-1; i++) {
    join(3+i*3, 6+i*3);
    join(3+i*3, 7+i*3);

    join(4+i*3, 6+i*3);
    join(4+i*3, 7+i*3);

    join(5+i*3, 8+i*3);
  }

  int k;
  cin >> k;

  for (int idx = 4; k != 0; k=k>>1, idx=idx+3) {
    if (k&1) {
      join(idx, idx+1);
    }
  }

  printf("%d\n", NNODES-1);
  for (int i = 1; i < NNODES; i++) {
    for (int j = 1; j < NNODES; j++) {
      putchar(adj[i][j]);
    }
    putchar('\n');
  }
  return 0;
}
