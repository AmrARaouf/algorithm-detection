//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 103;

struct Point {
	int x, y;
}p[maxn];

int n;
bool mk[maxn];

void search(int i) {
	mk[i] = true;
	for (int j=0; j < n; j++) if (!mk[j] && (p[i].x==p[j].x || p[i].y==p[j].y)) {
		search(j);
	}
}
int main() {
	int i;
	scanf("%d",&n);
	for (i=0; i < n; i++) {
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	int ans = 0;
	for (i=0; i < n; i++) if (!mk[i]) {
		search(i);
		ans++;
	}
	printf("%d\n",ans-1);
	return 0;
}