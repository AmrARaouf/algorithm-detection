//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctype.h>
using namespace std;
#define N 100010

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    if(k*2>n-1) {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",n*k);
        int i,j;
        for(i=1;i<=n;i++)
            for(j=1;j<=k;j++)
             {
                 int t=(i+j)%n;
                 if(t==0) t=n;
               printf("%d %d\n",i,t);
             }
    }
    return 0;

}

   	  	   	 	 		  		 	 		