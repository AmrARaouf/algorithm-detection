//Language: GNU C++0x


#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<int> > res;
    res.resize(n);
    if(2*k + 1 > n) {
        printf("-1\n");
    } else {
        printf("%d\n", n * k);
        for(int i=0; i<n; i++) {
            for(int j=0; j<k; j++) {
                int p = (i + j + 1) % n;
                printf("%d %d\n", i + 1, p + 1);
            }
        }
    }
}
