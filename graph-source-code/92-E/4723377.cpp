//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <stack>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100010;
const int M = 1000010;
const int inf = 0x3f3f3f3f;
const ll oo = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 9;

#define pb push_back
#define sz(x) ((x).size())
#define mp make_pair

int p[N];

int Find(int x){
    if(p[x] != x) p[x] = Find(p[x]);
    return p[x];
}

ll Pow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void out(int x){
    printf("%lld\n", (Pow(2, x) - 1 + mod) % mod);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        p[i] = i;
    int ret = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(Find(a) == Find(b)) {
            ret ++;
        }
        else p[Find(a)] = Find(b);
        out(ret);
    }
    return 0;
}
