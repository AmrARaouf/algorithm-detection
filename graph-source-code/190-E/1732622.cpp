//Language: GNU C++


#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef set<int> SI;
typedef queue<int> QI;

typedef SI::iterator SIit;

int main(int argc, char *argv[]) {
    int n, m, a, b;
    vector<VI> results;
    vector<PII> edges;
    SI nodes;

    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    // edge set
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--; b--;
        edges.push_back(make_pair(min(a,b), max(a,b)));
    }
    sort(edges.begin(), edges.end());

    // not yet visited nodes
    for (int i = 0; i < n; ++i)
        nodes.insert(i);
    
    // calc connected component for each node not yet used
    while (!nodes.empty()) {
        SIit c_it = nodes.begin();
        int c = *c_it; // connected component starter
        nodes.erase(c_it);

        VI cc; // current connected component
        QI q; // exploration queue
        q.push(c);

        while (!q.empty()) {
            c = q.front(); // current element
            q.pop();
            cc.push_back(c);

            vector<SIit> other; // iterators to set items for removal

            for (SIit it = nodes.begin(); it != nodes.end(); ++it) {
                a = min(c, *it);
                b = max(c, *it);
                if (!binary_search(edges.begin(), edges.end(), make_pair(a, b))) {
                    other.push_back(it);
                    q.push(*it);
                }
            }
        
            // removes CC elements
            vector<SIit>::iterator it;
            for (it = other.begin(); it != other.end(); ++it)
                nodes.erase(*it);
        }
        
        results.push_back(cc);
    }

    // output
    cout << results.size() << endl;
    for (unsigned int i = 0; i < results.size(); ++i) {
        cout << results[i].size();
        for (unsigned int j = 0; j < results[i].size(); ++j)
            cout << ' ' << results[i][j]+1;
        cout << endl;
    }

    return EXIT_SUCCESS;
}
