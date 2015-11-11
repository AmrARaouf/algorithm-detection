//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
int mat[101][101];
int cnt[101];
int main(){
    int n,m;
    cin>>n>>m;
    int x,y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        mat[x][y]=mat[y][x]=1;
        cnt[x]++;
        cnt[y]++;
    }
    int ans=0;
    while(true){
        vector <int> V;
        for(int i=1; i<=n; i++){
            if(cnt[i]==1)V.push_back(i);
        }
        if(!V.size())break;
        
        for(int i=0; i<V.size(); i++){
            for(int j=1; j<=n; j++){
                if(mat[V[i]][j]){
                    mat[V[i]][j]=0;
                    cnt[j]--;
                }
            }
            cnt[V[i]]=0;
        }
        ans++;
    }
    cout<<ans;
}