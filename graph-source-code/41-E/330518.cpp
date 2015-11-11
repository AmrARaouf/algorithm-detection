//Language: GNU C++


#include <vector>
#include <string>
#include <string.h>
#include <algorithm> 
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <cstdio>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cfloat>
#include <numeric>
#include <iostream>
  
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int n;
bool arr[103][103];
int main(){

	cin>>n;
		   cout<<((n / 2) * ((n + 1) / 2))<<endl;
            for(int i = 0; i < n/2; i++)
                for (int j = n / 2; j < n; j++)
                {
                    cout<<i+1<<" "<<j+1<<endl;
                }

	return 0;
}