//Language: GNU C++0x


#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
const int INF = 1000000007;

int cnt;
vector<int> e[100005];
map<PII,vector<PII>> o;
map<PII,int> idx;

PII make(int x, int y){
    if(x<y) return {x,y}; else return {y,x};
}

void gao(int x, int f){
    if(f) idx[make(x,f)]=++cnt;
    for(auto y:e[x]) if(y!=f){
        if(f) o[make(x,f)].push_back(make(y,x));
        gao(y,x);
    }
}

int main(){
    int n,x,y,r;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(r=1;r<=n;r++) if(e[r].size()==1) break;;
    gao(r,0);
    printf("%d\n",idx.size());
    vector<pair<int,PII>> u;
    for(auto& c:idx) u.push_back({c.second,c.first});
    sort(u.begin(),u.end());
    for(auto& c:u) printf("2 %d %d\n",c.second.first,c.second.second);
    for(auto& c:o){
        x=idx[c.first];
        for(auto& v:c.second){
            y=idx[v];
            if(x>y) swap(x,y);
            printf("%d %d\n",x,y);
        }
    }
    
}