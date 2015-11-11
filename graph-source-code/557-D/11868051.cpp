//Language: GNU C++11


#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int inf = 0xfffffff;
const long long Mod = 1000000007;
const double pi = acos(-1.0);
const int N = 112345;
const long long INF = 1LL<<60;
int fa[N];
std::vector<int> V[N];
int fid(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=fid(fa[x]);
}
int Id[N],vis[N];
long long Ans0,Ans1,Ans2,Ans3;
void gao(int u){
    queue<int> q;
    q.push(u);
    int cnt=0;
    Id[u]=1;
    long long o[3];
    o[1]=0;o[2]=0;
    while(!q.empty()){
        u=q.front();q.pop();
        if(vis[u])continue;
        vis[u]=1;
        cnt++;
        int flag=Id[u]==1?2:1;
        o[Id[u]]++;
        for(int i=0;i<V[u].size();i++){
            int v=V[u][i];
            if(Id[v]!=0){
                if(Id[v]!=flag)Ans0++;
            }
            if(!vis[v]){
                q.push(v);
                Id[v]=flag;
            }
        }
    }
    if(cnt==1){
        Ans3++;
    }
    else if(cnt==2){
        Ans2++;
    }else{
        Ans1+=o[1]*(o[1]-1)/2+o[2]*(o[2]-1)/2;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)fa[i]=i;
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        V[u].push_back(v);
        V[v].push_back(u);
        u=fid(u);v=fid(v);
        fa[u]=v;
    }
    for(int i=1;i<=n;i++){
        if(fa[i]==i)gao(i);
    }
    if(Ans0){
        cout<<"0"<<" "<<1<<endl;
    }else if(Ans1){
        cout<<"1 "<<Ans1;
    }else if(Ans2){
        cout<<"2 "<<(long long)Ans2*(n-2)<<endl;
    }else{
        cout<<"3 "<<(long long)(n-1)*n*(n-2)/6<<endl;
    }


}













