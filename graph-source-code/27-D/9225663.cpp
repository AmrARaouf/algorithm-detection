//Language: GNU C++


#include <iostream>
#include <string>
#include <algorithm>
#define N 102
using namespace std;
int color[N], a[N], b[N], n, m;
bool matched[N][N], doomed;
string ans = " oi";
void dfs(int node){
    for (int i = 0; i < m; i++){
        if (matched[node][i]){
            if (!color[i]){
                color[i] = 3 - color[node];
                dfs(i);
            }
            else
            if (color[i] == color[node]) doomed = 1;
        }
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        if (a[i]>b[i]) swap(a[i], b[i]);
    }
    // segmentation
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            matched[i][j] |= (a[i] > a[j] && b[i] > b[j] && a[i] < b[j]);
            matched[j][i] |= (a[i] > a[j] && b[i] > b[j] && a[i] < b[j]);
        }
    }
    for (int i = 0; i < m; i++){
        if (!color[i]){
            color[i] = 1;
            dfs(i);
        }
    }
    if (doomed){
        cout << "Impossible";
        return 0;
    }
    for (int i = 0; i < m; i++)
        cout << ans[color[i]];
  //  system("pause");
}