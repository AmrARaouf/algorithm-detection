//Language: GNU C++11


//          In the name of Allah

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    if (k % 2 == 0)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    cout << (4 * k) - 2 << ' ' << (2 * (k - 1) * (k - 1)) + (3 * k) - 2 << '\n';
    for (int i = 1; i < k; i++)
    {
        for (int j = k; j <= (2 * k - 2); j++)
        {
            cout << i << ' ' << j << '\n';
        }
    }

    for (int i = 1; i < k; i++)
    {
        for (int j = k; j <= (2 * k - 2); j++)
        {
            cout << (2 * k - 2) + i << ' ' << (2 * k - 2) + j << '\n';
        }
    }

    for (int i = 1; i < k; i++)
        cout << (4 * k - 3) << ' ' << i << '\n';
    for (int i = (2 * k - 1); i < (3 * k - 2); i++)
        cout << (4 * k - 2) << ' ' << i << '\n';

    for (int i = k; i < (2 * k - 2); i++)
    {
        cout << i << ' ' << i + 1 << '\n';
        i++;
    }
    for (int i = (3 * k - 2); i < (4 * k - 4); i++)
    {
        cout << i << ' ' << i + 1 << '\n';
        i++;
    }

    cout << (4 * k - 3) << ' ' << (4 * k - 2) << '\n';

    return 0;
}
