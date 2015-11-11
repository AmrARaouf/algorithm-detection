//Language: GNU C++


#include <cstdio>
#include <complex>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REPE(i,x,y) for (int i=(x);i<(y);i++)
#define REP(i,x,y) for (int i=(x);i<=(y);i++)
#define DREP(i,x,y) for (int i=(x);i>=(y);i--)
#define mp make_pair
#define pb push_back
#define MAXN 100100
#define endc '\n'

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(false);
	// cin.tie(0);
	int k; cin>>k;
	if (k%2 == 0) {
		cout<<"NO"<<endl; return 0; 
	}
	cout<<"YES"<<endl;
	if (k == 1) {
		cout<<2<<" "<<1<<endl;
		cout<<1<<" "<<2<<endl;
		return 0;
	}
	/* 1,2 bridge
	   3 ... k+1 -> 1
	   k+2 ... 2k -> 3...k+1
	   k+2 - k+3 , k+4 - k+5 , ... , 2k - 1 - 2k
	   2k+1 ... 3k-1 -> 2
	   3k ... 4k-1 -> 2k+1 ... 3k - 1

	*/
	int cnt = 0;	
	cout<<(4*k - 2)<<" "<<(2*k - 1)*k<<endl;

	cout<<1<<" "<<2<<endl; cnt++;
	REP(i,3,k+1) { 
		cout<<i<<" "<<1<<endl; cnt++;
		REP(j,k+2,2*k) {
			cout<<i<<" "<<j<<endl; cnt++;
		}
	}
	for (int i = k+2;i <= 2*k; i+= 2) {
		cout<<i<<" "<<i+1<<endl; cnt++;
	}

	REP(i,2*k + 1,3*k - 1) {
		cout<<2<<" "<<i<<endl; cnt++;
		REP(j,3*k,4*k - 2) {
			cout<<i<<" "<<j<<endl; cnt++;
		}
	}
	for (int i = 3*k; i<=4*k - 2;i+=2) {
		cout<<i<<" "<<i+1<<endl; cnt++;
	}
	//cout<<cnt<<endl;
	return 0;

	
}
