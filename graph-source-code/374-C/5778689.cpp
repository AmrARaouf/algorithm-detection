//Language: GNU C++


/*
ID: roben_71
PROG: acrobat
LANG: C++
*/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <cmath>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<fstream>
#include<queue>
#include<deque>
#include<stack>
#define pb push_back
//#define pop pop_back
#define li 200009
#define e 10000
#define maxxx 100000000
#define mp make_pair
#define ss second.second
#define sf second.first
#define fs first.second
#define ff first.first
#define st first
#define nd second
#define ll long long
#define inf 2147483647 
#define rep(i,r,n) for(int i=r;i<=n;i++)
#define clr(x,i) memset(x,i,sizeof(x))
#define min(x,i) x<i?x:i
#define max(x,i) x>i?x:i
#define ro(x,i) x-i<0?i-x:x-i
#define abs(x) x<0?-x:x
#define read(x) scanf("%d",&x)
#define getf scanf
#define print(x) printf("%d ",x)
//#define end printf("\n")
using namespace std;
//ifstream fin;
//ofstream fout;
FILE *outt,*inn;
ifstream fin("1.txt");
const int N = 1e3+10;
int n,m,ans[N][N],nxt[128],rank=0,vis[N][N];
char c[N][N];
bool mark[N][N];
int sol(int i,int j,int x,int y){
    if(c[i][j]=='A'){
        return (ans[x][y]+1);
    }
    else{
        return ans[x][y];
    }
}
void dfs(int i,int j){
    mark[i][j]=1;
    vis[i][j]=rank;
    bool is=0;//,ok=0;
    if(c[i][j+1]==nxt[c[i][j]]){
        is=1;
        if(vis[i][j+1]==rank){
        //  cout<<i<<" "<<j<<" "<<i<<" "<<j+1<<endl;
        //  cout<<rank;
            puts("Poor Inna!");
            exit(0);
        }
        if(!mark[i][j+1]){
        //  ok=1;
            dfs(i,j+1);
        }
        ans[i][j]=max(ans[i][j],sol(i,j,i,j+1));
    }
    //2
    if(c[i][j-1]==nxt[c[i][j]]){
        is=1;
        if(vis[i][j-1]==rank){
        //  cout<<i<<" "<<j<<" "<<i<<" "<<j-1<<endl;
        //  cout<<rank;
            puts("Poor Inna!");
            exit(0);
        }
        if(!mark[i][j-1]){
        //  ok=1;
            dfs(i,j-1);
        }
        ans[i][j]=max(ans[i][j],sol(i,j,i,j-1));
    }
    //3
    if(c[i+1][j]==nxt[c[i][j]]){
        is=1;
        if(vis[i+1][j]==rank){
        //  cout<<i<<" "<<j<<" "<<i+1<<" "<<j<<endl;
        //  cout<<rank;
            puts("Poor Inna!");
            exit(0);
        }
        if(!mark[i+1][j]){
        //  ok=1;
            dfs(i+1,j);
        }
        ans[i][j]=max(ans[i][j],sol(i,j,i+1,j));
    }
    //4
    if(c[i-1][j]==nxt[c[i][j]]){
        is=1;
        if(vis[i-1][j]==rank){
        //  cout<<i<<" "<<j<<" "<<i-1<<" "<<j<<endl;
        //  cout<<rank;
            puts("Poor Inna!");
            exit(0);
        }
        if(!mark[i-1][j]){
        //  ok=1;
            dfs(i-1,j);
        }
        ans[i][j]=max(ans[i][j],sol(i,j,i-1,j));
    }
    if(!is){
        if(c[i][j]=='A'){
            ans[i][j]=1;
        }
        
    }
//  if(!ok){
    vis[i][j]=0;
//  }
    return;
}
int main(){
    read(n),read(m);
    nxt['D']='I';
    nxt['I']='M';nxt['M']='A';nxt['A']='D';
    for(int i=1;i<=n;i++){
        scanf("%s",c[i]+1);
    }
    clr(ans,0);
    clr(vis,0);
    clr(mark,0);
    rank=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!mark[i][j] && c[i][j]=='D'){
                dfs(i,j);
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j]=='D'){
                res=max(res,ans[i][j]);
            }
        }
    }
    if(res==0){
        puts("Poor Dima!");
        return 0;
    }
    printf("%d",res);
    
    
    return 0;
}
 