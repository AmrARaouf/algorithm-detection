//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

#define FIN freopen("test.txt","r",stdin)
double val[5000];

int main(){
    //FIN;
    int n,m,a,b;
    double ans=0,w;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b>>w;
        ans=max(ans,(val[a]+val[b])/w);
    }
    printf("%.15lf",ans);
}