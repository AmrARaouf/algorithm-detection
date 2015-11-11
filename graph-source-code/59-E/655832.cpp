//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
const int MAXN=3000;
const int MAXM=20000;
const int INF=0x3f3f3f3f;
int n,m,trp;
struct Edges {
	int to,next;
} e[MAXM+MAXM+10];
int box[MAXN+10],size;
struct Triples {
	Triples(const int &xx=-1,const int &yy=-1,const int &zz=-1)
		:x(xx),y(yy),z(zz){}
	friend bool operator<(const Triples &a,const Triples &b) {
		if (a.x!=b.x) return a.x<b.x;
		if (a.y!=b.y) return a.y<b.y;
		return a.z<b.z;
	}
	int x,y,z;
};
set<Triples> ts;
queue<int> q;
int d[MAXN*MAXN+10];
bool inQueue[MAXN*MAXN+10];
int from[MAXN*MAXN+10];
void insert(const int &from,const int &to) {
	e[size].to=to;
	e[size].next=box[from];
	box[from]=size++;
}
int SPFA(const int &S,const int &T) {
	memset(inQueue,false,sizeof(inQueue));
	memset(d,0x3f,sizeof(d));
	q.push(-n+S);
	while (!q.empty()) {
		int cur=q.front(),nxt;	q.pop();
		int p=cur/n,u=cur%n,v;
		if (cur<0) p--,u+=n;
		int ud=cur>=0?d[cur]:0;
		if (cur>=0) inQueue[cur]=false;
		for (int i=box[u];~i;i=e[i].next)
			if (!ts.count(Triples(v=e[i].to,u,p)) && d[nxt=u*n+v]>ud+1) {
				d[nxt]=ud+1;
				from[nxt]=cur;
				if (!inQueue[nxt]) {
					inQueue[nxt]=true;
					q.push(nxt);
				}
			}
	}
	int mind=INF,ret=-1;
	for (int i=0;i<n;i++)
		if (mind>d[i*n+T])
			mind=d[ret=i*n+T];
	return ret;
}
void ReadIn() {
	size=0;
	memset(box,-1,sizeof(box));
	scanf("%d%d%d",&n,&m,&trp);
	for (int i=1,x,y;i<=m;i++) {
		scanf("%d%d",&x,&y);
		insert(--x,--y);
		insert(y,x);
	}
	for (int i=1,x,y,z;i<=trp;i++) {
		scanf("%d%d%d",&x,&y,&z);
		ts.insert(Triples(--x,--y,--z));
	}
}
int main() {
	ReadIn();
	int end=SPFA(n-1,0);
	if (!~end) { puts("-1"); return 0; }
	printf("%d\n",d[end]);
	do {
		printf("%d ",(end+n)%n+1);
		if (end<0) break;
		end=from[end];
	} while (true);
	putchar('\n');
	return 0;
}