//Language: GNU C++


#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define pb push_back
#define SIZE(A) ((int)A.size())
#define fi first
#define se second
using namespace std;

typedef pair<int,int> ii;

const int MAXN = 510;

vector<int> way[MAXN];

struct node{
	
	int x,y,s;
	node(int _x=0,int _y=0,int _s=0)
	{	x=_x;y=_y;s=_s;}
	
};

node q[MAXN*MAXN*10];

bool used[MAXN][MAXN][2];

int dad[MAXN*MAXN*10];

vector<int> res[2];

int main(){
	
	int n,m,at=0,al=0;
	
	scanf("%d %d",&n,&m);
	
	for(int i=1,a,b;i<=m;i++)
	{
		scanf(" %d %d",&a,&b);
		way[a].pb(b);
		way[b].pb(a);
	}
	
	q[++at]=node(1,n,0);
	
	while( at!=al ){
		
		node tmp=q[++al];
		if(tmp.s==0 && tmp.x==tmp.y)
			continue;
		
		if(tmp.s==0 && tmp.x==n && tmp.y==1)
		{
			for(int i=al;i;i=dad[i]){
				if(q[i].s==0)
					res[0].pb(q[i].x);
				if(q[i].s==1)
					res[1].pb(q[i].y);
			}
			
			cout << SIZE(res[0])-1 << endl;
			for(int i=SIZE(res[0])-1;i>=0;i--)
				printf("%d ",res[0][i]);
			puts("");
			
			for(int i=SIZE(res[1])-1;i>=0;i--)
				printf("%d ",res[1][i]);
			printf("1");
			puts("");
			
			return 0;
		}
		
		if(tmp.s==0){

#define go way[tmp.x]
			for(int i=0;i<SIZE(go);i++)
				if(!used[ go[i] ][tmp.y][1])
				{
					used[ go[i] ][tmp.y][1]=true;
					q[++at]=node(go[i],tmp.y,1);
					dad[at]=al;
				}
#undef go
		}
				
		else{

#define go way[tmp.y]
			
			for(int i=0;i<SIZE(go);i++)
				if(!used[tmp.x][go[i]][0] && tmp.x!=go[i])
				{
					used[tmp.x][go[i]][0]=true;
					q[++at]=node(tmp.x,go[i],0);
					dad[at]=al;
				}
			
#undef go

		}
		
	}
	
	puts("-1");
	
	return 0;
	
}
