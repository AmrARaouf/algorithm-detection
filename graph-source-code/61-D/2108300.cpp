//Language: GNU C++


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define M 100100
#define inf 0x7fffffff
struct node{
    int x,wei;
}a;
vector<node>v[M];
queue<int>q;
int n,parent[M];
long long dis[M],sum;
bool visit[M];

void insert(int x,int y,int c){
    a.x=y,a.wei=c;
    v[x].push_back(a);
    a.x=x,a.wei=c;
    v[y].push_back(a);
}
void init(){
    sum=0;
    for(int i=1;i<=n;i++)
        dis[i]=inf,v[i].clear();
    for(int i=1;i<n;i++){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        insert(x,y,c);
        sum+=c*2;
    }
}
void bfs(){
    while(!q.empty())
        q.pop();
    q.push(1);
    dis[1]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++){
            int nex=v[x][i].x;
            if(dis[nex]>dis[x]+v[x][i].wei){
                q.push(nex);
                dis[nex]=dis[x]+v[x][i].wei;
            }
        }
    }
}
void rebfs(int x){
    memset(visit,0,sizeof(visit));
    visit[x]=1;
    parent[x]=-1,parent[1]=-1;
    q.push(x);
    while(1){
        x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++){
            int nex=v[x][i].x;
            if(!visit[nex]){
                parent[nex]=x;
                visit[nex]=1;
                q.push(nex);
            }
        }
        if(parent[1]!=-1)
            return ;
    }
}
int find(){
    long long maxx=-1;
    int flag=0;
    for(int i=2;i<=n;i++)
        if(maxx<dis[i]){
            maxx=dis[i];
            flag=i;
        }
    return flag;
}
int main(){
    while(~scanf("%d",&n)){
        if(n==1){
            cout<<"0"<<endl;
            continue;
        }
        init();
        bfs();
        rebfs(find());
        int p=1;
        while(1){
            for(int i=0;i<v[p].size();i++){
                int nex=v[p][i].x;
                if(nex==parent[p]){
                    sum-=v[p][i].wei;
                    break;
                }
            }
            p=parent[p];
            if(p==-1)
                break;
        }
        cout<<sum<<endl;
    }
    return 0;
}
