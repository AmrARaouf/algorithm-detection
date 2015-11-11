//Language: GNU C++


/* 
 * File:   Road Construction.cpp
 * Author: Abdelgany
 *
 * Created on February 11, 2015, 4:56 PM
 */

#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
vector<vector<int> > adj(1005);

int main(){
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i++)
        if(adj[i].size() == 0){
            cout << n-1 << endl;
            for(int j = 1; j <= n; j++)
                if(i != j)
                    cout << i << " " << j << endl;
            return 0;
        }
}
