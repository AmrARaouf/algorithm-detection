//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int DR[] = {1, 0, -1, 0};
const int DC[] = {0, 1, 0, -1};

struct Operation {
    char ch;
    int r, c;
};

int n, m;
char s[500][501];
vector<Operation> res;

void dfs(int r, int c) {
    res.push_back({'B', r, c});
    s[r][c] = '#';
    for (int i = 0; i < 4; ++i) {
        int nr = r + DR[i];
        int nc = c + DC[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && s[nr][nc] == '.') {
            dfs(nr, nc);
        }
    }
    res.push_back({'D', r, c});
    res.push_back({'R', r, c});
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                dfs(i, j);
                res.pop_back();
                res.pop_back();
            }
        }
    }
    printf("%d\n", (int)res.size());
    for (int i=0;i<res.size();i++) {
        printf("%c %d %d\n", res[i].ch, res[i].r + 1, res[i].c + 1);
    }
    return 0;
}
