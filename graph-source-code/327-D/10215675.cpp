//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<set>
using namespace std;
#define REPF( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define REP( i , n ) for ( int i = 0 ; i < n ; ++ i )
#define CLEAR( a , x ) memset ( a , x , sizeof a )
typedef long long LL;
typedef pair<int,int>pil;
const int INF=0x3f3f3f3f;
struct node
{
    char c;
    int y,x;
}step[1000005];
int n,m,num;
char s[505][505];
bool used[505][505];
void doit(char c,int y,int x)
{
        s[y][x]=c;
        num++;
        step[num].c=c,step[num].y=y,step[num].x=x;
        return;
}
void dfs(int y,int x)
{
        if (s[y][x]!='B' || used[y][x]) return;
        used[y][x]=true;
        if (x>1) dfs(y,x-1);
        if (y>1) dfs(y-1,x);
        if (x<m) dfs(y,x+1);
        if (y<n) dfs(y+1,x);
        doit('D',y,x),doit('R',y,x);
        return;
}
int main()
{
        int i,j,t,x,sum;
        bool f;
        while (~scanf("%d%d",&n,&m))
        {
                for (i=1;i<=n;i++) scanf("%s",s[i]+1);
                num=0;
                for (i=1;i<=n;i++)
                  for (j=1;j<=m;j++)
                    if (s[i][j]=='.') doit('B',i,j);
                sum=0;
                memset(used,false,sizeof(used));
                for (i=1;i<=n;i++)
                   for (j=1;j<=m;j++)
                     if (s[i][j]=='B')
                     {
                            used[i][j]=true;
                            if (j>1) dfs(i,j-1);
                            if (i>1) dfs(i-1,j);
                            if (j<m) dfs(i,j+1);
                            if (i<n) dfs(i+1,j);
                     }
                printf("%d\n",num);
                for (i=1;i<=num;i++) printf("%c %d %d\n",step[i].c,step[i].y,step[i].x);
        }
        return 0;
}
