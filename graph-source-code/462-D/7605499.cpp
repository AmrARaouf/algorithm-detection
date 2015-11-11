//Language: GNU C++


#include <bits/stdc++.h>
#define FRO(i,a,b) for(int i=a; i>=b; i--)
#define FOR(i,a,b)  for(int i=a; i<=b; i++)
#define filein(t)  freopen(t , "r" , stdin)
#define fileout(t) freopen(t , "w" , stdout)
#define rep(i,n) for(int i=0; i<n; i++)
#define ll  long long
#define maxn 100005
#define ln 10000000003
#define oo 1000000007

using namespace std;

vector <int> a[maxn];
int kt[maxn];
int dd[maxn];
ll co[maxn];
ll ko[maxn];
ll n;

void DFS(int u)
{
    kt[u] = 1;
    co[u] = dd[u];
    ko[u] = 1 - dd[u];
    rep(i,a[u].size())
    {
        int v = a[u][i];
        if(kt[v] == 0)
        {
            DFS(v);
            co[u] = ( co[u] * (co[v] + ko[v]) % oo + ko[u] * co[v] % oo ) % oo;
            ko[u] = ( ko[u] * (co[v] + ko[v]) % oo);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //filein("inp.txt");
    //fileout("out.txt");
    int n, u;
    cin>>n;
    FOR(i,0,n-2)
    {
        cin>>u;
        a[i+1].push_back(u);
        a[u].push_back(i+1);
    }
    FOR(i,0,n-1) cin>>dd[i];
    DFS(0);
    cout<<co[0];
}
