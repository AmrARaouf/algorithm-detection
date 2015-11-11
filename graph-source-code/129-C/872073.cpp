//Language: MS C++


#pragma hdrstop
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<string.h>
#include<queue>
using namespace std;
long long n,i,l=0,ans=0,t,j,g,x,y,n1=1,n2=1,m;
long long a[101][101],sum[101],k[10][10];
char pole[10][10];
bool b[101],p,u[11][11];
queue <pair <int,int> > q;
int main()
{
	memset(k,-1,sizeof(k));
	for(i=1;i<=8;i++)
		for(j=1;j<=8;j++)
		{
			cin>>pole[i][j];
			//if(pole[i][j]=='S')
			//	k[i][j]=1;
			if(pole[i][j]=='M')
				k[i][j]=2;//,q.push(make_pair(i,j));
			if(pole[i][j]=='A')
				k[i][j]=3;
			if(pole[i][j]=='.')
				k[i][j]=0;
		}
	for(i=1;i<=8;i++)
		for(j=1;j<=8;j++)
			if(pole[i][j]=='S')
			{
				k[i][j]=1;
				if(i!=8)
					k[i+1][j]=1;
			}
	if(k[8][2]!=1)
		q.push(make_pair(8,2)),k[8][2]=2;
	if(k[8][1]!=1)
		q.push(make_pair(8,1)),k[8][1]=2;
	if(k[7][2]!=1)
		q.push(make_pair(7,2)),k[7][2]=2;
	if(k[7][1]!=1)
		q.push(make_pair(7,1)),k[7][1]=2;
	for(int z=1;z<=9;z++)
	{
		for(i=1;i<=8;i++)
			for(j=1;j<=8;j++)
				if(k[i][j]==2&&z!=1)
				{
					q.push(make_pair(i,j));
					//k[i][j]=2;
				}
		p=true;
		//memset(u,false,sizeof(u));
		while(q.size())
		{
			if(z==1)
			{
				p=false;
				break;
			}
			x=q.front().first,y=q.front().second;
			if(abs(k[x+1][y])!=1)
				k[x+1][y]=2,p=false;
			if(abs(k[x+1][y+1])!=1)
				k[x+1][y+1]=2,p=false;
			if(abs(k[x+1][y-1])!=1)
				k[x+1][y-1]=2,p=false;
			if(abs(k[x][y+1])!=1)
				k[x][y+1]=2,p=false;
			if(abs(k[x][y-1])!=1)
				k[x][y-1]=2,p=false;
			if(abs(k[x-1][y])!=1)
				k[x-1][y]=2,p=false;
			if(abs(k[x-1][y+1])!=1)
				k[x-1][y+1]=2,p=false;
			if(abs(k[x-1][y-1])!=1)
				k[x-1][y-1]=2,p=false;
			q.pop();
		}
		if(p)
		{
			cout<<"LOSE";
			return 0;
		}
		for(i=8;i>0;i--)
			for(j=8;j>0;j--)
			{
				if(pole[i][j]=='S')
				{
					pole[i][j]='.';
					k[i][j]=0;
					if(i!=8)
					{
						pole[i+1][j]='S';
						k[i+1][j]=1;
						if(i!=7)
							if(k[i+2][j]==2)
								q.push(make_pair(i+2,j));
						k[i+2][j]=1;
					}
				}
			}
	}
	cout<<"WIN";
	return 0;
}