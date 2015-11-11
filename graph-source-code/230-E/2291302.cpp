//Language: GNU C++


//Solution by Miras Myrzakerei
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <iomanip>

using namespace std;

#define INF 1000000001
#define sqr(x) (x) * (x)
#define sz 1000001
#define pb push_back
#define mp make_pair
#define mod 1000000007 
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.length())
#define F first
#define S second
#define pii pair<int,int>
#define LL long long
#define vi vector<int>
#define str string
#define read(x) scanf("%d",&x)
#define write(x) printf("%d",x)
#define readln(x) cin >> x;
#define writeln(x) cout << x;
#define writell(x) cout<<x
#define readll(x) cin>>x
#define for(x,y,z) for (int z = x; z <= y; ++z)

LL ans;
int n, m, s[sz], a, b;

int main()
{
	scanf ("%d%d", &n, &m);

	for (1, m, i)
	{
		scanf ("%d%d", &a, &b);
				
		s[a]++;
		s[b]++;
	}

	for (1, n, i)
		ans += ((LL)s[i] * (s[i] - 1)) / 2 + (LL)(n - s[i] - 1) * (n - s[i] - 2) / 2;

	writell ((ans - (LL)n * (n - 1) * (n - 2) / 6) / 2);			
}
