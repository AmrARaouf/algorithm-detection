//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sqr(n) ((n)*(n))

typedef long long ll;

ll gcd(ll a, ll b)
{
    while (a && b)
        if (a>b) a%=b;
        else b%=a;
    return a+b;
}

using namespace std;

typedef vector <int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector <pll> vll;

const int inf=1e9+7;

int a[3333][3333],b[3333][3333];

int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,i,x[33333],y[33333],j,k,d,ans=0;
    cin>>n>>m;
    for (i=0; i<m; i++)
    {
        cin>>x[i]>>y[i];
        a[x[i]][y[i]]=1;
    }
    for (i=0; i<m; i++)
        for (j=1; j<=n; j++)
            if (a[y[i]][j]==1) b[x[i]][j]++;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            d=b[i][j];
            if (i!=j && d>1) ans+=((1+(d-1))*(d-1))/2;
        }
    }
    cout<<ans;
    return 0;
}
