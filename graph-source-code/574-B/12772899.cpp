//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define pb push_back

int ar[4000][4000];
int main(){
    memset(ar, 0, sizeof ar);
    int n,m,a,b;
    cin >> n >> m;
    vvi graph(n, vi(0));

    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[a-1].pb(b-1);
        graph[b-1].pb(a-1);
        ar[a-1][b-1] = 1;
        ar[b-1][a-1] = 1;
    }

    int ans = (1<<30);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < graph[i].size(); j++){
            int n1 = graph[i][j];
            if(n1 > i)
                continue;
            for(int k = j+1; k < graph[i].size(); k++){
                int n2 = graph[i][k];
                if(n2 > i)
                    continue;
                if(ar[n1][n2] == 1){
                    int recog = graph[i].size() + graph[n1].size() + graph[n2].size() - 6;
                    ans = min(recog, ans);
                }
            }
        }
    }

    if(ans == (1<<30))
        cout << "-1" << endl;
    else
        cout << ans << endl;
    return 0;
}