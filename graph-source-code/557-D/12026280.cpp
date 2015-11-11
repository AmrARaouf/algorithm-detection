//Language: GNU C++11


#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <cstdio>
#include <string>
#include <cctype>
#include <bitset>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<char> VC;
typedef pair<int,int> PII;
typedef pair<int,double> PID;
typedef pair<double,int> PDI;
typedef pair<double,double> PDD;
#define mem(a,b) memset(a,b,sizeof(a))
#define foreach(it,a) for (__typeof(a.begin()) it = a.begin();it!=a.end();it++)
#define rforeach(it,a) for (__typeof(a.rbegin()) it = a.rbegin();it!=a.rend();it++)
#define dis(a,b) (sqrt(sqr(a)+sqr(b)))
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
#define abs(a) ((a)>0?(a):(-(a)))
#define lowbit(a) ((a) & (-(a)))
#define sqr(a) ((a)*(a))
#define PQ priority_queue;
#define mp make_pair
#define pb push_back
#define ft first
#define sc second

const int N = 3e5+10;
struct Edge{
	int v,next;
}edge[N];

int color[N],b[N],p[N],w[N],ent = 0 , flag , d[N];

void addedge(int u ,int v){
	edge[ent].v = v;
	edge[ent].next = p[u];
	p[u] = ent ++;
}

void make_tree(int x , int c, int num){
	color[x] = c;
	if (c == 1) b[num] ++;
	else w[num] ++;
	for (int i = p[x] ; ~i ; i = edge[i].next){
		int y = edge[i].v;
		if (!~color[y]) make_tree(y,c ^ 1,num);
		else if (color[y] == color[x]) flag = 1;
	}
}


int main() {
	int n , m;
	long long ans = 0;
	scanf("%d%d",&n,&m);
	if (!m){
		ans = 1LL * n * (n - 1) * (n - 2) / 6 ;
		cout<<"3 "<<ans<<endl;
		return 0;
	}
	flag = 1;
	mem(d,0);
	mem(p,-1);
	for (int i = 0 ; i < m ; ++ i){
		int x , y;
		scanf("%d%d",&x,&y);
		++ d[x] , ++ d[y];
		addedge(x,y);
		addedge(y,x);
		if (d[x] > 1 || d[y] > 1 ) flag = 0 ;
	}
	if (flag){
		ans = 1LL * m * (n - 2) ;
		cout<<"2 "<<ans<<endl;
		return 0 ;
	}
	mem(color,-1);
	int cnt = 0;
	for (int i = 1 ; i <= n ; ++i) 
		if (!~color[i])
			make_tree(i,0,cnt ++);
	if (flag) cout<<"0 1"<<endl;
	else {
		for (int i = 0 ; i < cnt ; ++ i)
			ans += 1LL * w[i] * (w[i] - 1) / 2 + 1ll * b[i] * (b[i] - 1) / 2;
		cout<<"1 "<<ans<<endl;
	}
    return 0;
}
