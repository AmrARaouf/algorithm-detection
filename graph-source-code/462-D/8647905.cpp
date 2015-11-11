//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

vector <vi> al;
ll dp[100011][4];
int x[100011];

ll p = 1000*1000*1000 + 7;

void DFS(int v)
{
    dp[v][0] = 1;
    dp[v][1] = 0;
    for (int i=0 ; i<al[v].size() ; i++)
    {
        int u = al[v][i];
        DFS(u);
        dp[v][1] = (dp[v][1] * dp[u][0])%p;
        dp[v][1] = (dp[v][1] + (dp[v][0] * dp[u][1])%p)%p;
        dp[v][0] = (dp[v][0] * dp[u][0])%p;
    }
    if (x[v] == 1)
        dp[v][1] = dp[v][0];
    else
        dp[v][0] = (dp[v][0] + dp[v][1])%p;
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n;
    scanf("%d", &n);
    al.assign(n+5, vi());
    for (int i=0 ; i<n-1 ; i++)
    {
        int t;
        scanf("%d", &t);
        al[t].push_back(i+1);
    }
    for (int i=0 ; i<n ; i++) scanf("%d", &x[i]);
    DFS(0);
    printf("%d\n", dp[0][1]);
}
