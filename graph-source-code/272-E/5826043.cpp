//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
vector<int>e[300005];
int flag[300005];
int n,m;
void gao(int k)
{
    int cnt=0;
    for(int i=0;i<e[k].size();i++)
        if(flag[k]==flag[e[k][i]])cnt++;
    if(cnt>1)
    {
     flag[k]=!flag[k];
     for(int i=0;i<e[k].size();i++)
        if(flag[k]==flag[e[k][i]])gao(e[k][i]);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);e[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        gao(i);
    for(int i=1;i<=n;i++)
        printf("%d",flag[i]);
}

		 		 	 	    	 		    		