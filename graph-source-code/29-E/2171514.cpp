//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#define MAXN 510
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;

int N,M;
int Dn[MAXN][MAXN][2];
int Dad[MAXN][MAXN][2][3];
int Pri[MAXN][2];
int Push;
vector<int> Way[MAXN];
queue<iii> q;

int main(){
	scanf("%d%d",&N,&M);
	
	for(int i=1,a,b;i<=M;i++){
		scanf("%d%d",&a,&b);
		Way[a].push_back(b);
		Way[b].push_back(a);
	}
	
	iii tmp;
	q.push(iii(ii(1,N),0));
	Dn[1][N][0]=1;
	while(!q.empty()){
		tmp=q.front(); q.pop();
		
		int a,b,k;
		a=tmp.fi.fi;
		b=tmp.fi.se;
		k=tmp.se;
		
		if(k==0 && a==N && b==1){
			printf("%d\n",Dn[a][b][k]-1);
			
			for(int ta,tb,tk;a!=1 || b!=N || k!=0;){
				if(!k){
					Push++;
					Pri[Push][1]=b;
				}
				else
					Pri[Push][0]=a;
				
				ta=a;
				tb=b;
				tk=k;
				a=Dad[ta][tb][tk][0];
				b=Dad[ta][tb][tk][1];
				k=Dad[ta][tb][tk][2];
			}
			Pri[++Push][0]=1;
			Pri[Push][1]=N;
			
			for(int i=Push;i;i--)
				printf("%d ",Pri[i][0]);
			printf("\n");
			for(int i=Push;i;i--)
				printf("%d ",Pri[i][1]);
			printf("\n");
			return 0;
		}
		
		if(k==0){
			for(int i=0,mi=Way[a].size();i<mi;i++)
				if(!Dn[Way[a][i]][b][1]){
					Dn[Way[a][i]][b][1]=Dn[a][b][0];
					Dad[Way[a][i]][b][1][0]=a;
					Dad[Way[a][i]][b][1][1]=b;
					Dad[Way[a][i]][b][1][2]=0;
					q.push(iii(ii(Way[a][i],b),1));
				}
		}
		else{
			for(int i=0,mi=Way[b].size();i<mi;i++)
				if(!Dn[a][Way[b][i]][0] && Way[b][i]!=a){
					Dn[a][Way[b][i]][0]=Dn[a][b][1]+1;
					Dad[a][Way[b][i]][0][0]=a;
					Dad[a][Way[b][i]][0][1]=b;
					Dad[a][Way[b][i]][0][2]=1;
					q.push(iii(ii(a,Way[b][i]),0));
				}
		}
	}
	
	printf("-1\n");

	return 0;
}
