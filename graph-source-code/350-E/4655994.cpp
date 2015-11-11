//Language: GNU C++


#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n,m,k,mkp,mkp2,umkp;
	bool marked[300]={};
	vector<int> mk,umk;
	cin >> n >> m >> k;
	if(n==k || (n-1)*(n-2)/2+(n-k)<m){
		cout << -1;
		return 0;
	}
	for(int i=0;i<k;i++){
		int a;
		cin >> a;
		marked[a-1]=true;
	}
	for(int i=0;i<n;i++){
		if(marked[i]) mk.push_back(i+1);
		else umk.push_back(i+1);
	}
	mkp=mk[0];
	mkp2=mk[1];
	umkp=umk[0];
	cout << mkp << " " << umkp << endl;
	cout << mkp2 << " " << umkp << endl;
	int cnt=2;
	if(cnt==m) return 0;
	for(int i=1;i<=n;i++){
		if(i==mkp) continue;
		for(int j=i+1;j<=n;j++){
			if(j==mkp) continue;
			if( (i==mkp2 && j==umkp) || (i==umkp && j==mkp2) ) continue;
			cout << i << " " << j << endl;
			cnt++;
			if(cnt==m) return 0;
		}
	}
	for(int i=1;i<umk.size();i++){
		cout << umk[i] << " " << mkp << endl;
		cnt++;
		if(cnt==m) return 0;
	}
	return 0;
}