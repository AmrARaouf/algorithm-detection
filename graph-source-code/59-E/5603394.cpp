//Language: MS C++


#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

int n, m, k, z;
vector<int> a[3030];
map<pair<int, int>, int> id;
map<int, bool> cant[100010];
int gone[100010];
int L[100010];

deque<pair<int, int>> q;
deque<int> len;

int main() {

    //freopen("E.in", "r", stdin);

    scanf("%d%d%d", &n, &m, &k);
    z = 0;
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);

        id[make_pair(u, v)] = ++z; L[z] = u;
        id[make_pair(v, u)] = ++z; L[z] = v;
    }
    
    for(int i = 0; i < k; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        
        int tid = id[make_pair(a, b)];
        if (tid) cant[tid][c] = 1;
    }

    memset(gone, 0, sizeof gone);
    q.push_back(make_pair(1, -1));
    len.push_back(0);
    gone[0] = -1;
    while (!q.empty()) {
        pair<int, int> now = q.front(); q.pop_front();
        int tlen = len.front(); len.pop_front();
        int u = now.first;
        int tid = now.second;
        if (u == n) {
            printf("%d\n", tlen);
            vector<int> ret; ret.clear();
            ret.push_back(u);
            while (tid > 0) {
                ret.push_back(L[tid]);
                tid = gone[tid];
            }
            for(int i = ret.size()-1; i >= 0; i--) printf("%d ", ret[i]);
            return 0;
        }
        

        for(int i = 0; i < a[u].size(); i++) {
            int v = a[u][i];
            int ttid = id[make_pair(u, v)];
            if (!gone[ttid] && (tid < 0 || !cant[tid][v])) {
                gone[ttid] = tid;
                q.push_back(make_pair(v, ttid));
                len.push_back(tlen+1);
            }
        }
    }

    printf("-1");

    return 0;
}