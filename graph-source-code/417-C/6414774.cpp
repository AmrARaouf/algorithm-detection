//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
int s[1005][1005];
int main()
{
    int i,j,n,m,k,pd=1,cnt=0;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
           if(i+j<=n)
           s[i][i+j]=1;
           else if((i+j)%n==0)s[i][n]=1;
           else s[i][(i+j)%n]=1;
        }
    }
    for(i=1;i<=n;i++)
    {
       if(pd==0)break;
       for(j=1;j<=n;j++)
       {
          if(s[i][j])cnt++;
          if(s[i][j]&&s[j][i])
          {
             pd=0;
             break;
          }
       }
    }
    if(pd==0)cout<<-1<<endl;
    else
    {
        cout<<cnt<<endl;
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       if(s[i][j])printf("%d %d\n", i, j);
    }
}

    return 0;
}