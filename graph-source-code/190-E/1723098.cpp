//Language: GNU C++


#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

int n,m;

vector<int> s[500005];

vector<vector<int> > res; 

int main(){
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        u--;v--;
        s[u].push_back(v);
        s[v].push_back(u);
        }
    int st[500005];
    memset(st,0,sizeof st);
    vector<int> k;
    priority_queue<pair<int,int> > Q;
    int tr=0;
    
    for (int i=0;i<n;i++) Q.push(make_pair(-0,i));
    
    while (!Q.empty()){
          int x=Q.top().second;
          int z=Q.top().first;
          Q.pop();
          if (z!=-st[x]) continue;  
          
          if (st[x]==tr){
              if (k.size()>0) res.push_back(k);
              k.clear();          
              }       
          k.push_back(x); 
          st[x]=-1;    
          for (int i=0;i<s[x].size();i++){
              if (st[s[x][i]]==-1) continue;
              st[s[x][i]]++;
              Q.push(make_pair(-st[s[x][i]],s[x][i]));
              }    
          tr++;
          }
    res.push_back(k);
          
    printf("%d\n",res.size());
    for (int i=0;i<res.size();i++){
        printf("%d",res[i].size());
        for (int j=0;j<res[i].size();j++) printf(" %d",res[i][j]+1);
        printf("\n");
        }    
    return 0;
    }
