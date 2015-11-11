//Language: GNU C++


#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<map>
#include<cstdlib>
#include<cmath>
#include<vector>
#define LL long long
#define IT __int64
#define zero(x) fabs(x)<eps
#define mm(a,b) memset(a,b,sizeof(a))
const int INF=0x7fffffff;
const double inf=1e8;
const double eps=1e-10;
const double PI=acos(-1.0);
const int MAXN=60;
using namespace std;
int n, m, ps, move[4][2]= {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool isPaint[MAXN][MAXN], isVis[MAXN][MAXN];
void input()
{
    cin>>n>>m;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
        {
            char c;
            cin>>c;
            if (c=='#')
            {
                isPaint[i][j]=true;
                ps++;
            }
        }
}
bool isValid(int x, int y)
{
    return 0<=x&&x<n&&0<=y&&y<m;
}
void dfs(int x, int y)
{
    isVis[x][y]=true;
    for (int i=0; i<4; ++i)
    {
        int p=x+move[i][0], q=y+move[i][1];
        if (isValid(p, q) && isPaint[p][q] && !isVis[p][q])
            dfs(p, q);
    }
}
bool isConnect()
{
    int x, y;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (isPaint[i][j])
            {
                x=i;
                y=j;
            }
    memset(isVis, false, sizeof(isVis));
    dfs(x, y);
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (isPaint[i][j] && !isVis[i][j])
                return false;
    return true;
}
int main()
{
    input();
    if (ps==1 || ps==2)
    {
        cout<<-1<<endl;
        return 0;
    }
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (isPaint[i][j])
            {
                isPaint[i][j]=false;
                if (!isConnect())
                {
                    cout<<1<<endl;
                    return 0;
                }
                isPaint[i][j]=true;
            }
    cout<<2<<endl;
    return 0;
}

		 			   	  	 		 		 				