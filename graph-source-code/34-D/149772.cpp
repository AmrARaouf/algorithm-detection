//Language: GNU C++


//D
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <deque>
#include <bitset>

using namespace std;

#define pb push_back;
typedef long long ll;
typedef pair<int, int> point;
typedef long int lint;
const int infnity = -1;

ll power (ll a, ll b)
{
  ll ans = 1;
  for (int i = 0; i < b; i++)
    ans *= a;
  return ans;
}
int *ar, *ar2;

vector<int> ans;
void DFS(int id, int r, int l)
{
  //ans.push_back(id);
  ar2[id] = l;
  if (id == r)
    return;
  
  DFS(ar[id], r, id);
}

int main ()
{
  int n, r1, r2;
  cin >> n >> r1 >> r2;
  r1--;
  r2--;
  ar = new int[n + 1];
  ar2 = new int[n + 1];
  for (int i = 0; i < n; i++)
    {
      if (i == r1)
	continue;
      cin >> ar[i];
      ar[i]--;
      ar2[i] = ar[i];   
    }
  DFS(r2, r1, -1);
  //r2--;
  for (int i = 0; i < n; i++)
    {
      if (i == r2)
	continue;
      cout << ar2[i] + 1;
      if (r2 > i)
	{
	  if (i < n - 2)
	    cout << " ";
	}
      else
	{
	  if (i < n - 1)
	    cout << " ";
	}
    }
  cout << endl;
  return 0;
}
