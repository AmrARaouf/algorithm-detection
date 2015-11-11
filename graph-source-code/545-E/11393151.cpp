//Language: GNU C++11


#include <bits/stdc++.h>
#define endl "\n"
#define FOR(x, y, z) for (int x = (y); x < (z); ++x)
#define FORR(x, y, z) for (int x = (y); x > (z); --x)
#define GET(a, n) for (int __i = 0; __i < (n); ++__i) cin >> a[__i];
#define GETM(a, n, m) for (int __i = 0; __i < (n); ++__i) for (int __j = 0; __j < m; ++__j) cin >> a[__i][__j];
#define PRINTM(a, n, m) for (int __i = 0; __i < (n); ++__i) { for (int __j = 0; __j < m; ++__j) cout << a[__i][__j] << " ";  cout << endl; };
#define PRINT(a, n) for (int __i = 0; __i < (n); ++__i) cout << a[__i] << " ";
#define IT(a) a.begin(), a.end()
#define CASE(a, s) cout << "Case #" << a << ": " << s << endl;
#define DEB(a) cout << #a << " = " << (a) << endl; cout.flush();
#define DEBA(a) for (auto __i: a) cout << __i << " "; cout << endl;
#define IFDEB(b, a) if (b) { cout << #a << " = " << a << endl; cout.flush(); }
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <vector <int>> VVI;
typedef pair <int, int> PII;
const int MOD = 1000000007;
template <class T> typename T::value_type arr_sum(const T& v, int n) { typename T::value_type sum = 0; FOR(i, 0, n) sum += v[i]; return sum; }
struct Sync_stdio { Sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); } } _sync_stdio;

struct Z
{
    int a;
    LL w;
    int operator < (const Z &a) const { return w > a.w; };
};

vector <vector <Z>> g;
vector <LL> d;

void dijkstra(int x)
{
    priority_queue <Z> pq;
    pq.push({x, 0});
    while (pq.size()) {
        Z t = pq.top();
        pq.pop();
        if (t.w != d[t.a]) {
            continue;
        }
        for (auto i: g[t.a]) {
            if (d[t.a] + i.w < d[i.a]) {
                d[i.a] = d[t.a] + i.w;
                pq.push({i.a, d[i.a]});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    map <PII, int> s;
    d.assign(n, LLONG_MAX);
    g.resize(n);
    FOR (i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        s[{min(a, b), max(a, b)}] = i;
    }
    int x;
    cin >> x;
    --x;
    d[x] = 0;
    dijkstra(x);
    vector <int> ans;
    LL res = 0;
    FOR (i, 0, n) {
        if (i == x) {
            continue;
        }
        int minc = INT_MAX;
        int mini = -1;
        for (auto j: g[i]) {
            if (d[j.a] + j.w == d[i]) {
                if (j.w < minc) {
                    minc = j.w;
                    mini = j.a;
                }
            }
        }
        ans.push_back(s[{min(i, mini), max(i, mini)}]);
        res += minc;
    }
    cout << res << endl;
    for (auto i: ans) {
        cout << i + 1 << " ";
    }
}
