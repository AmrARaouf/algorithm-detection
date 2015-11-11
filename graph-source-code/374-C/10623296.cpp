//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;
const long long int INF = 10000000000;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;
char s[1234];
char mat[2234][2234];
long long int dp[2234][2234];
long long solve(int i,int j){
    if(dp[i][j] == -2)return INF;
    else if(dp[i][j] !=  -1) return dp[i][j];
    long long cont = 0;
    
    
    dp[i][j] = -2;
    for(int i1 = 0;i1 < 4;i1++){
        if(mat[i][j] == 'D' && mat[i+dx[i1]][j+dy[i1]] == 'I')cont = max(solve(i+dx[i1],j+dy[i1]),cont);
        else if(mat[i][j] == 'I' && mat[i+dx[i1]][j+dy[i1]] == 'M')cont = max(solve(i+dx[i1],j+dy[i1]),cont);
        else if(mat[i][j] == 'M' && mat[i+dx[i1]][j+dy[i1]] == 'A')cont = max(solve(i+dx[i1],j+dy[i1]),cont);
        else if(mat[i][j] == 'A' && mat[i+dx[i1]][j+dy[i1]] == 'D'){cont = max(solve(i+dx[i1],j+dy[i1]),cont);}
    }
    if(mat[i][j] == 'A'){cont++;}
    dp[i][j] = cont;
    return dp[i][j];
}
int main(){
    memset(mat,0,sizeof mat);
    scanf("%d %d",&n,&m);   
    for(int i = 100;i < n+100;i++){
        scanf(" %s",s);
        for(int j = 100;j < m+100;j++){
            mat[i][j] = s[j-100];
        }
    }
    memset(dp,-1,sizeof dp);
    long long resp = 0;
    for(int i = 100;i < n+100;i++){
        for(int j = 100;j < m+100;j++){
            if(dp[i][j] == -1 && mat[i][j] == 'D')resp = max(resp,solve(i,j));
        }
    }
    if(resp == 0)printf("Poor Dima!\n");    
    else if(resp >= INF)printf("Poor Inna!\n");
    else printf("%lld\n",resp);
    return 0;
}