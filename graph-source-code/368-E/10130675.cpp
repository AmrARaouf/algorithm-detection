//Language: GNU C++0x


/*
user  : triveni
date  : 03/03/2015
time  : 15:05:00
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           std::make_pair(a,b)
#define      pb(a)             std::push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second

typedef long long LL;
LL MOD = 1000000007;

int main()
{
	int N, m;
	cin >> N >> m;
	LL a[100100];
	rep(i, m) scanf("%lld %lld",a+i, a+i);
	sort(a, a+m, greater<LL>());
	LL l = 0, r = N, mid;
	while(r - l > 1){
		mid = (l+r) / 2;
		LL xx = 0;
		if(mid&1) xx = mid * (mid - 1) / 2 + 1;
		else xx = mid * mid / 2;
		if(xx <= N) l = mid;
		else r = mid;
	}
	LL x = 0;
	if(r&1) x = r * (r - 1) / 2 + 1;
	else x = r * r / 2;
	if(x <= N) mid = r;
	else mid = l;

	mid = min(mid, (LL)m);
	LL ans = 0;
	for(int i = 0; i < mid; ++i) ans += a[i];
	cout << ans << endl;
	return 0;
}
