//Language: GNU C++


#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> road[3010];
long long damn[3010][3010];

int main()
{
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) road[i].clear();
        memset(damn, 0, sizeof(damn));
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            road[a].push_back(b);
        }
        
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            queue<int> q;
            for (int j = 0; j < road[i].size(); j++)
                q.push(road[i][j]);
            while (!q.empty()) {
                int x = q.front(); q.pop();
                for (int j = 0; j < road[x].size(); j++)
                    if (road[x][j] != i)
                        damn[i][road[x][j]]++;
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (damn[i][j] >= 2)
                    ans += damn[i][j] * (damn[i][j] - 1) / 2;
    
        cout << ans << endl;
    }
    return 0;
}