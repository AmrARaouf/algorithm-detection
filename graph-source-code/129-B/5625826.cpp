//Language: GNU C++


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
#define MAX 110
int map[MAX][MAX];
int cnt[MAX];
int vis[MAX];
int main()
{
    int n,m;
    while (cin>>n>>m)
    {
        int i,j,sum=0,u,v,flag=1;
        queue<int>Q;
        memset(map,0,sizeof(map));
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        for (i=0;i<m;i++)
        {
            cin>>u>>v;
            map[u][v]=map[v][u]=1;
            cnt[u]++;
            cnt[v]++;
        }
        while (flag)
        {
            flag=0;
            for (i=1;i<=n;i++)
            {
                if (!vis[i]&&cnt[i]==1)
                {
                    flag=1;
                    vis[i]=1;
                    Q.push(i);
                }
            }
//            for (i=1;i<=n;i++)
//            {
//                cout<<cnt[i]<<endl;
//            }
            while (!Q.empty())
            {
                int u=Q.front();
                Q.pop();
                for (i=1;i<=n;i++)
                {
                    if (map[u][i]&&!vis[i])
                    {
                        map[i][u]=map[u][i]=0;
                        cnt[i]--;
                    }
                }
            }
            if (flag)
            sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}

 		 		 		 	 	    	   		 	