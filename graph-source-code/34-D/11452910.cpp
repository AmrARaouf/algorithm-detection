//Language: GNU C++


#include <bits/stdc++.h>
#define vi  vector<int>
using namespace std;
typedef long long ll;
vi g[100000];
int n;
int r1;
int r2;
int a[100000];
void dfs(int c,int p){
    a[c]=p;
    int l=g[c].size();
    for (int i=0;i<l;i++){
        if (g[c][i]==p)continue;
        dfs(g[c][i],c);
    }
}
int main() {
 cin>>n>>r1>>r2;
 int t;
 for (int i=1;i<=n;i++){
     cin>>t;
     if (i==r1)i++;
     if (i<=n){
         g[i].push_back(t);
         g[t].push_back(i);
     }
 }
 dfs(r2,r2);
 for (int i=1;i<=n;i++){
     if (i!=r2)cout<<a[i]<<" ";
 }
}
