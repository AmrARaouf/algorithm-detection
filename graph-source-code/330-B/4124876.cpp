//Language: MS C++


#include <iostream>

using namespace std;
int n,m,s=1;
bool br[1001];
int main(){
	cin>>n>>m;
	int temp;
	for(int x=0;x<m*2;x++){
		cin>>temp;
		br[temp]=true;
	}
	while(br[s]){s++;}
	cout<<n-1<<endl;
	for(int x=1;x<=n;x++){
		if(x!=s){
			cout<<min(s,x)<<" "<<max(s,x)<<endl;
		}
	}
}