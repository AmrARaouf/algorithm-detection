//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
#define INF 100000000


int x,a[3005],mark[3005],i,k,n,aa,bb;
stack< int >vv;
vector< int >v[3005];
queue< int >q;

void dfs(stack< int >vv , int x ,int parent)
{
   for(int i=0;i<v[x].size();i++)
   {
      if(!mark[v[x][i]])
      {
         vv.push(v[x][i]);
         mark[v[x][i]]=1;
         dfs(vv,v[x][i],x);
         vv.pop();
         mark[v[x][i]]=0;
      }
      else 
      {
         if(v[x][i]!=parent&&(q.empty()))
         {
            while(!vv.empty())
            {
              k=vv.top();
              a[k]=0;
              q.push(k);
              if(k==v[x][i])
               break;
               vv.pop();
               
            }
         break;
         }
      
      }
   
   }


}

void bfs()
{
  
 while(!q.empty())
 {
    x=q.front();
    q.pop();
    for(int i=0;i<v[x].size();i++)
    {
       if(a[v[x][i]]>a[x]+1)
       {
         a[v[x][i]]=a[x]+1;
         q.push(v[x][i]);
       }
    }
    
  } 

}



int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
	  cin>>aa>>bb;
	  v[aa].push_back(bb);
	  v[bb].push_back(aa);
	  mark[i]=0;
	  a[i]=INF;
	}
	vv.push(1);
	dfs(vv,1,-1);
	bfs();
	for(i=1;i<=n;i++)
	{
	cout<<a[i]<<" ";
	}
	return 0;
}