//Language: GNU C++


#include <iostream>
#include <cmath>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

#define ld long double
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define maxn 10000007

using namespace std;

ll n;
int a[1005][1005];
int i, cur, j;

int print()
{
	 for (i = 1; i <= cur+2; i++){
		for (j = 1; j <= cur + 2; j++){
			if (a[i][j] == 0) printf("N");
			else printf("Y");
		}
		printf("\n");
		
	}
	return 0;
}

int main()
{
	cin >> n;
	
	if (n == 1){
		a[1][2] = 1;
		a[2][1] = 1;
		cur = 0;
		cout << 2 << endl;
		return print();
	}
/*	if (n == 2){
		a[1][3] = 1;
		a[3][1] = 1;
		a[3][2] = 1;
		a[2][3] = 1;
		a[1][4] = 1;
		a[4][1] = 1;
		a[4][2] = 1;
		a[2][4] = 1;
		return print();
	}*/
	cur  = 3;
	
	if (n & 1){
		a[2][5] = 1;
		a[2][3] = 1;
		a[2][4] = 1;
		a[5][2] = 1;
		a[3][2] = 1;
		a[4][2] = 1;
	}
	else{
		a[2][3] = 1;
		a[2][4] = 1;
		a[3][2] = 1;
		a[4][2] = 1;
	}
	
	
	n /= 2;
	
	while (n > 1){
		cur += 3;
		a[cur][cur - 3] = 1;
		a[cur - 3][cur] = 1;
		a[cur][cur - 2] = 1;
		a[cur - 2][cur] = 1;
		a[cur + 1][cur - 3] = 1;
		a[cur - 3][cur + 1] = 1;
		a[cur - 2][cur + 1] = 1;
		a[cur + 1][cur - 2] = 1;
		if (n & 1){
			a[cur - 3][cur + 2] = 1;
			a[cur + 2][cur - 3] = 1;
			a[cur - 2][cur + 2] = 1;
			a[cur + 2][cur - 2] = 1;
		}		
		a[cur + 2][cur - 1] = 1;
		a[cur - 1][cur + 2] = 1;
		
		n /= 2;	
	}
	
	for (i = 0 ; i <= 2; i++){
		a[1][cur + i] = 1;
		a[cur + i][1] = 1;
	}
	
	printf("%d\n", cur + 2);
	
	return print();	
}


