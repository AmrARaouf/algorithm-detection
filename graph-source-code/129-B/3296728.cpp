//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
ll gcd(ll a, ll b){
	return (b>0)? gcd(b, a%b) : a ;
}

int main(){


	int N,M;cin>>N>>M;
	vector <int> a,b;
	a.resize(M);b.resize(M);
	for(int i=0;i<M;++i){
		cin>>a[i]>>b[i];
		a[i]--;b[i]--;
	}

	int active[N];
	for(int i=0;i<N;++i)active[i]=1;

	int rem=N;
	int result=0;
	while(rem!=1){
		int prev=rem;
		int cnt[N];memset(cnt,0,sizeof(cnt));
		for(int i=0;i<M;++i){
			if(active[a[i]]&&active[b[i]]){
				cnt[a[i]]++;
				cnt[b[i]]++;
			}
		}

		for(int i=0;i<N;++i){
			if(active[i]&&cnt[i]==1){
				active[i]=0;
				--rem;
			}
		}
		if(rem==prev)break;
		++result;
	}
	cout<<result;
}
