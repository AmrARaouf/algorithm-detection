//Language: GNU C++0x


#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define pp pop_back
#define f first
#define s second
#define sz(a) (int)((a).size())

using namespace std;

const int N = (int)1e5 + 123;

int n, m;
vector < pair < int, int > > g[N], f[N];
vector < pair < int, pair < int, int > > > ans;
queue < int > q;
int d[N], p[N], d2[N];
int x[N], y[N], z[N];
map < pair < int, int >, bool > u;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> z[i];
        g[x[i]].pb(mp(y[i], z[i]));
        g[y[i]].pb(mp(x[i], z[i]));
    }
    memset(d, -1, sizeof d);
    q.push(1);
    d[1] = 0;
    while(!q.empty()) {
        int now = q.front();
//      cout << now << " asadsads\n";
        q.pop();
        for (auto to : g[now]) {
            if (d[to.f] == -1)
//              cout << to.f << endl,
                d[to.f] = d[now] + 1,
                q.push(to.f);
        }
    }
    memset(p, -1, sizeof p);
    memset(d2, -1, sizeof d2);
    q.push(1);
    d2[1] = 0;
    while(!q.empty()) {
        int now = q.front();
//      cout << now << " hey\n";
        q.pop();
        for (auto to : g[now]) {
            if (d[to.f] != d[now] + 1)
                continue;
//          cout << to.f << " to\n";
            if (d2[to.f] == -1)
                d2[to.f] = d2[now] + to.s,
                p[to.f] = now, 
                q.push(to.f);
            else if (d2[to.f] < d2[now] + to.s)
                d2[to.f] = d2[now] + to.s,
                p[to.f] = now;
        }
    }
    int now = n;
    while(now > 1) {
        u[mp(now, p[now])] = u[mp(p[now], now)] = 1;
//      cout << now << ' ' << p[now] << endl;
        if (d2[p[now]] == d2[now])
            ans.pb(mp(p[now], mp(now, 1)));
        now = p[now];
    }
    for (int i = 1; i <= m; i++)
        if (!u[mp(x[i], y[i])] && z[i] == 1)
            ans.pb(mp(x[i], mp(y[i], 0)));
    cout << sz(ans) << endl;
    for (int i = 0; i < sz(ans); i++)
        cout << ans[i].f << ' ' << ans[i].s.f << ' ' << ans[i].s.s << endl;
    return 0;
}
