//Language: GNU C++


#include<iostream>
#define MAX 100
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
bool dp[10][10][MAX+100];
int dx[]={0,0,0,1,-1,1,1,-1,-1},dy[]={0,1,-1,0,0,1,-1,1,-1};
bool func(int ny,int nx,char s[][10],int t){
    if(!dp[ny][nx][t])
        return 0;
    else if(s[ny][nx]=='A'){
        return 1;
    }else if(s[ny][nx]=='S'){
        //cout<<"888888888"<<endl;
        return dp[ny][nx][t]=0;
        
    }
    //s\cout<<"-----"<<endl;
    //if(t==0){
    /*rep(j,8){
        rep(k,8){
            if(ny==j&&nx==k)
            cout<<1;
            else
            cout<<s[j][k];
        }
        cout<<endl;
    }
        */
    /*  cout<<s[ny][nx]<<endl;
    cout<<ny<<nx<<endl;
    }
*/  
    char p[10][10];
    t++;
    for(int i=0;i<9;i++){
        int y=ny+dy[i];
        int x=nx+dx[i];
        if(x<0||y<0||x>7||y>7||s[y][x]=='S')
            continue;
        rep(j,8)
            rep(k,8){
                p[j][k]=s[j][k];
        }
        for(int j=7;j>=0;j--){
            for(int k=7;k>=0;k--){
                if(j==0){
                    if(p[j][k]=='S')
                        p[j][k]='.';
                }else{
                    if(p[j-1][k]!='A')
                    p[j][k]=p[j-1][k];
                }
            }
        }
        //if(t==1)
            //cout<<i<<endl;
        if(func(y,x,p,t))
            return 1;
    }
    return dp[ny][nx][t-1]=0;
}
int main(){
    char s[10][10];
    for(int i=0;i<8;i++)
        cin>>s[i];
    rep(i,8)
        rep(j,8)
        rep(k,MAX)
            dp[i][j][k]=1;
    
    if(func(7,0,s,0)==1)
        cout<<"WIN"<<endl;
    else
        cout<<"LOSE"<<endl;
    return 0;
}