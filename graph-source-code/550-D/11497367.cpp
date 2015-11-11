//Language: GNU C++11


/* ***********************************************
Author        :xdlove
Created Time  :2015年06月08日 星期一 19时16分17秒
File Name     :code.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void pt(int s,int n)
{
	for(int i = s + 1; i < s + n; i++)
		printf("%d %d\n",s,i);
	for(int i = s + 1; i < s + n; i++)
		for(int j = s + n; j < s + 2 * n - 1; j++)
			printf("%d %d\n",i,j);
	for(int i = s + n; i < s + 2 * n - 1; i += 2)
		printf("%d %d\n",i,i + 1);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	if(n & 1)
	{
		puts("YES");
		int u,e,tot = 1;
		u = (n - 1) * 4 + 2;
		e = (n - 1) * (2 * n + 1) + 1;
		cout<<u<<' '<<e<<endl;
		pt(1,n);
		printf("%d %d\n",1,2 * n);
		pt(2 * n,n);
	}
	else puts("NO");
    return 0;
}

		  			    	   					   			   		