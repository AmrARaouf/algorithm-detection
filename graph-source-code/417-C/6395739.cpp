//Language: GNU C++


#include <stdio.h>
#include <string.h>

struct node {
    int x, y;
} ans[940710];
int a[1010][1010];


int main(int argc, char *argv[]) {
    int n, k, i, j, cnt;
    int now, flag;
    while(scanf("%d%d", &n, &k) != EOF) {
        memset(a, 0, sizeof(a));
        memset(ans, 0, sizeof(ans));
        cnt = 0;
        flag = 0;
        for (i = 1; i <= n; i++) 
        {
            now = 0;
            if(flag == 0) 
            {
                for (j = 1; j <= n; j++) 
                {
                    if(i == j) continue;
                    if(a[i] [j]  == 1) continue;
                    a[i] [j]  = a[j] [i]  = 1;
                    ans[cnt] .x = i;
                    ans[cnt] .y = j;
                    cnt ++;
                    now ++;
                    if(now == k) 
                    {
                        break;
                    }
                }
                if(now != k) 
                {
                    flag = 1;
                }
            }
        }
        if(flag == 0) {
            printf("%d\n", cnt);
            for (i = 0; i < cnt; i++) {
                printf("%d %d\n", ans[i] .x, ans[i] .y);
            }
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
