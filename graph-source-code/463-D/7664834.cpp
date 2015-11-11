//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <bitset>
#define REP(a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(),v.end()
#pragma comment(linker, "/STACK:36777216")
using namespace std;

typedef long long ll;
const int MAXN = 1101;
const ll INF = 1LL << 60;
const int MOD = (int) 1e9 + 7;
typedef double db;
typedef pair<int, int> PP;
typedef pair<int, pair<int, int> > PL;
int n, k;
int s[6][MAXN];
vector<int> g[MAXN];
int poz[6][MAXN];
int ans[MAXN];
char used[MAXN];
int res = 0;
void dfs(int v){
    used[v] = 1;
    if (g[v].size() == 0) ans[v] = 1;
    for (int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if (!used[to])
            dfs(to);
        ans[v] = max(ans[v], ans[to] + 1);
    }
    //ans[v] = max(ans[v], 1);
    res = max(res, ans[v]);
}
int main(){

    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
    for (int j = 0; j < n; j++){
        scanf("%d", &s[i][j]);
        poz[i][s[i][j]]=j;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j) continue;
            int yes = 1;
            for (int p = 0; p < k; p++){
                if (poz[p][i] > poz[p][j]) yes = 0;
            }
            if (yes)
                g[i].push_back(j);
        }
    }
    for (int i = 1; i <= n;i++)
    if (!used[i]) dfs(i);
    printf("%d", res);
}
