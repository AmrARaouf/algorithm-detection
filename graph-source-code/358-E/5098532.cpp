//Language: GNU C++


#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

const int MaxN = 1000 + 5;

int a[MaxN][MaxN];
vector<int> lens;

int ok[MaxN];
bool used[MaxN][MaxN];

void dfs (int row, int col) {
    used[row][col] = true;
    if (a[row + 1][col] == 1 && !used[row + 1][col]) dfs(row + 1, col);
    if (a[row - 1][col] == 1 && !used[row - 1][col]) dfs(row - 1, col);
    if (a[row][col - 1] == 1 && !used[row][col - 1]) dfs(row, col - 1);
    if (a[row][col + 1] == 1 && !used[row][col + 1]) dfs(row, col + 1);
}

int main () {
    int n, m;
    int posX = -1, posY = -1;
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf ("%d", &a[i][j]);
            if (a[i][j] == 1) {
                posX = i;
                posY = j;
            }
        }
    if (posX == -1) {
        printf ("-1");
        return 0;
    }
    dfs(posX, posY);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 1 && !used[i][j]) {
                printf ("-1");
                return 0;
            }
    int hMany = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != 1) continue;
            int cnt = a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1];
            if (cnt == 0) {
                printf ("-1");
                return 0;
            }
            if (cnt % 2 == 1)
                hMany++;
        }
    if (hMany > 2) {
        printf ("-1");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int q = 0;
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1) 
                q++;
            else {
                if (q == 2) {
                    printf ("-1");
                    return 0;
                }
                if (q > 1)
                    lens.push_back(q);
                q = 0;
            }
        if (q != 0) {
            if (q == 2) {
                printf ("-1");
                return 0;
            }
            if (q > 1) 
                lens.push_back(q);
        }
    }
    for (int j = 1; j <= m; j++) {
        int q = 0;
        for (int i = 1; i <= n; i++)
            if (a[i][j] == 1)
                q++;
            else {
                if (q == 2) {
                    printf ("-1");
                    return 0;
                }
                if (q > 1)
                    lens.push_back(q);
                q = 0;
            }
        if (q != 0) {
            if (q == 2) {
                printf ("-1");
                return 0;
            }
            if (q > 1)
                lens.push_back(q);
        }
    }
    for (int i = 0; i < (int)lens.size(); i++) {
        lens[i]--;
    }
    for (int i = 0; i < (int)lens.size(); i++) {
        int cur = lens[i];
        for (int j = 1; j*j <= cur; j++) {
            if (cur % j == 0) {
                ok[j]++;
                if (j * j != cur) ok[cur / j]++;
            }
        }
    }
    bool f = false;
    for (int i = 2; i <= max(n, m); i++)
        if (ok[i] == (int)lens.size()) {
            printf ("%d ", i);
            f = true;
        }
    if (!f)
        printf ("-1");
}