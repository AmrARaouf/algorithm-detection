//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue> 
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define inf 2000000000
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
#define For(i,s,n) for (int i=s;i<=n;i++)
#define FOR(i,s,n) for (int i=s;i<n;i++)
#define Ford(i,s,n) for (int i=s;i>=n;i--)
typedef long long ll;
using namespace std;

vector <int> cycle,g[100005];
int n,m,k,x,y,p[100005],cycle_end;
bool used[100005],ind;


void dfs(int v,int l){
     if (ind) return;
     used[v]=true;
     FOR(i,0,g[v].size()){
                          int to=g[v][i];
                          if (l>k&&to==1){
                                          cycle_end=v;
                                          ind=true;
                                          return;
                                          }
                          if (ind) return;
                          if (!used[to]) p[to]=v,dfs(to,l+1);
                          }
     }


int main(){
    scanf("%d%d%d",&n,&m,&k);
    For(i,1,m){
               scanf("%d%d",&x,&y);
               g[x].pb(y);
               g[y].pb(x);
               }
    dfs(1,1);
    for (int i=cycle_end;i;i=p[i])
       cycle.pb(i);
    reverse(cycle.begin(),cycle.end());
    cout<<cycle.size()<<endl;
    FOR(i,0,cycle.size()) cout<<cycle[i]<<" ";
    //system("pause");
    }








