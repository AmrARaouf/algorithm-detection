//Language: MS C++


#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
vector<int> roads[100002];
int rep[100002] = { 0 };
int pos[100002] = { 0 };

void search(int p, int prev){
    pos[p] = rep[p];
    for (int i = 0; i < roads[p].size(); ++i){
        if (roads[p][i] == prev) continue;
        search(roads[p][i], p);
        pos[p] += pos[roads[p][i]];
    }
}

int main(){
    int n, x, y, t;
    vector<int> ans;

    cin >> n;
    for (int i = 1; i < n; ++i){
        cin >> x >> y >> t;
        roads[x].push_back(y);
        roads[y].push_back(x);
        if (t == 2){
            rep[x] = 1;
            rep[y] = 1;
        }
    }

    search(1, 0);

    for (int i = 1; i <= n; ++i){
        if (pos[i] == 1){
            ans.push_back(i);
        }
    }

    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i] << endl;
    }

}