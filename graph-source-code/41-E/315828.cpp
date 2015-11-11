//Language: GNU C++


#include <iostream>

using namespace std;

int main(){
  int n;cin >> n;
  cout<< (n-(n+1)/2) * ((n+1)/2) <<endl;
  for(int i = 0;i<(n+1)/2;i++){
    for(int j = 0; j < n-((n+1)/2);j++){
      cout <<1+ i << " " <<1+ j + (n+1)/2 <<endl;
    }
  }
  return 0;
}
