//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;

int dp[2 * maxn][1 << 8];
int preM[2 * maxn][1 << 8];
int preP[2 * maxn][1 << 8];
int A[maxn][maxn];
int Flag[maxn][maxn];
int dis[2*maxn][2*maxn];
char ans[maxn][maxn];
int N, M, K;
int ax[4] = {-1, 1, 0, 0};
int ay[4] = {0, 0, -1, 1};

int Calc(int x){
    return A[x/M][x%M];
}

int check(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= M) return 0;
    return 1;
}

int next[2 * maxn], que[4 * maxn * maxn], head, tail, sum[2 * maxn], inque[2 * maxn];
void getRoad(int AA, int BB){
 //   printf("getRoad : %d %d\n\n", AA, BB);
    head = tail = 0;
    que[tail++] = AA;
    memset(inque, 0, sizeof(inque));
    memset(sum, inf, sizeof(sum));
    memset(next, -1, sizeof(next));
    sum[AA] = Calc(AA);
    inque[AA] = 1;
    while(head < tail){
        int now = que[head++];
        inque[now] = 0;
        if(now == BB) continue;
        int nowX = now / M, nowY = now % M;
        for(int i = 0; i < 4; ++i){
            int nX = nowX + ax[i], nY =nowY + ay[i];
            if(check(nX, nY)){
                int temp = nX * M + nY;
                if(sum[temp] > sum[now] + A[nX][nY]){
                    sum[temp] = sum[now] + A[nX][nY];
                    next[temp] = now;
                    if(!inque[temp]){
                        que[tail++] = temp;
                        inque[temp] = 1;
                    }
                }
            }
        }
    }
    int q = BB;
    while(q != -1){
        ans[q/M][q%M] = 'X';
        q = next[q];
    }
}

void dfs(int q, int mask){
    if(q == -1 || mask == -1){
        return ;
    }
 //   printf("dfs : %d %d\n",q,mask);
 //   printf("pre : %d %d\n\n",preP[q][mask],preM[q][mask]);
    if(preP[q][mask] == q){
        dfs(q, preM[q][mask]);
        dfs(q, mask ^ preM[q][mask]);
    }
    else {
        if(preP[q][mask] != -1){
            getRoad(q, preP[q][mask]);
        }
        dfs(preP[q][mask], mask);
    }
}

int main(){
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            scanf("%d", &A[i][j]);
        }
    }
    memset(Flag, 0, sizeof(Flag));
    int P[10], pt = 0;
    for(int i = 0; i < K; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        P[pt++] = x * M + y;
    }
    memset(dis, inf, sizeof(dis));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            ans[i][j] = '.';
            int F = i * M + j;
            dis[F][F] = Calc(F);
            for(int k = 0; k < 4; ++k){
                int ix = i + ax[k], iy = j + ay[k];
                int S = ix * M + iy;
                if(check(ix, iy)){
                    dis[F][S] = dis[S][F] = A[i][j] + A[ix][iy];
                }
            }
        }
    }
    for(int k = 0; k < N * M; ++k){
        for(int i = 0; i < N * M; ++i){
            for(int j = 0; j < N * M; ++j){
                if(dis[i][k] != inf && dis[k][j] != inf && dis[i][j] > dis[i][k] + dis[k][j] - Calc(k)){
                    dis[i][j] = dis[i][k] + dis[k][j] - Calc(k);
                }
            }
        }
    }
//    printf("Here comes the dis :\n");
//    for(int i = 0; i < N * M; ++i){
//        for(int j = 0; j < N * M; ++j){
//            printf("%d ", dis[i][j]);
//        }
//        puts("");
//    }
    memset(dp, inf, sizeof(dp));
    memset(preP, -1, sizeof(preP));
    memset(preM, -1, sizeof(preM));
    for(int i = 0; i < K; ++i){
        dp[P[i]][1 << i] = A[P[i]/M][P[i]%M];
        for(int j = 0; j < N * M; ++j){
            if(dp[j][1<<i] > dp[P[i]][1<<i] + dis[P[i]][j] - Calc(P[i])){
                dp[j][1 << i] = dp[P[i]][1<<i] + dis[P[i]][j] - Calc(P[i]);
                preP[j][1 << i] = P[i];
                preM[j][1 << i] = (1 << i);
            }
        }
    }
    for(int mask = 0; mask < (1 << K); ++mask){
        if((mask -1) & mask){
            for(int i = 0; i < N * M; ++i){
                for(int sub = (mask - 1) & mask; sub > 0 ; sub = (sub - 1) & mask){
                    if(dp[i][sub] != inf && dp[i][sub ^ mask] != inf && dp[i][mask] > dp[i][sub] + dp[i][sub ^ mask] - Calc(i)){
                        dp[i][mask] = dp[i][sub] + dp[i][sub ^ mask] - Calc(i);
                        preP[i][mask] = i;
                        preM[i][mask] = sub;
                    }
                }
            }
            for(int i = 0; i < N * M; ++i){
                for(int j = 0; j < N * M; ++j){
                    if(dp[i][mask] != inf && dis[i][j] != inf && dp[j][mask] > dp[i][mask] + dis[i][j] - Calc(i)){
                        dp[j][mask] = dp[i][mask] + dis[i][j] - Calc(i);
                        preP[j][mask] = i;
                        preM[j][mask] = mask;
                    }
                }
            }
        }
    }
    int Max = inf, nP = -1, nM = -1;
    for(int i = 0; i < N * M; ++i){
        //if(i%M == 0) puts("");
     //   printf("%d ", dp[i][(1<<K)-1]);

        if(dp[i][(1 << K) - 1] < Max){
            Max = dp[i][(1 << K) - 1];
            nP = i, nM = (1 << K) - 1;
        }
    }
 //   puts("");
//    cout<<nP<<' '<<nM<<endl;
//    for(int i = 0; i < N; ++i){
//        ans[i][M] = '\0';
//        printf("%s\n",ans[i]);
//    }
    dfs(nP, nM);
    for(int i = 0; i < K; ++i){
        ans[P[i]/M][P[i]%M] = 'X';
    }
    printf("%d\n", Max);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            putchar(ans[i][j]);
        }
        puts("");
    }
}

 		 	 	   	 			    		   	 	