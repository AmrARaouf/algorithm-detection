//Language: GNU C++


#include <iostream>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <vector>

#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))

#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)

#define FOR(a, b, c) for(int a = b; a <= c; a++)
#define REP(a, b, c) for(int a = b; a < c; a++)

#define FORP(a, b) for(__typeof (b.begin ()) a = b.begin (); a != b.end (); a++)
#define FORS(a, b) for(int a = 0; a < (int) b.size (); a++)

#define ALL(a) a.begin (), a.end ()

#define fill(a, b) memset (a, b, sizeof (a))

#define X first
#define Y second

typedef long long LL;
typedef pair <int, int> pii;
typedef pair <int, pii> p3i;
typedef pair <pii, pii> p4i;

const int MAXINT = 1111 * 1111 * 1111;
const long long MAXLINT = MAXINT * 1ll * MAXINT;
const long double EPS = 1e-10;

#define FILE_NAME "io"

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, maxk;
int a[1005][1005];
int b[1005][1005];
int u[1005][1005];

int gcd (int a, int b) {
    if (!a) return b;
    if (!b) return a;
    while ((a%=b)&&(b%=a));
    return a+b;
}

bool OK (int x, int y) {
    return x>0 && y>0 && x<=n && y<=m && a[x][y];
}

void RUN (int x, int y, int dx, int dy) {
    int len = 0; x+=dx, y+=dy;
    while (OK (x, y)) {
        len++;
        if (a[x+dy][y+dx] || a[x-dy][y-dx]) maxk = gcd (maxk, len);
        x+=dx; y+=dy;
    }

    maxk = gcd (maxk, len);
}

void RUN (int x, int y) {
    for (int i = 0; i < 4; i++)
        RUN (x, y, dx[i], dy[i]);
}

void BUILD (int x, int y) {
    memset (u, 0, sizeof (u));
    queue <pii> q;
    q.push (mp (x, y));
    u[x][y] = 1;
    while (!q.empty ()) {
        x = q.front ().X;
        y = q.front ().Y;
        q.pop ();
        for (int i = 0; i < 4; i++) if (OK (x+dx[i], y+dy[i])) {
            if (!u[x+dx[i]][y+dy[i]])
                q.push (mp (x+dx[i], y+dy[i])),
                u[x+dx[i]][y+dy[i]] = 1;

            b[x][y]++;
        }
    }
}

void QUEUE (int x, int y) {
    u[x][y] = 1;
    for (int i = 0; i < 4; i++)
        if (OK (x+dx[i], y+dy[i]) && !u[x+dx[i]][y+dy[i]])
            QUEUE (x+dx[i], y+dy[i]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen (FILE_NAME".in", "r", stdin);
    freopen (FILE_NAME".out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        scanf ("%d", &a[i][j]);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) if (a[i][j] && !u[i][j])
        QUEUE (i, j), cnt++;

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        if (!a[i][j]) continue;
        int A,B; A=B=0;
        for (int k = 0; k < 4; k+=2)
            A += a[i+dx[k]][j+dy[k]],
            B += a[i+dx[k+1]][j+dy[k+1]];

        if ((A != 0 && B != 0) || ((A+B)&1))
            RUN (i, j);
    }

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        if (!a[i][j]) continue;
        int A,B; A=B=0;
        for (int k = 0; k < 4; k+=2)
            A += a[i+dx[k]][j+dy[k]],
            B += a[i+dx[k+1]][j+dy[k+1]];

        if ((A != 0 && B != 0) || ((A+B)&1)){
            BUILD (i, j); goto EXIT;
        }
    }

    EXIT:

    int sum=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        sum += b[i][j]&1;

    if (cnt>1) maxk=0;
    if (sum!=0 && sum!=2) maxk=0;
    if (maxk <= 1) { printf ("-1"); return 0; }
    for (int i = 2; i<=maxk; i++) if ((maxk%i) == 0)
        printf ("%d ", i);
    return 0;
}