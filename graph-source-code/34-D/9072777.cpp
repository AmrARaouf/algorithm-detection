//Language: GNU C++


#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
#define inf 10000000
#define PI acos(-1.0)
#define eps 1e-8
#define seed 131
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=50005;
int n,r1,r2;
int main()
{
    scanf("%d%d%d",&n,&r1,&r2);
    int p[maxn];
    memset(p,0,sizeof(p));
    int a;
    for(int i=1;i<=n;i++)
    {
        if(i==r1)
            i++;
        scanf("%d",&a);
        p[i]=a;
    }
    int m[maxn];
    memset(m,0,sizeof(m));
    m[r2]=-1;
    int u=r2;
    int tmp;
    while(1)
    {
        tmp=u;
        u=p[u];
        if(u==0)
        {
            //m[r1]=tmp;
            break;
        }
        m[u]=tmp;
    }
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(m[i]==-1)
            continue;
        if(m[i]==0)
        {
            if(flag)
            {
                printf("%d",p[i]);
                flag=false;
            }
            else
                printf(" %d",p[i]);
        }
        else
        {
            if(flag)
            {
                printf("%d",m[i]);
                flag=false;
            }
            else
                printf(" %d",m[i]);
        }
    }
    cout<<endl;
    return 0;
}





















		 				 						        		 				 	