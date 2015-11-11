//Language: GNU C++


#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct state{
    int a,b,cost;
    bool f;
    state(){}
    state(int x,int y,bool F,int z=0){
        a=x;
        b=y;
        f=F;
        cost=z;
    }
};
int n,e,a,b;
state parent[500][500][2];
bool vis[500][500][2];
vector<vector<int> > g;
vector<int> solA,solB;
int BFS(){
    queue<state> q;
    state s(0,n-1,0,0);
    q.push(s);
    vis[0][n-1][0]=true;
    parent[0][n-1][0]=state(-1,-1,0);
    while(!q.empty()){
        s=q.front();
        q.pop();
        if(!s.f && s.a==n-1 && s.b==0)
            return s.cost;
        if(!s.f){
            for(int i=0;i<g[s.a].size();++i)
                if(!vis[g[s.a][i]][s.b][1]){
                    vis[g[s.a][i]][s.b][1]=true;
                    parent[g[s.a][i]][s.b][1]=state(s.a,s.b,0);
                    q.push(state(g[s.a][i],s.b,1,s.cost+1));
                }
        }else
            for(int i=0;i<g[s.b].size();++i)
                if(g[s.b][i]!=s.a && !vis[s.a][g[s.b][i]][0]){
                    vis[s.a][g[s.b][i]][0]=true;
                    parent[s.a][g[s.b][i]][0]=state(s.a,s.b,1);
                    q.push(state(s.a,g[s.b][i],0,s.cost+1));
                }
    }
    return -2;
}
void print(int a,int b,bool f){
    if(parent[a][b][f].a==-1){
        solA.push_back(a);
        solB.push_back(b);
        return;
    }
    print(parent[a][b][f].a,parent[a][b][f].b,parent[a][b][f].f);
    if(!f)
        solB.push_back(b);
    else
        solA.push_back(a);
}
int main()
{
    scanf("%d%d",&n,&e);
    g.resize(n);
    while(e--){
        scanf("%d%d",&a,&b);
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    e=BFS()/2;
    printf("%d\n",e);
    if(e!=-1){
        print(n-1,0,0);
        for(int i=0;i<solA.size();++i)
            printf("%d ",solA[i]+1);
        puts("");
        for(int i=0;i<solB.size();++i)
            printf("%d ",solB[i]+1);
    }
    return 0;
}