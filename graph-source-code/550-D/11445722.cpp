//Language: MS C++


#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <exception>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if (n%2 == 0)
        cout<<"NO\n";
    else 
    {
        cout<<"YES\n";
        if (n == 1)
            cout<<"2 1\n1 2";
        else
        {
            cout<<(n + 2)*2<<' '<<n*(n + 2)<<endl;
            vector<int> deg((n + 2) * 2 + 1);
            for (int i = 1; i < n; ++i)
                for (int j = i + 1; j < n + 2; ++j)
                {
                    if (i > 2 && (j == i + 1) && i % 2) continue;
                    cout<<i<<' ' <<j<<endl;
                    ++deg[i];
                    ++deg[j];
                }
            for (int i = 3; i < n + 2; ++i)
            {
                cout<<i<<' '<<n + 2<<endl;
                ++deg[i];
                ++deg[n + 2];
            }
            cout<<n + 2<<' ' << n + 3<<endl;
            ++deg[n + 2];
            ++deg[n + 3];
            for (int i = n + 4; i < 2 * n + 3; ++i)
                for (int j = i + 1; j < 2 * n + 5; ++j)
                {
                    if (i > n + 5 && (j == i + 1) && i % 2) continue;
                    cout<<i<<' ' <<j<<endl;
                    ++deg[i];
                    ++deg[j];
                }
            for (int i = n + 6; i < 2 * n + 5; ++i)
            {
                cout<<i<<' '<<n + 3<<endl;
                ++deg[i];
                ++deg[n + 3];
            }

            /*cout<<deg[1]<<' '<<1<<endl;;
            for (int i = 2; i < 2 * n + 5; ++i)
                if (deg[i] != deg[i - 1]) cout<<deg[i]<<' ' <<i<<endl;*/
        }

    }
    return 0;
}
