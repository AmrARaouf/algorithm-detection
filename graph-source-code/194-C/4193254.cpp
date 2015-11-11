//Language: GNU C++


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std; 
const int M = 55; 
char g[M][M]; 
bool vis[M][M]; 
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1}; 
int n, m, x, y, cnt; 
queue< pair<int, int> >q; 

inline void insert(int x, int y){
	q.push(pair<int, int>(x, y)); 
}
int bfs(){
	for(int i = 0; i, n; i++){
		for(int j = 0; j<m; j++){
			if(g[i][j] == '#'&&!vis[i][j]){
//				cout << i << " " << j << endl; 
				insert(i, j), vis[i][j] = 1; 
				goto end;  
			}
		}
	}
end: 
	int k = 1; 
	while(!q.empty()){
		int x = q.front().first; 
		int y = q.front().second; 
		q.pop(); 
		for(int i = 0; i<4; i++){
			int xx = x+dir[i][0]; 
			int yy = y+dir[i][1]; 
			if(xx >= 0&&xx<n&&yy >= 0&&yy<m&&g[xx][yy] == '#'&&!vis[xx][yy]){
				vis[xx][yy] = 1; 
				insert(xx, yy); 
				k ++ ; 
			}
		}
	}
	return k; 
}
int main(){
	cin >> n >> m; 
	for(int i = 0; i<n; i++)
		cin >> g[i];
	cnt = 0; 
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cnt += g[i][j] == '#'; 
		}
	}
	if(cnt <= 2){
		puts("-1"); return 0; 
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){ 
			if(g[i][j] == '#'){
				memset(vis, 0, sizeof(vis)); 
				vis[i][j] = 1;
				if(bfs() != cnt-1){ 
					puts("1"); return 0; 
				}
			}
		}
	}
	puts("2"); 
	return 0; 
}

