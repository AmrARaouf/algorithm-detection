//Language: GNU C++


#include <iostream>
#include <vector>
#include <cstring>
#define sz(x) int(x.size())
using namespace std;
const int maxn=11111;
const int maxm=111111;
struct DisjointSet{
    int pa[maxn];
    void makeSet(int n){
        for (int i=0;i<=n;i++) pa[i]=i;
    }
    int findSet(int x){
        if (x!=pa[x]) pa[x]=findSet(pa[x]);
        return pa[x];
    }
    void unionSet(int x,int y){
        x=findSet(x);
        y=findSet(y);
        if (x!=y) pa[x]=y;
    }
}s1,s2;

int n,m;
struct Edge{
    int u,v;
    char c;
};
Edge vec[maxm];
vector<int> e1,e2;
int d;
int main()
{
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>vec[i].u>>vec[i].v>>vec[i].c;
    }
    s1.makeSet(n);
    s2.makeSet(n);
    for (int i=0;i<m;i++){
        if (vec[i].c=='S'){
            if (s1.findSet(vec[i].u)!=s1.findSet(vec[i].v)){
                s1.unionSet(vec[i].u,vec[i].v);
            }
        }
    }
    d=(n-1)/2;
    for (int i=0;i<m;i++){
        if (vec[i].c=='M'){
            if (s1.findSet(vec[i].u)!=s1.findSet(vec[i].v)){
                s1.unionSet(vec[i].u,vec[i].v);
                s2.unionSet(vec[i].u,vec[i].v);
                e1.push_back(i);
                d--;
            }
        }
    }
    for (int i=0;i<m;i++){
        if (vec[i].c=='M'&&d>0){
            if (s2.findSet(vec[i].u)!=s2.findSet(vec[i].v)){
                s2.unionSet(vec[i].u,vec[i].v);
                e1.push_back(i);
                d--;
            }
        }
    }
    for (int i=0;i<m;i++){
        if (vec[i].c=='S'){
            if (s2.findSet(vec[i].u)!=s2.findSet(vec[i].v)){
                s2.unionSet(vec[i].u,vec[i].v);
                e2.push_back(i);
                d--;
            }
        }
    }
    d=(n-1)/2;
    if (sz(e1)!=d||sz(e2)!=d) cout<<-1<<endl;
    else{
        cout<<n-1<<endl;
        for (int i=0;i<sz(e1);i++){
            cout<<e1[i]+1<<" ";
        }
        for (int i=0;i<sz(e2);i++){
            cout<<e2[i]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
