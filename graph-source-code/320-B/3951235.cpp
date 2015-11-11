//Language: MS C++


#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

int n;
int arr[103][2],k=0;
int vis[103]={false};
int a,b,t;
bool flag;
int dfs(int node){
	if(vis[node])return 0;
	if(node==b){
		flag=true;
		return 0;
	}
	vis[node]=true;
	for(int i=0;i<k;i++){
		if(i==node)continue;
		if((arr[i][0]<arr[node][0] && arr[node][0]<arr[i][1]) || (arr[i][0]<arr[node][1] && arr[node][1]<arr[i][1])){
			dfs(i);
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t>>a>>b;
		
		if(t==1){
			arr[k][0]=a;
			arr[k++][1]=b;
		} else {
			a--;
			b--;
			flag=false;
			for(int i=0;i<k;i++){
				vis[i]=false;
			}
			dfs(a);
			if(flag){
				cout<<"YES"<<endl;
			} else {
				cout<<"NO"<<endl;
			}
		}
	}
}