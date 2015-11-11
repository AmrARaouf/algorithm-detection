//Language: GNU C++


#include<iostream>
#include<cmath>
using namespace std;
const int maxn=1000+1,maxk=5+1;
int n,k;
int a[maxk][maxn];
int b[maxk][maxn];
int dp[maxn];
int check(int i,int j)
{
    for(int t = 1;t<=k;t++)
    {
        if(b[t][i]>b[t][j])
            return 0;
    }
    return 1;
}
int main()
{
    cin>>n>>k;
    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            b[i][a[i][j]]=j;
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(check(a[1][i],a[1][j]))
            {
                dp[j]=max(dp[i]+1,dp[j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
