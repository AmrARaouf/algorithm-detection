//Language: GNU C++


#include<map>
#include<set>
#include<list>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;
#define lowbit(x) (x&(-x))
#define INF 99999999
#define LLINF 0x7fffffffffffffffll
#define LL __int64
#define MAXN 2100
#define MAXE 1100000
#define CH 129
#define eps 1e-8
#define PI acos(-1.0)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define CC(m,what) memset(m,what,sizeof(m))
#define fuck puts("<<---------------------");
template<class Z>inline bool checkmax(Z &a,Z b){if(a==-1||a<b){a=b;return true;}return false;}
template<class Z>inline bool checkmin(Z &a,Z b){if(a==-1||a>b){a=b;return true;}return false;}

int n,s,t;
int net[510],size;
void init(){
    size=0;
    memset(net,-1,sizeof(net));
}
struct EDGE{
    int v,next;
}edge[51000];
void add(int u,int v){
    edge[size].v=v;
    edge[size].next=net[u];
    net[u]=size++;
}
struct Node{
    int x,y,z;
    Node(){}
    Node(int _x,int _y,int _order){
        x=_x; y=_y; z=_order;
    }
};
int pre[510][510][2];
queue<Node> q;
void gao(){
    while(!q.empty()) q.pop();
    memset(pre,0,sizeof(pre));
    pre[1][n][0]=-1;
    q.push(Node(1,n,0));
    while(!q.empty()){
        int x=q.front().x,y=q.front().y,z=q.front().z^1;
        q.pop();
        if(x==y && z) continue;//大家都走完了一轮 判断非法 
        if(z){//z为1时x走 
            for(int i=net[x]; i!=-1; i=edge[i].next){
                int v=edge[i].v;
                if(pre[v][y][z]==0){
                    pre[v][y][z]=x;
                    q.push(Node(v,y,z));
                }
            }
        }
        else{//z为0时y走 
            for(int i=net[y]; i!=-1; i=edge[i].next){
                int v=edge[i].v;
                if(pre[x][v][z]==0){
                    pre[x][v][z]=y;
                    q.push(Node(x,v,z));
                }
            }
        }
    }
    if(pre[n][1][0] == 0){
        puts("-1"); return;
    }
    //printf("%d~~~%d\n",pre[n][1][0],pre[n][1][1]);
    vector<int> px,py;
    px.push_back(n); py.push_back(1);
    int x=n,y=1,z=0;
    while(pre[x][y][z]!=-1){
        if(z){
            x=pre[x][y][z];
            px.push_back(x);
        }
        else{
            y=pre[x][y][z];
            py.push_back(y);
        }
        z^=1;
    }
    printf("%d\n",px.size()-1);
    for(int k=px.size()-1; k>=0; k--){
        printf("%d",px[k]);
        printf(k==0?"\n":" ");
    }
    for(int k=py.size()-1; k>=0; k--){
        printf("%d",py[k]);
        printf(k==0?"\n":" ");
    }
}
///////////////////////////////
inline void scan_f(int &num){
    char in;
    int flag=0;
    in=getchar();
    while(in<'0'||in>'9'){
        if(in=='-')flag=1;
        in=getchar();        
    }    
    num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
        num*=10,num+=in-'0';
    }
    if(flag)num=-num;
}
/////////////////////////////
int main(){
    int i,j,h;
    int a,b,c;
    int m;
    while(scanf("%d%d",&n,&m)!=EOF){
        init();
        for(i=1;i<=m;i++){
            //scanf("%d%d",&a,&b);
            scan_f(a); scan_f(b);
            add(a,b); add(b,a);
        }
        gao();
    }
    return 0;
}