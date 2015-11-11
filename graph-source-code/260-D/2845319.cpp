//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const int MaxN = 100224;

int n, color, weight;

set<pair<int, int> > S1, S2;
int cntb, cntr;

int main()
{
    cin.sync_with_stdio(0);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> color >> weight;

        if (color) S1.insert(make_pair(weight, i));
        else S2.insert(make_pair(weight, i));

        if (color) cntb++;
        else cntr++;

    }

    int edges = 0;

    for (set<pair<int, int> >::iterator it1 = S1.begin(), it2 = S2.begin(); !S1.empty() && !S2.empty() ; )
    {
        int w1 = (*it1).first, w2 = (*it2).first;

        if (w1 > w2)
        {
            printf("%d %d %d\n", (*it1).second , (*it2).second, w2);

            int idx = (*it1).second;

            S2.erase(it2);
            S1.erase(it1);
            it2 = S2.begin();

            S1.insert(make_pair(w1 - w2, idx));
            it1 = S1.begin();
        }
        else if  (w2 > w1)
        {
            printf("%d %d %d\n", (*it1).second, (*it2).second, w1);

            int idx = (*it2).second;

            S2.erase(it2);
            S1.erase(it1);
            it1 = S1.begin();

            S2.insert(make_pair(w2 - w1, idx));
            it2 = S2.begin();
        }
        else
        {
            int i = (*it1).second, j = (*it2).second;

            S1.erase(it1);
            S2.erase(it2);

            if (cntr > cntb)
            {
                S1.insert(make_pair(0, i) );
                cntr--;
            }
            else {S2.insert(make_pair(0, j) ); cntb--;}

            it1 = S1.begin();
            it2 = S2.begin();
            printf("%d %d %d\n", i , j, w1);
        }
    }

    return 0;
}
