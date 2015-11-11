//Language: GNU C++0x


#include<bits/stdc++.h>
using namespace std;
vector<int> e[1000];
int a[100];

main() {

    int k;
    scanf("%d", &k);

    if (k == 1) {
        printf("2\nNY\nYN");
        return 0;
    }

    int timer = 2, len = 0;
    for (int cur = 0, i = 1; k >= (1 << i); i++) {
        e[cur].push_back(timer);
        e[cur].push_back(timer + 1);
        e[timer].push_back(timer + 2);
        e[timer + 1].push_back(timer + 2);
        cur = timer + 2;
        timer += 3;
        a[i] = cur;
        len += 2;
    }
    e[timer - 1].push_back(1);
    len++;

    char flag = false;
    for (int i = 30; i >= 0; i--) {
        if ((k & (1 << i)) == 0) continue;
        if (!flag) {
            flag = true;
            continue;
        }
        int cur_len = i * 2, cur = a[i];
        while(cur_len + 1 < len) {
            e[cur].push_back(timer);
            cur = timer++;
            cur_len++;
        }
        e[cur].push_back(1);
    }

    #ifndef ONLINE_JUDGE
    for (int v = 0; v < timer; v++)
        for (int to : e[v])
            printf("%d %d\n", v + 1, to + 1);
    return 0;
    #endif // ONLINE_JUDGE

    int n = timer;
    char s[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            s[i][j] = 'N';
    for (int v = 0; v < n; v++)
        for (int to : e[v])
            s[v][to] = s[to][v] = 'Y';

    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c", s[i][j]);
        printf("\n");
    }

    return 0;
}