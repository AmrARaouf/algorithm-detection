//Language: GNU C++


#include <stdio.h>
#include <set> 
#include <queue>
#include <algorithm>
using namespace std;
int n,m,res=-1;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
set<int> v;

struct State{
    int steps;
    char a[15][15];
    
    int hash(){
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res=171*res+a[i][j];
            }
        }
        return res;
    }
    void takeout(char c){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==c){
                    a[i][j]='.';
                    return;
                }
            }
        }
        return;
    }
    void increase(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]>='0' && a[i][j]<='9')a[i][j]++;
            }
        }
    }
};

queue<State> q;

bool inside(int x,int y){
    return x>=0 && x<n && y>=0 && y<m;
}

void move(State& state){
    int x,y,h;
    state.steps++;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(state.a[i][j]=='2'){
        for(int f=0;f<4;f++){
            x=i+dx[f];y=j+dy[f];
            if(inside(x,y)){
                if(state.a[x][y]=='@'){
                    res=state.steps;
                    return;
                }
                if(state.a[x][y]=='.'){
                    state.a[x][y]='1';
                    h=state.hash();
                    if(v.find(h)==v.end()){
                        q.push(state);
                        v.insert(h);
                    }
                    state.a[x][y]='.';
                }
            }
        }
        return;
    }
    return;
}

int main(){
    //freopen("D:\\input.txt","r",stdin);
    bool f=false;
    int len=0;
    State init,p;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",init.a[i]);
        for(int j=0;j<m;j++){
            //printf("%c",init.a[i][j]);
            if(init.a[i][j]>='0' && init.a[i][j]<='9'){
                len=max(len,init.a[i][j]-'0');
            }
        }
        //printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(init.a[i][j]=='@'){
                if(inside(i-1,j) && init.a[i-1][j]!='#')f=true;
                if(inside(i+1,j) && init.a[i+1][j]!='#')f=true;
                if(inside(i,j-1) && init.a[i][j-1]!='#')f=true;
                if(inside(i,j+1) && init.a[i][j+1]!='#')f=true;
            }
        }
    }
    if(!f){
        printf("-1");
        return 0;
    }
    init.steps=0;
    q.push(init);
    v.insert(init.hash());
    while(!q.empty() && res==-1){
        p=q.front();q.pop();
        p.takeout(len+'0');
        p.increase();
        move(p);
    }
    printf("%d",res);
    return 0;
}