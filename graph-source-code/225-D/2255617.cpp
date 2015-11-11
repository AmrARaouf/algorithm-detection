//Language: MS C++


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//#define ll __int64
#define ll long long
#define ls rt<<1
#define rs ls|1
#define lson l,mid,ls
#define rson mid+1,r,rs
#define middle l+r>>1
#define esp (1e-8)
#define type int
#define clr(x,c) memset(x,c,sizeof(x))
typedef pair<int,int> pii;

void swap(int &x,int &y){int t=x;x=y;y=t;}
type max(type x,type y){return x>y? x:y;}
type min(type x,type y){return x<y? x:y;}
const int inf=0x3F3F3F3F;
//const double pi=acos(-1.0);
const int M=15 +5;
int T,cas;

int n,m,head,tail;
char maze[M][M];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}},tot=0;

struct node{
    int x[10],y[10],c;
    void move(node &p){
        c=p.c+1;
        for(int i=1;i<tail;i++)
            x[i+1]=p.x[i],y[i+1]=p.y[i];
    }
    bool operator < (const node &p) const{
        for(int i=1;i<=tail && i<=6;i++){
            if(x[i]<p.x[i]) return 1;
            if(x[i]==p.x[i] && y[i]<p.y[i]) return 1;
        }
        return 0;
    }
}s;

map<node,int>mp;
queue<node>q;

int bfs(){
    s.c=0;
    while(!q.empty()) q.pop();
    q.push(s);
    mp.clear();
    mp[s]=1;
    while(!q.empty()){
        s=q.front(),q.pop();
        node t;
        for(int i=0;i<4;i++){
            t.x[1]=s.x[1]+dir[i][0];
            if(t.x[1]<1 || t.x[1]>n) continue;
            t.y[1]=s.y[1]+dir[i][1];
            if(t.y[1]<1 || t.y[1]>m) continue;
            if(maze[t.x[1]][t.y[1]]=='@') return s.c+1;
            if(maze[t.x[1]][t.y[1]]=='#') continue;
            bool flag=true;
            for(int j=2;j<tail;j++)
                if(t.x[1]==s.x[j] && t.y[1]==s.y[j])
                    flag=false;
            if(!flag) continue;
            t.move(s);
            if(!mp[t]) q.push(t),mp[t]=1;
        }
    }
    return -1;
}

void preSof(){
    return;
}

void run(){
    int i,j;
    for(i=tail=1;i<=n;i++){
        scanf("%s",maze[i]+1);
        for(j=1;j<=m;j++) if(isdigit(maze[i][j])){
                int tmp=maze[i][j]-'0';
                maze[i][j]='.';
                tail=max(tail,tmp);
                s.x[tmp]=i,s.y[tmp]=j;
        }
    }
    int ans=bfs();
    printf("%d\n",ans);//printf("---%d---\n",tot);
}

int main(){
    //freopen("1.in","r",stdin);
    //freopen("test.out","w",stdout);
    preSof();
    //run();
    while(~scanf("%d%d",&n,&m)) run();
    //for(scanf("%d",&T),cas=1;cas<=T;cas++) run();
    return 0;
}