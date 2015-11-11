//Language: GNU C++0x


#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

const int N = 3005;

int n, m, p[N], cnt;
bool vis[N];
vector <pair<int, int> > opt;

int main(){
    scanf("%d", &n);
    for (int i=1;i<=n;++i) scanf("%d", &p[i]);
    scanf("%d", &m);
    cnt = n;
    for (int i=1;i<=n;++i){
        if (vis[i]) continue;
        vis[i] = true;
        for (int j=p[i]; j != i; j = p[j]) vis[j] = true;
        cnt--;
    }
    if (cnt == m){
        puts("0");
        return 0;
    }
    if (cnt > m){
        int bx;
        printf("%d\n", cnt - m);
        int t = cnt - m;
        while (t--){
            for (bx = 1; bx == p[bx] && bx <= n; ++bx);
            if (bx > n) break;
            int k = n;
            for (int i = p[bx]; i != bx; i = p[i]){
                if (k>i) k=i;
            }
            swap(p[bx], p[k]);
            printf("%d %d ", bx, k);
        }
        puts("");
    }
    else{
        memset(vis, false, sizeof vis);
        int bx = 1;
        vis[1] = true;
        for (int i = p[1]; i != 1; i = p[i]) vis[i] = true;
        printf("%d\n", m - cnt);
        for (int i = 1; i<=m - cnt; ++i){
            while (vis[bx]) ++bx;
            printf("1 %d ", bx);
            vis[bx] = true;
            for (int i = p[bx]; i != bx && !vis[i]; i = p[i]) vis[i] = true;
            swap(p[1], p[bx]);
        }
        puts("");
    }
}
