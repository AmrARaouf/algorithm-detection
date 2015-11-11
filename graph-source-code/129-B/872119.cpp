//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, answer = 0;
vector <vector <int> > im;
vector <pair <int, int> > to_ban;
bool delta;

int main(void)
{
#ifdef CUCUMBER
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
#endif
    cin >> n >> m;
    im.resize(n);
    for (int loop = 0; loop < m; loop++)
    {
        int first, second;
        cin >> first >> second;
        first--, second--;
        im[first].push_back(second);
        im[second].push_back(first);
    }

    delta = true;
    while (delta)
    {
        delta = false;
        for (int look = 0; look < n; look++)
        {
            pair <int, int> neigh = make_pair(0,0);
            for (int run = 0; run < im[look].size(); run++)
            {
                if (im[look][run] != -1)
                    neigh.first++, neigh.second = run;
            }
            if (neigh.first == 1)
                to_ban.push_back(make_pair(look, neigh.second));
        } 
        
        if (to_ban.size() != 0)
        {
            answer++, delta = true;
            for (int loop = 0; loop < to_ban.size(); loop++)
            {
                int tg_inx = to_ban[loop].first;
                int tg_edge= to_ban[loop].second;
                /*cerr << tg_inx << " " << tg_edge << "\n";
                for (int x = 0; x < im.size(); x++)
                {
                    for (int y = 0; y < im[x].size(); y++)
                        cerr << im[x][y] << " ";
                    cerr << "\n";
                } 
                cerr << "\n";*/
                if (im[tg_inx][tg_edge] == -1)
                    continue;
                for (int run = 0; run < im[im[tg_inx][tg_edge]].size(); run++)
                {
                    if (im[im[tg_inx][tg_edge]][run] == tg_inx)
                    {
                        im[im[tg_inx][tg_edge]][run] = -1;
                        break;
                    }
                }
                im[tg_inx][tg_edge] = -1;
            }
            to_ban.clear();
        }
    }

    cout << answer << "\n";

    return 0;
}