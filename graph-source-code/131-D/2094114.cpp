//Language: GNU C++


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
#define M 3010
vector<int >v[M];
queue<int >q;
stack<int >sta;
int n,dis[M],id[M];
bool flag[M];

void init(){
    for(int i=1;i<=n;i++)
        v[i].clear(),dis[i]=M,id[i]=0,flag[i]=1;
    for(int i=1,x,y;i<=n;i++){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
        id[x]++,id[y]++;
    }
}
void find(){
    while(1){
        for(int i=1;i<=n;i++)
            if(flag[i]&&id[i]==1){
                flag[i]=0;
                sta.push(i);
            }
        if(sta.empty())
            break;
        while(!sta.empty()){
            int x=sta.top();
            sta.pop();
            for(int i=0;i<v[x].size();i++){
                int nex=v[x][i];
                id[nex]--;
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(flag[i]){
            q.push(i);
            dis[i]=0;
        }
}
void bfs(){
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++){
            int nex=v[x][i];
            if(dis[nex]>dis[x]+1){
                dis[nex]=dis[x]+1;
                q.push(nex);
            }
        }
    }
}
int main(){
    while(~scanf("%d",&n)){
        init();
        find();
        bfs();
        for(int i=1;i<=n;i++)
            printf("%d ",dis[i]);
        printf("\n");
    }
    return 0;
}
