//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll ;

const int MAXN = 2*(int)1e5 + 10 ;

int n,L;
vector<int> v ;
int st[MAXN],ed[MAXN];
ll cost[MAXN] ;
map<int,int> num ;
vector< pair<int,pair<int,int> > > e[MAXN] ;
bool visit[MAXN] ;
ll d[MAXN] ;
int pre[MAXN] , px[MAXN] ;

int main(){
    scanf("%d%d",&n,&L);
    v.push_back(0) ; v.push_back(L);
    for (int i=0;i<n;i++){
        int t,p;
        scanf("%d%d%d%d",&st[i],&ed[i],&t,&p);
        ed[i]+=st[i];
        st[i]-=p;
        cost[i] = t+p ;
        v.push_back(st[i]);
        v.push_back(ed[i]);
    }
    sort(v.begin() , v.end()) ;
    int N = 0 ;
    vector<int> list ;
    for (int i = 0 ; i < v.size() ; i++)
        if (i==0 || v[i]!=v[i-1]) num[v[i]] = N++ , list.push_back(v[i]);
    for (int i = 0 ; i < N-1 ; i++)
    {
        e[i].push_back(make_pair(-1,make_pair(i+1,list[i+1]-list[i])));
        e[i+1].push_back(make_pair(-1,make_pair(i,list[i+1]-list[i])));
    }
    for (int i=0;i<n;i++){
        if (st[i]<0) continue ;
        e[num[st[i]]].push_back(make_pair(i+1,make_pair(num[ed[i]],cost[i])));
    }
    priority_queue< pair<ll,int> > q ;
    for (int i = 0 ; i < N ; i++) d[i] = 1000000000LL*1000000000LL ;
    d[num[0]] = 0LL ; q.push(make_pair(0,num[0])) ;
    px[num[0]] = -1 ;
    while (!q.empty()){
        int u = q.top().second ; q.pop() ;
        if (visit[u]) continue ;
        visit[u] = true ;
        for (int i = 0 ; i < e[u].size() ; i++){
            int v = e[u][i].second.first ;
            if (visit[v]) continue ;
            if (d[v] > d[u] + e[u][i].second.second){
                d[v] = d[u] + e[u][i].second.second ;
                px[v] = u ;
                pre[v] = e[u][i].first ;
                q.push(make_pair(-d[v],v));
            }
        }
    }
    cout << d[num[L]] << endl ;
    int x = num[L] ;
    vector<int> res ;
    while (x!=-1){
        if (px[x]==-1) break ;
        if (pre[x]!=-1) res.push_back(pre[x]) ;
        x=px[x] ;
    }
    reverse(res.begin(),res.end()) ;
    printf("%d\n",res.size()) ;
    for (int i = 0 ; i < res.size() ; i++)
        printf("%d ",res[i]);
    printf("\n");
    return 0 ;
}
