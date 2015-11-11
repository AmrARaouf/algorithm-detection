//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
int  known[111];
int fl=0;
int le[111];
int ri[111];
int nodes;
void dfs(int i,int j){
	if(i==j){
		known[j]=1;
		fl=1;
		return;
	}
	known[i]=1;
	int k;
	for(k=1;k<=nodes;k++){
		if(known[k]==0){
			if(( le[k]<le[i] && le[i]< ri[k]) || (le[k]< ri[i] && ri[i] < ri[k])){
				dfs(k,j);
			}
		}

	}
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	int i;
	int x,y,z;
	int j=1;
	int k;
	nodes=0;
	for(i=0;i<n;i++){
		scanf("%d %d %d",&x,&y,&z);
		if(x==1){
			le[j]=y;
			ri[j]=z;
			nodes=j;
			j++;
		}
		if(x==2){
			memset(known,0,sizeof(known));
			fl=0;
			dfs(y,z);
			if(known[z]==1){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
	return 0;
}

