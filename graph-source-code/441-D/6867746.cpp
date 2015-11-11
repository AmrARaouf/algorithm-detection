//Language: GNU C++0x


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <fstream>

#define REP(I, N) for (int I = 0; I < (N); ++I)
#define PER(I, N) for (int I = (N); I >= 0; --I)
#define PERR(I, A, B) for (int I = (A); I >= (B); --I)
#define REPP(I, A, B) for (int I = (A); I <  (B); ++I)
#define REPN(I, A, B) for (int I = (A); I <= (B); ++I)
#define REPC(I, A, C) for (int I = (A); (C); ++I)
#define REPPP(I, A, B, C) for (int I = (A); I <  (B); I += C)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define RIIII(X, Y, Z, W) scanf("%d%d%d%d", &(X), &(Y), &(Z), &(W))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define DRIIII(X, Y, Z, W) int X, Y, Z, W; scanf("%d%d%d%d", &X, &Y, &Z, &W)
#define RS(X) scanf("%s", (X))
#define LEN(X) (int(strlen(X)))
#define SZ(X) (int((X).size()))
#define SUM(X, N) accumulate(X, X + (N), 0)
#define MS0(X) memset((X), 0, sizeof(X))
#define MSI(X) memset((X), 0xFF, sizeof(X))
#define F first
#define S second
#define MP make_pair
#define PB push_back

#ifdef DK
const int MAX = 11;
#else
const int MAX = 3e3 + 11;
#endif

using namespace std;

int P[MAX], ID[MAX], C[MAX], R1[2 * MAX], R2[2 * MAX];
int N, M, K, res;

static int pre() {
  int id = 1;
  MS0(ID);
  MS0(C);
  REP(i, N) {
    if (ID[i]) continue;
    int v = P[i];
    while (!ID[v]) {
      ID[v] = id;
      C[id]++;
      v = P[v];
    }
    id++;
  }
  return id - 1;
}

static void inc() {
  REP(i, N) {
    if (C[ID[i]] == 1) continue;
    REPP(j, i + 1, N) {
      if (ID[i] == ID[j]) {
        swap(P[i], P[j]);
        R1[res] = i;
        R2[res] = j;
        res++;
        return;
      }
    }
  }
}

static void dec() {
  REPP(i, 1, N) {
    if (ID[0] != ID[i]) {
      swap(P[0], P[i]);
      R1[res] = 0;
      R2[res] = i;
      res++;
      return;
    }
  }
}

int main() {
#ifdef DK
  freopen("in.txt", "r", stdin);
#endif
  RI(N);
  REP(i, N) {
    RI(P[i]);
    P[i]--;
  }
  RI(M);
  K = N - M;
  while (pre() < K) inc();
  while (pre() > K) dec();
  printf("%d\n", res);
  REP(i, res) printf("%d %d ", R1[i] + 1, R2[i] + 1);
  return 0;
}