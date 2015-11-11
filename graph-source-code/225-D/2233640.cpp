//Language: GNU C++


#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define LL long long
#define inf (1<<31)-1
#define PI 3.141592653
#define mod 1000000007
#define N 20
#define M 20
#define pb(a) push_back(a);
#define em empty
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
struct node
{
   int x[9],y[9];
   int step;       
};
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
char G[N][M];
int d[N][M];
set<int> st; 
int len,n,m;
queue<node> q;
int hash(node a)  
{  
    int ret=0;  
    for(int i=0;i<len;i++) ret=ret*131+a.x[i];  
    for(int i=0;i<len;i++) ret=ret*131+a.y[i];  
    return ret;  
} 
int bfs()
{
     int pos=0;
     while(!q.em())
     {
         node cur=q.front(),tmp;
         pos++;
         int nx,ny;
         for(int i=0;i<len-1;i++) d[cur.x[i]][cur.y[i]]=pos;
         for(int j,i=0;i<4;i++)
         {
            nx=cur.x[0]+dir[i][0];
            ny=cur.y[0]+dir[i][1];
            if(!(nx>=0&&nx<n&&ny>=0&&ny<m)||G[nx][ny]=='#') continue;
            if(d[nx][ny]==pos) continue; 
            if(G[nx][ny]=='@') return cur.step+1;
            tmp.x[0]=nx,tmp.y[0]=ny;
            tmp.step=cur.step+1;
            for(int i=0;i<len-1;i++)
               tmp.x[i+1]=cur.x[i],tmp.y[i+1]=cur.y[i];
            int hs=hash(tmp);
            if(st.count(hs)) continue;
            st.insert(hs);
            q.push(tmp);
         }
         q.pop();
     }    
     return -1;
}
int main()
{

     while(~scanf("%d%d",&n,&m))
     {
         node tmp;
         len=0; 
         for(int i=0;i<n;i++)
            scanf("%s",G[i]);
         for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
           {
              char t=G[i][j];
              if(t<='9'&&t>='1')
              {
                  tmp.x[t-'1']=i;
                  tmp.y[t-'1']=j;
                  len=max(len,t-'0');                                 
              }               
           }      
         tmp.step=0;
         q.push(tmp);
         st.insert(hash(tmp));
         int ans=bfs();
         printf("%d\n",ans);
     }     
}
