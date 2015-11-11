//Language: GNU C++


#include <cstdio>
#include <vector>
#define PB push_back
using namespace std;

vector<int> v[100003];

int main()
{
	int n;scanf("%d",&n);
	printf("%d\n",n-1);
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		printf("2 %d %d\n",x,y);
		v[x].PB(i); v[y].PB(i);
	}
	for(int i=1;i<=n;i++)
		if(v[i].size()>1)
			for(int j=1;j<v[i].size();j++)
				printf("%d %d\n",v[i][0],v[i][j]);
	return 0;
}
    			 		   		 	  			