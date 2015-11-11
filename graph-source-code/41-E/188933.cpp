//Language: MS C++


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

int n;

int main()
{
	cin >> n;
		
	cout<< n/2 * (n - n/2)<<endl;
	
	for (int i = 0; i < n/2; i++)
		for (int j = n/2; j < n; j++)
			cout<<i+1<<' '<<j+1<<endl;

	//system("pause");
	return 0;
}