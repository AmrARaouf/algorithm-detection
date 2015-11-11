//Language: GNU C++


#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
vector<int> vec[100100],ans[100100];
int main()
{
    int i,j,k,l,m,n=0,req;
    int x,y;
    cin>>i>>j;
    int A[i];
    for(k=0;k<i;k++)
    {
        cin>>A[k];
        if(n<A[k])
        n=A[k];
        vec[A[k]].push_back(k);
    }
    if(vec[0].size()!=1)
    {
        cout<<"-1";
        return 0;
    }
    for(k=1;k<=n;k++)
    {
        if(k==1)
        req=j;
        else
        req=j-1;
        int psze=vec[k].size();
        long long lsize=vec[k-1].size();
        if(psze>(lsize*req))
        {
            cout<<"-1";
            return 0;
        }
        for(l=0;l<vec[k].size();l++)
        {
            x=vec[k][l];y=vec[k-1][l/req];
            //cout<<x<<" "<<y<<" "<<k<<endl;
            ans[x].push_back(y);
            ans[y].push_back(x);
        }
    }
    cout<<(i-1)<<endl;
    for(k=0;k<i;k++)
    {
        for(l=0;l<ans[k].size();l++)
        {
            if(ans[k][l]>k)
            cout<<k+1<<" "<<ans[k][l]+1<<endl;
        }
    }
    return 0;
}   
        
        
        
        
        
        
        
        
        
        
        
        
        
    