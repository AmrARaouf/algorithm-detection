//Language: GNU C++0x


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

struct seg {
    int x1, y1, x2, y2;
    seg() {}
    seg(int xa, int ya, int xb, int yb) {
        x1 = min(xa,xb);
        x2 = max(xa,xb);
        y1 = min(ya,yb);
        y2 = max(ya,yb);
    }
    int dist(struct seg& s) {
        int dx = 0, dy = 0;
        if (s.x1 > x2) dx = s.x1 - x2;
        else if (s.x2 < x1) dx = x1 - s.x2;
        if (s.y1 > y2) dy = s.y1 - y2;
        else if (s.y2 < y1) dy = y1 - s.y2;
        return dx*dx + dy*dy;
    }
}s[1000];
int d[1000], h[1000][1000];

int main() {
    int a, b, xa, ya, xb, yb, n;
    int i, j, x1, x2, y1, y2;
    cin>>a>>b>>xa>>ya>>xb>>yb>>n;
    for (i=0; i<n; i++) {
        cin>>x1>>y1>>x2>>y2;
        s[i] = seg(x1,y1,x2,y2);
    }
    struct seg from = seg(xa,ya,xa,ya);
    struct seg to = seg(xb,yb,xb,yb);
    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            if (s[i].dist(s[j]) <= a*a) h[i][j] = h[j][i] = 1;
        }
    }
    queue<int> q;
    for (i=0 ;i<n; i++) {
        if (s[i].dist(from) <= a*a) q.push(i), d[i] = 1;
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (i=0; i<n; i++) {
            if (d[i]==0 && h[cur][i]) {
                q.push(i), d[i] = d[cur] + 1;
            }
        }
    }
    double ans = 1e8;
    for (i=0; i<n; i++) {
        int dist = s[i].dist(to);
        if (d[i]!=0 && dist <= a*a) {
            ans = min(d[i]*(a+b)+sqrt(dist*1.0), ans);
        }
    }
    if (from.dist(to) <= a*a) ans = min(sqrt(from.dist(to)*1.0), ans);
    if (ans == 1e8) cout<<-1<<endl;
    else cout<<ans<<endl;
}