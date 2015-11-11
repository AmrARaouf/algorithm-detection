//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

typedef long long LL;
#define REP(i,e) for (int (i) = 0; (i) < (e); ++(i))
#define foreach(__my_iterator,__my_object) for (typeof((__my_object).begin()) __my_iterator = (__my_object).begin(); __my_iterator!= (__my_object).end(); __my_iterator++)

int a[100010],b[100010];
int prev[100010];

void solve(){
}

int main(){
  int n;
  cin >> n;
  memset(prev, -1, sizeof(prev));
  vector <int> v;
  vector <int> w;
  REP(i, n-1){
    cin >> a[i];
    cin >> b[i];
    if(prev[a[i]] != -1){
      v.push_back(prev[a[i]]);
      w.push_back(i);
    }
    if(prev[b[i]] != -1){
      v.push_back(prev[b[i]]);
      w.push_back(i);
    }
    prev[a[i]] = i;
    prev[b[i]] = i;
  }
  
  printf("%d\n", n-1);
  REP(i, n-1) printf("2 %d %d\n", a[i], b[i]);
  REP(i, v.size()){
    printf("%d %d\n", v[i]+1, w[i]+1);
  }

  return 0;
}
/*
echo "
4
3
3 4
4 10
6 10
9
3
3 4
4 10
7 10
9
2
6 6
10 3
13
2
6 6
10 3
14
 */
