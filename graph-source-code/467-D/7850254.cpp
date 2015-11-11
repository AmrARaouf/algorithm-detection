//Language: GNU C++


#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <bitset>
#include <algorithm>

#define forit(it,S) for(__typeof(S.begin()) it = (S).begin(); it != (S).end(); it++)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);

const int maxn = (int)5e5 + 10;

map<string, vector<string> > g;
vector<string> cur;
map<string, pii> res;

int R(string s) {
    int n = 0;
    for (int i = 0; i < sz(s); i++) {
        n += s[i] == 'r';
    }
    return n;
}

void norm(string &s) {
    for (int i = 0; i < sz(s); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
}

bool cmp(string s1, string s2) {
    int n1 = R(s1);
    int n2 = R(s2);
    if (n1 < n2) return true;
    if (n1 > n2) return false;
    return sz(s1) < sz(s2);
}

void dfs(string s, int x, int y) {
    res[s] = mp(x,y);
    for (int i = 0; i < sz(g[s]); i++) {
        string t = g[s][i];
        if (!res.count(t)) {
            dfs(t,x,y);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int m; cin >> m;

    set<string> st;

    vector<string> v;

    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        norm(s);
        v.pb(s);
        st.insert(s);
    }

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string s1,s2; cin >> s1 >> s2;
        norm(s1);
        norm(s2);
        g[s2].pb(s1);
        st.insert(s1);
        st.insert(s2);
    }
    

    forit(it,st) {
        cur.pb(*it);
    }

    sort(all(cur),cmp);

    for (int i = 0; i < sz(cur); i++) if (!res.count(cur[i])) {
        dfs(cur[i],R(cur[i]),sz(cur[i]));
    }

    long long X = 0;
   	long long Y = 0;

    for (int i = 0; i < sz(v); i++) {
        X += res[v[i]].first;
        Y += res[v[i]].second;
    }

    cout << X << " " << Y << endl; 



    return 0;
}