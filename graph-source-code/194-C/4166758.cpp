//Language: GNU C++


#include<utility>
#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<vector>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<sstream>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<deque>
#include<cctype>
#include<ctime>
#include<limits.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};
int n,m;
bool v[55][55];
char maps[55][55];
int dfs(int x,int y){
	if(x<0 || y<0 || x>=n || y>=m || maps[x][y]=='.' || v[x][y])return 0;
	v[x][y]=true;
	for(int i=0;i<4;i++)dfs(x+dx[i],y+dy[i]);
	return 1;
}
int main(){
	cin>>n>>m;
	int s=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		cin>>maps[i][j];
		if(maps[i][j]=='#')s++;
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(maps[i][j]=='#'){
		maps[i][j]='.';
		memset(v,false,sizeof(v));
		int cnt=0;
		for(int k=0;k<4;k++)cnt+=dfs(i+dx[k],j+dy[k]);
		if(cnt>1){
			cout<<1;
			return 0;
		}
		maps[i][j]='#';
	}
	if(s<3)cout<<-1;else cout<<2;
	return 0;
}
