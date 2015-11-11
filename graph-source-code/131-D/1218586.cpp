//Language: GNU C++


#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int visited[3000];
map <int,int> m;
int root = -1;

bool detectcycle (int, const vector <vector<int> > &);
bool dfs(int, int, const vector <vector<int> > &);
int getpathvalue (int, const vector <vector<int> > &);

int main(){

    int n, v1, v2, node;
    cin >> n;
    vector < vector<int> > x(n);
    
    
    for (int i = 0; i < n; i++) visited[i] = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> v1 >> v2;
        x[v1-1].push_back(v2-1);
        x[v2-1].push_back(v1-1);
    }
    
    //for (int i = 0; i < x[0].size(); i++) cout << x[0][i] << " ";
    //cout << endl;
    for (int i = 0; i < n; i++) {

        if (!visited[i]){
            if (detectcycle(i, x)) break;
        }
    }

    //for (int i = 0; i < n; i++) cout << visited[i] << " ";
    //cout << endl << root+1 << endl;
    m.clear();
    dfs(0, root, x);
    //for (int i = 0; i < n; i++) cout << visited[i] << " ";

    //cout << endl;

    queue<int>q;
    for (int i = 0; i < n; i++) if(visited[i]) q.push(i);

    while (!q.empty()){
        node = q.front();
        int dest;
        //cout << node+1 << " ";
        q.pop();
        for (int i = 0; i < x[node].size(); i++) {
            dest = x[node][i];
            if (!visited[dest]) {
                visited[dest] = visited[node]+1;
                //cout << node+1 << " " << dest+1 << " " << visited[node] << " " << visited[dest] << endl;
                q.push(dest);
            }
        }    
    } 
    //cout << endl;
    for (int i = 0; i < n; i++) cout << visited[i]-1 << " ";
    cout << endl;
}

bool detectcycle(int i, const vector <vector<int> > &v) {
    
    //cout << i+1 << " " << visited[i] << endl; 
    int dest, src;
    src = i+1;
    if (visited[i]) {
        root = i;
        return true;
    }

    visited[i] = 1;
    
    for (int j = 0; j < v[i].size(); j++) {
		dest = v[i][j]+1;
		if (m[dest] == src || m[src] == dest) continue;
		//cout << i+1 << " hi" << endl;
		m[dest] = src;
		m[src] = dest;
        bool iscycle = detectcycle(v[i][j], v);
        if (iscycle) return true;
        
    }    
    visited[i] = 0;
    //cout << "!visited " << i+1 << endl;
    return false;
}

bool dfs (int i, int j, const vector <vector<int> > &v) {

    if (i == j) return true;
    int dest, src;
    src = i+1;
    for (int k = 0; k < v[i].size(); k++) {
        dest = v[i][k]+1;
        if (m[dest] == src || m[src] == dest) continue;
        m[dest] = src;
        m[src] = dest;
        bool found = dfs(v[i][k],j,v);
        if (found) visited[i] = 0;
        if (found) return true;
    }
    //cout << i << " " << root << endl;
    return false;
}    
