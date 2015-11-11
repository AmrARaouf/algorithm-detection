//Language: GNU C++


/*
 * CCivilization.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: abdelkarim
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 300008;

int vis[N];
int memo[N];
int id[N];

void init(int n) {
    for (int i = 0; i <= n; i++)
        id[i] = i;
}

int root(int i) {
    while (i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

bool isC(int a, int b) {
    return root(a) == root(b);
}

void Union(int a, int b) {
    a = root(a), b = root(b);
    if (a == b)
        return;
    if (a > b)
        swap(a, b);
    id[b] = a;
}

int head[N], to[2 * N], nxt[2 * N], lst;

void addEdge(int f, int t) {
    nxt[lst] = head[f];
    head[f] = lst;
    to[lst++] = t;
}

int mx, l;
int ID;
void dfs(int src, int d = 0) {
    if (vis[src] == ID)
        return;
    vis[src] = ID;
    if (d > mx) {
        mx = d;
        l = src;
    }
    for (int i = head[src]; i != -1; i = nxt[i]) {
        int nxt = to[i];
        dfs(nxt, d + 1);
    }
}

#define GETCHAR getchar
void Read(int &x) {
    char c, r = 0, n = 0;
    x = 0;
    for (;;) {
        c = GETCHAR();
        if ((c == '-') && (!r))
            n = 1;
        else if ((c >= '0') && (c <= '9'))
            x = x * 10 + c - '0', r = 1;
        else if (r)
            break;
    }
    if (n)
        x = -x;
}

int main() {
    ID = 0;
    int n, m, q;
    Read(n);
    Read(m);
    Read(q);
    init(n);
    memset(head, -1, sizeof head);
    lst = 0;
    while (m--) {
        int a, b;
        Read(a);
        Read(b);
        a--, b--;
        addEdge(a, b);
        addEdge(b, a);
        Union(a, b);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ID++;
            mx = -1;
            dfs(i);
            mx = -1;
            ID++;
            dfs(l);
            memo[root(i)] = mx;
        }
    }
    int type, a, b;
    while (q--) {
        Read(type);
        if (type == 2) {
            Read(a);
            Read(b);
            a--, b--;
            int r1 = root(a);
            int r2 = root(b);

            if (r1 == r2)
                continue;
            if (r1 > r2)
                swap(r1, r2);
            Union(a, b);
            int Max = max(memo[r1], memo[r2]);
            int Min = min(memo[r1], memo[r2]);
            memo[r1] = max(Max, (Max + 1) / 2 + (Min + 1) / 2 + 1);
        } else {
            Read(a);
            a--;
            a = root(a);
            printf("%d\n", memo[a]);
        }
    }

}
