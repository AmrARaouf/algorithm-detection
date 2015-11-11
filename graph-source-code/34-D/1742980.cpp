//Language: GNU C++


#include"stdio.h"
#include"string.h"
#include "algorithm"
#include "math.h"
using namespace std;
int main()
{ 
     int r1,r2,n,x,s[50005],ans[50005],i,f,t,v[50005];
	//freopen("E:\\in.txt","r",stdin);
    scanf("%d%d%d",&n,&r1,&r2);
	memset(v,0,sizeof(v));
    for (i=1;i<=n;i++)
    {
		if(i==r1) continue;
		scanf("%d",&s[i]);
    }
	x=r2;
	while(1)
	{
	    if(x==r1) break;
		t=s[x];
        ans[t]=x;
		v[t]=1;
        x=t;
	}
	f=0;
	for (i=1;i<=n;i++)
	{
		if(i==r2) continue;
		if(f==0)
		{   
			if(v[i]==0)
			printf("%d",s[i]);
			else printf("%d",ans[i]);
			f=1;
		}
		else
		{
			if(v[i]==0)
				printf(" %d",s[i]);
			else printf(" %d",ans[i]);
		}
	}
	printf("\n");
   return 0;  
}
   		  	 		   	  				  			