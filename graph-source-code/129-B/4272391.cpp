//Language: GNU C++


#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>

#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
#define PI 3.14159265

using namespace std;

int main()
{
	int n,m;
	int ar[105];
	int a,b;
	int ans=0;
	vector<int> temp;
	bool rep;
	pair<int,int> student[10000];
	
	memset(ar,0,sizeof(ar));
	scanf("%d %d",&n,&m);
	
	for (int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		ar[a]++;
		ar[b]++;
		student[i] = make_pair(a,b);
	}
	
	rep = true;
	
	while(rep)
	{
		temp.clear();
		rep = false;
		
		for (int i=1;i<=n;i++)
		{
			if (ar[i]==1)
			{
				for (int j=0;j<m;j++)
				{
					if (student[j].first==i || student[j].second==i)
					{
						temp.push_back(j);
						rep = true;
						break;
					}
				}
			}
		}
		
		if(rep)
		{
			int siz=temp.size();
			for (int j=0;j<siz;j++)
			{
				if (ar[student[temp[j]].first]==1 || ar[student[temp[j]].second]==1)
				{
					ar[student[temp[j]].first]--;
					ar[student[temp[j]].second]--;
					student[temp[j]].first = student[temp[j]].second = 0;
				}
			}
			ans++;	
		}
	}
	
	printf("%d\n",ans);
	
 	return 0;
}

