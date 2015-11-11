//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MaxN = 300224;

int n, m;
vector<int> V[MaxN];
int group[MaxN];

int main()
{
    cin.sync_with_stdio(0);
    srand(time(NULL));

    cin >> n >> m;
    for (int i = 1; i <= n; i++) group[i] = rand() % 2;

    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;

        V[from].push_back(to);
        V[to].push_back(from);
    }

    while (true)
    {
        bool found = false;

        for (int i = 1; i <= n; i++)
        {
            int degree = 0;
            for (int j = 0; j < V[i].size(); j++) if (group[i] == group[V[i].at(j)]) degree++;
            if (degree > 1)
            {
                found = true;
                group[i] ^= 1;
            }
        }
        if (!found) break;
    }

    for (int i = 1; i <= n; i++) printf("%d", group[i]);
    printf("\n");

    return 0;
}
