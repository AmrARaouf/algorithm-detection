//Language: GNU C++


#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN=505;

int N;
int X[MAXN],X2[MAXN];
LL ANS[MAXN];
int map[MAXN][MAXN],map2[MAXN][MAXN];

void init(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) scanf("%d",&map[i][j]);
    }
    for(int i=1;i<=N;i++) scanf("%d",&X[i]);
    for(int i=1;i<=N;i++) X2[N-i+1]=X[i];
}

void work(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=k;i++) map2[X2[i]][X2[k]]=map[X2[i]][X2[k]];
        for(int i=1;i<=k;i++) map2[X2[k]][X2[i]]=map[X2[k]][X2[i]];
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                int i2=X2[i],j2=X2[j],k2=X2[k];
                if(map2[k2][i2]+map2[i2][j2]<map2[k2][j2]) map2[k2][j2]=map2[k2][i2]+map2[i2][j2];
                if(map2[j2][i2]+map2[i2][k2]<map2[j2][k2]) map2[j2][k2]=map2[j2][i2]+map2[i2][k2];
            }
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                int i2=X2[i],j2=X2[j],k2=X2[k];
                //if(map2[i2][k2]>=0){
                //  if(map2[i2][j2]==-1 || map2[i2][k2]+map[k2][j2]<map2[i2][j2]){
                //      map2[i2][j2]=map2[i2][k2]+map[k2][j2];
                //  }
                //}
                //if(map2[k2][j2]>=0){
                //  if(map2[i2][j2]==-1 || map[i2][k2]+map2[k2][j2]<map2[i2][j2]){
                //      map2[i2][j2]=map[i2][k2]+map2[k2][j2];
                //  }
                //}
                if(map2[i2][j2]==-1 || map2[i2][k2]+map2[k2][j2]<map2[i2][j2]){
                    map2[i2][j2]=map2[i2][k2]+map2[k2][j2];
                }
                //if(map2[i2][j2]==-1 || map[i2][k2]+map[k2][j2]<map2[i2][j2]){
                //  map2[i2][j2]=map[i2][k2]+map[k2][j2];
                //}
            }
        }
        LL ans=0;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                int i2=X2[i],j2=X2[j];
                //if(map2[i2][j2]>0) 
                ans+=map2[i2][j2];
            }
        }
        ANS[k]=ans;
    }
    for(int i=N;i>=1;i--) printf("%I64d ",ANS[i]);
}

int main(){
    init();
    work();
    return 0;
}