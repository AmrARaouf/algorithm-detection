//Language: MS C++


#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define F first
#define S second
#define INF 1000000000
#define W1 while(true)
typedef long long LL;
const long double eps=1e-7;
const long double pi=3.1415926535897932384626433832795;

int main(){
	int n;
	int mas[2001];
	cin >>n;
	FOR(i,0,n){
		cin >> mas[i];
		if (mas[i]!=-1)mas[i]=mas[i]-1;
	}
	int max=-1, temp,num;
	FOR(i,0,n){
		temp=0;
		num=i;
		W1{
			temp++;
			if (mas[num]==-1) break;
			num=mas[num];
		}
		if (temp>max) max=temp;
	}
	cout << max;
}

