//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>
#include <stack>
#include <map>
#include <set>

using namespace std;
int n;
int k;
int main()
{
	while(cin>>n>>k)
	{
		if(n>= 1+(2*k))
		{
			cout<<n*k<<endl;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<k;j++)
				{
					int a = (i+j+1)%n;
					printf("%d %d\n",i+1,a+1);
				}
			}
		}
		else
		{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}

