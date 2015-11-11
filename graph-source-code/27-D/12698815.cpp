//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 205;
int head[MAXN];
int edge[MAXN*MAXN*2];
int next1[MAXN*MAXN*2];
int esz;
int u[MAXN],v[MAXN];
int co[MAXN];

void addedge(int u,int v){
    edge[esz]=v;
    next1[esz]=head[u];
    head[u]=esz++;
}

vector<int>q;

int dfs(int u){
    if(co[u^1])return 0;
    if(co[u])return 1;
    co[u]=1;
    q.push_back(u);
    for(int i=head[u];i+1;i=next1[i]){
        int v=edge[i];
        if(!dfs(v))return 0;
    }
    q.pop_back();
    return 1;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u[i],&v[i]);
        if(u[i]>v[i])swap(u[i],v[i]);
    }
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            if(v[j]>v[i] && u[j]<v[i] && u[j]>u[i] || v[i]>v[j] && u[i]<v[j] && u[i]>u[j]){
             //   printf("%d %d\n",i,j);
                addedge(i<<1,j<<1|1);
                addedge(i<<1|1,j<<1);
                addedge(j<<1,i<<1|1);
                addedge(j<<1|1,i<<1);
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(!co[i<<1] && !co[i<<1|1]){
            if(!dfs(i<<1)){
                int L=q.size();
                for(int j=0;j<L;j++)co[q[j]]=0;
                q.clear();
                if(!dfs(i<<1|1)){
                    printf("Impossible\n");
                    return 0;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(co[i<<1])printf("i");
        else printf("o");
    }
    puts("");
    return 0;
}
