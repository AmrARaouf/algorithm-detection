//Language: GNU C++


#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100100, MOD = (1e9)+9;
int pai[MAXN], prof[MAXN];

int raiz(int a) {
    if (a == pai[a]) return a;
    return pai[a] = raiz(pai[a]);
}

void merge(int a, int b) {
    if (prof[a] < prof[b]) swap(a,b);
    pai[b] = a;
    if (prof[a] == prof[b]) prof[a]++;
}

int main() {
    int N, a, b, M;
    scanf("%d %d",&N,&M);
    for (int i=1; i<=N; i++) {
        pai[i] = i;
        prof[i] = 0;
    }
    long long resp = 1LL;
    for (int i=1; i<=M; i++) {
        scanf("%d %d",&a,&b);
        a = raiz(a); b = raiz(b);
        if (a == b) {
            resp *= 2;
            resp %= MOD;
        }
        else merge(a,b);
        printf("%I64d\n",resp-1);
    }
    return 0;
}
