//Language: GNU C++


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

#define xx first
#define yy second
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pp pop_back
#define pii pair<int ,int>
#define vi vector<int>
using namespace std;
const int maxn=1000000+10;
int deg[maxn];
ll n,m;
ll ans;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        deg[u]++;deg[v]++;
    }
    ans=n*(n-1)*(n-2)/6;
    ans-=m*(n-2);
    for(int i=1;i<=n;i++)ans+=deg[i]*(deg[i]-1)/2;
    cout<<ans;
    //cin>>n;
}