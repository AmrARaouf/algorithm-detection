//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

int N,M;
int mp[1024][1024],tmp[1024][1024],g[1024][1024];
int minL,sx,sy;

bool Link(int x1,int y1,int x2,int y2)
{
    if(x1==x2)
    {
        if(y1>y2) swap(y1,y2);
        for(int i=y1;i<=y2;i++) if(!mp[x1][i]) return false;
        return true;
    }
    if(y1==y2)
    {
        if(x1>x2) swap(x1,x2);
        for(int i=x1;i<=x2;i++) if(!mp[i][y1]) return false;
        return true;
    }
    return false;
}

void Draw(int x1,int y1,int x2,int y2)
{
    if(x1==x2)
    {
        if(y1>y2) swap(y1,y2);
        for(int i=y1;i<=y2;i++) g[x1][i]=1;
    }
    if(y1==y2)
    {
        if(x1>x2) swap(x1,x2);
        for(int i=x1;i<=x2;i++) g[i][y1]=1;
    }
}

int ax[4]={1,-1,0,0};
int ay[4]={0,0,1,-1};

bool  inrange(int x,int y)
{
    return x>=0&&y>=0&&x<N&&y<M;
}

void dfs(int x,int y,int L)
{
    if(tmp[x][y]) return;
    tmp[x][y]=1;
    for(int k=0;k<4;k++)
    {
        int xx=x+ax[k]*L;
        int yy=y+ay[k]*L;
        if(inrange(xx,yy)&&Link(x,y,xx,yy))
        {
            dfs(xx,yy,L);
        }
    }
}

bool solve(int L)
{
    memset(tmp,0,sizeof(tmp));
    memset(g,0,sizeof(g));
    dfs(sx,sy,L);
    for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
    {
        if(tmp[i][j])
        {
            tmp[i][j]=0;
            for(int k=0;k<4;k++)
            {
                int xx=i+ax[k]*L;
                int yy=j+ay[k]*L;
                if(inrange(xx,yy)&&Link(i,j,xx,yy))
                {
                    Draw(i,j,xx,yy);
                    tmp[i][j]++;
                }
            }

        }
    }
    int sum=0,ji=0;
    for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
    {
        if(g[i][j]!=mp[i][j]) return false;
        if(tmp[i][j]%2==1) ji++;
    }
    if(ji==2||ji==0) return true;
    return false;

}

int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            scanf("%d",&mp[i][j]);
        }
        memset(g,0,sizeof(g));

        minL=100000;
        for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(minL<10000) break;
            if(mp[i][j])
            {
                sx=i;sy=j;
                minL=0;
                for(int k=1;k<N;k++)
                {
                    if(j+k>=M||mp[i][j+k]==0) break;
                    minL++;
                }
                
                if(minL==0)
                {
                    for(int k=1;k<N;k++)
                    {
                        if(j+k>=N||mp[i+k][j]==0) break;
                        minL++;
                    }
                }
                
            }
        }
        //cout<<minL<<endl;
        if(minL>10000)
        {
            printf("-1\n");continue;
        }

        vector<int> ans;
        for(int L=2;L<=minL;L++)
        {
            if(minL%L==0)
            {
                if(solve(L)) ans.push_back(L);
            }
        }
        if(ans.size()==0) {printf("-1\n");continue;}
        for(int i=0;i<ans.size();i++)
        {
            if(i) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");

    }
    return 0;
}
