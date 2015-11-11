//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<list>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define LL long long
#define maxn 1000005
#define mod 1000000007
int a[305]={0};
int mp[305][305];
vector<int>g;
int main()
{
    memset(mp,0,sizeof(mp));
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        int idx;
        scanf("%d",&idx);
        a[idx]=1;
    }
    if(k==n)    printf("-1\n");
    else if(m>n*(n-1)/2-k+1)   printf("-1\n");
    else
    {
        int idx=-1;
        vector<int>now;
        for(int i=1;i<=n;i++)
        {
            if(!a[i]&&idx==-1)   idx=i;
            else if(a[i]&&now.size()<2)   now.push_back(i);
            else g.push_back(i);
        }
        for(int i=1;i<g.size();i++)
        {
            mp[g[i-1]][g[i]]=1;
            m--;
        }
        if(now[0]<idx)  mp[now[0]][idx]=1;
        else mp[idx][now[0]]=1;
        if(now[1]>idx) mp[idx][now[1]]=1;
        else mp[now[1]][idx]=1;
        m-=2;
        if(g.size()>0){
        m--;
        if(now[0]>g[0]) mp[g[0]][now[0]]=1;
        else mp[now[0]][g[0]]=1;}
        for(int i=1;i<=n;i++)
        {
            if(m==0)    break;
            for(int j=i+1;j<=n;j++)
            {
                if(mp[i][j])    continue;
                if(i==now[0]&&j==now[1])    continue;
                if(i==now[0]&&a[j])
                {
                    if(mp[j][now[1]]||mp[now[1]][j])    continue;
                }
                if(i==now[1]&&a[j])
                {
                    if(mp[j][now[0]]||mp[now[0]][j])    continue;
                }
                if(j==now[0]&&a[i])
                {
                    if(mp[i][now[1]]||mp[now[1]][i])    continue;
                }
                if(j==now[1]&&a[i])
                {
                    if(mp[i][now[0]]||mp[now[0]][i])    continue;
                }
                mp[i][j]=1;
                m--;
                if(m==0)    break;
            }
        }
        for(int i=1;i<=n;i++)   for(int j=1;j<=n;j++)
        {
            if(mp[i][j])    printf("%d %d\n",i,j);
        }
    }
}

	       		    		 	 	 		 	 		  	