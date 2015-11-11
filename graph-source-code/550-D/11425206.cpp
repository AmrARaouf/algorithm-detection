//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

#define rep(x, y, z) for (int x = y; x < z; x++)
#define s(x) (int)x.size()
#define pb(i) push_back(i)
#define pop pop_back();
#define mp(i, j) make_pair(i, j)
#define pii pair<int, int>
#define ll long long
#define ull unsigned long long
#define vec vector 
#define fs first
#define sec second
#define str string

const int Maxn = 1000;

int k;

void solve()
{
    cout << 4 * k - 2 << " " << k * (2 * k - 1) << endl;
    rep(i, 2, k + 1)
        cout << "1" << " " << i << endl;
    rep(i, 2, k + 1)
        rep(j, k + 1, 2 * k)
            cout << i << " " << j << endl;
    for(int i = k + 1; i < 2 * k; i += 2)
        cout << i << " " << i + 1 << endl;
    rep(i, 2 * k + 1, 3 * k)
        cout << 2 * k << " " << i << endl;
    rep(i, 2 * k + 1, 3 * k)
        rep(j, 3 * k, 4 * k - 1)
            cout << i << " " << j << endl;
    for(int i = 3 * k; i < 4 * k - 1; i += 2)
        cout << i << " " << i + 1 << endl;
    cout << "1 " << 2 * k << endl;
}

int main()
{
    cin >> k;
    if (k % 2 == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    solve();
    return 0;
}




