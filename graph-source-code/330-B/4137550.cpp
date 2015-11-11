//Language: GNU C++


#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
#include <string>
#include <functional>

#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define tr(cont, it) for (typeof(cont.begin()) it = cont.begin() ; it != cont.end() ; it++)

#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;

int n, m;

bool canUse[1010];

int main() {
    scanf("%d %d\n", &n, &m);
    memset(canUse, true, sizeof canUse);
    for (int i=0 ; i<m ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        canUse[a] = canUse[b] = false;
    }

    int use;
    for (use=0 ; !canUse[use] ; use++)
        ;

    printf("%d\n", n-1);
    for (int i=0 ; i<n ; i++) {
        if (i == use) continue;
        printf("%d %d\n", i+1, use+1);
    }
}