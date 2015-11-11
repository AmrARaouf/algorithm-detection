//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N = 50001;
const int MAX = 1000000000;
//cout<<fixed<<setprecision(10);
int n,r1,r2,p[N];

void dfs(int x, int newp) {
 if (x!=r1)
   dfs(p[x], x);
 p[x] = newp;
}

int main() {
  cin >> n >> r1 >> r2;
  for(int i = 1;i<=n;i++)
    if (i!=r1)
      cin >> p[i];
      else p[i] = -1;
  dfs(r2, -1);
  for(int i = 1;i<=n;i++)
    if (i!=r2)
     cout << p[i] << " ";
}