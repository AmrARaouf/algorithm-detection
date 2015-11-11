//Language: GNU C++


#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 500 + 10;
int val[MAX];
int main(){
	int n, m;
	double ans = 0.0;
	scanf("%d %d", &n, &m);
	for(int i = 1 ; i <= n ; i++) scanf("%d", &val[i]);
	for(int i = 0 ; i < m ; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ans = max(ans, (double)(val[a]+val[b])/(double)c);
	}
	printf("%.9f\n", ans);
	return 0;
}
