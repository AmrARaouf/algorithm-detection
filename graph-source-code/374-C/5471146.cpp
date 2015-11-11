//Language: GNU C++


# include <bits/stdc++.h>

using namespace std;

const int N = 1001,M = 1001;
char mytab [N][M];
int dp[N][M];
int state[N][M];
int nn,mm;

int dx [] = {  0,  0, -1, 1};
int dy [] = {  1, -1, 0, 0};


bool valid (char parent, char children){
     //cout<<parent<<" "<<children<<endl;
     if(children == 'A' && parent == 'M') return true;
     if(children == 'M' && parent == 'I') return true;
     if(children == 'I' && parent == 'D') return true;
     if(children == 'D' && parent == 'A') return true;
     return false;
}

bool dfs(pair<int,int> ini){
     //cout<<mytab[ini.first][ini.second]<<endl;
     if(state[ini.first][ini.second] == 1) return true;
     if(state[ini.first][ini.second] == 2) return false;
     state[ini.first][ini.second] = 1;
     
     for(int i = 0; i < 4; ++i){
          int nx = ini.first + dx[i];;
          int ny = ini.second + dy[i];
          if(nx >= nn || nx < 0 || ny < 0 || ny >= mm)continue;
          char children = mytab[nx][ny];
          char parent = mytab[ini.first][ini.second];
          
          if(valid(parent,children)){
               //cout<<parent<<" "<<children<<endl;
               if(dfs(make_pair(nx,ny))) return true;
          }
     }
     
     state[ini.first][ini.second] = 2;
     return false;
}

int dfs2(pair<int,int> ini){
     if(dp[ini.first][ini.second] != -1) return dp[ini.first][ini.second];
     int mayor = 0;
     for(int i = 0; i < 4; ++i){
          int nx = ini.first + dx[i];
          int ny = ini.second + dy[i];
          if(nx >= nn || nx < 0 || ny < 0 || ny >= mm)
               continue;
          char children = mytab[nx][ny];
          char parent = mytab[ini.first][ini.second];
          if(valid(parent, children))
               mayor = max(mayor, dfs2(make_pair(nx,ny)));
     }
     return dp[ini.first][ini.second] = mayor + 1;
}



int main(){
     int n,m;
     cin >> n >> m;
     nn = n;
     mm = m;
     for(int i = 0; i < n; ++i){
          for(int j = 0; j < m; ++j){
               cin >> mytab[i][j];
          }
     }
     
     /*pair<int,int> ini;
     int cont = 0;bool flag = false;
     for(int i = 0; i < n; ++i){
          for(int j = 0; j < m; ++j){
               if(mytab[i][j] == 'D'){
                    ini = make_pair(i,j);
                    flag = true;
                    break;
               }
          }
          if(flag)break;
     }*/
     
     for(int i = 0; i < n; ++i){
          for(int j = 0; j < m; ++j){
               state[i][j] = 0;
               dp[i][j] = -1;
          }
     }
     bool flag = false;
     for(int i = 0; i < n; ++i){
          for(int j = 0; j < m; ++j){
               if(!state[i][j] && mytab[i][j] == 'D'){
                    if(dfs(make_pair(i,j))){
                         flag = true;
                         break;
                    }
               }
          }
          if(flag) break;
     }
     if(flag){
          cout<<"Poor Inna!"<<endl;
          return 0;
     }
     int mayor = -1;
     for(int i = 0; i < n; ++i){
          for(int j = 0; j < m; ++j){
               if(mytab[i][j] == 'D')
                   if(dfs(make_pair(i,j))) continue;
                   else mayor = max(mayor, dfs2(make_pair(i,j)));
          }
     }
     if(mayor<4) cout<<"Poor Dima!"<<endl;
     else cout<<(mayor - (mayor%4))/4<<endl; 
     return 0;
}