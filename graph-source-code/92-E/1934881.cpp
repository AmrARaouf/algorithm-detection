//Language: MS C++


#include <stdio.h>
#define N 100005
#define R 1000000009

int n, m, par[N];

void set_union(int a, int b){
    par[a] = b;
}
int set_par(int a){
    return a == par[a]? a : par[a] = set_par(par[a]);
}

int main(void){
    int i, a, b, pa, pb, ans = 1;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) par[i] = i;
    for(i=1; i<=m; i++){
        scanf("%d %d", &a, &b);
        pa = set_par(a), pb = set_par(b);
        if(pa == pb) ans <<= 1;
        else set_union(pa, pb);
        ans %= R;
        if(ans == 0) printf("%d\n", R-1);
        else printf("%d\n", ans-1);
    }

    return 0;
}