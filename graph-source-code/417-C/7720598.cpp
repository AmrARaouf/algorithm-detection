//Language: GNU C++0x


#include <cstdio>

using namespace std;

char a[1001][1001];

int main()
{	
	int n,k,cnt;
	
	scanf("%d%d",&n,&k);

	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int j = 1; j <= n && cnt < k; j++) {
			if (i == j) continue;
			if (!a[j][i]) a[i][j] = true,cnt++;
		}
		if (cnt < k) {
			puts("-1");
			return 0;
		}
	}
	printf("%d\n",n * k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j]) printf("%d %d\n",i,j);
}