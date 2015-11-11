//Language: GNU C++


//Bismillahir Rahmanir Raheem

#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<string.h>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<stdlib.h>
#include<string>
#include<set>
#include<iomanip>
#define rep(i,n) for(i=1;i<=n;i++)
#define FOR(i,n) for(i=0;i<n;i++)
#define si(i) scanf("%d",&i)
#define sii(i,j) scanf("%d %d",&i,&j)
#define siii(i,j,k) scanf("%d %d %d",&i,&j,&k)
#define INF 1e9
#define lld long long int
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("output.txt","w",stdout);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ui unsigned int
#define came "came"
#define pii pair<long long int,int>
#define ninf (-1e9)-2
#define inf (1e9)+2
using namespace std;

struct data
{
    int x,y;
    int col;
    data(){}
    data(int a, int b, int c)
    {
        x=a,y=b,col=c;
    }
    void set(int a, int b, int c)
    {
        x=a,y=b,col=c;
    }
}a[100005];

vector<int> ans;

int id[1005];

int parent(int x)
{
    if(id[x]==x) return x;
    else
    {
        return id[x]=parent(id[x]);
    }
}

bool unit(int x, int y)
{
    x=parent(x),y=parent(y);
    if(x==y)
    {
        return false;
    }
    id[x]=y;
    return true;
}



int main()
{
    //FRO
    int n,m;
    scanf("%d %d",&n,&m);
    if((n-1)%2!=0)
    {
        printf("-1\n");
        return 0;
    }
    int i,j;
    for(i=1;i<=n;i++) id[i]=i;
    int x,y;
    char col[15];
    for(i=0;i<m;i++)
    {
        scanf("%d %d %s",&x,&y,col);
        a[i].set(x,y,col[0]=='S');
    }
    int p;
    for(i=0;i<m;i++)
    {
        if(a[i].col==0)
        {
            if(unit(a[i].x,a[i].y)) p++;
        }
    }
    int l=(n-1)/2,tot=0;
    if(p<l)
    {
        printf("-1\n");
        return 0;
    }
    int w=l;
    tot=p;
    for(i=0;i<m;i++)
    {
        if(a[i].col==1)
        {
            if(unit(a[i].x,a[i].y))
            {
                ans.push_back(i);
                tot++;
                w--;
            }
        }
    }
    if(tot<n-1)
    {
        printf("-1\n");
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        id[i]=i;
    }
    int sz=ans.size();
    for(i=0;i<sz;i++)
    {
        unit(a[ans[i]].x,a[ans[i]].y);
    }
    for(i=0;i<m && w;i++)
    {
        if(a[i].col==1)
        {
            if(unit(a[i].x,a[i].y))
            {
                ans.push_back(i);
                w--;
            }
        }
    }
    if(w)
    {
        printf("-1\n");
    }
    else
    {
        w=l;
        for(i=0;w && i<m;i++)
        {
            if(a[i].col==0)
            {
                if(unit(a[i].x,a[i].y))
                {
                    ans.push_back(i);
                    w--;
                }
            }
        }
        sz=ans.size();
        cout<<sz<<endl;
        for(i=0;i<sz;i++)
        {
            printf("%d ",ans[i]+1);
        }
        printf("\n");
    }
    return 0;
}
