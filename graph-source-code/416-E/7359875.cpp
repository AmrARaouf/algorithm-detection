//Language: GNU C++0x


#include <iostream>
#include <vector>

int IntMaxVal = (int) 1e20;

#define minimize(a, b) { a = min(a, b); }

using namespace std;

template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }

const int MAXN = 500;

vector<int> allVertices; // helper array to iterate all vertices
int allMinDist[MAXN + 1][MAXN + 1];

class cEdge {
    public:
    
    int v1;
    int v2;
    int len;
};

istream& operator >>(istream& is, cEdge &e) { is >> e.v1 >> e.v2 >> e.len; return is; }

void FloydWarshall(vector<cEdge> &edges) {
    for (auto v1 : allVertices) for (auto v2 : allVertices) allMinDist[v1][v2] = IntMaxVal;
    for (auto v : allVertices) allMinDist[v][v] = 0;
    
    for (auto &edge : edges) {
        allMinDist[edge.v1][edge.v2] = allMinDist[edge.v2][edge.v1] = edge.len;
    }
        
    for (auto v3 : allVertices) for (auto v1 : allVertices) for (auto v2 : allVertices) {
        if (allMinDist[v1][v3] != IntMaxVal && allMinDist[v3][v2] != IntMaxVal) {
            minimize(allMinDist[v1][v2], allMinDist[v1][v3] + allMinDist[v3][v2]);
            allMinDist[v2][v1] = allMinDist[v1][v2];
        }
    }
}

int main() {
    int n; cin >> n;
    int m; cin >> m;
    
    for (int i = 0 ; i < n ; i++) allVertices.push_back(i + 1);
    
    auto edges = readVector<cEdge>(m);

    FloydWarshall(edges);

    int inEdges[n + 1][n + 1];
    for (auto v1 : allVertices) for (auto v2 : allVertices) inEdges[v1][v2] = 0;
    
    for (auto &edge : edges) {
        for (auto v : allVertices) {
            if (allMinDist[v][edge.v1] + edge.len == allMinDist[v][edge.v2]) inEdges[v][edge.v2]++;
            if (allMinDist[v][edge.v2] + edge.len == allMinDist[v][edge.v1]) inEdges[v][edge.v1]++;
        }
    }
                            
    for (auto source : allVertices) {
        for (int j = source + 1 ; j <= n ; j++) {
            int count = 0;
            for (auto mid : allVertices) {
                if (allMinDist[source][mid] + allMinDist[mid][j] == allMinDist[source][j]) count += inEdges[source][mid];
            }
            cout << count << ' ';
        }
    }
}