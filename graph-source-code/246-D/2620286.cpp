//Language: MS C++


#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int c [2000000];
int cn[2000000]={0};
map< long long,bool > hashm;

void add(int a,int b)
{

	if (a!=b)
	{
		long long c=(long long)a*1000000+b;
		map< long long , bool >::const_iterator ifind =hashm.find( c );
		if (ifind==hashm.end())
		{
			hashm[c]=true;
			cn[a]++;
		}
	}
}
void main()
{


	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%d",&c[i]),cn[c[i]]=1;

	for (int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		///a=rand()%n+1;
		///b=rand()%n+1;
		a--;
		b--;
		add(c[a],c[b]);
		add(c[b],c[a]);
	}
	int maxi=0;
	for (int i=0;i<=100000;i++)
		if (cn[i]>cn[maxi])
			maxi=i;
	printf("%d",maxi);
}