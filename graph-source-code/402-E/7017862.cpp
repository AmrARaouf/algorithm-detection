//Language: GNU C++



#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)
#define For(i, a, b) for (int (i) = (a); (i) <= (b); (i) ++)
#define db(x) cout << #x << " = " << (x) << endl;
#define dba(a, x, y){cout << #a << " :";For(i, (x), (y))cout<<" "<<(a)[(i)];cout<<endl;}
#define dbp(p){cout << #p << " = (" << p.first << ", " << p.second << ")"<< endl;}
#define mp make_pair
#define pb push_back
#define endl '\n'
#define ll long long
#define ld long double
#define pi 3.1415926535897932384626433832795028
const int INF = INT_MAX;
const ll INFL = LLONG_MAX;

int N, a, c, c2;
bool positive[2100][2100], was[2100];
int dfs2(int n)
{
    if (!was[n])
    {
        c2++;
        was[n]=true;
        rep1(i, N) if (positive[i][n]) dfs2(i);
    }
}
int dfs(int n)
{
    if (!was[n])
    {
        c++;
        was[n]=true;
        rep1(i, N) if (positive[n][i]) dfs(i);
    }
}
int main()
{
	ios_base::sync_with_stdio(0); cout.precision(15);
    cin >> N;
    rep1(i, N) rep1(j, N) cin >> a, positive[i][j] = a>0;
    dfs(1);
    memset(was, 0, sizeof was);
    dfs2(1);
    cout << ((c == N && c2 == N) ? "YES" : "NO") << endl;

}
