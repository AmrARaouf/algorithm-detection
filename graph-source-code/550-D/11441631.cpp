//Language: GNU C++11


// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define ALL(x) (x).begin(), (x).end()
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
#define IO() {ios_base::sync_with_stdio(0); cin.tie(0);}
#define nl '\n'
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<class A, class B> inline bool mina(A &x, B y) {return(x>y)?(x=y,1):0;}
template<class A, class B> inline bool maxa(A &x, B y) {return(x<y)?(x=y,1):0;}
template<class A, class B> inline A geta(A &x, const B y) {A t=x;x=y;return t;}

int K;

inline void f(int a, int b)
{
	printf("%d %d\n", a, b);
}

int main()
{
	IO();
	cin >> K;
	if(K&1)
	{
		printf("YES\n");
		printf("%d %d\n", 4*K-2, (2*K-1)*K);
		f(1,2);
		FOR(i,0,K-1)
		{
			int a = 2*i+2;
			f(1,a+1);
			f(2,a+2);
		}
		FOR(i,0,K-1) FOR(j,0,K-1)
		{
			int a = 2*i+2;
			int b = 2*(j+K);
			f(a+1,b+1);
			f(a+2,b+2);
		}
		FOR(i,0,K/2)
		{
			int a = 2*(2*i+K);
			f(a+1,a+3);
			f(a+2,a+4);
		}
	}
	else printf("NO\n");

	return 0;
}

  		  	   	 	 	 	 								