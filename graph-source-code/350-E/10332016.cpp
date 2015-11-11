//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

int a[1010];
bool lab[1010];
vector<pair<int,int> > ans;
bool use[1010][1010];
int p[1010];
int f(int x){
    return x==p[x]?x:p[x]=f(p[x]);
}
int main(){
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    if(K==n){
        puts("-1");
        return 0;
    }
    for(int i=0;i<K;i++){
        scanf("%d",&a[i]);
        lab[a[i]]=true;
    }
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    sort(a,a+K);
    for(int i=1;i<=n&&m;i++){
        for(int j=i+1;j<=n&&m;j++){
            if(i==a[0]){
                if(lab[j])continue;
            }
            int fi=f(i),fj=f(j);
            if(fi==fj)continue;
            p[fi]=fj;
            m--;
            ans.push_back({i,j});
            use[i][j]=true;
        }
    }
    for(int i=1;i<=n&&m;i++){
        for(int j=i+1;j<=n&&m;j++){
            if(use[i][j])continue;
            if(i==a[0]){
                if(lab[j])continue;
            }
            m--;
            ans.push_back({i,j});
        }
    }
    if(m){
        puts("-1");
        return 0;
    }
    for(int i=0;i<ans.size();i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}
