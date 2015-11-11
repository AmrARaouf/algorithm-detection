//Language: GNU C++0x


#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
typedef pair<int, int> pii;
const int inf = 1e9;
const int mod = 1e9+7;
const int N = 3005;
const int M = 20050;
template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x <0) {
        putchar('-');
        x = -x;
    }
    if (x>9) pt(x / 10);
    putchar(x % 10 + '0');
}
typedef long long ll;
int n, m, k;
map<pii, int> mp;
set<int>G[M << 1];
struct Edge{
    int from, to, nex;
    Edge(int a = 0, int b = 0, int c = 0):from(a), to(b), nex(c){}
}edge[M<<1];
int head[N], edgenum;
int dp[M << 1], pre[M << 1];
void add(int u, int v){
    Edge E = { u, v, head[u] };
    edge[edgenum] = E;
    mp[pii(u, v)] = edgenum;
    dp[edgenum] = inf;
    head[u] = edgenum++;
}
void input(){
    memset(head, -1, sizeof head); edgenum = 0;
    mp.clear();
    while (m--){
        int u, v; rd(u); rd(v);
        add(u, v); add(v, u);
    }
    for (int i = 0, u, v, c; i < k; i++){
        rd(u); rd(v); rd(c);
        if (mp.count(pii(u, v)))
            G[mp[pii(u, v)]].insert(c);
        swap(c, u);
        if (mp.count(pii(u, v)))
            G[mp[pii(u, v)]].insert(c);
    }
}
void spfa(int x){
    queue<int>q;
    for (int i = head[x]; ~i; i = edge[i].nex){
        q.push(i);
        dp[i] = 0;
        pre[i] = -1;
    }
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int i = head[edge[u].to]; ~i; i = edge[i].nex){
            int v = edge[i].to;
            if (dp[i] > dp[u]+1 && G[u].count(v) == 0){
                q.push(i);
                dp[i] = dp[u] + 1;
                pre[i] = u;
            }
        }
    }
}
vector<int>ans;
int main() {
    rd(n); rd(m); rd(k);
    input();
    spfa(1);
    int las = -1;
    for (int i = head[n]; ~i; i = edge[i].nex){
        if (dp[i ^ 1]!=inf && (las == -1 || dp[las]>dp[i^1])){
            las = i ^ 1;
        }
    }
    if (las == -1)puts("-1");
    else{
        ans.push_back(n);
        while (las != -1){
            ans.push_back(edge[las].from);
            las = pre[las];
        }
        printf("%d\n", ans.size() - 1);
        for (int i = ans.size() - 1; i >= 0; i--)printf("%d ", ans[i]);
    }

    return 0;
}
/*
 
*/