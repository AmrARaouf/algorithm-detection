//Language: GNU C++


#include <iostream>
#include <cmath>
using namespace std;

int comb[101];
bool mat[101][101];

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif

    for (int i = 3; i <= 100; ++i) {
        comb[i] = (i * (i - 1) * (i - 2)) / 6;
    }

    int n, k;
    cin >> k;
    bool ok = false;

    for (int i = 3; i <= 100; ++i) {
        if (comb[i] == k) {
            ok = true;
            n = i;
            break;
        } else if (comb[i] > k) {
            n = i - 1;
            break;
        } 
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                mat[i][j] = false;
            } else {
                mat[i][j] = true;
            }
        }
    }

    int cmb = comb[n];
    while (ok == false) {
        ++n;
        mat[n][1] = true;
        mat[1][n] = true;
        for (int i = 2; i < n && cmb + i - 1 <= k; ++i) {
            mat[n][i] = true;
            mat[i][n] = true;
            cmb += i - 1;
        }
        if (cmb == k) {
            ok = true;
        }
    }
    cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << mat[i][j];
        }
        cout << '\n';
    }

    return 0;
}

