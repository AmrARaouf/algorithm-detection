//Language: GNU C++0x


#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 500010;

int n, m;

int st[2][maxn];
int sz[2];
vector<int> G[maxn];
vector<int> ans[maxn];
int cnt = 0;
bool vis[maxn];

queue<int> q;
int flag = 0;
void bfs(int x, int gi) {
    q.push(x);
    int u, t;
    while (!q.empty()) {
        u = q.front(); q.pop();
        // printf("flag = %d\n", flag);
        // printf("u = %d\n", u);
        if (vis[u]) continue;
        vis[u] = 1;
        ans[gi].push_back(u);
        sz[!flag] = 0;
        for (int i = 0; i < sz[flag]; i++) {
            int v = st[flag][i];
//            printf("    v = %d\n", v);
            if (!binary_search(G[u].begin(), G[u].end(), v)) {
                q.push(v);
//                printf("push(%d)\n", v);
            }
            else {
                st[!flag][sz[!flag]++] = v;
            }
        }
        flag = !flag;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        st[0][i] = i + 1;
        sort(G[i+1].begin(), G[i+1].end());
    }
    sz[0] = n;
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bfs(i, ++cnt);
        }
    }
    
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
        printf("%d", ans[i].size());
        for (int j = 0; j < ans[i].size(); j++) printf(" %d", ans[i][j]);
        putchar('\n');
    }
    return 0;
}

			  		   		 	   		      	 			