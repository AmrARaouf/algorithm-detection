//Language: GNU C++


#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

int n,m;
int fa[500005];
vector <int> e[500005];
bool v[500005];

int getFather( int x ){
	if(fa[x]==x) return x;
	return fa[x]=getFather(fa[x]);
}

void Merge(int x,int y){
	int px=getFather(x),py=getFather(y);
	fa[px]=py;
}

int main()
{
	scanf( "%d%d", &n , &m );
	for( int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int Min=2000000000;
	int t=0;
	for(int k=1;k<=n;k++)
		if(e[k].size()<Min){
			Min=e[k].size();
			t=k;
		}
	int start=t;
	for(int i = 0;i<e[start].size();i++)
		v[e[start][i]] = 1;
	for(int k=1;k<=n;k++)
        if (v[k])
            fa[k]=k;
        else
            fa[k]=start;
	for(int i=0;i<e[start].size();i++){
		int y=e[start][i];
		memset(v,0,sizeof(v));
		for(int j=0;j<e[y].size();j++)
			v[e[y][j]]=1;
		for(int k=1;k<=n;k++)
			if(v[k]==0)
				Merge(k,y);
	}
	for( int k=1;k<=n;k++)
		fa[k]=getFather(k);
	int len = 0;
	for(int k=1;k<=n;k++) e[k].clear();
	for(int k=1;k<=n;k++){
		int fk = fa[k];
		if(e[fk].size()==0)len ++;
		e[fk].push_back(k);
	}
	printf("%d\n",len);
	for(int k=1;k<=n;k++){
		if(e[k].size()>0){
			printf("%d",e[k].size());
			for(int j = 0;j<e[k].size();j++)
				printf(" %d",e[k][j]);
			printf("\n");
		}
	}
	return 0;
}
/*
4 4
1 2
1 3
4 2
4 3

3 1
1 2
*/

 			   					 	 			      		  			