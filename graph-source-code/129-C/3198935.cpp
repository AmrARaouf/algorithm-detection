//Language: GNU C++


#include<cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 100000000
#define MAX 1000000
#define MAXN 1000000
int map[10][10];
int vis[10][10];
int sx,sy,ex,ey;
int t;

struct P
{
    int x,y,t;
}q[MAX];

int inmap(int x,int y)
{
    return x>=1&&y>=1&&x<=8&&y<=8;
}

int dirx[9]={0,0,0,1,-1,1,-1,1,-1};
int diry[9]={0,1,-1,0,0,1,-1,-1,1};
int main()
{
   //freopen("C:\in.txt","r",stdin);
   int flag=0,win=0;
   memset(map,0,sizeof(map));

    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
        {
            char c;
            cin>>c;
            if(c=='M')
                sx=i,sy=j;
            if(c=='A')
                ex=i;ey=j;
            if(c=='S')
                map[i][j]=1;
        }
        int l,r;
        l=r=0;
        P tmp;
        tmp.x=sx;
        tmp.y=sy;
        tmp.t=0;
        q[r++]=tmp;
        for(int i=1;i<=30;i++)
        {
            if(i>9&&l<r)
            {
               win=1;
               break;
            }
            memset(vis,0,sizeof(vis));
            while(l<r)
            {
                if(q[l].t==i)
                    break;
                P u=q[l++];
                if(!map[u.x][u.y])
                for(int k=0;k<=8;k++)
                {
                    int nx=u.x+dirx[k];
                    int ny=u.y+diry[k];
                    if(inmap(nx,ny)&&!vis[nx][ny]&&!map[nx][ny])
                    {
                        if(nx==ex&&ny==ey)
                            {win=1;
                            }
                        vis[nx][ny]=1;
                        tmp.x=nx;
                        tmp.y=ny;
                        tmp.t=i;
                        q[r++]=tmp;
                    }
                }
                if(win)
                    break;
            }
            //-----rebuild----
            for(int k=8;k>=1;k--)
            for(int j=1;j<=8;j++)
               map[k][j]=map[k-1][j];
            if(win)
              break;
        }
        if(win)
            cout<<"WIN"<<endl;
        else
            cout<<"LOSE"<<endl;


    return 0;
}

 						  							 							  	