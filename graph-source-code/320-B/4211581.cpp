//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int m,x,y,vis[110],map[110][110]={0};
struct Iterval
{
    int st,ed;
}iter[110];
int Judge(int &a,int &b)
{
    if(iter[b].st < iter[a].st && iter[a].st < iter[b].ed) return 1;
    if(iter[b].st < iter[a].ed && iter[a].ed < iter[b].ed) return 1;
    return 0;
}
void creat(int &k)
{
    for(int i=k-1;i>0;i--)
    {
        if(Judge(k,i)) map[k][i] = 1;
        if(Judge(i,k)) map[i][k] = 1;
    }
}
int solve(int st,int ed)
{
    if(st == ed) return 1;
    vis[st] = 1;
    for(int i=1;i<=m;i++)
    {
        if(map[st][i] == 1 && vis[i] == 0)
        {
            if(solve(i,ed))return 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    m = 0;
    for(int i=0;i<n;i++)
    {
        int k,x,y;
        cin>>k>>x>>y;
        if(k == 1)
        {
            iter[++m].st = x;
            iter[m].ed = y;
            creat(m);
        }
        else
        {
            memset(vis,0,sizeof(vis));
            if(solve(x,y))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}

   		 					 	    		  	   	