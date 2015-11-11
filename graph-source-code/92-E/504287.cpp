//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<cmath>
#include<cstdlib>
#include<functional>
using namespace std;
int F[100100];
int find(int x){
	return x==F[x]?x:find(F[x]);
}
bool mg(int a,int b){
	a=find(a);b=find(b);
	if(a==b)return true;
	else{
		if(a<b)F[b]=a;else F[a]=b;
		return false;
	}
}
int main(){
	int n,m,ans,a,b,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<=n;++i)F[i]=i;
	ans=1;
	for(i=0;i<m;++i){
		scanf("%d %d",&a,&b);
		if(mg(a,b)){
			ans<<=1;
			ans%=1000000009;
		}
		printf("%d\n",(ans+1000000008)%1000000009);
	}
	return 0;
}
