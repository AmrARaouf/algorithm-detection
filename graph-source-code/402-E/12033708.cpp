//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

const int MAX = 2005;
int n, l, seen[MAX], t[MAX];
vector <int> g[MAX], gt[MAX];

void dfs1(int nod) {
    seen[nod] = 1;

    for(int i = 0; i < g[nod].size(); i++) {
        int newn = g[nod][i];

        if(!seen[newn])
            dfs1(newn);
    }

    t[l--] = nod;
}

void dfs2(int nod) {
    seen[nod] = 1;

    for(int i = 0; i < gt[nod].size(); i++) {
        int newn = gt[nod][i];

        if(!seen[newn])
            dfs2(newn);
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d", &n); l = n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int val; scanf("%d", &val);

            if(val > 0 && i != j) {
                g[i].push_back(j);
                gt[j].push_back(i);
            }
        }
    }

    for(int i = 1; i <= n; i++)
        if(!seen[i])
            dfs1(i);

    for(int i = 1; i <= n; i++)
        seen[i] = 0;

    int l = 0;
    for(int i = 1; i <= n; i++) {
        int s = t[i];

        if(!seen[s]) {
            l++;
            dfs2(s);
        }
    }

    if(l == 1)
        printf("YES\n");

    else printf("NO\n");

    return 0;
}
