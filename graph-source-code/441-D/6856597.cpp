//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cstring>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    int arr[n+1];
    int parent[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        parent[i]=-1;
    }
    cin>>m;
    int grp=0;
    for(int i=1;i<=n;i++)
    {
        if(parent[i]==-1)
        {
            grp++;  
            int x=i;
            while(parent[x]==-1)
            {
                parent[x]=i;
                x=arr[x];
            }
        }
    }
    int k=abs(n-m-grp);
    cout<<k<<endl;
    if(grp>n-m)
    {
        while(k)
        {
            for(int i=1;i<=n;i++)
            {
                if(parent[i]!=1)
                {
                    cout<<1<<" "<<i<<" ";
                    int x=parent[arr[i]];
                    for(int j=1;j<=n;j++)
                    {
                        if(parent[j]==x)
                            parent[j]=1;
                    }
                    break;
                }
            }
            k--;
        }
    }
    else if(grp<n-m)
    {
        //cout<<1111<<endl;
        int ind =1;
        while(k)
        {
            for(int i=1;i<=n;i++)
            if(arr[i]!=i)
            {
                ind=i;
                break;
            }
            int x=10000;
            //cout<<parent[1]<<" "<<parent[2]<<" "<<parent[3]<<endl;
            for(int i=ind+1;i<=n;i++)
            {
                if(parent[arr[i]]==parent[arr[ind]])
                    {x=i;break;}
            }
            cout<<ind<<" "<<x<<" ";
            int temp=arr[ind];
            arr[ind]=arr[x];
            arr[x]=temp;            
            for(int i=1;i<=n;i++)
                parent[i]=-1;
            for(int i=1;i<=n;i++)
            {
                if(parent[i]==-1)
                {
                    int x=i;
                    while(parent[x]==-1)
                    {
                        parent[x]=i;
                        x=arr[x];
                    }
                }
            }
            k--;
        }
    }
    cout<<endl;

}