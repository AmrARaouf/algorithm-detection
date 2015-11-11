//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

const long long linf = 5e18 + 9;
const int inf = 1e9 + 9;
const int  N = 1e5 + 9;

vector< pair< int, int > > edge[N], gr[N], arr;

int dist[N], come[N], ind[N][5];

int n, m, u, v, b, ans;

bool flag, way[N], hash[N];

void spfa() {
    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
    }

    queue < int > q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        hash[node] = false;
        for (int i = 0; i < edge[node].size(); i++) {
            if (dist[node] + 1 < dist[edge[node][i].first]) {
                dist[edge[node][i].first] = dist[node] + 1;
                if (!hash[edge[node][i].first]) {
                    hash[edge[node][i].first] = true;
                    q.push(edge[node][i].first);
                }
            }
        }
    }
}

void DAG(int node) {
    if (hash[node] == true) return;    
    hash[node] = true;
    for (int i = 0; i < edge[node].size(); i++) {
        if (dist[node] + 1 == dist[edge[node][i].first]) {
            gr[node].push_back(make_pair(edge[node][i].first, edge[node][i].second));
        }
        DAG(edge[node][i].first);
    }
}

void spEsc() {
    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
    }

    queue < int > q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        hash[node] = false;
        for (int i = 0; i < gr[node].size(); i++) {
            if (dist[node] + !gr[node][i].second + 1 < dist[gr[node][i].first]) {
                dist[gr[node][i].first] = dist[node] + !gr[node][i].second + 1;
                come[gr[node][i].first] = node;
                if (!hash[gr[node][i].first]) {
                    hash[gr[node][i].first] = true;
                    q.push(gr[node][i].first);
                }
            }
        }
    }
}

void esc(int node) {
    if (node == -1) return ;
    esc(come[node]);
    way[node] = true;
}

int main() {

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &b);
        edge[u].push_back(make_pair(v, b));
        edge[v].push_back(make_pair(u, b));
        ind[i][1] = u;
        ind[i][2] = v;
        ind[i][3] = b;
    }

    spfa();

    memset(hash, false, sizeof hash);

    DAG(1);

    memset(hash, false, sizeof hash);

    spEsc();

    come[1] = -1;

    esc(n);

    for (int i = 1; i <= m; i++) {
        if (way[ind[i][1]] == true and way[ind[i][2]] == true and !ind[i][3]) ans++;
        else if ((way[ind[i][1]] == false or way[ind[i][2]] == false) and ind[i][3]) ans++;
    }
    
    cout << ans << endl;

    for (int i = 1; i <= m; i++) {
        if (way[ind[i][1]] == true and way[ind[i][2]] == true and !ind[i][3]) cout << ind[i][1] << " " << ind[i][2] << " " << !ind[i][3] << endl;
        else if ((way[ind[i][1]] == false or way[ind[i][2]] == false) and ind[i][3]) cout << ind[i][1] << " " << ind[i][2] << " " << !ind[i][3] << endl;
    }
    
    return 0;
}