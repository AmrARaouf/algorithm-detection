//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define eps 1e-8
#define oo (1LL<<45LL)

#define pll pair<long long, long long>

using namespace std;

long long T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an;
long long d[1010][1010], f[1010][1010];
long long b[1010], c[1010], v[1010], dd[1010];
vector < pair<long long,long long> > a[1010];

int main(){
        scanf("%I64d%I64d", &n, &m);
        scanf("%I64d%I64d", &e, &r);
        e--; r--;
        for (int i=0; i<=n; i++)
                for (int j=0; j<=n; j++)
                        d[i][j] = -1;
        for (int i=0; i<m; i++){
                scanf("%I64d%I64d%I64d", &q, &w, &t);
                q--; w--;
                pair <long long, long long> te = make_pair(w, t);
                a[q].push_back(te);
                te = make_pair(q, t);
                a[w].push_back(te);
        }
/*      for (int i=0; i<n; i++){
                for (int j=0; j<a[i].size(); j++)
                        printf("%d %d %d ", i, a[i][j].first, a[i][j].second);
                puts("");
        }
*/
        for (int rr = 0; rr < n; rr++){
                for (int i=0; i<n; i++)
                        dd[i] = oo, v[i] = 0;
//              priority_queue<pair<long long,long long> > qq;
                priority_queue< pll, vector< pll >, greater< pll > > qq;
                qq.push((pair <long long,long long> (0, rr)));
                while (!qq.empty()){
                        pair <long long,long long> tt = qq.top(); qq.pop();
//                      printf("%d %d\n", tt.first, tt.second);
                        if (v[tt.second] == 1) continue;
                        v[tt.second] = 1;
                        if (dd[tt.second] > tt.first) dd[tt.second] = tt.first;
                        for (int i=0; i<a[tt.second].size(); i++)
                                qq.push(pair <long long, long long> ((tt.first + a[tt.second][i].second), a[tt.second][i].first));
                }
                for (int i=0; i<n; i++)
                        f[rr][i] = dd[i];
        }
/*
        for (int i=0; i<n; i++){
                for (int j=0; j<n; j++)
                        printf("%d ", f[i][j]);
                puts("");
        }
        puts("");
*/

        for (int i=0; i<n; i++)
                scanf("%I64d%I64d", &b[i], &c[i]);
        for (int i=0; i<n; i++)
                for (int j=0; j<n; j++){
                        if (f[i][j] <= b[i])
                                d[i][j] = c[i];
                        else d[i][j] = oo;
                }
        for (int i=0; i<n; i++)
                d[i][i] = 0;

/*
        for (int i=0; i<n; i++){
                for (int j=0; j<n; j++)
                        printf("%d ", d[i][j]);
                puts("");
        }
*/

        for (int i=0; i<n; i++)
                v[i] = 0, dd[i] = oo;
        dd[e] = 0;
        for (int i=0; i<n; i++){
                mi = oo;
                for (int j=0; j<n; j++)
                        if (dd[j] < mi && v[j] == 0)
                                mi = dd[j], w = j;
                v[w] = 1;
//              printf("%d %d\n", w, mi);
                for (int j=0; j<n; j++)
                        if (d[w][j] != oo && v[j] == 0 && dd[j] > d[w][j] + dd[w])
                                dd[j] = d[w][j] + dd[w];
        }
        if (dd[r] > oo-1000)
                printf("-1\n");
        else printf("%I64d\n", dd[r]);



        return 0;
}