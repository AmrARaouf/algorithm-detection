//Language: GNU C++


#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <iomanip>

using namespace std;

#define FORST(X,S,T) for(int X=(S); X<=(T); X++)  
#define RFORST(X,S,T) for(int X=(S); X>=(T); X--)  
#define FOR(X,XB) for(int X=0; X<(XB); X++)
#define RFOR(X,XB) for(int X=(XB)-1; X>=0; X--)
#define FORSTL(X,C) for(X=C.begin();X!=C.end();X++)
#define RFORSTL(X,C) for(X=C.rbegin();X!=C.rend();X++)
#define SQR(X) ((X)*(X))
#define MID(X,Y) (((X)+(Y))/2)
#define MIN(X,Y) (X=min((X),(Y)))
#define MAX(X,Y) (X=max((X),(Y)))
#define FILL(X,V) memset(X,V,sizeof(X))
#define FILE_R(X) freopen(X, "r", stdin)
#define FILE_W(X) freopen(X, "w", stdout)  
#define ERREQ(X,Y) (fabs((X)-(Y))<EPS)
#define DBGL cout << "here" << endl;
#define INITLISTS {L=0; FILL(adj,-1);}
#define SZ(X) (int)sizeof(X)
const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;
typedef long long LL;
typedef vector<int> VI;

#define MAXN 2005

int deg[MAXN];
LL w[MAXN][MAXN];

int main(){

	int N, K;
	LL sum = 0, x;
	cin >> N >> K;
	FILL(deg, 0);
	FOR(i, N){
		FORST(j, i+1, N-1){
			scanf("%I64d", &w[i][j]);
			if(w[i][j]!=-1){ deg[i]++; deg[j]++; }
		}
	}
	FOR(i, N){
		FORST(j, i+1, N-1){
			if(w[i][j]!=-1){
				if(K==1 || K==N-1){
					sum += w[i][j]*2;
				}else{
					sum += w[i][j]*(deg[i]+deg[j]-2);
				}
			}
		}
	}
	cout << sum/(K==2?N*(N-1)/2:N) << endl;
	return 0;
}