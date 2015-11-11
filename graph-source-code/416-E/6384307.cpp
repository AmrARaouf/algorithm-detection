//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<queue>
#include<bitset>
#define N 510
using namespace std;
int len[N][N]={0};
int ori[N][N]={0};
int ans[N][N]={0};
bool used[N]={0};
int main(){
     int n,m,i,j,k,x,y,l,a[N],b[N];
     bitset<N> reach[N];
     scanf("%d%d",&n,&m);
     while(m--){
        scanf("%d%d%d",&x,&y,&l);
        len[x][y]=len[y][x]=ori[x][y]=ori[y][x]=l;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(j==i) continue;
            for(k=1;k<=n;k++){
                if(k==i||k==j) continue;
                if(!len[j][i] || !len[i][k]) continue;
                if(!len[j][k] || len[j][i]+len[i][k]<len[j][k]){
                    len[j][k]=len[j][i]+len[i][k];
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            a[j]=j;
            b[j]=0;
            reach[j].reset();
            reach[j].set(j);
        }
        for(j=1;j<=n;j++){
            for(k=1;k<n;k++){
                if((a[k]!=i && !len[i][a[k]]) || len[i][a[k]]>len[i][a[k+1]]){
                    x=a[k];
                    a[k]=a[k+1];
                    a[k+1]=x;
                }
            }
        }
        for(j=1;j<=n;j++){
            if(a[j]!=i && !len[i][a[j]]) continue;
            for(k=j+1;k<=n;k++){
                if(!ori[a[j]][a[k]]) continue;
                if(ori[a[j]][a[k]]+len[i][a[j]]==len[i][a[k]]){
                    b[k]++;
                    reach[k]|=reach[j];
                }
            }
        }
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                if(reach[j].test(k)) ans[i][a[j]]+=b[k];
            }
        }
    }
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++){
            printf("%d",ans[i][j]);
            if(i==n-1&&j==n) putchar('\n');
            else putchar(' ');
        }
    }
    return 0;
}
