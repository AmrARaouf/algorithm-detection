//Language: GNU C++0x


#include <bits/stdc++.h>
using namespace std;

map< int, set<int> > mp;
int col[100005];

int main(){
		
	int n, m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++){
		cin>>col[i];
		mp[col[i]]=set<int>();
	}
	
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		if(col[a]==col[b]) continue;
		mp[col[a]].insert(col[b]);
		mp[col[b]].insert(col[a]);
	}
	
	int mx=-1, id;
	for(auto &i: mp){
		if((int)i.second.size()>mx){
			mx=i.second.size();
			id=i.first;
		}
	}
	
	cout<<id<<endl;
	
	return 0;
}

