//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<list>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define LL long long
#define maxn 300005
#define mod 1000000007
int d[3005][3005];
vector<int>g[3005];
vector<int>superstition[3005][3005];
int fro[3005][3005];
bool v[3005][3005]={0};
int n,m,k;
int fin=-1;
stack<int>s;
bool ok(int a,int b,int c)
{
    return binary_search(superstition[a][b].begin(),superstition[a][b].end(),c);
}
int bfs()
{
    for(int i=0;i<=n;i++)   for(int j=0;j<=n;j++)   d[i][j]=INF;
    queue<pair<int,int> >q;
    q.push(make_pair(0,1));
    d[0][1]=1;
    fro[0][1]=-1;
    int all=0;
    while(!q.empty())
    {
        int si=q.size();
        while(si--)
        {
            int nowf=q.front().first;
            int nows=q.front().second;
            v[nowf][nows]=0;
            q.pop();
            if(nows==n)
            {
                fin=nowf;
                return all;
            }
            for(int i=0;i<g[nows].size();i++)
            {
                int temp=g[nows][i];
                if(d[nows][temp]<=d[nowf][nows]+1||ok(nowf,nows,temp))  continue;
                d[nows][temp]=d[nowf][nows]+1;
                fro[nows][temp]=nowf;
                if(v[nows][temp])   continue;
                q.push(make_pair(nows,temp));
                v[nows][temp]=1;
            }
        }
        all++;
    }
    fin=-1;
    return -1;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<k;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        superstition[a][b].push_back(c);
    }
    for(int i=1;i<=n;i++)   for(int j=1;j<=n;j++)
    {
        if(i==j||superstition[i][j].size()<=1)    continue;
        sort(superstition[i][j].begin(),superstition[i][j].end());
    }
    printf("%d\n",bfs());
    int fin2=n;
    while(fin!=-1)
    {
        s.push(fin2);
        fin2=fin;
        fin=fro[fin][s.top()];
    }
    while(!s.empty())
    {
        printf("%d ",s.top());
        s.pop();
    }
    return 0;
}

   	  		 		 		     	 	   		 			