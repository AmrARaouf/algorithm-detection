//Language: GNU C++0x


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;
int main(){
	int n, m;
	
	int in;
	cin>>n>>m;
	vector<int> v(n + 1, 0);
	for(int i = 1; i <= n; ++i){
		cin>>in;
		v[i] = in;
	}
	int a, b;
	double c = 0;
	double ret = 0;
	for(int i = 0; i < m; ++i){
		cin>>a>>b>>c;
		ret = max((double)((v[a] + v[b]) / c), ret);
	}
	cout<<fixed<<std::setprecision(10)<<ret<<endl;
	return 0;
}
