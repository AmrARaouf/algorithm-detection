//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

int main(){
    bool vis[505] = {false} ;
    int d[505][505] = {{0}} ;
    long long ans[505] = {0} ;
    int a[505] ;
    int n ;
    scanf("%d",&n) ;
    for(int i = 1 ;i <= n ; i++){
        for(int j = 1 ;j <= n ;j++){
            scanf("%d",&d[i][j]) ;
        }
    }
    for(int i = 1 ;i <= n ; i++){scanf("%d",&a[i]) ;vis[i] = true ;}
    vis[a[n]] = false ;
    for(int k = n ; k >= 1 ;k--){
        for(int i = 1 ;i <= n ; i++){
            for(int j = 1 ;j <= n ; j++){
                d[i][j] = min(d[i][j] , d[i][a[k]] + d[a[k]][j]) ;
            }
        }
        for(int i = 1 ; i <= n ; i++){
            if(vis[i])continue;
            for(int j = 1 ;j <= n ;j++){
                if(vis[j])continue ;
                ans[k]+=d[i][j] ;
            }
        }
        vis[a[k-1]] = false ;
    }
    for(int i = 1 ;i <= n ; i++)printf("%I64d ",ans[i]) ;
    return 0;
}
