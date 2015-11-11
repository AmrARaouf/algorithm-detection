//Language: GNU C++0x


#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define rep(x, a, b) for(int (x) = (a); (x) < int(b); ++(x))
#define Wait cin.sync(); cin.get();
#define INF_INT 2000000000;
#define INF 0x3F3F3F3F
#define y1 qwerty 
#define EPS 1e-6
using namespace std;
typedef long long                  ll;
typedef pair<long long, long long> pll;
typedef pair<int, int>             pii;
typedef pair<double, int>          pdi;
typedef pair<string, string>       pss;

queue<int> q;
int used[100001];
int d[100001];
int x, n, m;

void bfs(int s){
	q.push(s);	
	d[s] = 0;
	used[s] = 1;
	while (!q.empty()){
		int top = q.front();
		q.pop();
		x = 2 * top;
		if (x <= 10001 && !used[x]){
			q.push(x);
			used[x] = 1;
			d[x] = d[top] + 1;
			if (x == m)  return;
		}
		x = top - 1;
		if (x > 0 && !used[x]){
			q.push(x);
			used[x] = 1;
			d[x] = d[top] + 1;
			if (x == m)  return;
		}
	}
}


int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);	
	cin >> n >> m;
	bfs(n);
	cout << d[m] << endl;
	
	//printf("TIME: %.3lf\n", (long double)(clock()) / CLOCKS_PER_SEC);
	Wait
	return 0;
}