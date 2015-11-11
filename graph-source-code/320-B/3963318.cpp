//Language: GNU C++


#include<stdio.h>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

#define mod 1000000007

    int n,j,f,top=1;
    int v,x,y;
    int a[105][2];
    int mat[105][105];
    int m=0;
    int visited[1004]={0};
int ret=0;


int dfs(int st,int fi)
{
    //cout<<st<<" ";
    int i;
if(st==fi)
{ret=1;}
visited[st]=1;

    for(i=1;i<top;i++)
    {
        if(ret==1){break;}
        if((((a[i][0]<a[st][0]&&a[st][0]<a[i][1]) || (a[i][0]<a[st][1]&&a[st][1]<a[i][1]) ))&&visited[i]!=1)
        dfs(i,fi);
    }

    return ret;
}



int main()
{int i;

    cin>>n;
for(j=0;j<n;j++)
{int v2;
   cin>>v2>>x>>y;
   if(v2==1)
   {
       a[top][0]=x;a[top][1]=y;top++;


     m++;
   }
   else
   {

  int vc;
  for(i=0;i<1004;i++)
  {visited[i]=0;}
  ret=0;
  if(dfs(x,y))
     cout<<"YES\n";
  else
    cout<<"NO\n";

   }
}
return 0;
}
