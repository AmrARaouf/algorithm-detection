//Language: GNU C++



#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int data[1005];

int main()
{
    int m,n,a,b,i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&data[i]);
    int ans=0;
    while(m--){
        scanf("%d%d",&a,&b);
        ans+=data[a]<data[b]? data[a]:data[b];
    }
    printf("%d\n",ans);
}

  	  	  	 	   	  		  			  	