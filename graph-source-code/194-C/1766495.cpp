//Language: GNU C++


#include <vector>
#include <iostream>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(vector<vector<char> > &cell, vector<vector<bool> > &used, int x,
        int y, int * marked_vertices) {
    used[x][y] = true;
    ++(*marked_vertices);
    int n = cell.size();
    int m = cell[0].size();
    for (int i = 0; i < 4; ++i) {
        if (0 <= x + dx[i] && x + dx[i] < n && 0 <= y + dy[i] &&
                y + dy[i] < m && cell[x + dx[i]][y + dy[i]] == '#' &&
                !used[x + dx[i]][y + dy[i]]) {
            dfs(cell, used, x + dx[i], y + dy[i], marked_vertices);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > cell(n, vector<char>(m));
    vector<vector<bool> > used(n, vector<bool>(m));
    int vertices = 0, marked_vertices = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cell[i][j];
            if (cell[i][j] == '#')
                ++vertices;
        }
    }
    if (vertices < 3) {
        cout << -1; 
        return 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (cell[i][j] == '#') {
                cell[i][j] = '.';
                for (int k = 0; k < 4; ++k) {
                    if (0 <= i + dx[k] && i + dx[k] < n && 0 <= j + dy[k] &&
                            j + dy[k] < m && cell[i + dx[k]][j + dy[k]] ==
                            '#') {
                        dfs(cell, used, i + dx[k], j + dy[k],
                                &marked_vertices);
                        if (marked_vertices < vertices - 1) {
                            cout << 1;
                            return 0;
                        }
                        break;
                    }
                }
                cell[i][j] = '#';
                marked_vertices = 0;
                for (int k = 0; k < n; ++k)
                    used[k].assign(m, false);
            }
    cout << 2;
}
