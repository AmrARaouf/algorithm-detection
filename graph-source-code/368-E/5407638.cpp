//Language: GNU C++


/**
 * Copyright (c) 2013 Authors. All rights reserved.
 * 
 * FileName: E.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2013-12-11
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>

using namespace std;

typedef long long LL;
typedef pair<int, int> Pii;
typedef complex<double> Point;
typedef complex<double> Vector;
#define X real()
#define Y imag()

const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;
const int hash_mod = 1000037;
const double pi = acos(-1);
const double eps = 1e-10;

const int maxm = 100000 + 5;

int n, m;
int q[maxm], w[maxm];

bool check(LL x)
{
        LL cnt = x * (x - 1) / 2;
        if (x % 2 == 0) cnt += x / 2 - 1;
        return cnt < n;
}

int main()
{
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i)
                scanf("%d%d", &q[i], &w[i]);
        sort(w, w + m);
        int l = 1, r = m;
        while (l < r) {
                int mid = l + (r - l + 1) / 2;
                if (check(mid)) l = mid;
                else r = mid - 1;
        }
        LL res = 0;
        for (int i = 0; i < l; ++i)
                res += w[m-i-1];
        printf("%I64d\n", res);

        return 0;
}
