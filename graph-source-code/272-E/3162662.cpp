//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<string>
#include<bitset>
#include<queue>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<cctype>
#include<complex>
#include<list>
#include<climits>
#define pgs(a) printf("GG %s", a); 
#define pg(a) printf("GG %d\n", a)
#define re(i,n) for(int (i) = 0; (i) < int(n); ++i)
//div M_PI time left count distance 不能用哦，已经定义了。
using namespace std;
typedef long long ll;
template<class T>
void inline maxi(T &a,const T &b){
	a=max(a,b);
}
template<class T>
void inline mini(T &a,const T &b){
	a=min(a,b);
}
void shownum(int n,int m, int W = 6){
	for(int i = n; i <= m; ++i){
		cout<<setw(W)<<i;
	}
	cout<<endl;
}
template<class T>
void show(T &a,int n,int m, int W = 6){
	for(int i = n; i <= m; ++i){
		cout<<setw(W)<<a[i];
	}
	cout<<endl;
}
template<class T>
void show(T &a, int W = 6){
	re(u, SIZE(a)){
		cout << setw(W) << a[u];
	}
	cout << endl;
}
const int maxnum = int(3e5)+10;
const int maxint = INT_MAX;
const int minint = INT_MIN;
vector<int> graph[maxnum];
int in[maxnum];
int ans[maxnum];
int q[maxnum];
int hi[maxnum];
int qlen;
bool cmp(int x, int y){
	return in[x] > in[y];
}
void sink(int i){
	int t = q[i];
	for(int next = i * 2; next <= qlen; i = next, next = i * 2){
		if(next + 1 <= qlen && cmp(q[next + 1], q[next])) next++;
		if(cmp(t, q[next]))
			break;
		q[i] = q[next];
		hi[q[next]] = i;
	}
	q[i] = t;
	hi[t] = i;
}
void swim(int i){
	int t = q[i];
	for(int next = i / 2; next >= 1; i = next, next = i / 2){
		if(cmp(q[next], t))
			break;
		q[i] = q[next];
		hi[q[next]] = i;
	}
	q[i] = t;
	hi[t] = i;
}
void fix(int x){
	int before = in[x];
	in[x] = 0;
	re(i, graph[x].size())
		if(ans[x] == ans[graph[x][i]]){
			in[x]++;
		}
	if(in[x] > before){
		swim(hi[x]);
	}else if(in[x] < before){
		sink(hi[x]);
	}
}
void mmain(){
	int n, m;
	scanf ( "%d%d", &n, &m );
	memset(q, 0, sizeof(q));
	qlen = 0;
	memset(ans, 0, sizeof(ans));
	re(i, n) graph[i].clear();
	re(i, m){
		int x, y;
		scanf ( "%d%d", &x, &y );
		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}
	re(i, n) in[i] = graph[i].size();
	re(i, n){
		q[++qlen] = i;
		hi[i] = qlen;
	}
	for(int i = qlen / 2; i >= 1; --i){
		sink(i);
	}
	while ( 1 ) {
		int node = q[1];
		if(in[node] <= 1)
			break;
		ans[node] = !ans[node];
		fix(node);
		//shownum(0, n - 1);
		//show(ans, 0, n - 1);
		re(i, graph[node].size()) fix(graph[node][i]);
		//show(in, 0, n - 1);
		//show(in, 0, n - 1);
		//show(q, 1, n);
		//show(hi, 0, n - 1);
		//pg(1);
	}
	re(i, n) ans[i] == 0 ? printf("0") : printf("1");
	puts("");
}
//#define codeforces CODEFORCES
//#define codeforces_input CODEFORCES_FILE
#define MANY_TEST CODEFORCES_MANY_TEST
#define MANY_TESST 3
int main(){
#ifdef codeforces
	#ifdef codeforces_input
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	#ifdef MANY_TEST
	re(bbbbbwwwwww,MANY_TESST)
		mmain();
	return 0;
	#endif
#endif
	mmain();
}
