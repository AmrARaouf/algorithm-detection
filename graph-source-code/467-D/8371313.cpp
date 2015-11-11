//Language: GNU C++0x


#include <cstdio>
#include <utility>
#include <cctype>
#include <queue>
#include <set>
#include <unordered_map>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
#define FOR(x, b, e) for(int (x)=(b); x<=(e); ++(x))
#define FORD(x, b, e) for(int (x)=(b); x>=(e); --(x))
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
#define PII pair<int, int>

char buf[500*1000+9];
vector<string> All;

void convToLower(char *ptr) {
    while (*ptr) {
        *ptr = tolower(*ptr);
        ptr++;
    }
}

PII getResult(const string &s) {
    PII ret(0, 0);
    for (auto c : s) {
        ret.second++;
        if (c == 'r')
            ret.first++;
    }
    return ret;
}

void explore1(const vector<VI> &LoN, VI &visited, int v, VI &order) {
    visited[v] = 1;

    for (auto &&n : LoN[v]) if (!visited[n])
        explore1(LoN, visited, n, order);
    order.PB(v);
}

PII explore(int repr, const vector<VI> &LoN, VI &visited, const vector<string> &W, int v, const vector<PII> &reprs) {
    visited[v] = repr;
    PII best = getResult(W[v]);

    for (auto &&n : LoN[v]) {
        if (visited[n] == -1)
            best = min(best, explore(repr, LoN, visited, W, n, reprs));
        else if (visited[n] != repr) {
            best = min(best, reprs[visited[n]]);
        }
    }
    return best;
}

int addToGraph(unordered_map<string, int> &M, vector<string> &W, const string &s) {
    W.PB(s);
    int i = W.size() - 1;
    M[W.back()] = i;
    return i;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<string> Ess;
    unordered_map<string, int> M;

    REP(i, N) {
        scanf("%s", buf);
        convToLower(buf);
        string s = buf;
        if (M.count(s) == 0)
            addToGraph(M, All, buf);
        Ess.PB(s);
    }

    int m;
    scanf("%d", &m);

    vector<pair<string, string>> Tmp;
    REP(i, m) {
        pair<string, string> p;

        scanf("%s", buf);
        convToLower(buf);
        p.ST = buf;
        if (M.count(buf) == 0)
            addToGraph(M, All, p.ST);

        scanf("%s", buf);
        convToLower(buf);
        p.ND = buf;
        if (M.count(buf) == 0)
            addToGraph(M, All, p.ND);

        Tmp.PB(p);
    }

    int n = All.size();
    vector<VI> LoN(n);
    vector<VI> rLoN(n);

    for (auto &&p : Tmp) {
        int a = M[p.ST], b = M[p.ND];
        LoN[a].PB(b);
        rLoN[b].PB(a);
    }

    VI order;
    VI visited(n, 0);
    REP(i, n) if (!visited[i])
        explore1(rLoN, visited, i, order);

    REP(i, n)
        visited[i] = -1;

    vector<PII> reprs;
    REP(i, n) {
        int v = order[n - 1 - i];
        if (visited[v] == -1)
            reprs.PB(explore(reprs.size(), LoN, visited, All, v, reprs));
    }

    pair<LL, LL> ans = MP(0, 0);

    REP(i, N) {
        int v = M[Ess[i]];
        PII tmp = reprs[visited[v]];
        ans.ST += tmp.ST;
        ans.ND += tmp.ND;
    }
    cout << ans.ST << " " << ans.ND << endl;
    return 0;
}
