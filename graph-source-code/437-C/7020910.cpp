//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
vector<int> v2[2005];
vector< pair<int,int> >v;
int i,j,k,n,m,d[2005],hh[2005],a[2005],x,y,t;

int main(){
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        v.push_back(make_pair(a[i],i));
    }
    sort(v.begin(),v.end(),greater<pair<int,int> >());
    for(i=0;i<n;i++)
        hh[i]=v[i].second;
    for(i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        x--,y--;
        v2[x].push_back(y);
        v2[y].push_back(x);
        d[x]+=a[y];
        d[y]+=a[x];
     }

  
     for(i=0;i<n;i++){
         t+=d[hh[i]];
        
         k=hh[i];
         for(j=0;j<v2[k].size();j++){
            
             d[v2[k][j]]-=a[k];    
         }
     }
    printf("%d",t);

    return 0;
}