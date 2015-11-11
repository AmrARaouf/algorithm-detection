//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int vis[1002];
struct point{
    int a,b;
}p[1002*1002];

int n;
void dfs(int u){
    vis[u]=1;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(p[i].a==p[u].a||p[i].b==p[u].b){
              //  printf("%d,%d\n",p[i].a,p[i].b);
                dfs(i);
            }
        }
    }
}

int main(){

    scanf("%d",&n);
    memset(vis,0,sizeof vis);
    for(int i=0;i<n;i++){
       scanf("%d%d",&p[i].a,&p[i].b);
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
           // printf("%d:\n",cnt);
            ++cnt;
            dfs(i);
        }
    }
    printf("%d\n",cnt-1);

    return 0;
}
