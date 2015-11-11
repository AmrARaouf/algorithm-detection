//Language: GNU C++0x


#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> graph[100500];
bool problem[100500];    
int dp[100500];
bool used[100500];

void dfs(int v) {
    used[v] = true;
    for(vector<int>::iterator i = graph[v].begin(); i != graph[v].end(); i++) {
             if (used[*i] == false) {dfs(*i);
             dp[v] += dp[*i];}
    }
    if (problem[v] == true) dp[v]++;
}   
     
    
    
int main() {
    for(int i = 1; i <= 100300; i++) {
            problem[i] = false;
            dp[i] = 0;
            used[i] = false;
    }
    int n;
    scanf("%d", &n);
    int lf, rg, type;
    for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &lf, &rg, &type);
            if (type == 2) problem[lf] = problem[rg] = true;
            graph[lf].push_back(rg);
            graph[rg].push_back(lf);
    }
    dfs(1);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
            if (dp[i] == 1) ans++;
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++) {
            if (dp[i] == 1) cout << i << " ";
    }    
        
                  
                          
                  
    
          
    return 0; 
}
