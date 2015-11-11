//Language: GNU C++


#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int n;
vector <int> G[100007];

int main(){
	int x,y;
	scanf("%d",&n);
	for (int i=1; i<=n; i++) G[i].clear();
	printf("%d\n",n-1);
	for (int i=1; i<n; i++){
        scanf("%d%d",&x,&y);
		G[x].push_back(i);
		G[y].push_back(i);
        printf("2 %d %d\n",x,y);
	}
	for (int i=1; i<=n; i++){
		for (int j=0; j<G[i].size()-1; j++)
                printf("%d %d\n",G[i][j],G[i][j+1]);
	}
	return 0;
}

	 	  	 	 		 		   		    			 		 	