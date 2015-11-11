//Language: GNU C++


#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n,m,ma,dx[]={-1,1,0,0},dy[]={0,0,1,-1},a[1100][1100],goo[1100][1100];
char c;
bool v[1100][1100],fin[1100][1100];

int go(int i,int j)
{
    if(goo[i][j]!=-1)
        return goo[i][j];
    int ret = 0;
    int maxy = 0;
    v[i][j] = 1;

    for(int k=0;k<4;++k)
        if(i+dx[k]>=1 && i+dx[k]<=n && j+dy[k]>=1 && j+dy[k]<=m)
            if((4+a[i+dx[k]][j+dy[k]]-a[i][j])%4 == 1)
            {

                if(v[i+dx[k]][j+dy[k]]==1 && fin[i+dx[k]][j+dy[k]]==0)
                {
                    return -1;
                }

                else
                {
                    int y = go(i+dx[k],j+dy[k]);
                    if(y==-1)
                        return -1;
                    if(a[i][j]==2)
                        ret = 1;

                    if(maxy < y)
                    {
                        maxy = y;
                    }
                }
            }
    fin[i][j]=1;
    goo[i][j] = maxy+ret;
    return goo[i][j];
}

int main()
{
    //freopen("input.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            cin>>c;
            if(c=='D')
                a[i][j]=0;
            if(c=='I')
                a[i][j]=1;
            if(c=='M')
                a[i][j]=2;
            if(c=='A')
                a[i][j]=3;

            goo[i][j] = -1;
        }

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(v[i][j]==0 && a[i][j]==0)
            {
                int x = go(i,j);
                if(x>ma)
                {
                    ma = x;
                }
                if(x==-1)
                {
                    cout<<"Poor Inna!";
                    return 0;
                }
            }
        }

    if(ma==0)
    {
        cout<<"Poor Dima!";
        return 0;
    }


    cout<<ma;

    return 0;
}
