//Language: GNU C++0x


#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=100001;
const int INF=0x7FFFFFFF;
const double eps=1e-8;
const double pi=acos(-1.0);

struct point{
	int x,y;
	point(){}
	point(int x, int y):x(x),y(y){}
};

struct line{
	point a,b;
	line(){}
	line(point a, point b){
		if (a.x>b.x) swap(a,b);
		if (a.y>b.y) swap(a,b);
		this->a=a; this->b=b;
	}
};

int n,a,b;
point st,ed;
vector<line> L;
queue<int> q;
bool vis[MAXN];
int dist[MAXN];

void init(){
	int x,y;
	scanf("%d%d",&a,&b);
	scanf("%d%d%d%d",&st.x,&st.y,&ed.x,&ed.y);
	scanf("%d",&n);
	for (int i=0; i<n; i++){
		scanf("%d%d",&x,&y);
		point a=point(x,y);
		scanf("%d%d",&x,&y);
		point b=point(x,y);
		L.push_back(line(a,b));
	}
	L.push_back(line(st,st));
}

int sqr(int x){
	return x*x;
}

int dist2(line a, line b){
	int dx=0,dy=0;
	if (a.a.x>b.b.x) dx=a.a.x-b.b.x; else
	if (b.a.x>a.b.x) dx=b.a.x-a.b.x;

	if (a.a.y>b.b.y) dy=a.a.y-b.b.y; else
	if (b.a.y>a.b.y) dy=b.a.y-a.b.y;
	return sqr(dx)+sqr(dy);
}

void solve(){
	int n=L.size();
	memset(vis,0,sizeof(vis));
	memset(dist,60,sizeof(dist));
	int maxlong=dist[n-1];
	dist[n-1]=0; q.push(n-1);
	L.push_back(line(ed,ed));
	while (!q.empty()){
		int node=q.front(); q.pop();
		for (int i=0; i<n; i++)
			if (dist[node]+1<dist[i] && dist2(L[i],L[node])<=a*a){
				dist[i]=dist[node]+1;
				if (!vis[i]){
					vis[i]=true;
					q.push(i);
				}
			}
		vis[node]=false;
	}
	double ret=1e11;
	for (int i=0; i<n; i++)
		if (dist[i]<maxlong && dist2(L[i],L[n])<=a*a){
			ret=min(ret,dist[i]*(a+b)+sqrt(dist2(L[i],L[n])));
		}
	if (ret>1e10) printf("-1\n"); else printf("%.10lf\n",ret);
}

int main(){
	init();
	solve();
	return 0;
}

