//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(m<=n)
    {
        int ans=abs(m-n);
        cout<<ans<<endl;
    }
    else
    {
        int count=0;
        while(m>n)
        {
            if(m%2==0)
                {
                    m/=2;count++;
                }
            else
                {
                    m+=1;count++;
                }
        }
        cout<<count+(n-m)<<endl;
    }
    return 0;
}