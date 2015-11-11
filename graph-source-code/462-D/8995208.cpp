//Language: MS C++


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define mx 100005
#define mod 1000000007 
long long dp1[mx],dp2[mx];
int a[mx];
vector<int> adj[mx];
void dfs(int x, int p){
    dp1[x]=a[x];
    dp2[x]=!a[x];
    int omar = adj[x].size();
    for(int i=0;i<omar;++i)
    {
        int to=adj[x][i];
        if(to==p)continue;
        dfs(to,x);
        long long v=dp1[to]+dp2[to];
        dp1[x]=dp1[x]*(v)%mod + dp2[x]*dp1[to];
        dp1[x]%=mod;
        dp2[x]=dp2[x]*(dp2[to]+dp1[to])%mod ;
        dp2[x]%=mod;
    }

}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;++i){
        int pi;
        cin>>pi;
        adj[pi].push_back(i);
        adj[i].push_back(pi);
    }
    for(int i=0;i<n;++i)
        cin>>a[i];
    dfs(0,-1);
    cout<<dp1[0]<<endl;
    //system("pause");
}