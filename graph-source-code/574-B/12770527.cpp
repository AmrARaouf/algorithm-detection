//Language: MS C++


#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;
#define ini(n) scanf("%d",&n)
#define inii(a,b) scanf("%d%d",&a,&b)
const int MAXN=4010;
const int INF=10000005;
bool musketeers[MAXN][MAXN];
int konwPeople[MAXN];
int main() {
    int n, m;
    inii(n, m);
    int a, b;
    memset(konwPeople, 0, sizeof(int)*n);
    memset(musketeers, false, sizeof(musketeers));
    for (int i = 0; i < m; i++) {
        inii(a, b);
        a--; b--;
        musketeers[a][b] = musketeers[b][a] = true;
        konwPeople[a]++; konwPeople[b]++;
    }
    int minValue = INF;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (musketeers[i][j]) {
                for (int k = j + 1; k < n; k++) {
                    if (musketeers[i][k] && musketeers[j][k]) {
                        minValue = min(minValue, konwPeople[i] + konwPeople[j] + konwPeople[k] - 6);
                    }
                }
            }
        }
    }
    if (minValue == INF)
        printf("-1\n");
    else
        printf("%d\n", minValue);
    return 0;
}