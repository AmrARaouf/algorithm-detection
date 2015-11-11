//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

vector<bool> used;
vector <vector<int> > g;
int l;
vector <int> b;

void dfs(int v){
    used[b[v]]=true;
    for (int j=0;j<g[v].size();j++){
        int to=g[v][j];
        if (to!=l){
            if (!(used[b[to]])) dfs(to);
        }
    }
}

int main(){
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
   int n,m;
   cin >> n >> m;
   string s;
   vector <string> a;
   getline(cin,s,char(10));
   for (int i=0;i<n;i++){
     getline(cin,s,char(10));
     a.push_back(s);
   }
   int ans=3;
   int c=0;
   vector <int> p;
   g.assign(2500,p);
   b.assign(2500,0);
   for (int i=0;i<n;i++){
     for (int j=0;j<m;j++){
        if (a[i][j]=='#'){
            c++;
            int v=m*i+j;
            p.push_back(v);
            b[v]=p.size()-1;
            int r=0;
            if ((i > 0)&&(a[i-1][j]=='#')){
                 r++;
                 g[v].push_back(v-m);
                 g[v-m].push_back(v);
            }
            if ((i < n-1)&&(a[i+1][j]=='#')){
                 r++;
                 g[v].push_back(v+m);
                 g[v+m].push_back(v);
            }
            if ((j > 0)&&(a[i][j-1]=='#')){
                 r++;
                 g[v].push_back(v-1);
                 g[v-1].push_back(v);
            }
            if ((j < m-1)&&(a[i][j+1]=='#')){
                 r++;
                 g[v].push_back(v+1);
                 g[v+1].push_back(v);
            }
            if (r==2) ans=2;
        }
     }
   }
   if (c <=2){
    cout << -1;
    return 0;
   }
   if (c==3){
    cout << 1 ;
    return 0;
   }
    int e=p.size();
    for (int i=0;i<e;i++){
        used.assign(e,false);
        bool ff=true;
        l=p[i];
        if (i==0) dfs(p[1]);
        else dfs(p[i-1]);
        for (int j=0;j<e;j++)
            if (!(used[j])&&(i!=j)){
                ans=1;
                ff=false;
                break;
            }
        if (!(ff)) break;
    }
    cout << ans;
}
