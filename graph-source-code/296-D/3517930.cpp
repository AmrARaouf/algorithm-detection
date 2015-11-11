//Language: GNU C++


#include<stdio.h>
#include<iostream>
#define ll long long
#define M  508
using namespace std;
ll dis[M][M];
ll num[M];
ll ans[M];
int main()
{
    ll n;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while(~scanf("%I64d",&n))
    {
        for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)scanf("%I64d",&dis[i][j]);
        for(ll i=n;i>0;i--)scanf("%I64d",&num[i]);
        ans[1]=0;
        for(ll i=2;i<=n;i++)
        {
            ll p=num[i];
            for(ll j=1;j<i;j++)
            {
                ll t1=num[j];
                for(ll k=1;k<i;k++)
                {
                    ll t2=num[k];
                    if(dis[t2][p]>dis[t2][t1]+dis[t1][p]) dis[t2][p]=dis[t2][t1]+dis[t1][p];
                }
            }
            for(ll j=1;j<i;j++)
            {
                ll t1=num[j];
                for(ll k=1;k<i;k++)
                {
                    ll t2=num[k];
                    if(dis[p][t2]>dis[p][t1]+dis[t1][t2]) dis[p][t2]=dis[p][t1]+dis[t1][t2];
                }
            }
            for(ll j=1;j<i;j++)
            {
                ll t1=num[j];
                for(ll k=1;k<i;k++)
                {
                    ll t2=num[k];
                    if(dis[t2][t1]>dis[t2][p]+dis[p][t1]) dis[t2][t1]=dis[t2][p]+dis[p][t1];
                }
            }
            ans[i]=0;
            for(ll j=0;j<=i;j++)
            {
                ll t1=num[j];
                for(ll k=0;k<=i;k++)
                {
                    ll t2=num[k];
                    ans[i]+=dis[t1][t2];
                }
            }
        }
        for(ll i=n;i>=1;i--)
        {
            if(i==n)printf("%I64d",ans[i]);
            else printf(" %I64d",ans[i]);
        }
        puts("");
    }
    return 0;
}
