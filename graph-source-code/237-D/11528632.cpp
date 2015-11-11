//Language: GNU C++


#include<map>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MP make_pair
#define X first
#define Y second
const int maxn=111111;

vector<int> G[maxn];
vector<pair<int,int> > ans;

int main(){
    int n;while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) G[i].clear();
        ans.clear();
        for(int i=1;i<n;i++){
            int u,v;scanf("%d%d",&u,&v);
            ans.push_back(MP(u,v));
            G[u].push_back(i);G[v].push_back(i);
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++) printf("2 %d %d\n",ans[i].X,ans[i].Y);
        for(int u=1;u<=n;u++){
            for(int i=0;i+1<G[u].size();i++){
                printf("%d %d\n",G[u][i],G[u][i+1]);
            }
        }
    }
    return 0;
}

	  				  	 		 	   		 	  		  	 	