//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;
#define NN 505
#define MM 10010
#define FI "notmeet.i1"
#define FO "notmeet.o1"
struct Node {
    short u, v, id; // Linh o u, Tuan o v va nguoi den sau la id
    Node(){}
    Node(short u, short v, short id): u(u), v(v), id(id) {}
};
queue<Node> Q;
short pre[NN][NN][2], n, m;
vector<int> ke[NN], ra, rb;

void BFS(){
    Node tt;
    Q.push(tt = Node(1, n, 0));
    pre[tt.u][tt.v][tt.id] = -1;
    while (!Q.empty()) {
        tt = Q.front();
        Q.pop();
        int u = tt.u, v = tt.v;
        tt.id = !tt.id;
        if (u == v && tt.id) {
            continue;
        }
        if (tt.id) {
            for (vector<int>::iterator it = ke[u].begin(); it != ke[u].end(); it++) {
                tt.u = *it;
                if (pre[tt.u][tt.v][tt.id] == 0) {
                    pre[tt.u][tt.v][tt.id] = u;
                    Q.push(tt);
                }
            }
        } else {
            for (vector<int>::iterator it = ke[v].begin(); it != ke[v].end(); it++) {
                tt.v = *it;
                if (pre[tt.u][tt.v][tt.id] == 0) {
                    pre[tt.u][tt.v][tt.id] = v;
                    Q.push(tt);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    ifstream cin(FI);
    ofstream cout(FO);
    #endif // ONLINE_JUDGE
    cin >> n >> m;
    for (int u, v, i = 0; i < m; ++i) {
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    BFS();
    Node tt = Node(n, 1, 0);
    if (pre[tt.u][tt.v][tt.id] == 0) { cout <<"-1\n"; return 0;}
    ra.push_back(tt.u);
    rb.push_back(tt.v);
    do {
        if (tt.id) {
            ra.push_back(tt.u = pre[tt.u][tt.v][tt.id]);
        } else {
            rb.push_back(tt.v = pre[tt.u][tt.v][tt.id]);
        }
        tt.id = !tt.id;
    } while (pre[tt.u][tt.v][tt.id] != -1);

    reverse(ra.begin(), ra.end());
    reverse(rb.begin(), rb.end());
    cout << ra.size() - 1 << endl;
    for (int i = 0; i < ra.size(); i++) cout << ra[i] << ' ';
    cout << endl;
    for (int i = 0; i < rb.size(); ++i) cout << rb[i] << ' ';
    cout << endl;
    return 0;
}
