//Language: GNU C++


/*
 * s.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: felix
 */

//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <sstream>
#include <string.h>
#include<fstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL, LL> PII;
typedef vector<int> VI;

#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define For(i,a,b) for(int (i)=(a);i<(b);++(i))
#define FoR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define I insert
#define mod 1000000007
#define INF 1000000001
#define PB push_back
#define x0 sdfhrthrth
#define x1 fdhttrlhn
#define y0 kihrbdb
#define y1 ugvrrtgtrg
#define eps 1e-5
#define X first
#define Y second

map<string, int> mp;
string rmp[100005];
int cnt = 0;
int n, k;
string s;

int ref[100005];
PII val[100005];

int add(string s) {
    int ind;
    if (mp.count(s) == 0) {
        mp[s] = cnt;
        rmp[cnt] = s;
        int r = 0;
        FOR(i,0,s.size())
            if (s[i] == 'r')
                r++;
        val[cnt] = MP(r, s.size());
        cnt++;
    }
    ind = mp[s];
    return ind;
}

VI g[100005];

bool us[100005];

void bfs(int v) {
    queue<int> q;
    q.push(v);
    while (q.size()) {
        int u = q.front();
        q.pop();
        us[u] = true;
        FOR(i,0,g[u].size())
        {
            int to = g[u][i];
            if (val[to] <= val[u])
                continue;
            val[to] = val[u];
            q.push(to);
        }
    }

}

int main() {
    cin >> n;
    FOR(i,0,n)
    {
        cin >> s;
        FOR(j,0,s.size())
            s[j] = tolower(s[j]);
        ref[i] = add(s);
    }

    cin >> k;
    FOR(i,0,k)
    {
        cin >> s;
        FOR(j,0,s.size())
            s[j] = tolower(s[j]);
        int ind1 = add(s);
        cin >> s;
        FOR(j,0,s.size())
            s[j] = tolower(s[j]);
        int ind2 = add(s);
        g[ind2].PB(ind1);
    }

    FOR(i,0,cnt)
        if (!us[i])
            bfs(i);

    PII ans = MP(0, 0);
    FOR(i,0,n)
    {
        ans.X += val[ref[i]].X;
        ans.Y += val[ref[i]].Y;
    }
    cout << ans.X << " " << ans.Y;
    return 0;
}
