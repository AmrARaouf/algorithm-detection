//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <ctime>

using namespace std;

int N, M, x, y;
int D[1000500];

int main() {
#ifndef ONLINE_JUDGE
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);
#endif
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        D[x]++;
        D[y]++;
    }

    long long ans = 0;
    for(int i = 1; i <= N; i++)
        ans += (long long)D[i] * (D[i] - 1) + (long long)(N - 1 - D[i]) * (N - 2 - D[i]) - (long long)D[i] * (N - 1 - D[i]);
    ans /= 6;

    printf("%I64d", ans);

	return 0;
}
