//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
vector < pair<int,int> > an;
int n,k,i,j;
bool mark[1002][1002];
bool z;
int main()
{
	cin>>n>>k;
	z=true;
	for(i=1;i<=n;i++)
	{
		int q = 0;
		for(j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			if(q==k)
				break;
			if(!mark[i][j])
			{
				mark[i][j] = mark[j][i] =true;
				an.push_back(make_pair(i,j));
				q++;
			}
		}
		if(q<k)
		{
			z=false;
			break;
		}
	}
	if(!z)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<an.size()<<endl;
	for(i=0;i<an.size();i++)
	{
		printf("%d %d\n", an[i].first, an[i].second);
	}
	return 0;
} 