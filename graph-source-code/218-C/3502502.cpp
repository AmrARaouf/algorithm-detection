//Language: MS C++


#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <math.h>
#include <sstream>
#include <stack>

#define REP(i, to) for(size_t i = 0; i < to; i++)
#define DOWNTO(i, to) for(size_t i = to; i >= 0; i--)
#define ZERO(a) memset((a), 0, sizeof(a))
typedef long long LL;
typedef std::vector<int> VI ;
typedef std::vector<LL> VL ;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
typedef std::vector<PII> VPII;
typedef std::vector<PLL> VPLL;
template<class T> const T& min(const T& a, const T& b, const T& c) { return min(a, min(b, c));}
template<class T> const T& max(const T& a, const T& b, const T& c) { return max(a, max(b, c)); }
template<class T> std::string toStr(T t);
 
using namespace std;

// 1 - first node
class Graph {

public:
    typedef vector<size_t> vset;

private:
    vector<vset> edges;
    vector<vset> redges;
    bool inReversedSide;
    vector<bool> lastDfsVisited;
    
    void checkVertexesRanges(size_t vetrtexIndex){
        if (edges.size() <= vetrtexIndex + 1) {
            edges.resize(vetrtexIndex + 1);
            redges.resize(vetrtexIndex + 1);
        }
    }

public:

    Graph(size_t prelim_size = 15):inReversedSide(true) {
        edges.resize(prelim_size + 1);
        redges.resize(prelim_size + 1);
    }

    void addEdge(size_t from, size_t to) {
        checkVertexesRanges(max(from, to));
        edges.at(from).push_back(to);
        redges.at(to).push_back(from);
    }

    void toggleReverseSide() {
        inReversedSide = !inReversedSide;
    }

    const vset& friendsFrom(size_t from) {
        checkVertexesRanges(from);
        if (inReversedSide)
            return edges.at(from);
        else
            return redges.at(from);
    }

    const vset& friendsTo(size_t to) {
        checkVertexesRanges(to);
        if (!inReversedSide)
            return edges.at(to);
        else
            return redges.at(to);
    }
    
    void dfs(size_t from, vector<size_t>& connected) {
        lastDfsVisited.resize(edges.size());
        if(lastDfsVisited.at(from)) return;
        stack<size_t> unexplored;
        unexplored.push(from);
        while (!unexplored.empty()) {
            size_t current = unexplored.top();
            lastDfsVisited[current] = true;
            connected.push_back(current);
            unexplored.pop();
            const vset& friends = friendsFrom(current);

            REP(i, friends.size()){
                size_t v = friends.at(i);
                if (lastDfsVisited[v]) continue;
                lastDfsVisited[v] = true;
                unexplored.push(v);
            }
        }
        
        //REP(i, connected.size()) lastDfsVisited.at(connected.at(i)) = false;

    }

};


int main() {
    
    size_t n;
    cin >> n;
    VPII dots;
    REP(i,n){
        int x, y;
        cin >> x >> y;
        dots.push_back(make_pair(x,y));
    }

    Graph g(n);
    REP(i, n){
        REP(j,n){
            if(j==i) continue;
            if(dots[i].first == dots[j].first || dots[i].second == dots[j].second){
                g.addEdge(i,j);
                
            }
        }
    }
    
    int count = 0;
    REP(i,n){
        Graph::vset visited;
        g.dfs(i, visited);
        if(!visited.empty()) count++;
    }

    cout << count - 1;

}


template<class T>
string toStr(T t){
    std::stringstream strstream;
    string resStr;
    strstream << t;
    strstream >> resStr;
    return resStr;
}
