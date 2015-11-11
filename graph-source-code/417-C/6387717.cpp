//Language: MS C++


#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <complex>
#include <ctime>
#include <iomanip>
#include <cassert>
#include <sstream>
#include <iterator>

using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAXN = 1e3 + 5;
const int MAXN2 = 1e4 + 5;
const double EPS = 1e-16;
const ll INF = 10000000000000;

int g[MAXN][MAXN];

void solve(){
	int n,k;
	cin >> n >> k;
	int m = 0;
	for(int i = 1;i <= n;i++){
		int cnt = 0;
		for(int j = 1;j <= n;j++){
			if(i == j) continue;
			if(!g[i][j] && !g[j][i]){
				g[i][j] = 1;				
				cnt++;
				m++;
				if(cnt == k) break;
			}
		}
		if(cnt < k){
			printf("-1");
			return;
		}
	}
	printf("%d\n",m);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(g[i][j]){
				printf("%d %d\n",i,j);
			}
		}
	}
}

int main()
{
	//assert(freopen(file".in","r",stdin)); assert(freopen(file".out","w",stdout));
	#ifndef ONLINE_JUDGE
	assert(freopen("input.txt","r",stdin));
	assert(freopen("output.txt","w",stdout));
	#endif		
	int t = 1;	
	while(t--){
		solve();
	}
	return 0;	
}