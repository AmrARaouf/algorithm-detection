//Language: GNU C++


#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

int n,m;
char g[55][55];
int d[4][2]={0,-1,0,1,-1,0,1,0};
bool v[55][55];

void find(int x, int y){
	v[x][y]=true;
	for(int i=0; i<4; ++i){
		int xx=x+d[i][0];
		int yy=y+d[i][1];
		if(0<=xx && xx<n && 0<=yy && yy<m && g[xx][yy]=='#' && !v[xx][yy]){
			find(xx,yy);
		}
	}
}
int s1,s2,s3,s4;

int main()
{
//	freopen("in.txt","r",stdin);
	 
	while(cin >> n >> m){
		int ls=0;s1=s2=s3=s4=-1;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j){
				cin >> g[i][j];
				if(g[i][j]=='#'){
					ls++;
					if(s1==-1){
						s1=i,s2=j;
					}
					else{
						s3=i,s4=j;
					}
				}
			}
		if(ls==1 || ls==2){
			cout << -1 << endl;
			continue;
		}
		
		
		bool flg=false;
		for(int i=0; i<n && !flg; ++i){
			for(int j=0; j<m && !flg; ++j){
				if(g[i][j]=='#'){
					g[i][j]='.';
					memset(v,false,sizeof(v));
					if(i==s1 && j==s2)
						find(s3,s4);
					else find(s1,s2);
					for(int ii=0; ii<n && !flg; ++ii){
						for(int jj=0; jj<m && !flg; ++jj){
							if(g[ii][jj]=='#' && !v[ii][jj])
								flg=true;
						}
					}
					g[i][j]='#';
				}
			}
		}
		
		if(flg)
			cout << 1 << endl;
		else cout << 2 << endl;
	}
	return 0;
}
       	 	    	 			    	  	