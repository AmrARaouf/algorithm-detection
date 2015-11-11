//Language: GNU C++0x


#include<stdio.h>
#include<vector>
#include<algorithm>
#define PB push_back
using namespace std;
bool t[102][102];
int cnt[102];
int main(){
	int n,m;
   scanf("%d%d",&n,&m);
   for(int i=0;i<m;i++){
		int a,b; scanf("%d%d",&a,&b);
		t[a][b]=t[b][a]=1;
		cnt[a]++; cnt[b]++;
	}
	int ans=0;
	while(1){
		bool f=1;
		vector<int> V;
		for(int i=1;i<=n;i++) if(cnt[i]==1){ f=0; V.PB(i); }
		if(f) break;
		for(int i=0;i<V.size();i++){
			for(int j=1;j<=n;j++){
				if(t[V[i]][j]==1){
					t[V[i]][j]=0;
					t[j][V[i]]=0;
					cnt[V[i]]--;
					cnt[j]--;
				}	
			}
		}
		ans++;
	}
	printf("%d\n",ans);
}
