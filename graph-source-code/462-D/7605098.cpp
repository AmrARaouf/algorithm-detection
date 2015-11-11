//Language: GNU C++


//#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <iomanip>
#include <queue>
#include <iostream>
#include <ctime>
#include <fstream>
#include <functional>
#include <cstdlib>
#include <iterator>

#define ll long long
#define pb push_back
#define mp make_pair
#define D long double
#define pi pair<int,int>
#define si set <pi>
#define F first
#define S second
#define forn(i,n) for (int(i)=0;(i)<(n);i++)
#define forr(i,x,y) for (int(i)=(x);(i)<=(y);i++)
#define ford(i,x,y) for (int(i)=(x);(i)>=(y);i--)
#define rev reverse
#define in insert
#define er erase
#define all(n) (n).begin(),(n).end()
#define graf vector<vector<pi> >
#define graf1 vector<vector<ll> >
#define sqr(a) (a)*(a)

const ll INF=1000000007;
const D cp=2*asin(1.0);
const D eps=1e-9;
const ll mod=1000000007;

using namespace std;

ll n,dp[100001][2],x[100001];
graf1 a;

void dfs(int v, int p=-1)
{
    dp[v][0]=1;
    dp[v][1]=0;
    for(int i=0;i<a[v].size();i++)
    {
        int u=a[v][i];
        if (u==p) continue;
        dfs(u);
        dp[v][1]*=dp[u][0];
        dp[v][1]%=mod;
        dp[v][1]+=dp[v][0]*dp[u][1];
        dp[v][1]%=mod;
        dp[v][0]*=dp[u][0];
        dp[v][0]%=mod;
    }
    if (x[v]==1)  dp[v][1]=dp[v][0]; else dp[v][0]+=dp[v][1],dp[v][0]%=mod;
}

int main()
{
    cin>>n;
    a.resize(n);
    forn(i,n-1) {int y;cin>>y;a[y].pb(i+1);}
    forn(i,n) cin>>x[i];
    dfs(0);
    cout<<dp[0][1];
    return 0;
}
