//Language: GNU C++


#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cctype>

using namespace std;
typedef long long int64;
const int inf = 0x3f3f3f3f;
typedef double real;
const real eps = 1e-6;
typedef pair<int,int> pip;
#define Eo(x) { cerr << #x << " = " << (x) << endl; }

struct ppp{
	int x,y,n;
	bool operator<(const ppp& t)const{
		if (x != t.x) return x < t.x;
		if (y != t.y) return y < t.y;
		return n < t.n;
	}
}a[1000];
char how[1000];
char can[1000][2];
char was[1000];
int n,m; 

bool outside(int a, int x, int y){
	return a < x || a > y;
}

bool inside(int a, int x, int y){
	return a > x && a < y;
}

bool dfs(int v){
	was[v] = 1;
	if (!can[v][0] && !can[v][1]) return false;
	for (int t = 0; t < 2; t++) if (can[v][t]){
		can[v][t^1] = 0;
		how[v] = t;
	}
	int x = a[v].x;
	int y = a[v].y;
	for (int i = 0; i < m; i++) if (i != v){
		int ix = a[i].x;
		int iy = a[i].y;
		if ((inside(ix,x,y) && outside(iy,x,y)) || (inside(iy,x,y) && outside(ix,x,y))){
			int should = how[v]^1;
			can[i][should^1] = 0;
			if (!can[i][should]) return false;
			if (!was[i]){
				if (!dfs(i)) return false;
			}
		}
	}
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; i++){
		int x,y; scanf("%d%d",&x,&y);
		x--;y--;
		if (x > y) swap(x,y);
		a[i].x = x;
		a[i].y = y;
		a[i].n = i;
	}
	memset(can,1,sizeof(can));	
	for (int i = 0; i < m; i++){
		if (!was[i]){
			can[i][1] = 0;
			if (!dfs(i)){
				puts("Impossible");
				return 0;
			}
		}
	}
	for (int i = 0; i < m; i++){
		printf("%c",how[i] == 1 ? 'o' : 'i');
	}
	puts("");
	return 0;
}

