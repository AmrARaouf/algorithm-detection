//Language: GNU C++


#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define N 100001

int n, m;

int f[N];

vector<int> g[N];
vector<int> gr[N];

set<int> reachedFromA, reachedFromU;

bool visited[N];
bool visitedRev[N];

int main(){
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        scanf("%d", f + i);
    }

    for(int i = 1; i <= m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    queue<int> q;

    //from used -> reversed graph
    for(int i = 1; i <= n; i++){
        if(f[i] == 2){
            reachedFromU.insert(i);
            q.push(i);
            visitedRev[i] = true;
        }

    }

    while(!q.empty()){
        int head = q.front();
        q.pop();

        if(f[head] == 1){
            continue;
        }

        for(int i = 0; i < gr[head].size(); i++){
            if(!visitedRev[gr[head][i]]){
                visitedRev[gr[head][i]] = true;
                q.push(gr[head][i]);
                reachedFromU.insert(gr[head][i]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(f[i] == 1){
            reachedFromA.insert(i);
            q.push(i);
            visited[i] = true;
        }
    }

    while(!q.empty()){
        int head = q.front();
        q.pop();

        for(int i = 0; i < g[head].size(); i++){
            int v = g[head][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                reachedFromA.insert(v);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(reachedFromA.count(i) && reachedFromU.count(i)){
            printf("1\n");
        }
        else{
            printf("0\n");
        }

    }

    return 0;
}
