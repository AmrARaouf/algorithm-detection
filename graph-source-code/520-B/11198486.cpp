//Language: GNU C++11


//: vs (;
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+100;

int n,m;
vector <int> a[maxn];
int dis[maxn];
deque <int> q;
bool mark[maxn];

void bfs(int x){
    mark[x] = true;
    for(int i = 0;i < a[x].size();i++){
        if(mark[a[x][i]] == false){
            q.push_front(a[x][i]);
            dis[a[x][i]] = dis[x]+1;
            mark[a[x][i]] = true;
        }
    }
    while(!q.empty()){
        int t = q.back();
        q.pop_back();
        bfs(t);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1;i < maxn-1;i++){
        if(2*i <= maxn-1)
            a[i].push_back(2*i);
        if(i-1 > 0)
            a[i].push_back(i-1);
    }
    bfs(n);
    cout << dis[m] << endl;
}