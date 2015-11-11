//Language: GNU C++


#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

vector < int > g[110]; // граф
int n; // число вершин

//vector<int> color; // цвет вершины (0, 1, или 2)
vector<int> cl[100][100];
//vector<int> time_in, time_out; // "времена" захода и выхода из вершины
int dfs_timer = 0; // "таймер" для определения времён
int to, ans;
int used[102][103];

void dfs (int v, int color) {
    //time_in[v] = dfs_timer++;
    //color[v] = 1;
    if(color!=-1)used[v][color]=1;
    else {
        memset(used[v], 1, sizeof(used[v]));
    }
    //cout<<v<<" "<<color<<endl;
    if(v == to){
        ans++;
        return;
    }
    vector<int>::iterator i;
    for (i=g[v].begin(); i!=g[v].end(); ++i){
        
        if(color == -1){
            for(int j=0; j<cl[*i][v].size();j++){
                   if(!used[*i][cl[*i][v][j]]) dfs (*i,cl[*i][v][j]);
            }
        } else {
            for(int j=0; j<cl[*i][v].size();j++){
                if(cl[*i][v][j] == color && !used[*i][color]){
                    dfs (*i,color);
                }
            }
        }
    }
    
   // color[v] = 2;
    //time_out[v] = dfs_timer++;
}


int main()
{
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        cin>>c;
        a--;
        b--;
        
        cl[a][b].push_back(c);
        cl[b][a].push_back(c);
        g[a].push_back(b);
        g[b].push_back(a);
        
    }
    int q;
    cin>>q;
    while(q--){
        cin>>a>>to;
        a--;
        to--;
        ans=0;
        memset(used, 0 , sizeof(used));
        dfs(a,-1);
        cout<<ans<<endl;
        
    }
    
 
    return 0;
}




