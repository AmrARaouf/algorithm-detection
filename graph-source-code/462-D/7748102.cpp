//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int mm=1000000007;
int main()
{
	//freopen("output.txt","w",stdout);
	int p[100000],o[100000],fa[100000];
	long long f[100000][2];
	int n,i,j,l,r;
	long long x0,x1;
	o[0]=0;
	scanf("%d",&n);
	for (i=1;i<n;i++)
	{
		o[i]=0;
		scanf("%d",&fa[i]);
		o[fa[i]]++;
	}
	for (i=0;i<n;i++)
	{
		scanf("%d",&l);
		if (l==0)
		{
			f[i][0]=1;
			f[i][1]=0;
		}
		else 
		{
			f[i][0]=0;
			f[i][1]=1;
		}
	}
	r=0;
	l=0;
	for (i=1;i<n;i++)
		if (o[i]==0)
		{
		//	cout << i << endl;
			p[l]=i;
			l++;
		}
	while (r<l)
	{
		j=p[r];
//		cout << "=============" << endl;
//		cout << j << ' ' <<  f[j][0] << ' ' << f[j][1] << endl; 
		//cout << "#" << j << ": f[0]=" << f[j][0] << "   f[1]=" < f[j][1] << endl; 
		if (j==0)
			break;
		r++;
		i=fa[j];
		o[i]--;
//		cout << o[i] << endl;
//		cout << j << ' ' <<  i << ' ' << f[j][0] << ' ' << f[j][1] << endl;
		if (o[i]==0)
		{
		//	cout << "true " << l << endl; 
			p[l]=i;	
			l++;
		}
		x0=(f[i][0]*f[j][0])%mm;
		x0=(x0+f[i][0]*f[j][1])%mm;
		x1=(f[i][1]*f[j][1])%mm;
		x1=(x1+f[i][1]*f[j][0])%mm;
		x1=(x1+f[i][0]*f[j][1])%mm;
		f[i][0]=x0;
		f[i][1]=x1;
	}
//	for (i=0;i<n;i++)
//		cout << p[i] <<  ' ';
//	cout << endl;
	cout << f[0][1] << endl;
	return 0;
}
