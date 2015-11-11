//Language: GNU C++


#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;

vector<int> a[100005], b[100005];
int la[100005] = { 0 }, lb[100005] = { 0 };
bool aa[100005] = { 0 }, bb[100005] = { 0 };
int s[100005] = { 0 };

int main()
{
    int n = 0, m = 0, i = 0, x = 0, y = 0, ga = 0, gb = 0, p = 0, sz = 0;

    while (scanf("%d%d", &n, &m) == 2) {
        for (i = 1; i <= n; i ++) {
            scanf("%d", s + i);
            a[i].clear();
            b[i].clear();
        }
        while (m --) {
            scanf("%d%d", &x, &y);
            a[x].push_back(y);
            b[y].push_back(x);
        }
        memset(aa, 0, sizeof(aa));
        memset(bb, 0, sizeof(bb));
        ga = 0;
        gb = 0;
        for (i = 1; i <= n; i ++) {
            if (s[i] == 1) {
                la[ga ++] = i;
                aa[i] = true;
            }
            else if (s[i] == 2) {
                lb[gb ++] = i;
                bb[i] = true;
            }
        }

        p = 0;
        while (p < ga) {
            x = la[p ++];
            sz = a[x].size();
            for (i = 0; i < sz; i ++) {
                y = a[x][i];
                if (!aa[y]) {
                    aa[y] = true;
                    la[ga ++] = y;
                }
            }
        }

        p = 0;
        while (p < gb) {
            y = lb[p ++];
            sz = b[y].size();
            for (i = 0; i < sz; i ++) {
                x = b[y][i];
                if (!bb[x]) {
                    bb[x] = true;
                    if (s[x] != 1) {
                        lb[gb ++] = x;
                    }
                }
            }
        }

        for (i = 1; i <= n; i ++) {
            if (aa[i] && bb[i]) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
    }
    return 0;
}























