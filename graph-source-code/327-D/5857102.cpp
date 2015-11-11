//Language: GNU C++


#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

// Define Some Variables
#define eps 1e-14
#define si 110
#define pi acos(-1.0)
#define inf (1<<30)-1
#define mod 1000000000 //10^9

//Define Some Functions
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define max(a,b) (a>b ?a:b)
#define min(a,b) (a<b ?a:b)
#define sqr(a)((a)*(a))
#define area(x1,y1,x2,y2,x3,y3) (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) //Area of a triangle
#define dist(x1,y1,x2,y2) (sqr(x1-x2)+sqr(y1-y2)) //Distance between two points
#define mem(a,v) memset(a,v,sizeof(a))
inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }
#define fr(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)

typedef __int64 i64;
//typedef long long i64;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int i,j,l,n,cs=1,cnt,sm,fg,m,ans;
char ch[510][510],st[6000010][10];

i64 bmod(i64 a,i64 b)
{
    if(b==0)
        return 1;
    i64 x=bmod(a,b/2);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}

int gcd(int a,int b)
{
    while(b>0)
    {
        a%=b;
        a^=b;
        b^=a;
        a^=b;
    }
    return a;
}

i64 lcm(i64 a,i64 b)
{
    return ((a*b)/gcd(a,b));
}

/*
int ara[si],cnt_p=1,pr[si];

void sieve()
{
    int num=si-5,i,j,root;
    root=sqrt(num);
    pr[cnt_p++]=2;
    ara[1]=1;
    for(i=3;i<=num;i=i+2)
    {
        if(ara[i]==0)
        {
            pr[cnt_p++]=i;
            if(i<=root)
            {
                for(j=i*i;j<=num;j+=2*i)
                    ara[j]=1;
            }
        }
    }
}
*/

void dfs(int x,int y)
{
    if(x>=n||y>=m||x<0||y<0)
    return ;

    if(ch[x][y]=='#')
    return ;

    ch[x][y]='#';
    sprintf(st[ans++],"B %d %d",x+1,y+1);
    int k;
    rep(k,0,4)
    {
        int xx=dx[k]+x;
        int yy=dy[k]+y;
        dfs(xx,yy);
    }
    if(x!=i||y!=j)
    {
        sprintf(st[ans++],"D %d %d",x+1,y+1);
        sprintf(st[ans++],"R %d %d",x+1,y+1);
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    while(~scanf("%d%d",&n,&m))
    {
        sm=cnt=0;
        fg=1;
        rep(i,0,n)
        scanf("%s",ch[i]);

        ans=0;
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                if(ch[i][j]=='.')
                dfs(i,j);
            }
        }
        printf("%d\n",ans);
        rep(i,0,ans)
        puts(st[i]);
    }
    return 0;
}
