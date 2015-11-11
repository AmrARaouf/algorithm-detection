//Language: GNU C++


#include <algorithm>
#include <stdio.h>
using    namespace std;

bool ans;
char s[12][12];
bool mark[70][12][12];
bool forb[70][12][12];
int dir[9][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

bool dfs(int k , int r , int c)
{
  if(r==1 && c==8)  return true;
  mark[k][r][c]=true;
  for(int i=0 ; i<9 ; i++)
  {
    int rr=r+dir[i][0];
    int cc=c+dir[i][1];
    if(rr<1 || rr>8 || cc<1 || cc>8) continue;
    if(mark[k+1][rr][cc])            continue;
    if(forb[k][rr][cc])              continue;
    if(forb[k+1][rr][cc])            continue;
    if(dfs(k+1,rr,cc))               return true;
  }
  return false;
}

int main()
{
  for(int i=1 ; i<=8 ; i++)
    scanf("%s",s[i]+1);
  for(int i=1 ; i<=8 ; i++)
    for(int j=1 ; j<=8 ; j++)
      if(s[i][j]=='S')
        for(int k=i ; k<=8 ; k++)
          forb[k-i][k][j]=true;
  ans=dfs(0,8,1);
  if(ans)   printf("WIN\n");
  else      printf("LOSE\n");
  return 0;
}
