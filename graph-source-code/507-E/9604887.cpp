//Language: GNU C++


#include<bits/stdc++.h>

using namespace std;

int n, m, bl;
vector< vector< pair<int, bool> > > g;
vector< pair< int, pair<int, int > > > gl;
vector<int> d, dn, w, p, ph;
vector<char> used;

int main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    g.assign(n, vector< pair<int, bool> > (0));
    bl = 0;
    for (int i=0; i<m; i++) {
        int x, y;
        bool z;
        cin >> x >> y >> z;
        --x; --y;
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
        gl.push_back(make_pair(x, make_pair(y, z)));
        bl+=z;
    }

    d.assign(n, -1);
    dn.assign(n, -1);
    w.assign(n, -1);
    p.assign(n, -1);
    ph.assign(n, -1);
    used.assign(n, 0);

    queue<int> q;
    q.push(0);
    d[0]=0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i=0; i<g[v].size(); i++) {
            int to = g[v][i].first;
            if (d[to] != -1)
                continue;
            d[to] = d[v]+1;
            q.push(to);
        }
    }
    q.push(n-1);
    dn[n-1]=0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i=0; i<g[v].size(); i++) {
            int to = g[v][i].first;
            if (dn[to] != -1)
                continue;
            dn[to] = dn[v] + 1;
            q.push(to);
        }
    }

    int k = d[n-1];
    q.push(0);
    w[0]=0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (used[v])
            continue;
        used[v] = true;
        for (size_t i=0; i<g[v].size(); i++) {
            int to = g[v][i].first;
            if (d[to]+dn[to]!=k || d[v]+1+dn[to]!=k || used[to])
                continue;
            if (w[to] != -1 && w[to]>=w[v]+g[v][i].second)
                continue;
            w[to] = w[v]+g[v][i].second;
            p[to]=v;
            q.push(to);
        }
    }
    int v = n-1;
    while(v!=0) {
        if(p[v]==-1)
            break;
        ph[v] = p[v];
        v = ph[v];
    }
    cout << bl + k - 2*w[n-1] << endl;
    for (int i=0; i<m; i++) {
        int v = gl[i].first;
        int to = gl[i].second.first;
        int c = gl[i].second.second;
        if (ph[v]==to || ph[to]==v) {
            if (!c) {cout << v+1 << " " << to+1 << " " << 1 << endl;}
        } else if (c) cout << v+1 << " " << to+1 << " " << 0 << endl;
    }
    return 0;
}
