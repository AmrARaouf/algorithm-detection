//Language: GNU C++0x


//saurav shekhar
#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-7
#define INF 1234567890
#define MOD 1000000007

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int LIM = 1003; 
bool visited[LIM];
int pos[LIM][5];
int lcs[LIM];		// lcs[i] = length of longest lcs ending at i;
int n, k;

bool occ_before(int u, int v) {
	//printf("called with i = %d, num = %d\n", u, v);
	for(int i = 0; i < k; i++) {
		//printf("pos[%d, %d] = %d,  pos[%d, %d] = %d\n", u, k, pos[u][k], v, k, pos[v][k]);
		if(pos[u][i] >= pos[v][i]) return false;
	}
	return true;
}

int find_lcs(int num) {
	if(visited[num] == true) return lcs[num];
	visited[num] = true;
	int templen;
	int& maxlen = lcs[num];
	for(int i = 1; i <= n; i++) {
		if(occ_before(i, num)) {
			//printf("%d occ before %d\n", i, num);
			templen = find_lcs(i) + 1;
			maxlen = max(maxlen, templen);
		}
	}
	return maxlen;
}

int main()
{
	memset(visited, false, sizeof visited);
	cin >> n >> k;
	int foo, bar, tmp;
	for(int i = 0; i < k; i++)
		for(int j = 0; j < n; j++) {
			cin >> tmp;
			pos[tmp][i] = j;
			//printf("pos[%d, %d] = %d\n",tmp, i, pos[tmp][i] );
		}
	for(int i = 1; i <= n; i++) lcs[i] = 1;
	int ans = 0;
	for(int i = 1; i <= n; i++ ) if(!visited[i]) {
		tmp = find_lcs(i);
		ans = max(ans, tmp);
	}
	//for(int i = 1; i <= n; i++) cout << i << "," << lcs[i] << " ";
	cout << ans << "\n";
	return 0;
}




















