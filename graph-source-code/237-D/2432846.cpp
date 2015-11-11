//Language: GNU C++


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adj[100500];

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    printf("%d\n", n - 1);
    for(int i = 1; i < n; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        printf("2 %d %d\n", from, to);
        ++cnt;
        adj[from].push_back(cnt);
        adj[to].push_back(cnt);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < adj[i].size(); j++)
            printf("%d %d\n", adj[i][0], adj[i][j]);
    }
    return 0;
}
