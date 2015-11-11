//Language: GNU C++


//============================================================================
// Name        : SAS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <string.h>
int main() {
	int a[110][110],b[110],c[110],i,j,n,m,x,y,group,l,k;
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[y][x]=1;
		a[x][y]=1;
		b[x]++;
		b[y]++;
	}
	l=1;
	group=0;
	while (l)
	{
		l=0;
		for (i=1;i<=n;i++)
		if (b[i]==1)
			{
				l++;
				c[l]=i;
			}
		for (i=1;i<=l;i++)
		{
			j=1;
			k=c[i];
			while (!a[k][j]) j++;
			if (b[j]>1) a[j][k]=0;
			b[k]--;
			b[j]--;
		}

		if (l) group++;
	}
	printf("%d\n",group);
	return 0;
}

	 	   	 	  		 				 	    		