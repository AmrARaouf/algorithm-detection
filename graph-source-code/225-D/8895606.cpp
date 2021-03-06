//Language: GNU C++


#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int x[20],y[20],z;
}h;
char d[20][20];
int n,m,g,p[4][2]={0,1,0,-1,1,0,-1,0};
set<int> v;
node solve (node &s) {
	int i;
	node r;
	for (i=g;i>=2;i--) {r.x[i]=s.x[i-1];r.y[i]=s.y[i-1];}
	r.z=s.z+1;
	return r;
}
int work (node &s) {
	int r=0,i;
	for (i=1;i<=g;i++) r=r*1023+s.x[i];
	for (i=1;i<=g;i++) r=r*1023+s.y[i];
	return r;
}
int bfs ( ) {
	int i,j;
	queue<node> q;
	q.push(h);
	v.insert(work(h));
	while (!q.empty()) {
		node k=q.front();q.pop();
		int x=k.x[1],y=k.y[1];
		for (i=0;i<4;i++) {
			int a=x+p[i][0],b=y+p[i][1];
			if (d[a][b]==0 || d[a][b]=='#') continue;
			if (d[a][b]=='@') return k.z+1;
			bool f=false;
			for (j=1;j<g && f==false;j++) {
				if (a==k.x[j] && b==k.y[j]) f=true;
			}
			if (f==true) continue;
			node w=solve(k);
			w.x[1]=a;w.y[1]=b;
			int t=work(w);
			if (v.find(t)==v.end()) {v.insert(t);q.push(w);}
		}
	}
	return -1;
}
int main ( ) {
	int i,j;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) scanf("%s",&d[i][1]);
	g=0;h.z=0;
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			if (d[i][j]>='0' && d[i][j]<='9') {
				int t=d[i][j]-'0';
				h.x[t]=i;h.y[t]=j;
				g++;
			}
		}
	}
	int ans=bfs();
	printf("%d\n",ans);
	return 0;
}
/*
Sample test(s)

input

4 5
##...
..1#@
432#.
...#.

output

4

input

4 4
#78#
.612
.543
..@.

output

6

input

3 2
3@
2#
1#

output

-1
*/
