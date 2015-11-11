//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#include <set>
#include <map>
#define reset(a , b) memset(a , b , sizeof(a))
//
using namespace std;

const long long INF = 1000000000;
const int N = 200100;
typedef pair<long long , int> PII;

priority_queue<PII , vector<PII> , greater<PII> > PQ;
int n , m , P , cnt ,  Q , lab[N] , tt ,t;
bool choose[N];
long long d[N];
PII ans[N] , e;

int FindSet(int u) {
    if (lab[u] <= 0) return u;
    lab[u] = FindSet(lab[u]);
    return lab[u];
}

void union_(int r , int q , long long val) {
    if (lab[r] < lab[q]) {
        lab[q] = r;
        d[r] += d[q] + val;
    } else {
        if (lab[q] == lab[r]) lab[q]--;
        lab[r] = q;
        d[q] += d[r] + val;
    }
}

int main() {
    //freopen("input.in" , "r" , stdin);
    //freopen("output.out" , "w" , stdout);
    cin >> n >> m >> P >> Q;
    for (int i = 1 ; i <= m ; i++){
        int u , v , val;
        scanf("%d%d%d" , &u , &v , &val);
        t = FindSet(u);
        tt = FindSet(v);
        if (tt != t) union_(t , tt , val);
        else d[tt] += val;
        e = PII(u , v);
    }
    for (int i = 1 ; i <= n ; i++){
        int t = FindSet(i);
        if (!choose[t]){
            choose[t] = true;
            PQ.push(PII(d[t] , t));
        }
    }
    if (PQ.size() < Q) {
        printf("NO\n");
        return 0;
    }
    while (PQ.size() != Q) {
        PII u , v;
        u = PQ.top(); PQ.pop();
        v = PQ.top(); PQ.pop();
        ans[++cnt] = PII(u.second , v.second);
        long long SS = min(INF , d[u.second] + d[v.second] + 1);
        if (SS == 0) SS = 1000;
        union_(u.second , v.second , SS);
        tt = FindSet(u.second);
        PQ.push(PII(d[tt] , tt));
        e = ans[cnt];
    }
    if (cnt > P) {
        cout << "NO";
        return 0;
    }
    if (cnt < P){
        int tmp = P - cnt;
        if (e.first == 0 || e.second == 0) {
            cout << "NO";
            return 0;
        }
        for (int i = 1 ; i <= tmp ; i++)
            ans[++cnt] = e;
    }

    cout << "YES" << endl;
    for (int i = 1 ; i <= cnt ; i++)
        cout << ans[i].first << " " << ans[i].second << endl;
}
