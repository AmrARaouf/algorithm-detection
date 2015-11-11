//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
#include<string>
#include<set>
#include<map>
#include<iomanip>
#include<sstream>
#include<functional>
#include<climits>
#define eps 1e-9
const int mod = 1e9 + 7;
using namespace std;

int n, m, res, a, b, v[10001];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        res += min(v[a], v[b]);
    }
    printf("%d\n", res);
    return 0;
}