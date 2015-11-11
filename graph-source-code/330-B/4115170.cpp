//Language: GNU C++


#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int n,m,flag[1111],sum;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(flag,0,sizeof(flag));
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			flag[x]=flag[y]=1;
		}
		int it=0;
		for(int i=1;i<=n;i++){
			if(flag[i]==0){
				it=i;
				break;
			}
		}
		printf("%d\n",n-1);
		for(int i=1;i<=n;i++){
			if(i==it)
			    continue;
			printf("%d %d\n",i,it);
		}
	}
	return 0;
}
