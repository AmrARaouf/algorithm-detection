//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int mat[101][101][101],i,j,k;
    for(i=0;i<101;i++){
        for(j=0;j<101;j++){
            for(k=0;k<101;k++) mat[i][j][k]=0;
        }
    }
    int n,m;cin>>n>>m;
    for( i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mat[a][b][c] =1;
        mat[b][a][c] =1;
    }
    int q;
    cin>>q;
    while(q--){
        int st,en,ct=0;
        cin>>st>>en;
        int visit[101];
        
        for(i=1;i<=100;i++){
            for(int l=1;l<=100;l++){
                visit[l]=0;
            }
            queue<int> q;
            int t=0;
            q.push(st);
            while(!q.empty()){
                int k=q.front();
                q.pop();
                visit[k]=1;
                for(j=1;j<=n;j++){
                    if(mat[k][j][i] ==1 && !visit[j]){
                        if(j==en){
                            t=1;
                            break;
                        }
                        visit[j]=1;
                        q.push(j);
                    }
                }
                if(t==1) break;
            }
            if(t==1) ct++;
        }
        cout<<ct<<"\n";
    }
    return 0;
}