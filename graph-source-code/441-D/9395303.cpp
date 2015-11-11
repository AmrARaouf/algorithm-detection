//Language: GNU C++


#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int N = 3005;
int n, m, k, p[N];
bool vis[N];
inline void mk(int v) {
    for (int i = v;!vis[i];i = p[i])vis[i] = 1;
}
int main() {
    while(~scanf("%d", &n)){
        for (int i = 0;i < n;++i)scanf("%d", &p[i]),--p[i];
        scanf("%d", &m);
        m = n - m;
        for (int i = 0;i < n;++i)if (!vis[i])k++,mk(i);
        for (int i = 0;i < n;++i)vis[i] = false;
        printf("%d\n", (int)abs(k-m));
        if (k > m) {
            mk(0);
            for (int i = 1;i < n && k > m;++i) {
                if (!vis[i]) {
                    printf("%d %d ", 1, i+1);//  minimize sequence lexorder
                    k--;
                    mk(i);
                }
            }
        }else if (k < m) {
            for (int i = 0;i < n && k < m;++i) {
                vector <int> pos(n, -1);
                int cur = 0;
                for (int j = p[i];j != i;j = p[j])pos[j] = ++cur;//mark order in this ring
                pos[i] = cur;
                cur = 0;
                for (int j = i+1;j < n && k < m;++j)//searching for in same ring 
                    if (pos[j] > cur) {
                        printf("%d %d ", i+1, j+1);
                        k++;
                        cur = pos[j];
                        swap(p[i], p[j]);
                    }
            }
        }
        puts("");
    }
    return 0;
}
