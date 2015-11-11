//Language: MS C++


#include <iostream>
#include <vector>
using namespace std;
int main()
{
	//freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	vector< pair<int,int> > ans;
	for(int i=1;i<n;i++)
		ans.push_back( make_pair(i,i+1) );
	for(int i=1;i<n;i++)
		for(int j=i+3;j<=n;j+=2)
			ans.push_back( make_pair(i,j) );
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	return 0;
}