//Language: GNU C++


#include <iostream>
using namespace std;
int main(){
  int i,j,n;
  cin>>n;
  cout<<(n/2)*(n/2+n%2)<<'\n';
  for(i=1;i<=n/2;++i)
   for(j=n/2+1;j<=n;++j)cout<<i<<' '<<j<<'\n';
  return 0;
}
