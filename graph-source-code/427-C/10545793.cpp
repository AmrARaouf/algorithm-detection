//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define cnt(x , n) count(x.begin(),x.end(),n)
#define so(x) sort(x.begin(),x.end())
#define rso(x) sort(x.rbegin(),x.rend())
#define mx(x) *max_element(x.begin(),x.end())
#define mn(x) *min_element(x.begin(),x.end())
#define rev(x) reverse(x.begin(),x.end())
#define pb push_back
#define al(n) (n).begin(),(n).end()
#define ral(n) (n).rbegin(),(n).rend()
#define mp make_pair
#define sz size()
#define F first
#define S second
#define rFoR(i,x,n) for(int i=x;i>n;--i)
#define FoR(i,x,n) for(int i = x; i < n; i++)
#define RE(s) freopen(s, "r", stdin)
#define WR(s) freopen(s, "w", stdout)
#define MAX 100009
#define MOD 1000000007

vector<vector<int> > adj;
vector<vector<int> > adjRev;
int t = 0, c = 0, minCost = INT_MAX;
int arr[MAX];
vector<int> r;
bool visited[MAX];
int lebal[MAX];

void DFS1(int i) {
    visited[i] = 1;
    for (int j = 0; j < adjRev[i].sz; ++j) {
        if (!visited[adjRev[i][j]]) {
            DFS1(adjRev[i][j]);
        }
    }
    lebal[++t] = i;
}
void DFS2(int i) {
    visited[i] = 1;
    if (arr[i] < minCost) {
        minCost = arr[i];
        c = 0;
    }
    if (arr[i] == minCost)
        ++c;
    for (int j = 0; j < adj[i].sz; ++j) {
        if (!visited[adj[i][j]]) {
            DFS2(adj[i][j]);
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    RE("text.txt");
#endif
    int n, m, from, to;
    long long res = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    adj.resize(n);
    adjRev.resize(n);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> from >> to;
        --from, --to;
        adj[from].pb(to);
        adjRev[to].pb(from);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (!visited[i]) {
            DFS1(i);
        }
    }
    memset(visited, 0, sizeof(visited));

    for (int i = n; i > 0; --i) {
        if (!visited[lebal[i]]) {
            DFS2(lebal[i]);
            r.pb(c);
            res += minCost;
        }
        minCost = INT_MAX;
    }
    long long numOfWays = 1;
    for (int i = 0; i < r.sz; ++i) {
        numOfWays *= r[i];
        numOfWays %= MOD;
    }
    cout << res << " " << numOfWays << endl;
    return 0;
}
