//Language: GNU C++


#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define sc scanf
#define pr printf
#define pb push_back
int parent[2000], n;


int main(){
	sc("%d", &n);
	
	for(int i = 0; i < n; ++i)
	     sc("%d", &parent[i]);	
	int m = 0;
	for(int i = 0; i < n; ++i){
	 	int x = parent[i], cnt = 1;
	 	if(x > 0)x--;
	 	while(x != -1){
	 	 	x = parent[x];
	 	 	cnt++;
	 	 	if(x > 0) x--;
	 	}
	 	m = max(m, cnt);
	}
	cout << m;
	return 0;
}                                                   