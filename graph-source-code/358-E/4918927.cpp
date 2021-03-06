//Language: GNU C++


#include <iostream>
using namespace std;
#define MAXN 1111
#define MAXM 1111
int N,M,A,Cnt,X,Y,K,Odd;
int Sum1[MAXN][MAXM],Sum2[MAXN][MAXM];
int Vis[MAXN][MAXM];
int Dx[4]={-1,0,0,1};
int Dy[4]={0,-1,1,0};
bool check(int x,int y) { return x>=1&&x<=N&&y>=1&&y<=M; }
int sum(int x1,int y1,int x2,int y2)
{
    if(x1>x2) swap(x1,x2);
    if(y1>y2) swap(y1,y2);
    return (x1==x2)?(Sum2[x2][y2]-Sum2[x1][y1-1]):(Sum1[x2][y2]-Sum1[x1-1][y1]);
}
int DFS(int x,int y)
{
    Vis[x][y]=K;
    int ret=2,deg=0;
    for(int d=0;d<4;++d)
    {
        int newx=x+Dx[d]*K;
        int newy=y+Dy[d]*K;
        if(check(newx,newy)&&sum(x,y,newx,newy)==K+1)
        {
            ++deg;
            ret+=K-1;
            if(Vis[newx][newy]!=K)
                ret+=DFS(newx,newy);
        }
    }
    Odd+=deg&1;
    return ret;
}
int main()
{
    cin>>N>>M;
    for(int n=1;n<=N;++n)
        for(int m=1;m<=M;++m)
        {
            cin>>A;
            if(A==1&&X==0)
            {
                X=n;
                Y=m;
            }
            Cnt+=A;
            Sum1[n][m]=Sum1[n-1][m]+A;
            Sum2[n][m]=Sum2[n][m-1]+A;
        }
    if(Cnt==1)
        cout<<-1;
    else
    {
        bool flag=true;
        for(K=2;K<=N;++K)
        {
            Odd=0;
            if(DFS(X,Y)==Cnt*2&&(Odd==0||Odd==2))
            {
                cout<<K<<" ";
                flag=false;
            }
        }
        if(flag)
            cout<<-1;
    }
    return 0;
}