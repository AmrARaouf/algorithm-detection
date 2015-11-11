//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctime>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <complex>
#include <cctype>
#include <functional>
using namespace std;
#define LL long long
#define pi acos(-1.0)
#define eps 1e-9
#define M 109320
int m,n,k=0,flag=1;;
struct node{
    int x,y;
}c[2010][2010],d[10];
int b[2010][2010],v[2010][2010],e[10];
char a[2010][2010];
const int dy[]={0,-1,0,1,0};
const int dx[]={0,0,-1,0,1};
void dfs(int x,int y){
    if(!flag)return;
    v[x][y]=k;
    char xx=a[x][y];
    int x1=x+dx[xx],y1=y+dy[xx];
    if(!a[x1][y1]){
        b[x][y]=1;c[x][y].x=x;c[x][y].y=y;
        return;
    }
    if(v[x1][y1]==k){flag=0;return;}
    if(!v[x1][y1])dfs(x1,y1);
    b[x][y]=b[x1][y1]+1;
    c[x][y].x=c[x1][y1].x;
    c[x][y].y=c[x1][y1].y;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    #endif
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            char x=a[i][j];
            if(x=='#')a[i][j]=0;
            if(x=='<')a[i][j]=1;
            if(x=='^')a[i][j]=2;
            if(x=='>')a[i][j]=3;
            if(x=='v')a[i][j]=4;
        }
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(v,0,sizeof(v));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)if(a[i][j]){
            if(b[i][j])continue;
            k++;dfs(i,j);
        }
    }
    if(!flag){printf("-1\n");return 0;}
    int max=0,max1=0,s=0,t=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(b[i][j]>max){max=b[i][j];s=0;}
            if(b[i][j]==max)s++;
        }
    if(!max){printf("0\n");return 0;}
    if(s==1){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if((b[i][j]<max)&&(b[i][j]>max1))max1=b[i][j];
    }else max1=max;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if((b[i][j]==max)||(b[i][j]==max1)){
                flag=1;
                for(int k=0;k<t;k++)
                    if((d[k].x==c[i][j].x)&&(d[k].y==c[i][j].y)&&(b[i][j]==e[k]))flag=0;
                if(flag){
                    d[t].x=c[i][j].x;d[t].y=c[i][j].y;e[t]=b[i][j];
                    t++;
                    if(t>1){
                        printf("%d",max+max1);return 0;
                    }
                }
            }
    printf("%d",max+max1-1);
    return 0;
}