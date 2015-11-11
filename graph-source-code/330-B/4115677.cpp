//Language: GNU C++


#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define N 1000

using namespace std;

bool used[N + 1];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    memset(used, false, sizeof(used));

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        used[a] = used[b] = true;
    }

    printf("%d\n", n - 1);

    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            for(int j = 1; j <= n; j++) {
                if(i != j)  printf("%d %d\n", i, j);
            }
            break;
        }
    }

    return 0;
}
