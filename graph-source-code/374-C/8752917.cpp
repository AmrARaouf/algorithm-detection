//Language: GNU C++


//In the name of God

#include <iostream>
#include <vector>
using namespace std;
const int MAXN=1010;
char c[MAXN][MAXN];
bool mark[MAXN][MAXN],loop;
int dp[MAXN][MAXN],n,m,move[4][2];
void dfs(int x,int y)
{
  if(dp[x][y]!=0 || mark[x][y])
    return;
  //cout<<x<<" "<<y<<endl;
  mark[x][y]=true;
  char ch=c[x][y],nc;
  if(ch=='D')
    nc='I';
  else if(ch=='I')
    nc='M';
  else if(ch=='M')
    nc='A';
  else
    nc='D';
  int ans=1;
  for(int i=0;i<4;i++)
    {
      int x2=x+move[i][0],y2=y+move[i][1];
      if(x2<n && y2<m && c[x2][y2]==nc)
	{
	  if(mark[x2][y2])
	    loop=true;
	  dfs(x2,y2);
	  ans=max(ans,dp[x2][y2]+1);
	}
    }
  dp[x][y]=ans;
  mark[x][y]=false;
}

int main()
{
  move[0][0]=1;
  move[1][0]=-1;
  move[2][1]=1;
  move[3][1]=-1;
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>c[i][j];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      dfs(i,j);
  if(loop)
    cout<<"Poor Inna!"<<endl;
  else
    {
      int ans=0;
      for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	  {
	    if(c[i][j]=='D')
	      ans=max(ans,dp[i][j]/4);
	    // cout<<i<<" "<<j<<":"<<dp[i][j]<<endl;
	  }
      if(ans==0)
	cout<<"Poor Dima!"<<endl;
      else
	cout<<ans<<endl;
    }
  return 0;
}
