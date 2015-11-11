//Language: GNU C++0x


#include <bits/stdc++.h>

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;

const int MAXM = 200200;

string ss = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
vector<int> G[64*64];
vector<int> rG[64*64];

void dfs(int cur, vector<int>& path) {
    while (!G[cur].empty()) {
        int next = G[cur].back();
        G[cur].pop_back();
        dfs(next, path);
    }
    path.push_back(cur);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int S[3];
        for (int j = 0; j < 3; j++) {
            S[j] = lower_bound(ss.begin(), ss.end(), s[j]) - ss.begin();
        }
        int in = S[0] * 64 + S[1];
        int out = S[1] * 64 + S[2];
        G[in].push_back(out);
        rG[out].push_back(in);
    }
    int start = -1, end = -1, nonzero = 0;
    for (int i = 0; i < 64*64; i++) {
        int tmp = (int)G[i].size() - (int)rG[i].size();
        if (abs(tmp) > 1) {
            cout << "NO" << endl;
            return;
        } else if (tmp == 1) {
            if (start != -1) {
                cout << "NO" << endl;
                return;
            } else {
                start = i;
            }
        } else if (tmp == 0) {
            nonzero++;
        } else {
            if (end != -1) {
                cout << "NO" << endl;
                return;
            } else {
                end = i;
            }
        }
    }
    if (start * end < 0) {
        cout << "NO" << endl;
        return;
    }
    if (start == -1) {
        for (int i = 0; i < 64*64; i++) {
            if (G[i].size() > 0) {
                start = i;
                break;
            }
        }
    }
    vector<int> path;
    dfs(start, path);
    if (path.size() != n+1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    reverse(path.begin(), path.end());
    int x = path[0] / 64;
    int y;
    string s;
    s += ss.substr(x, 1);
    int N = path.size();
    for (int i = 1; i < N-1; i++) {
        x = path[i] / 64;
        s += ss.substr(x, 1);
    }
    x = path[N-1] / 64;
    y = path[N-1] % 64;
    s += ss.substr(x, 1);
    s += ss.substr(y, 1);
    cout << s << endl;
}

int main() {
    solve();
    return 0;
}
