//Language: GNU C++


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n<2*m+1)
    {cout<<"-1";return 0;}
    else
    { cout<<n*m<<"\n";
        for(int i=1;i<=n;i++)
        { int ctr=m;
            for(int j=(i+1);j!=i&&ctr;j++)

            {
                if(j>n)
                    j=1;
                printf("%d %d\n",i,j);
            ctr--;
            }
        }
    }
    return 0;

}
