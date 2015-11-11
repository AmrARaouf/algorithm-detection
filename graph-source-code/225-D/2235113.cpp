//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<deque>
#include<set>
#define oo 1000000000
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
//Buffer reading
int INP,AM;
#define BUFSIZE (1<<12)
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) { \
if(!*inp) { \
    if (feof(stdin)) memset(BUF, 0, sizeof BUF); else fread(BUF,1,BUFSIZE,stdin); \
    inp=BUF; \
} \
INP=*inp++; \
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) { \
AM=0;\
GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
if (INP=='-') {AM=1;GETCHAR(INP);} \
j=INP-'0'; GETCHAR(INP); \
while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
if (AM) j=-j;\
}
//End of buffer reading
                            /*                           END OF TEMPLATE                            */
// VOI 2013
// IOI 2014

int n,m,l=0;
int grid[20][20],slot[20][20];
string G[20];
vii start;
ii target;
queue<vii> pq;
queue<ii> q;
bool finish=false;
int Dist[16][16];
map<vii,int> dist;
bool pre_bfs()
{
    memset(Dist,-1,sizeof(Dist));
    Dist[start[0].first][start[0].second]=0;
    int i,j;
    q.push(start[0]);
    while(!q.empty())
    {
        ii x=q.front(); q.pop();
        int cx=x.first,cy=x.second;
        for(i=1; i<=4; i++)
        {
            int a=cx,b=cy;
            if(i==1) a++; if(i==2) b++;
            if(i==3) a--; if(i==4) b--;
            if(a>=1 && b>=1 && a<=n && b<=m && slot[a][b])
            {
                if(Dist[a][b]==-1)
                {
                    Dist[a][b]=Dist[cx][cy]+1;
                    if(ii(a,b)==target) return true;
                    q.push(ii(a,b));
                }
            }
        }
    }
    return false;
}
void bfs()
{
    int i,j;
    dist[start]=0;
    pq.push(start);
    vii t;
    t.assign(l,ii());
    bool Free[16][16];
    memset(Free,true,sizeof(Free));
    while(!pq.empty())
    {
        vii x=pq.front(); pq.pop();
        int d=dist[x];
        for(i=1; i<x.size()-1; i++) Free[x[i].first][x[i].second]=false;
        int cx=x[0].first,cy=x[0].second;
        for(i=1; i<=4; i++)
        {
            int a=cx,b=cy;
            if(i==1) a++; if(i==2) a--;
            if(i==3) b++; if(i==4) b--;
            if(a>=1 && b>=1 && a<=n && b<=m && grid[a][b] && Free[a][b])
            {
                if(target==ii(a,b))
                {
                    printf("%d",d+1);
                    return;
                }
                t[0]=ii(a,b);
                for(j=1; j<l; j++) t[j]=x[j-1];
                if(!dist.count(t))
                {
                    dist[t]=d+1;
                    pq.push(t);
                }
            }
        }
        for(i=1; i<x.size()-1; i++) Free[x[i].first][x[i].second]=true;
    }
    printf("-1");
}
int main()
{
    int i,j;
    string s;
    scanf("%d %d\n",&n,&m);
    for(i=1; i<=n; i++)
    {
        getline(cin,G[i]);
        for(j=0; j<m; j++) if(G[i][j]>='1' && G[i][j]<='9') l=max(l,G[i][j]-48);
    }
    start.assign(l,ii());
    for(i=1; i<=n; i++)
        for(j=0; j<m; j++)
        {
            if(G[i][j]=='#') slot[i][j+1]=grid[i][j+1]=0;
            else slot[i][j+1]=grid[i][j+1]=1;
            if(G[i][j]>='1' && G[i][j]<='9') start[G[i][j]-49]=ii(i,j+1);
            if(G[i][j]=='@') target=ii(i,j+1);
        }
    if(!pre_bfs())
    {
        printf("-1");
        return 0;
    }
    bfs();
    return 0;
}
