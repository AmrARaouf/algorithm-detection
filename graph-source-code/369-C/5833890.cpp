//Language: MS C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <complex>
#include <ctime>  
#include <cstdlib>
using namespace std;

#pragma comment(linker, "/STACK:100000000")

#define mp make_pair
#define pb push_back
#define sz(x) (int)(x).size()
#define ll long long
#define ull unsigned long long

vector<pair<int, int> > v[100100];
int mas[100100];

void dfs(int s, int l, int t, int lst) {
    if(t == 2) {
        mas[l] = 0;
        mas[s] = 1;
        l = s;
    }
    for(int i = 0, maxi = sz(v[s]); i < maxi; i++) {
        if(v[s][i].first != lst) {
            dfs(v[s][i].first, l, v[s][i].second, s);
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        v[a].pb(mp(b, t));
        v[b].pb(mp(a, t));
    }
    dfs(1, 1, 1, 1);
    int cnt = 0;
    for(int i = 0; i <= n; i++) cnt += mas[i];
    printf("%d\n", cnt);
    for(int i = 0; i <= n; i++) {
        if(mas[i] == 1) printf("%d ", i);
    }
    return 0;
}