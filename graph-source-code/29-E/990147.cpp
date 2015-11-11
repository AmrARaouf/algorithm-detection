//Language: GNU C++


#include <queue>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

class State{
public:
    int t, i, j;
    State(int ti, int ii, int ji){
        t = ti;
        i = ii;
        j = ji;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> adj[n];
    for(int k = 0; k < m; k++){
        int i, j;
        cin >> i >> j;
        
        i--;j--;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    
    //do BFS.
    int p[2][n][n];
    memset(p, -1, sizeof p);
    
    bool v[2][n][n];
    memset(v, false, sizeof v);
    v[0][0][n-1] = true;
    
    queue<State> q;
    q.push(State(0, 0, n-1));
    
    
    while(!q.empty()){
        State st = q.front();
        q.pop();
        //cout << st.i << " " << st.j<< " " << st.t << endl;
        
        if(st.t == 0 && st.i == n-1 && st.j == 0){
            vector<int> res[2];
            
            int nowi = n-1, nowj = 0, nowt = 0;
            while(p[nowt][nowi][nowj] != -1){
                if(nowt == 0){
                    res[1].push_back(nowj);
                    
                    nowj = p[nowt][nowi][nowj];
                    nowt = 1 - nowt;
                }else{
                    res[0].push_back(nowi);
                    
                    nowi = p[nowt][nowi][nowj];
                    nowt = 1 - nowt;
                }
            }
            res[0].push_back(0);
            res[1].push_back(n-1);
            
            cout << res[0].size() - 1 << endl;
            for(int i = res[0].size()-1; i >= 0; i--)
                if(i == res[0].size()-1)cout << 1 + res[0][i];
                else cout << " " << 1 + res[0][i];
            cout << endl;
            
            for(int i = res[1].size()-1; i >= 0; i--)
                if(i == res[1].size()-1)cout << 1 + res[1][i];
                else cout << " " << 1 + res[1][i];
                
            cout << endl;
            
            return 0;
        }
        
        if(st.t == 0){
            for(int ii = 0; ii < adj[st.i].size(); ii++){
                int i = adj[st.i][ii];
                //if(i == st.j)continue;
                
                if(!v[1 - st.t][i][st.j]){
                    v[1 - st.t][i][st.j] = true;
                    p[1 - st.t][i][st.j] = st.i;
                    
                    q.push(State(1 - st.t, i, st.j));
                }
            }
        }else{
            for(int ji = 0; ji < adj[st.j].size(); ji++){
                int j = adj[st.j][ji];
                if(j == st.i)continue;
                
                if(!v[1 - st.t][st.i][j]){
                    v[1 - st.t][st.i][j] = true;
                    p[1 - st.t][st.i][j] = st.j;
                    
                    q.push(State(1 - st.t, st.i, j));
                }
            }
        }
    }
    
    cout << -1 << endl;
}
