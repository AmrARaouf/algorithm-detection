//Language: GNU C++0x


#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

struct edge {
int vr,sl,ob;
};

int a,v,t,r[500005],b,x,y,k,obr[500005],stt[500005],mar[500005],ya[500005],sa[500005],ihh[500005],ab[500005];

vector<edge> edi[200003];
void dfs(int x) {
    for (stt[x];stt[x]<edi[x].size();stt[x]++) {
        int j=stt[x];
        int to=edi[x][j].vr;
        int in=edi[x][j].sl;
        if (mar[in]==1) continue;
        mar[in]=1;
        dfs(to);
    }
    t++;
    r[t]=x;
}
void add_edge(int x, int y) {
    v++;
    r[v]=x;
    ya[v]=y;
    edi[x].push_back({y,v,0});
    edi[y].push_back({x,v,1});
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> a >> b;
    for (int i=1;i<=b;i++) {
        cin >> x >> y;
        add_edge(x,y);
        sa[x]++;
        sa[y]++;
    }
    for (int i=1;i<=a;i++) {
        if (sa[i]%2==1) {
            k++;
            ab[k]=i;
        }
    }
    for (int i=1;i<=k;i+=2)
        add_edge(ab[i],ab[i+1]);
    if (v%2==1) add_edge(1,1);
    dfs(1);
    cout << v << "\n";
    for (int i=1;i<=t-1;i++)
        if (i%2==0) cout << r[i] << " " << r[i+1] << "\n";
        else cout << r[i+1] << " " << r[i] << "\n";
    return 0;
}
