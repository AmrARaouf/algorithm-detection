//Language: MS C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define N 102
struct Point{
    int x,y;
}p[N];
int mat[N][N],tot[N],pre[N];
int find(int x){
    int r=x;
    while (pre[x]!=x){
        x=pre[x];
    }
    int j;
    while (r!=x){
        j=pre[r];
        pre[r]=x;
        r=j;
    }
    return x;
}
void link(int x,int y){
    int dx=find(x),dy=find(y);
    if (dx!=dy)
        pre[dx]=pre[dy];
}
int main(){
    int n;
    while (~scanf("%d",&n)){
        for (int i=1;i<=n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        memset(mat,-1,sizeof(mat));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++){
                if (p[i].x==p[j].x || p[i].y==p[j].y){
                    mat[i][j]=1;
                }
            }
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++){
                if (i==k)
                    continue;
                for (int j=1;j<=n;j++){
                    if (j==k || i==j)
                        continue;
                    if (mat[i][k]!=-1 && mat[k][j]!=-1){
                        if (mat[i][j]==-1 || mat[i][j]>mat[i][k]+mat[k][j]){
                            mat[i][j]=mat[i][k]+mat[k][j];
                        }
                    }
                }
            }   
        for (int i=1;i<=n;i++)
            pre[i]=i;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (find(i)!=find(j)){
                    if (mat[i][j]!=-1){
                        link(i,j);
                    }
                }
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (find(i)!=find(j)){
                    ans++;
                    link(i,j);
                }
        printf("%d\n",ans);

    }
}
