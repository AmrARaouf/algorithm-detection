//Language: GNU C++


#include <iostream>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define X first
#define Y second

using namespace std; 

int n, m, p, q;
int x[300000];
int y[300000];
int l[300000];
int next[300000];
int pr[300000];
int u[300000];
int co;
int qu;
int sec;
int qq[300000];
int xx1, xx2;
long long leng[300000];

void dfs(int v){
     u[v] = 1;
     qu++;
     sec = v;
     int i = pr[v];
     while (i){
           leng[co] += (long long)(l[i]);
           if (u[y[i]] == 0) dfs(y[i]);
           i = next[i];
     }
}

    priority_queue<pair<long long, int> > Q;

int main(){
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &x[i], &y[i], &l[i]);
        x[i + m] = y[i];
        y[i + m] = x[i];
        l[i + m] = l[i];
    }
    for (int i = 1; i <= m + m; i++){
        next[i] = pr[x[i]];
        pr[x[i]] = i;
    }
    
    for (int i = 1; i <= n; i++)
        if (u[i] == 0) {
                 co++;                 
                 qu = 0;
                 sec = 0;
                 dfs(i);                 
                 qq[co] = i;
                 if (qu > 1){
                        xx1 = i;
                        xx2 = sec;
                 }
        }
               
    if (co < q){
           cout << "NO\n";
           return 0;
    }
    
    if (q == n){
          if (p == 0){
                cout << "YES\n";
          } else {
                cout << "NO\n";                 
          }
          return 0;
    }
        
    if (co - p > q){
           cout << "NO\n";
           return 0;
    }
    
  // cout << co << endl;
        
    for (int i = 1; i <= co; i++){
        Q.push(mp(-leng[i]/2, qq[i]));
    }
    
    p -= (co - q);    
        
    printf("YES\n");
    for (int i = co - 1; i >= q; i--){
        long long v1 = -Q.top().first;
        int e1 = Q.top().second;
        Q.pop();
        long long v2 = -Q.top().first;
        int e2 = Q.top().second;
        Q.pop();
        printf("%d %d\n", e1, e2);        
        xx1 = e1;
        xx2 = e2;
        Q.push(mp(-min(v1+v2 + 1, 1000000000LL)-v1-v2, e1));
    }
    
    for (int i = 1; i <= p; i++)
        printf("%d %d\n", xx1, xx2);
        
//    system("pause");
    return 0;
}
