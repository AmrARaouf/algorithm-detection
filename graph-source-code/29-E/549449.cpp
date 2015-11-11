//Language: GNU C++


#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

struct data
{
       int k1;
       int k2;
       int fa;
};

int n,m;
data q[800500];
vector<int> adj[600];
bool vis[800500];
int nd1[30050],nd2[30050];

int main()
{
    for(int i=1;i<=n;i++)
       adj[i].clear();
    memset(vis,false,sizeof(vis));
       
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        
        adj[s].push_back(t);
        adj[t].push_back(s);
    }
    
    int a=0,b=1;
    q[a].k1=1;
    q[a].k2=n;
    q[a].fa=-1;
    vis[1*600+n]=true;
    
    bool fd=false;
    int num;
    while(a<b)
    {
        int k1=q[a].k1,k2=q[a].k2;
        for(int i=0;i<adj[k1].size();i++)
        {
             int next1=adj[k1][i];
             for(int j=0;j<adj[k2].size();j++)
             {
                int next2=adj[k2][j];
                if(next2==next1||vis[next1*600+next2]) continue;
                
                vis[next1*600+next2]=true;
                q[b].k1=next1;
                q[b].k2=next2;
                q[b].fa=a;
                
                if(next1==n&&next2==1)
                {
                   fd=true;
                   int it=b;
                   num=0;
                   while(it!=-1)
                   {
                      nd1[num]=q[it].k1;
                      nd2[num]=q[it].k2;
                      num++;
                      it=q[it].fa;
                   }
                   break;
                }
                b++;
             }
             if(fd) break;
        }
        if(fd) break;
        a++;
    }
    
    if(!fd) {printf("-1\n");}
    else
    {
        printf("%d\n",num-1);
        for(int i=num-1;i>0;i--)
           printf("%d ",nd1[i]);
        printf("%d\n",nd1[0]);
        for(int i=num-1;i>0;i--)
           printf("%d ",nd2[i]);
        printf("%d\n",nd2[0]);
    }
   // system("PAUSE");
}

  			  	   	    	    				