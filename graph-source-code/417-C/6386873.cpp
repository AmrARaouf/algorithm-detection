//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 1005
#define dbg(aa)	cout << #aa << " -> " << aa << endl;
using namespace std;
typedef pair < int , int > pii;
int K,N;
bool A[MAXN][MAXN];
int main()
{
	vector < pii > res;
	int N,i,j,s;
	scanf("%d %d" , &N , &K );
	if( N <= 2*K ) { printf("-1\n"); return 0; }
	FOR(i,1,N)
	{
		s = 0;
		for(j = 1; j <= N && s < K; j++)
			if( i != j && !A[i][j] && !A[j][i] )
			{
				A[i][j] = A[j][i] = true;
				res.push_back( make_pair( i , j ) );
				s++;
			}
	}
	printf("%d\n" , (int) res.size() );
	vector < pii > :: iterator it;
	for(it = res.begin(); it != res.end(); ++it)
		printf("%d %d\n" , it->f , it->s );

	return 0;
}
