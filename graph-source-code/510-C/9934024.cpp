//Language: GNU C++0x


#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        names[i] = s;
    }
    unordered_set<char> out_edges[26];
    unordered_set<char> in_edges[26];
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < names[i].length(); ++j) {
            if (names[i + 1].length() <= j) {
                cout << "Impossible";
                return 0;
            }
            char source_index = names[i][j] - 'a';
            char target_index = names[i + 1][j] - 'a';
            if (names[i][j] != names[i + 1][j]) {
                out_edges[source_index].insert(target_index);
                in_edges[target_index].insert(source_index);
                break;
            }
        }
    }
    queue<char> sources;
    for (int i = 0; i < 26; ++i) {
        if (in_edges[i].empty())
            sources.push(i);
    }
    string ans;
    while (!sources.empty()) {
        char source = sources.front();
        ans.push_back(source + 'a');
        for (auto it = out_edges[source].begin(); it != out_edges[source].end(); ++it) {
            char target = *it;
            in_edges[target].erase(source);
            if (in_edges[target].empty())
                sources.push(target);
        }
        sources.pop();
    }
    if (ans.length() == 26)
        cout << ans;
    else
        cout << "Impossible";
}