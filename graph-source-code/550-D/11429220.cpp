//Language: GNU C++


#include<cstdio>
using namespace std;

bool g[400][400];

int main(){
	int k;
	scanf("%d",&k);
	if(k==1){
		printf("YES\n2 1\n1 2");
		return 0;
	}
	if(k%2==0){
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=k+1;i++){
		for(int j=1;j<=k+1;j++){
			if(i!=j){
				g[i][j]=1;
			}
		}
	}
	for(int i=1;i<=k-1;i++){
		g[k+2][i]=1;
		g[i][k+2]=1;
	}
	for(int i=1;i<=((int)(k/2));i++){
		g[i<<1][(i<<1)-1]=0;
		g[(i<<1)-1][i<<1]=0;
	}
	printf("YES\n");
	printf("%d %d\n",(k+2)*2,(((((k+1-1)*(k+1))/2)-(k/2))+k-1)*2+1);
	for(int i=1;i<=k+2;i++){
		for(int j=i+1;j<=k+2;j++){
			if(g[i][j]){
				printf("%d %d\n",i,j);
				printf("%d %d\n",i+k+2,j+k+2);
			}
		}
	}
	printf("%d %d\n",k+2,(k+2)*2);
	return 0;
}
