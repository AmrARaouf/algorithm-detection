//Language: GNU C++


#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int ch[4] = {'v', '^', '>', '<'};
const int N = 2005;

int n, m, ans;
char a[N][N];

inline int idx(int x, int y) { return x*m+y; }

inline bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(int x, int y, int d) {
    int maxd = d;
    a[x][y] = 0;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(in(nx, ny) && a[nx][ny] == ch[i]) {
            maxd = max(maxd, dfs(nx, ny, d+1));
        }
    }
    return maxd;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%s", a[i]);
    PII maxd(0, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(a[i][j] == '#') {
                for(int k = 0; k < 4; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(in(nx, ny) && a[nx][ny] == ch[k]) {
                        int d = dfs(nx, ny, 1);
                        ans = max(ans, d+d-1);
                        if(d > maxd.first){
                            maxd.second = maxd.first;
                            maxd.first = d;
                        } else if(d > maxd.second) {
                            maxd.second = d;
                        }
                    }
                }
            }
        }
    }
    ans = max(ans, maxd.first+maxd.second);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(a[i][j] != '#' && a[i][j]) {
                return puts("-1"), 0;
            }
        }
    }
    printf("%d\n", ans);
}