//Language: GNU C++


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

int n, k;
int v[5][1010];
int dp[1010];
int later[5][1010][1010];

int solve(int i) {
    if (i==n) return 0;
    if (dp[i]>=0) return dp[i];

    int tmp = 0;
    for (int j=i+1; j<n; j++) {
        bool good = 1;
        for (int kk=1; kk<k; kk++) {
            if (!later[kk][v[0][i]][v[0][j]]) {
                good = 0;
                break;
            }
        }
        if (good) tmp = max(tmp, 1 + solve(j));
    }

    dp[i] = tmp;
    return tmp;

}

int main() {

    cin>>n>>k;
    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) scanf("%d", &v[i][j]);
        for (int j=0; j<n; j++) {
            for (int t=j+1; t<n; t++) later[i][v[i][j]][v[i][t]] = 1;
        }
    }

    for (int i=0; i<n; i++) dp[i] = -1;

    int res = 0;
    for (int i=0; i<n; i++) {
        res = max(res, 1 + solve(i));
    }

    cout<<res<<endl;

    return 0;

}
