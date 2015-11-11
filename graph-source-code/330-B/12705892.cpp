//Language: GNU C++


#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define ALL(z) z.begin(), z.end()
#define F first
#define S second

using namespace std;

int n, m, x, y, ans, met, a[1500][1500];

int main()
{
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m;

    for (int i = 1; i <= m; ++i){
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for (int i = 1; i <= n; ++i){
        met = 0;
        for (int j = 1; j <= n; ++j){
            if (a[i][j] == 1){
                met = 1;
                break;
            }
        }
        if (!met){
            cout << n - 1 << endl;
            for (int j = 1; j <= n; ++j){
                if (i != j) cout << i << " " << j << endl;
            }
            break;
        }
    }
    return 0;
}
