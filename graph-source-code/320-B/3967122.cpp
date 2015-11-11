//Language: GNU C++


#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<limits.h>
#include<set>

using namespace std;

#define maxn 100010
#define mod 1000000000
#define pi acos(-1.0)
#define inf INT_MAX
#define lc n<<1
#define rc n<<1|1

typedef long long ll;

struct line
{
    int x;
    int y;
}a[1010];

int vis[1010];
int cnt;
int v=0;

void dfs(int k)
{
    vis[k]=v;
    for(int i=1;i<=cnt;i++)
    {
        if(vis[i]!=v&&(a[k].x>a[i].x&&a[k].x<a[i].y||a[k].y>a[i].x&&a[k].y<a[i].y))
            dfs(i);
    }
}

int main()
{
    int n,t,s,e;
    scanf("%d",&n);

    cnt=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(t==1)
        {
            cnt++;
            scanf("%d%d",&a[cnt].x,&a[cnt].y);
        }
        else
        {
            scanf("%d%d",&s,&e);
            v++;
            dfs(s);
            if(vis[e]==v)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}