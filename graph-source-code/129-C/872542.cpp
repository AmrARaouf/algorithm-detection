//Language: GNU C++


#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<math.h>
#include<cstdlib>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<ctype.h>
#include<string>
#include<map>
#include<fstream>
#include<iomanip>
using namespace std;

#define pb push_back
#define PI acos(-1.0)
#define INT_MX 2147483647
#define INT_MN -2147483647
#define SIZE 100000
#define i64 long long
#define dle double
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define sq(a) a*a
#define eps 0.00000000001
#define mems(x) memset(x,0,sizeof(x))

int xx[]={0,0,0,1,-1,1,-1,1,-1};
int yy[]={0,1,-1,0,0,1,-1,-1,1};

typedef queue<int>qi;

qi q1,q2,q3;
char str[9][9];
bool S[15][15][15];

bool bfs()
{
  int i,j,a,b,c,d,s,cnt=0;
  q1.push(7),q2.push(0);q3.push(0);

  while(!q1.empty()){
   a=q1.front();b=q2.front();s=q3.front();
   q1.pop();q2.pop();q3.pop();
   if(s>=9||(a==0&&b==7))
    return 1;
 
   rep(i,0,8)
   {
     c=a+xx[i],d=b+yy[i];
     if(c<0||d<0||c>7||d>7||S[c][d][s]||S[c][d][s+1]) continue;
     q1.push(c),q2.push(d),q3.push(s+1); 
   }
}
   return 0;
}
int main()
{
    int kase,i,j,a,b;
     
    rep(i,0,7)
    {
      gets(str[i]);
      rep(j,0,7)
       if(str[i][j]=='S')
       {
         S[i][j][0]=1;a=i;b=1;
         while(1)
         {
           if(a+1>7)
            break;
           S[a+1][j][b]=1;
           b++;a++;
         }
       }
    }
    if(bfs())
     printf("WIN\n");
    else
     printf("LOSE\n");
     while(!q1.empty())
      q1.pop(),q2.pop(),q3.pop();
    return 0;
}
