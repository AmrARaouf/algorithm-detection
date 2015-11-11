//Language: MS C++


#define _HAS_CPP0X 0
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <queue>
#include <cassert>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#define FOR(i, n) for(int i = 0; i < (int)(n); ++i)

int n;
LL D[512][512];
LL RD[512][512];
int X[512];
LL SD[2][512][512];
int GI[512];
int GIn;

LL R[512];

LL DD[512];
LL RDD[512];
bool DW[512];

void Dijkstra(int start, LL DD[512], LL D[512][512]){
	memset(DD, -1, 512 * 8);
	memset(DW, 0, 512);
	
	DD[start] = 0;
	for (;;){
		LL minD = -1;
		int minU = -1;
		for (int i = 0; i < GIn; i++){
			int u = GI[i];
			if (!DW[u] && DD[u] != -1 && (minD == -1 || DD[u] < minD)){
				minD = DD[u];
				minU = u;
			}
		}
		if (minU == -1){
			break;
		}		
		DW[minU] = true;
		for (int i = 0; i < GIn; i++){
			int v = GI[i];
			if (DW[v]){
				continue;
			}
			LL nd = DD[minU] + D[minU][v];
			if (DD[v] == -1 || nd < DD[v]){
				DD[v] = nd;
			}
		}
	}
}

int main()
{
#ifdef _DEBUG
	freopen("inp.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &D[i][j]);
			RD[j][i] = D[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &X[i]);
		X[i]--;
	}	
	GIn = 0;

	int t = 0;
	for (int i = n - 1; i >= 0; i--){
		int nt = 1 - t;
		
		int u = X[i];	
		GI[GIn++] = u;
		Dijkstra(u, DD, D);
		Dijkstra(u, RDD, RD);
		SD[nt][u][u] = 0;

		R[i] = 0;
		for (int j = 0; j < GIn; j++){
			int v = GI[j];			
			SD[nt][u][v] = DD[v];
			SD[nt][v][u] = RDD[v];
			R[i] += SD[nt][u][v];
			R[i] += SD[nt][v][u];
		}
		for (int j = 0; j < GIn; j++){
			for (int k = 0; k < GIn; k++){
				int v = GI[j];
				int w = GI[k];
				if (v == u || w == u){
					continue;
				}
				SD[nt][v][w] = min(SD[t][v][w], SD[nt][v][u] + SD[nt][u][w]);				
				R[i] += SD[nt][v][w];
			}
		}		
		t = 1 - t;
	}
	for (int i = 0; i < n; i++){
		if (i > 0){
			printf(" ");
		}
		printf("%I64d", R[i]);
	}
	printf("\n");
	return 0;
}