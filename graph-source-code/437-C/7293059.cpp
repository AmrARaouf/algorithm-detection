//Language: GNU C++


#include <fstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#define pb push_back
#define mp make_pair
#define sortvi(a) sort(a.begin(), a.end())
#define FOR(i, start, final) for (int i=start; i<=final; ++i)
#define ROF(i, start, final) for (int i=start; i>=final; --i)

#define f cin
#define g cout

//void f(int &x){char k;for(k=getchar();k<= 32;k=getchar());for(x=0;'0'<=k;k=getchar())x=x*10+k-'0';}


/*void f(int &x)//parsare cu semn
{
    char k; bool semn=0;
    for (k = getchar(); (k>'9' || k<'0');)
    {
        if (k=='-') semn=1;
        k=getchar();
    }
    for (x = 0; '0' <= k; k = getchar())    x = x * 10 + k - '0';
    if (semn==1) x=-x;
}*/


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int> pi;
typedef vector< int > vi;
typedef vector< pair< int, int > > vpi;

int N, M, x, y, sol, a[1005];

int main()
{
    f.sync_with_stdio(false);
    f>>N>>M;
    FOR(i,1,N)f>>a[i];
    FOR(i,1,M)
        f>>x>>y, sol+=min(a[x], a[y]);

    g<<sol<<'\n';
    return 0;
}
