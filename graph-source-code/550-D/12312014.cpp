//Language: GNU C++


#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if(n % 2 == 0){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	int a = ((n-1) * 4 + 2), b = a * n / 2;
	printf("%d %d\n", a, b);
	n--;
	int s = n * 4, t = s + 1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%d %d\n", i + 1, j + n + 1);
			printf("%d %d\n", i + n * 2 + 1, j + n * 3 + 1);
		}
		printf("%d %d\n", s + 1, i + n + 1);
		printf("%d %d\n", t + 1, i + n * 3 + 1);
	}
	printf("%d %d\n", s + 1, t + 1);
	for(int i = 0; i < n/2 ; ++i){
		printf("%d %d\n", i + 1, n - i);
		printf("%d %d\n", i + n * 2 + 1, n * 3 - i);
	}
	return 0;
}

 	  	 			   					  					 	  	 	