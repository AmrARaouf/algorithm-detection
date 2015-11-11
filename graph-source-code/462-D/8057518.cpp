//Language: MS C++


// esta3anna 3al sha2a belAllah ..
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<sstream>
#include<limits.h>
#include<iomanip>
#include<cstring>
#include<bitset>
#include<fstream>
#include<cmath>
#include<cassert>
#include <stdio.h>
#include<ctype.h>
using namespace std;
#define rep(i,n,m) for(int i = (int)(n), _m = (int)(m); i < _m; ++ i)
#define rrep(i,n,m) for(int i = (int)(n), _m = (int)(m); i >= _m; -- i)
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mems(arr, v) memset(arr, v, sizeof arr)
#define setBit(mask, bit) ((mask) | (1LL << (bit)))
#define resetBit(mask, bit) ((mask) & (~(1LL << (bit))))
#define flipBit(mask, bit) ((mask) ^ (1LL << (bit)))
#define is0(mask, bit)(((mask) & (1LL << (bit))) == 0)
#define is1(mask, bit)(((mask) & (1LL << (bit))) != 0)
#define removeLastBit(mask) ((mask) & ((mask) - 1LL))
#define firstBitOn(mask) ((mask) & ~((mask) - 1LL))
#define grayCode(mask) ((mask) ^ ((mask) << 1LL))
#define repSubMasks(subMask, mask) for(ll subMask = (ll)(mask), _mask = subMask; subMask; subMask = _mask & (subMask - 1))
int countBits(long long mask) {int res = 0; while(mask) mask &= (mask - 1), ++ res; return res;}
string toString(long long n) {stringstream ss; ss << n; return ss.str();}
long long toNumber(string s) {stringstream ss; long long n; ss << s; ss >> n; return n;}
#define INT_MAX  1000000000
#define INT_MIN -1000000000
#define INF 1000000000
#define EPS 1e-9
#define MOD 1000000007
#define debug(x) cout << #x << " : " << x << endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define Read() freopen("input.txt","r",stdin)
#define Write() freopen("output.txt","w",stdout)
ll dp[100010][2];
#define MOD 1000000007 
bool black[100010];
#define white !black
vector<vector<int> > adjList;
ll mod_inverse(ll n, ll p) {
    if(!p) return 1;
    if(p == 1) return n;
    ll res = mod_inverse(n, p / 2);
    res = (res * res) % MOD;
    if(p & 1)
        res = (res * n) % MOD;
    return res;
}
ll rec(int node, bool has_black_ancestor, int parent) {
    if(adjList[node].size() == 1 && parent != -1) return black[node] || has_black_ancestor;
    ll &res = dp[node][has_black_ancestor];
    if(res != -1) return res;
    res = 0;
    ll all_ok = 1;
    rep(i, 0, adjList[node].size()) {
        int child = adjList[node][i];
        if(child == parent) continue;
        all_ok = (all_ok * rec(child, 1, node)) % MOD;
    }
    if(black[node] || has_black_ancestor)
        res = all_ok;
    if(white[node]) {
        rep(i, 0, adjList[node].size()) {
            int child = adjList[node][i];
            if(child == parent) continue;
            ll all_but_this = (all_ok * mod_inverse(rec(child, 1, node), MOD - 2)) % MOD;
            res += (all_but_this * rec(child, 0, node)) % MOD;
            res %= MOD;
        }
    }
    return res;
}
int main() {
   // Read();
    int n, p;
    while(cin >> n) {
        adjList.clear();
        adjList.resize(n);
        rep(i, 1, n) {
            cin >> p;
            adjList[p].pb(i);
            adjList[i].pb(p);
        }
        rep(i, 0, n)
            cin >> black[i];
        mems(dp, -1);
        cout << rec(0, 0, -1) << endl;
    }
}