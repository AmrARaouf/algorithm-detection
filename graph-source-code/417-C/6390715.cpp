//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

using namespace std;

int main()
{
    int i,n,k,a,ctr,fg=0,bn=0;
    scanf("%d %d",&n,&k);
    int table[n+1][n+1];
    for(i=0;i<n+1;i++)
        for(a=0;a<n+1;a++)
        table[i][a]=0;

    for(i=1;i<n+1;i++)
        {   ctr=0;
            a=i+1;
            while(ctr<k)
            {if(a==n+1)
                a=1;ctr++;
            if(a==i)
                fg=1;
            if(table[min(a,i)][max(a,i)]!=0)
                fg=1;
            table[min(a,i)][max(a,i)]=1;
            a++;bn++;
            }
        }
     if(fg)
            printf("-1\n");
     else
     {   printf("%d\n",bn);
         for(i=1;i<n+1;i++)
        {   ctr=0;
            a=i+1;
            while(ctr<k)
            {if(a==n+1)
                a=1;ctr++;
            printf("%d %d\n",i,a);
            a++;
            }
        }
     }
}
