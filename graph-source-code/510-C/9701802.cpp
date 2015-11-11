//Language: GNU C++


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>
#include <cstring>
using namespace std;
int n;
string s1, s2;
int graph[26][26];
int inDegree[26];
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s1;
    for (int i = 0; i < 26; i++) {
        memset(graph[i], 0, sizeof(int) * 26);
    }
    memset(inDegree, 0, sizeof(int) * 26);
    bool orderLogical = true;
    n--;
    while (n--) {
        cin >> s2;
        bool isLogic = false;
        for (int i = 0, j = 0; i < s1.length() && j < s2.length(); i++, j++) {
            if (s1[i] != s2[j]) {
                graph[s1[i] - 'a'][s2[j] - 'a'] = 1;
                isLogic = true;
                break;
            }
        }
        if (!isLogic) {
            orderLogical &= s1.length() <= s2.length();
        }
        s1 = s2;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (graph[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    char res[27];
    int count = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res[count] = (char)(cur + 'a');
        count++;
        for (int i = 0; i < 26; i++) {
            if (graph[cur][i] == 1) {
                graph[cur][i] = 0;
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
        }
    }
    res[26] = '\0';

    if (count == 26 && orderLogical) {
        cout << res << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}
