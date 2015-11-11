//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 2010;
const int M = 200010;
struct Edge{
	int u, v, idx;
	char tp;
}edge[M];
struct ROAD{
	int v, idx;
	void push(int _v, int _idx){ v = _v; idx = _idx; }
};

std::vector<ROAD> road[N];
struct PREVEVE{
	int u, idx;
	void push(int _u, int _idx){ u = _u; idx = _idx; }
}prev[N];
int que[N], fr, bk;
bool vst[N];

int p[N], ok[M], size[N];
int find(int a){ return a == p[a] ? a : p[a] = find(p[a]); }
void uni(int a, int b){ p[find(a)] = find(b); }


int main(){
	int n, m, x, y; // S M
	char s[20];
	while (~scanf("%d %d", &n, &m)){
		for (int i = 0; i < m; i++){
			scanf("%d %d %s", &edge[i].u, &edge[i].v, s);
			edge[i].tp = s[0];
			edge[i].u--;edge[i].v--;
			edge[i].idx = i;
		}
		if (n == 1){
			puts("0");
		} else {
			if (n % 2 == 0) puts("-1");
			else {
				ROAD tmp;
				x = y = 0;
				for (int i = 0; i < n; i++) p[i] = i, road[i].clear();;
				for (int i = 0; i < m; i++){
					if (find(edge[i].u) != find(edge[i].v)){
						uni(edge[i].u, edge[i].v);
						tmp.push(edge[i].v, i);
						road[edge[i].u].push_back(tmp);
						tmp.push(edge[i].u, i);
						road[edge[i].v].push_back(tmp);
						ok[i] = true;
						if (edge[i].tp == 'S') x++;
						else y++;
					} else
						ok[i] = false;
				}
				if (x + y != n - 1){
					puts("-1");
				} else {
					if (x < y){
						std::swap(x, y);
						for (int i = 0; i < m; i++){
							if (edge[i].tp == 'S') edge[i].tp = 'M';
							else edge[i].tp = 'S';
						}
					}
					int done = 0;
					if (x != y){
						for (int i = 0; i < n; i++)size[i] = road[i].size();
						for (int i = 0, u, v; i < m; i++){
							if (!ok[i] && edge[i].tp == 'M'){
								memset(vst, false, sizeof(vst));
								fr = bk = 0;
								que[bk++] = edge[i].u;
								vst[edge[i].u] = 1;
								while (fr < bk){
									u = que[fr++];
									for (int l = 0; l < size[u]; l++){
										v = road[u][l].v;
										if (!vst[v]){
											que[bk++] = v;
											vst[v] = 1;
											prev[v].push(u, road[u][l].idx);
										}
									}
								}
								v = edge[i].v;
								while (v != edge[i].u){
									if (edge[prev[v].idx].tp == 'S'){
										done++;
										ok[i] = true;
										ok[prev[v].idx] = false;
										int idx = prev[v].idx;
										u = edge[idx].u;
										v = edge[idx].v;
										for (int j = 0; j < size[u]; j++){
											if (road[u][j].v == v){
												for (int k = j + 1; k < size[u]; k++)
													road[u][k-1]=road[u][k];
												road[u].pop_back();
												size[u]--;
												break;
											}
										}
										u = edge[idx].v;
										v = edge[idx].u;
										for (int j = 0; j < size[u]; j++){
											if (road[u][j].v == v){
												for (int k = j + 1; k < size[u]; k++)
													road[u][k-1]=road[u][k];
												road[u].pop_back();
												size[u]--;
												break;
											}
										}
										
										u = edge[i].u; v = edge[i].v;
										tmp.push(v, i);
										road[u].push_back(tmp); size[u]++;
										tmp.push(u, i);
										road[v].push_back(tmp); size[v]++;
										break;
									}
									v = prev[v].u;
								}
								if (2*done == x - y) break;
							}
						}
					}
					if (2*done == x - y){
						printf("%d\n", n - 1);
						bool flg = false;
						for (int i = 0; i < m; i++){
							if (ok[i]){
								if (flg) putchar(' ');
								printf("%d", i+1);
								flg = true;
							}
						}
						puts("");
					} else
						puts("-1");
				}
			}
		}
	}
	
	return 0;
}
