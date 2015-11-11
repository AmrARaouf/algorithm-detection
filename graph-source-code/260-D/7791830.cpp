//Language: GNU C++0x


//Karol Kaszuba
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;

#define FOR(i,x,y) for(int i=(x);i<=(y);++i)
#define REP(i,x) FOR(i,0,(x)-1)
#define FORD(i,x,y) for(int i=(x);i>=(y);--i)
#define VAR(i,c) __typeof(c) i=(c)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)

#define SIZE(c) (int)((c).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define IN insert
#define ER erase
#define MP make_pair
#define ST first
#define ND second
#define IOSYNC ios_base::sync_with_stdio(0)

void jebaj()
{
	set<PII> secik[2];
	int n;
	cin >> n;
	REP(i, n)
	{
		int a, w;
		cin >> a >> w;
		secik[a].IN(MP(w, i + 1));
	}
	int s = SIZE(secik[0]), ss = SIZE(secik[1]);
	REP(i, s + ss - 1)
	{
		VAR(it1, secik[0].begin());
		VAR(it2, secik[1].begin());
		int x, y;
		if(it1->ST < it2->ST || (it1->ST == it2->ST && SIZE(secik[0]) > SIZE(secik[1])))
		{
			x = 0;
			y = 1;
		}
		else
		{
			x = 1;
			y = 0;
		}
		set<PII>::iterator it;
		
		if(x == 0)	
			it = it1;
		else
			it = it2;
		
		VAR(ite, secik[y].lower_bound(MP(it->ST, 0)));
		cout << it->ND << " " << ite->ND << " " << it->ST << "\n";
		PII a = *ite;
		secik[y].ER(ite);
		secik[y].IN(MP(a.ST - it->ST, a.ND));
		secik[x].ER(it);
	}
	
}

int main()
{
	IOSYNC;	
	int t;
	t = 1;
	//cin >> t;
	
	REP(i, t) 
	{
		jebaj();
	}
}
