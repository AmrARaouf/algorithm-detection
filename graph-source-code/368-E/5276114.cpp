//Language: MS C++


//#pragma comment(linker, "/STACK:134217728")
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
//#include <ctime>
using namespace std;

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef std::multiset<int>::iterator Iter;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define INF 1000000007
#define y1 agaga
#define ll long long    

int n,m,p;
int q[100000];
long long s[100000];
int w;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);

    cin >> n >> m;

    FOR(i,0,m)
        cin >> w >> q[i];

    sort(q,q+m);
    reverse(q,q+m);

    s[0]=q[0];
    FOR(i,1,m)
        s[i]=s[i-1]+q[i];

    long long l=1;
    long long r=m+1;

    while (r-l>1)
    {
        long long m=(l+r) / 2;
        
        long long k=m;

        if (k%2==0)
            k=(k)*(k-1) / 2 + k / 2 - 1;
        else
            k=(k)*(k-1) / 2;

        if (k<=n-1) l=m;
        else
            r=m;
    }

    long long sol=s[l-1];

    //cout << l << endl;

    cout << sol << endl;
    
    return 0;
}