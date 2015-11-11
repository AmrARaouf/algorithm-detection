//Language: GNU C++


#include<cstdio>
#include<cstring>

int n, m, s, a, b, c, ans;
int p[111][111];

int get_root(int id, int cur) {
	return p[id][cur] == -1 ? cur : p[id][cur] = get_root(id, p[id][cur]);
}

void merge(int id, int a, int b) {
	int x = get_root(id, a), y = get_root(id, b);
	if (x!=y)
		p[id][x] = y;
}

int main() {
	memset(p, -1, sizeof p);
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d", &a, &b, &c);
		merge(c, a, b);
	}
	
	scanf("%d",&s);
	for(int i=0;i<s;i++){
		scanf("%d%d", &a, &b);
		ans =0;
		for(int j=1;j<=m;j++)
			ans += (get_root(j, a) == get_root(j, b));
		printf("%d\n", ans);
	}
	
	return 0;
}