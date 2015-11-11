//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 2000000000
#define MEMSET_INF 127
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

msi stringid;
vi g[200001];
int vis[200001];
int size[200001];
int rs[200001];
int w;
int ord[200001];
vi essay;

bool myComp(int x, int y){
    if(rs[x] != rs[y])  
        return rs[x] < rs[y];
    else
        return size[x] < size[y];
}

void upCase(string &s){
    for (int i = 0; i < s.size(); ++i){
        if (s[i]>='a')
            s[i] -= 'a' - 'A';
    }
}


int countr(string s){
    int total = 0;
    for (int i = 0; i < s.size(); ++i){
        if(s[i] == 'R')
            total++;
    }
    return total;
}

int addString(string &s){
    upCase(s);
    int id = stringid[s];
    if(id == 0){
        w++;
        stringid[s] = w;
        rs[w] = countr(s);
        size[w] = s.size();
        return w;
    }else
        return id;
}

void dfs(int node){
    vis[node] = 1;
    for (int i = 0; i < g[node].size(); ++i){
        if(!vis[g[node][i]]){
            rs[g[node][i]] = rs[node];
            size[g[node][i]] = size[node];
            dfs(g[node][i]);
        }

    }
}

int main(int argc, char const *argv[]){
    int m;
    cin >> m;
    w = 0;
    for (int i = 0; i < m; ++i){
        string s;
        cin >> s;
        essay.pb(addString(s));
    }   

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i){
        string s1, s2;
        cin >> s1 >> s2;
        addString(s1);
        addString(s2);
        g[stringid[s2]].pb(stringid[s1]);
    }

    memset(vis, 0, sizeof vis);

    for (int i = 1; i <= w; ++i){
        ord[i-1] = i;
    }
    sort(ord, ord+w, myComp);

    for (int i = 0; i < w; ++i)
    {
        if(!vis[ord[i]]){
            dfs(ord[i]);
        }
    }

    ll totalr = 0;
    ll totalsize = 0;

    for (int i = 0; i < essay.size(); ++i){
        totalr += rs[essay[i]];
        totalsize += size[essay[i]];
    }

    cout << totalr << " " << totalsize << endl;
    return 0;
}