//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>
using namespace std;

#define LL long long int
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define debug(args...) do {cerr << #args << ": "; dbg,args; cerr << endl;} while(0)
#define DEL 102

vector<int> a[300];
set<int> ng[300];
vector<int> comp[300];
vector<int> comp2[2];
int n,m;
int vis[300];
int fin[300];
int label [300];
int dfs(int cnode,int clab){
    if(label[cnode])
        return 0;
    comp[clab].PB(cnode);
    label[cnode] = clab;
    for(int i=0;i<(int)a[cnode].size();i++)
        dfs(a[cnode][i], clab);
    return 1;
}
int neg(int x){
    if(x < DEL)
        return x+DEL;
    return x - DEL;
}
void dfs2(int cnode,int ccomp){
    if(vis[cnode])
        return;
    vis[cnode] = 1;
    for(int i=0;i<(int)comp[cnode].size();i++){
        if((comp[cnode][i]< DEL && ccomp == 0)||(comp[cnode][i] >= DEL && ccomp == 1))
            fin[comp[cnode][i]] = 1;
        else
            fin[comp[cnode][i]] = 0;
    }
    set<int> ::iterator it;
    for(it = ng[cnode].begin();it != ng[cnode].end();it++)
        dfs2 (*it, 1 - ccomp);
}
int main(){
    int x,y,c,i;
    cin >> n >> m;
    while(m--){
        cin >> x >> y >> c;
        x --;
        y --;
        if(c == 0){
            a[x].PB(DEL + y);
            a[DEL+y].PB(x);
            a[y].PB(DEL + x);
            a[DEL + x].PB(y);
        }
        else{
            a[x].PB(y);
            a[y].PB(x);
            a[DEL + x].PB(DEL + y);
            a[DEL + y].PB(DEL + x);
        }
    }
    int clab = 1;
    for(i=0;i<n;i++){
        if(dfs(i,clab))
            clab ++;
    }
    for(i=0;i<n;i++){
        if(label[i] == label[i+DEL]){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    int j;
    for(i=1;i<clab;i++){
        for(j=0;j<(int)comp[i].size();j++){
            ng[i].insert(label[neg(comp[i][j])]);
        }
    }
    int cnt = 0;
    for(i=1;i<clab;i++){
        if(vis[i])continue;
        dfs2(i, 0);
    }
    for(i=0;i<n;i++)
        cnt += fin[i];
    cout<<cnt<<endl;
    for(i=0;i<n;i++)
        if(fin[i])
            cout<< i + 1 <<" ";
    cout<<endl;
    return 0;
}

