//Language: MS C++


#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1001;
int n;
int mas2[MAXN][MAXN];
int mas[MAXN][MAXN];
vector<int> g[MAXN];
bool used[MAXN];
bool used2[MAXN][MAXN];
void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (! used[to])
            dfs (to);
    }
}
int main() {
    cin >> n;
    int h = 0;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        mas[--x][--y] = (++h);
    }
    for (int x = 0; x < MAXN; x++) {
        for (int y = 0; y < MAXN; y++) {
            if(mas[x][y] > 0) {
                for (int i = y; i < MAXN; i++) {
                    if(i == y) 
                        continue;
                    if(mas[x][i]) {
                        g[mas[x][y]-1].push_back(mas[x][i]-1);
                        g[mas[x][i]-1].push_back(mas[x][y]-1);
                        break;
                    }
                }
                for (int i = x; i < MAXN; i++) {
                    if(i == x) 
                        continue;
                    if(mas[i][y]) {
                        g[mas[x][y]-1].push_back(mas[i][y]-1);
                        g[mas[i][y]-1].push_back(mas[x][y]-1);
                        break;
                    }
                }
            }
        }
    }
    int cc = 0;
    for (int i = 0; i < n; i++) {
        if(!used[i]) {
            dfs(i);
            cc++;
        }
    }
    if(cc == 1) cout << 0;
    else cout << max(cc-1,0);
    return 0;
}