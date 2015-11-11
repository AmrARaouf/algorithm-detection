//Language: GNU C++


#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<queue>
#include<cstring>
#include<ctime>

using namespace std;

vector<vector<int > > G;
vector<int> color;
vector<int> p;
vector<int> d;
queue<pair<int, int> > q;
int n;

bool ex = false;
void dfs(int v) {
    if(ex) return;
    color[v] = 1;
    for(int i = 0; i < G[v].size(); i++) {
        if(ex) return;
        int u = G[v][i];
        if(color[u] == 1 && p.size() > 0 && p.back() != u) {
            ex = true;
            color.clear();
            color.resize(n, 0);
            p.push_back(v);
//            for(int i = 0; i < p.size(); i++) {
//                cerr << p[i] << " ";
//            }
//            cerr << endl;
            while(p.back() != u) {
//                cerr << p.back() << endl;
                q.push(make_pair(p.back(), 0));
                color[p.back()] = 1;
                p.pop_back();
            }
            color[u] = 1;
            q.push(make_pair(u, 0));
            return;
        }
        if(color[u] == 0) {
            p.push_back(v);
            dfs(u);
            if(ex) return;
            p.pop_back();
        }
    }
    if(ex) return;
    color[v] = 2;
}

int main() {
//    freopen("D.in", "r", stdin);
//    freopen("D.out", "w", stdout);
    cin >> n;
    G.resize(n);
    color.resize(n, 0);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0);
//    cerr << "OK" << endl;
    d.resize(n, 0);
    while(!q.empty()) {
        pair<int, int> v0 = q.front();
        int v = v0.first;
        q.pop();
        for(int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            if(!color[u]) {
                q.push(make_pair(u, v0.second + 1));
                color[u] = 1;
                d[u] = v0.second + 1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    return 0;
}
