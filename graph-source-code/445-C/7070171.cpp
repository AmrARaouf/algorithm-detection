//Language: MS C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;
int main() {
   int n, m, a, b, c;
   double res = 0.0;
   scanf("%d %d", &n, &m);
   vector<int> v(n+1);
   for(int i = 1; i <= n; i++)
   {
	   scanf("%d", &v[i]);
   }
   for(int i = 0; i < m; i++)
   {
	   scanf("%d %d %d", &a, &b, &c);
	   double d = (v[a] + v[b]) / double(c);
	   if(d > res) res = d;
   }
   printf("%.14f\n", res);
   return 0;
}