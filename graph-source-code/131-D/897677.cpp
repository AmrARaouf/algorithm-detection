//Language: GNU C++


#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

#include <bitset>
#include <algorithm>
#include <map>
#include <fstream>
#define pb push_back
#define MP make_pair
#define FOR(a,b) for((a)=0 ; (a)<(b) ; (a)++)
typedef long long ll;
using namespace std;
vector<int> table[3001];
vector<int> V;
int N;
bool used[3001];
bool cycle[3001];
int dis[3001];
int cur[3001];
void dfs(int from , int s, int depth){
    int i,j;
    for(i=0;i<table[s].size();i++){
        int to = table[s][i];
        if(to == from)continue;

        if(used[to]){
            for(j=0;j<depth;j++){
                if(cur[j]==to){
                    for(;j<depth;j++)
                    cycle[cur[j]]=1;
                    
                    break;
                }
            }
        }else{
            used[to] = 1;
            cur[depth] = to;
            dfs(s,to,depth+1);
        }
    }

}
void bfs(){
    int i,j,k;
    queue< pair<int,int> > Q;
    for(i=1;i<=N;i++){
        if(cycle[i])Q.push(MP(i,0));
    }
    while(!Q.empty()){
        int s= Q.front().first;
        int d = Q.front().second;
        if(dis[s]==0)d = 0;
        for(i=0;i<table[s].size();i++){
            int to =table[s][i];
            if(dis[to] > d + 1){
                dis[to] = d+1;
                Q.push(MP(to,d+1));
            }
        }   
        Q.pop();
    }
    return ;
}
int main(){
    int i,j,k,M,P,l,m,n;
    cin >> N;
    int t1,t2;
    for(i=0;i<N;i++){
        cin >> t1>>t2;
        table[t1].pb(t2);
        table[t2].pb(t1);
    }
    cur[0] = 1;
    used[1] = 1;
    dfs(0,1,1);
    for(i=1;i<=N;i++)
    if(cycle[i]){
    V.pb(i);
    dis[i] = 0;
    }else dis[i]=100000;
    bfs();
    for(i=1;i<N;i++){
        cout<<dis[i]<<" ";
    }
    cout<<dis[N]<<endl;
}
