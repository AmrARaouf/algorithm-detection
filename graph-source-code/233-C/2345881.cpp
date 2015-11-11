//Language: MS C++


#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int k, n;
char m[110][110];

int main(){
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> k;
    memset(m, 0, sizeof(m));
    int l = 1, r = 100;
    while (r - l > 1){
        int m1 = (l + r) / 2;
        if (m1 * (m1 - 1) * (m1 - 2) / 6 <= k)
            l = m1;
        else
            r = m1;
    }
    for (int i = n; i < n + l; i++)
        for (int j = n; j < n + l; j++)
            if (i != j)
                m[i][j] = 1;
    n = l;
    k -= l * (l - 1) * (l - 2) / 6;

    while (k){
        l = 1, r = 100;
        while (r - l > 1){
            int m1 = (l + r) / 2;
            if (m1 * (m1 - 1) / 2 <= k)
                l = m1;
            else
                r = m1;
        }
        k -= l * (l - 1) / 2;
        for (int i = 0; i < l; i++)
            m[i][n] = 1, m[n][i] = 1;
        n++;
    }

    cout << n << '\n';
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << (char)(m[i][j] + 48);
        cout << '\n';
    }
    return 0;
}