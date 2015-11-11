//Language: GNU C++


#include <cstdio>

#define N 100000
#define mod 1000000007

using namespace std;

long long f[N+10][2];
int n,x,mm,head[N+10],c[N+10];
struct node
{
    int u,v,next ;
}p[N+10];
void add(int x,int y)
{
    p[mm].v = y ;
    p[mm].next = head[x] ;
    head[x] = mm++ ;
}

void dfs(int x)
{
    f[x][c[x]]=1;
    for (int i=head[x]; i; i=p[i].next)
    {
        int y=p[i].v;
        dfs(y);
        f[x][1]=(f[x][1]*f[y][0]%mod+f[x][1]*f[y][1]%mod+f[x][0]*f[y][1]%mod)%mod;
        f[x][0]=(f[x][0]*f[y][0]%mod+f[x][0]*f[y][1]%mod)%mod;
    }
}

int main()
{
    scanf("%d",&n);
    mm = 1 ;
    for (int i=2; i<=n; ++i) scanf("%d",&x),add(++x,i);
    for (int i=1; i<=n; ++i) scanf("%d",&c[i]);
    dfs(1);
    printf("%I64d\n",f[1][1]);
    return 0;
}