//Language: GNU C++


#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#include<queue>
#define PB push_back
#define MP make_pair
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef map<int,int> MII;
const int DX[8]={1,-1,0,0,1,1,-1,-1};
const int DY[8]={0,0,1,-1,1,-1,1,-1};
const int intmax=0x7fffffff;
int mp[105][105],n,m,nk;
int d[105][105][1<<7];
PII fa1[105][105][1<<7],fa2[105][105][1<<7];
char f[105][105];
struct node
{
    int dis,x,y;
    node(int a,int b,int c):x(a),y(b),dis(c){}
    bool operator <(const node &a) const
    {
        return dis>a.dis;
    }
};
priority_queue<node> qu;
inline int pow2(int n)
{
    return 1<<n;
}
inline int get2(int n,int p)
{
    return (1<<p)&n;
}
void print(int x,int y,int k)
{
    f[x][y]='X';
    if (fa1[x][y][k].first==-1)
        if (fa2[x][y][k].second==-1) return;
        else
        {
            print(x,y,fa2[x][y][k].first);
            print(x,y,fa2[x][y][k].second);
        }
    else print(fa1[x][y][k].first,fa1[x][y][k].second,k);
}
int main()
{
    scanf("%d%d%d",&n,&m,&nk);
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        scanf("%d",&mp[i][j]);
    memset(d,0x3f,sizeof(d));
    for(int i=0;i<nk;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        d[a-1][b-1][pow2(i)]=mp[a-1][b-1];
        fa1[a-1][b-1][pow2(i)]=MP(-1,-1);
        fa2[a-1][b-1][pow2(i)]=MP(-1,-1);
    }
    for(int i=1;i<pow2(nk);i++)
    {
        for(int j=0;j<n;j++)
        for(int k=0;k<m;k++)
        for(int l=(i-1)&i;l;l=(l-1)&i)
        {
            d[j][k][i]=min(d[j][k][i],d[j][k][l^i]+d[j][k][l]-mp[j][k]);
            if (d[j][k][i]==d[j][k][l^i]+d[j][k][l]-mp[j][k])
            {
                fa1[j][k][i]=MP(-1,-1);
                fa2[j][k][i]=MP(l^i,l);
            }
        }
        while(!qu.empty()) qu.pop();
        for(int j=0;j<n;j++)
        for(int k=0;k<m;k++)
            qu.push(node(j,k,d[j][k][i]));
        while(!qu.empty())
        {
            node tmp=qu.top();
            qu.pop();
            int dis=tmp.dis;
            int x=tmp.x;
            int y=tmp.y;
            if (dis>d[x][y][i]) continue;
            for(int di=0;di<4;di++)
            {
                int nx=x+DX[di];
                int ny=y+DY[di];
                if (nx<n&&nx>=0&&ny<m&&ny>=0)
                {
                    if (dis+mp[nx][ny]<d[nx][ny][i])
                    {
                        d[nx][ny][i]=dis+mp[nx][ny];
                        fa1[nx][ny][i]=MP(x,y);
                        fa2[nx][ny][i]=MP(-1,-1);
                        qu.push(node(nx,ny,d[nx][ny][i]));
                    }
                }
            }
        }
    }
    int ans=intmax;
    int ansx,ansy;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        ans=min(ans,d[i][j][pow2(nk)-1]),f[i][j]='.';
        if (ans==d[i][j][pow2(nk)-1]) ansx=i,ansy=j;
    }
    printf("%d\n",ans);
    print(ansx,ansy,pow2(nk)-1);
    for(int i=0;i<n;i++) puts(f[i]);
}
