//Language: GNU C++11


#include<stdio.h>
#include<set>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MX = 100005;

struct UF{
    int p[MX];
    int find(int x){ return p[x] == 0? x: p[x] = find(p[x]); }
    bool merge(int x, int y){
        x = find(x), y = find(y);
        if( x == y ) return false;
        p[x] = y; return true;
    }
} uf, uf2;

struct edge{
    int A, B, d, ad;
    bool operator<(const edge &l)const{
        return d < l.d;
    }
};

edge D[MX];
int ans[MX], store[MX];
map<int, vector<pii> > G;
map<int,int> ti;
set<int> chk;
int vst = 0;
 
int dfs(int x) {
    if( ti.count(x) ) return ti[x];
    int res = ti[x] = ++vst;
    for(pii c : G[x]){
        int ad = c.second, e = c.first;
        if( chk.count(ad) ) continue;
        chk.insert(ad);
        int r = dfs(e);
        res = min(res, r);
        if( r > ti[x] ) ans[ad] = 2;
    }
    return res;
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) scanf("%d%d%d", &D[i].A, &D[i].B, &D[i].d), D[i].ad = i;
    sort(D, D+M);
    for(int i = 0, j = 0; i < M; i = j){
        G.clear(); chk.clear(); ti.clear();
        for(; D[i].d == D[j].d; j++){
            int A = D[j].A, B = D[j].B, d = D[j].ad;;
            int x = uf.find(A), y = uf.find(B);
            if( x != y ){
                G[x].push_back(pii(y, d));
                G[y].push_back(pii(x, d));
                ans[d] = 1;
            }
        }

        for(auto it : G) dfs(it.first);

        for(int k = i; k < j; k++){
            int A = D[k].A, B = D[k].B;
            uf.merge(A, B);
        }
    }

    for(int i = 0; i < M; i++){
        if( ans[i] == 0 ) printf("none\n");
        else if( ans[i] == 1 ) printf("at least one\n");
        else printf("any\n");
    }
    return 0;
}
