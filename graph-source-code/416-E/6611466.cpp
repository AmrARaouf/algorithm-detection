//Language: MS C++


#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <utility>
#include <cstring>

#define sum(x) ((x)*((x)+1)/2)
#define abs(x) (((x)<0 ? -(x) : (x)))
#define min(x,y) (((x) < (y)) ? (x) : (y))
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define printArray(x) {for(int prt=0;prt<x.size();prt++){cout << x[prt] << ',';} cout << endl;}

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m; 
    const int N = 600;
    vector< vector<int> > graph(N);
    vector< vector<int> > dist(N);

    for (int i = 1; i <= n; i++){
        graph[i] = vector< int>(N);
        for (int j = 1; j <= n; j++){
            graph[i][j] = (i == j) ? 0 : (INT_MAX / 3);
        }
    }

    for (int j = 0; j < m; j++){
        int x, y, L;
        cin >> x;
        cin >> y;
        cin >> L;
        graph[x][y] = L;
        graph[y][x] = L;
    }

    for (int i = 1; i <= n; i++){
        dist[i] = vector< int>(N);
        for (int j = 1; j <= n; j++){
            dist[i][j] = graph[i][j];
        }
    }
    //Floyd-Warshall-Algorithm
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    //for (int i = 1; i <= n; i++){
        //for (int j = 1; j <= n; j++){
            //cout << graph[i][j] << " ";
        //}
        //cout << endl;
    //}

    vector<int> edgesEndingIn(N);
    for (int s = 1; s <= n; s++){
        for (int interNode = 1; interNode <= n; interNode++){
            edgesEndingIn[interNode] = 0;
            for (int prevNode = 1; prevNode <= n; prevNode++){
                if (prevNode != interNode){
                    if (dist[s][prevNode] + graph[prevNode][interNode] == dist[s][interNode] && dist[s][interNode] != (INT_MAX/3)){
                        //prevNode lies directly before interNode on shortest path to interNode
                        edgesEndingIn[interNode] ++;
                    }
                }
            }
        }
        for (int t = s + 1; t <= n;t++){
            //Look at all possible internodes
            int edges = 0;
            for (int interNode = 1; interNode <= n; interNode++){
                //On shortest path?
                if (dist[s][interNode] + dist[interNode][t] == dist[s][t]){
                    edges += edgesEndingIn[interNode];
                }
            }
            cout << edges << " ";
        }
    }
    //cin.get();
    //cin.get();
}