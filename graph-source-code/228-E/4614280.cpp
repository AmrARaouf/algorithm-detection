//Language: GNU C++


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

#define xx first
#define yy second
#define ll long long
#define ull unsigned
#define pb push_back
#define pp pop_back
#define pii pair<int ,int>
#define vi vector<int>
#define mp make_pair
using namespace std;
const int maxn=100+10;
int n,m;
vector<pii> adj[maxn];
bool mark[maxn];
int on[maxn];
bool flag;
void DFS(int v){
    mark[v]=true;
    for(int j=0;j<adj[v].size();j++){
        pii x=adj[v][j];
        if(!mark[x.xx]){
            if(adj[v][j].yy)on[x.xx]=on[v];
            else on[x.xx]=on[v]+1;
            mark[x.xx]=true;
            DFS(x.xx);
        }
        else
            if(adj[v][j].yy==(on[v]+on[x.xx]+2)%2)flag=true;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].pb(mp(v,c));
        adj[v].pb(mp(u,c));
    }
    for(int i=1;i<=n;i++)if(!mark[i])DFS(i);
    if(flag){cout<<"Impossible";return 0;}
    int cnt=0;
    for(int i=1;i<=n;i++)if(on[i]%2)cnt++;
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)if(on[i]%2)cout<<i<<" ";
    //cin>>n;
}