//Language: GNU C++0x


#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int a[400]={0};
vector <int> k1,k2;
int c[310][310]={{0}};

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		a[x]=1;
		k1.push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			k2.push_back(i);
		}
	}
	if(k!=n){
		if(((n*(n-1))/2)-(k-1)<m){
			cout<<-1<<endl;
			return 0;
		}
	}else{
		cout<<-1<<endl;
		return 0;
	}
	c[k1[0]][k2[0]]=1;
	c[k2[0]][k1[0]]=1;
	c[k1[1]][k2[0]]=1;
	c[k2[0]][k1[1]]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==k1[0] && a[j]==1){
				c[i][j]=1;
				c[j][i]=1;
			}
			c[i][i]=1;
			c[j][j]=1;
		}
	}
	cout<<k1[0]<<" "<<k2[0]<<endl;
	cout<<k1[1]<<" "<<k2[0]<<endl;
	int xx=2;
	for(int i=1;i<=n;i++){
		if(xx==m){
			return 0;
		}
		if(c[i][k2[0]]==0){
			cout<<i<<" "<<k2[0]<<endl;
			xx++;
			c[i][k2[0]]=1;
			c[k2[0]][i]=1;
			if(xx==m){
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(xx==m){
				return 0;
			}
			if(c[i][j]==0){
				cout<<i<<" "<<j<<endl;
				xx++;
				c[i][j]=1;
				c[j][i]=1;
				if(xx==m){
					return 0;
				}
			}
		}
	}
}

