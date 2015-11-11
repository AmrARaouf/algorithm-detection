//Language: GNU C++


/*
 Anton Gulikov
*/
#pragma comment(linker,"/STACK:300000000")
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <math.h>
#include <string>
#include <stdlib.h>

#define gcd(a,b) __gcd((a),(b))
#define sqr(a) ((a)*(a))
#define odd(a) ((a)&1)
#define foru(i,n) for (int i=0;i<(n);i++)
#define ford(i,n) for (int i=(n)-1;i>=0;i--)
#define forab(i,l,r) for (int i=(l);i<=(r);i++)
#define forabd(i,r,l) for (int i=(r);i>=(l);i--)
#define fillchar(a,b) memset((a),(b),sizeof((a)))
#define pb push_back
#define F first
#define S second
#define all(x) x.begin,x.end
#define pw2(x) (1ull<<(x))
#define mp make_pair

const long double eps=1e-20;
const long double pi=acos(-1.0);
const long long inf=1000*1000*1000*1000*1000*1000;
const long long base=1000*1000*1000+7;

using namespace std;

int n,m,x,y;
set<int> q;
vector  < vector <int> > g(333333);
int f[333333],now[333333];

void kill(int x){
	if (now[x]<2) return;
	foru(i,g[x].size()){
		if (f[x]^f[g[x][i]]) now[g[x][i]]++; else now[g[x][i]]--;
	}
	f[x]^=1;
	now[x]=0;
	foru(i,g[x].size()) if (f[x]^1^f[g[x][i]]) now[x]++;
	foru(i,g[x].size()) if (now[g[x][i]]>1) q.insert(g[x][i]);
	if (now[x]>1) q.insert(x);
}

int main(){
	scanf("%d%d",&n,&m);
	foru(i,m){
		scanf("%d%d",&x,&y);
		x--; y--;
		g[x].pb(y); g[y].pb(x);
	}	
	foru(i,n) now[i]=g[i].size();
	foru(i,n) if (now[i]>1) q.insert(i);
	while (!q.empty()){
		x=*q.begin();
		q.erase(x);
		kill(x);
	}
	foru(i,n) printf("%d",f[i]);
	return 0;
}