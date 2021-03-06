//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long LL;

const int MAX_N = 100000;
const int BOUND = 1000000000;

int father[MAX_N + 10], n, p, q, m;
LL size[MAX_N + 10];
priority_queue<pair<LL, int>, vector<pair<LL, int> >, greater<pair<LL, int> > > pq;

int findFather(int a){
	if(father[a] != a)
		father[a] = findFather(father[a]);
	return father[a];
}

int main(){
#ifdef LOCAL
	freopen("test.in", "r", stdin);
#endif

	scanf("%d%d%d%d", &n, &m, &p, &q);
	for(int i = 1; i <= n; i ++)
		father[i] = i;
	for(int i = 0; i < m; i ++){
		int a, b, len;
		scanf("%d%d%d", &a, &b, &len);
		int fa = findFather(a);
		int fb = findFather(b);
		if(fa != fb){
			father[fa] = fb;
			size[fb] += size[fa];
		}
		size[fb] += len;
	}	
	int cnt = 0;
	for(int i = 1; i <= n; i ++)
		if(findFather(i) == i){
			pq.push(make_pair(size[i], i));
			++ cnt;
		}
	if(cnt - q > p || cnt < q || (q == n && p > 0)){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	int aa = 0, bb = 0;
	for(int i = 1; i <= n; i ++)
		if(findFather(i) != i){
			aa = i;
			bb = findFather(i);
			break;
		}
//	LL tot = 0;
	for(int i = cnt; i > q; i --){
		pair<LL, int> a = pq.top(); pq.pop();
		pair<LL, int> b = pq.top(); pq.pop();
		aa = a.second;
		bb = b.second;
		printf("%d %d\n", a.second, b.second);
//		tot += min(a.first + b.first + 1, (LL)BOUND);
		pq.push(make_pair(min((LL)BOUND, a.first + b.first + 1 + a.first + b.first), b.second));
	}
	for(int i = cnt - q; i < p; i ++){
		printf("%d %d\n", aa, bb);
//		tot += 1000;
	}


	return 0;
}


