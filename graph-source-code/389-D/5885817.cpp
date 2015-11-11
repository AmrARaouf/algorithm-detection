//Language: MS C++


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <iomanip>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <ctime>
#include <functional>
#include <bitset>

#define pb push_back
#define mk make_pair
#define sqr(N) ((N)*(N))
#define F first
#define S second
#define maxn 101010

using namespace std;                         

typedef long long ll;

int ans[1111][1111], v = 2, i, j, k;

void go(int x){
  int i, k = 0, p = 0;
  v++;
  if(x == 1){
    ans[1][v] = 1;
    ans[v][4] = 1;
  }
  else{
    ans[1][v] = ans[1][v + 1] = 1;
    k = 2;
    p = 1;
    while(k < x){
      v += 2;
      p++;
      ans[v - 2][v] = 1;
      ans[v - 2][v + 1] = 1;
      ans[v - 1][v] = 1;
      ans[v - 1][v + 1] = 1;
      k *= 2;
    }
   p += 3;
   if(p == 32)p = 2;
   ans[p][v] = 1;
   ans[p][v + 1] = 1;
   v++; 
  }
}

int main(){
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif
  scanf("%d", &k);
  ans[1][3] = 1;
  for(i = 4; i <= 31; i++){
    ans[i][i - 1] = 1;
  }
  ans[31][2] = 1;
  v = 31;
  k--;
  while(k > 0){
    int l = 0;
    while((1 << (l + 1)) <= k)l++;
    k -= (1 << l);
    go(1 << l);  
  }
  for(i = 1; i <= v; i++)
    for(j = 1; j <= v; j++){
      if(ans[i][j])ans[j][i] = 1;
      if(ans[j][i])ans[i][j] = 1;
      //if(ans[i][j] && i < j)printf("%d %d \n", i, j);
    }
  printf("%d\n", v);
  for(i = 1; i <= v; i++){
    for(j = 1; j <= v; j++){
      if(ans[i][j])printf("Y");
      else printf("N");
    }
    printf("\n");
  }
  return 0;
}         