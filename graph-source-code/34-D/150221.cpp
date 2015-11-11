//Language: GNU C++


#include <iostream>
using namespace std;
int p[50010];
int ans[50010];
int main()
{
    int n,r1,r2;
    cin>>n>>r1>>r2;
    for(int i=1;i<=n;i++)
    {
        if(i==r1)
            continue;
        cin>>p[i];
        ans[i]=p[i];
    }
    for(int u=r2;u!=r1;u=p[u])
    {
        ans[p[u]]=u;
    }
    int tc=0;

    for(int i=1;i<=n;i++)
    {
        if(i==r2)
            continue;
        if(tc!=0)
            cout<<" "<<ans[i];
        else 
            cout<<ans[i];
        tc++;
    }
    return 0;
}
