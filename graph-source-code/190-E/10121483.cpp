//Language: GNU C++


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include <limits.h>
#include<cmath>
#include<map>
#include<queue>
#include<set>
using namespace std;


#define LL long long
#define N 500005
const long long  mod =1000000009;  //这个必须是质数
int n,m;
vector<int> v[N];
bool vis[N],w[N];
int father[N];
vector<int> ans[N];
int q[N];
int rank[N];
map<int,int> mp;
int getfather(int j)
{
    return father[j]==j?j:father[j]=getfather(father[j]);
}
void solve1()
{
    for (int j=0;j<n;j++){
        father[j]=j;
    }
    for (int j=0;j<n;j++){
        memset(w,0,4*n);
        for (int k=0;k<v[j].size();k++) w[v[j][k]]=1;
        for (int k=0;k<n;k++){
            if (!w[k]){
                int g=getfather(k);
                int h=getfather(j);
                father[g]=h;
            }
        }
    }
    for (int j=0;j<n;j++) father[j]=getfather(j);
    int tot=0;
    for (int j=0;j<n;j++){
        if (mp[father[j]]==0){
            tot++;
            mp[father[j]]=tot;
        }
        ans[mp[father[j]]].push_back(j);
    }
    printf("%d\n",tot);
    for (int j=1;j<=tot;j++){
        printf("%d",ans[j].size());
        for (int k=0;k<ans[j].size();k++){
            printf(" %d",ans[j][k]+1);
        }
        printf("\n");
    }
}
int pos[N];
bool cmp(const int a,const int b)
{
    return q[a]>q[b];
}
void solve2()
{
    for (int j=0;j<n;j++) pos[j]=j;
    sort(pos,pos+n,cmp);
    int num=m/n+1;
    for (int j=0;j<n;j++){
        int x=pos[j];
        if (j>=num) father[x]=num;else father[x]=x;
    }
    rank[num]=n;
    for (int j=0;j<num;j++){
        int x=pos[j];
       // printf("ok%d %d\n",x+1,v[x].size());
        memset(w,0,n*4);
        for (int k=0;k<v[x].size();k++){
            w[v[x][k]]=1;
        }
        for (int k=0;k<n;k++){
            if (!w[k]){
                int g=getfather(x);
                int h=getfather(k);
                if (g==h) continue;
                if (rank[g]>rank[h]) father[h]=g;
                else {
                    father[g]=h;
                    if (rank[g]==rank[h]) rank[h]++;
                }
            }
        }
    }
    for (int j=0;j<n;j++) father[j]=getfather(j);
    int tot=0;
    for (int j=0;j<n;j++){
        if (mp[father[j]]==0){
            tot++;
            mp[father[j]]=tot;
        }
        ans[mp[father[j]]].push_back(j);
    }
    printf("%d\n",tot);
    for (int j=1;j<=tot;j++){
        printf("%d",ans[j].size());
        for (int k=0;k<ans[j].size();k++){
            printf(" %d",ans[j][k]+1);
        }
        printf("\n");
    }

}
int main()
{
    scanf("%d%d",&n,&m);
    for (int j=0;j<m;j++){
        int g,h;
        scanf("%d%d",&g,&h);
        g--;h--;
        q[g]++;q[h]++;
        v[g].push_back(h);
        v[h].push_back(g);
    }
    if (n<5000) solve1();
    else solve2();
    return 0;
}

