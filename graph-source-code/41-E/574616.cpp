//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n,i,j,cnt;
	while(scanf("%d",&n)!=EOF)
	{
		cnt=0;
		for(i=0;i<n;++i)
			for(j=i+1;j<n;j+=2)
				cnt++;
		printf("%d\n",cnt);
		for(i=0;i<n;++i)
			for(j=i+1;j<n;j+=2)
				printf("%d %d\n",i+1,j+1);
	}
	return 0;
}
				      		 			 	 				 		