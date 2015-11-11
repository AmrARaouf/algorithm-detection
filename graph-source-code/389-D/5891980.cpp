//Language: GNU C++


/*
 *       Author:  Wine93
 * Created Time:  2014/2/4 0:18:56
 *    File Name:  0018.cpp
 */
# include<map>
# include<set>
# include<cmath>
# include<queue>
# include<stack>
# include<vector>
# include<string>
# include<cstdio>
# include<cstring>
# include<iostream>
# include<algorithm>
# include<functional>
using namespace std;

typedef pair<int,int> PII;
# define INF 1<<30
# define LL long long
# define MOD 1000000007
# define VI vector<int>
# define VLL vector<LL>

# define F first
# define S second
# define pb push_back
# define lb lower_bound
# define up upper_bound
# define lowbit(x)(x&-x)
# define lson l,m,rt<<1
# define rson m+1,r,rt<<1|1
# define clr(x) (x).clear()
# define sz(x) ((int)(x).size())
# define all(x) (x).begin(),(x).end()
# define mem(x,y) memset(x,y,sizeof(x))
# define forall(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();it++)

# define N 100
int a[N][N];
VI ans;
vector<PII> edge;

void build(int n)
{
    int i,j,u,v;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]=0;
    for(i=0;i<sz(edge);i++)
    {
        u=edge[i].F;
        v=edge[i].S;
        a[u][v]=a[v][u]=1;
    }
}

void pri(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i][j]) printf("Y");
            else printf("N");
        }
        printf("\n");
    }
}

VI getbit(int n)
{
    int pos=0; 
    clr(ans);
    while(n)
    {
        if(n&1) ans.pb(pos);
        n>>=1;
        pos++;
    }
    return ans;
}

void addedge(int u,int v)
{
    edge.pb(PII(u,v));
}

int main()
{
    //freopen("in.txt","r",stdin);
    int i,m,n,bit,uu,vv,u,v,pos;
    while(scanf("%d",&m)!=EOF)
    {
        if(m==1)
        {
            printf("2\n");
            printf("NY\n");
            printf("YN\n");
            continue;
        }
        clr(edge);
        VI ans=getbit(m);
        sort(all(ans));
        bit=ans[sz(ans)-1];
        n=bit*3+2;
        //构造最高位
        for(i=2;i<=bit;i++)
        {
            uu=(i-1)*3;
            vv=uu+1;
            u=i*3;
            v=u+1;
            addedge(uu,u);
            addedge(uu,v);
            addedge(vv,u);
            addedge(vv,v);
        }
        addedge(1,3);
        addedge(1,4);
        addedge(bit*3,2);
        addedge(bit*3+1,2);
        //构造其余位
        for(i=1;i<bit;i++)
            addedge(i*3+2,(i+1)*3+2);
        addedge(bit*3+2,2);
        for(i=0;i<sz(ans)-1;i++)
        {
            pos=ans[i];    
            if(pos==0) addedge(1,5);
            else
            {
                uu=pos*3;
                vv=uu+1;
                u=(pos+1)*3+2;
                addedge(uu,u);
                addedge(vv,u);
            }
        }
        printf("%d\n",n);
        build(n);
        pri(n);
    }
    return 0;
}

