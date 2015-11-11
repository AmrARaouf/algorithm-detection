//Language: GNU C++


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
typedef pair<int,int>ii;
ii a[100020];
int c[100020];
int n,x,y;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		a[i]=ii(x,y);
		if(!c[x])
			c[x]=i;
		if(!c[y])
			c[y]=i;
	}
	printf("%d\n",n-1);
	for(int i=1;i<n;i++)
		printf("2 %d %d\n",a[i].X,a[i].Y);
	for(int i=1;i<n;i++)
	{
		if(i!=c[a[i].X])
			printf("%d %d\n",i,c[a[i].X]);
		if(i!=c[a[i].Y])
			printf("%d %d\n",i,c[a[i].Y]);
	}
	return 0;
}