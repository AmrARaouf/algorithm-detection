//Language: GNU C++


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<climits>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define PII pair<long long,long long>
#define mst(x) memset(x,0,sizeof(x))
#define FOR(x,y,z) for(int x = y; x < z; x++)
#define FER(x,y,z) for(int x=y; x<=z;x++)
#define LL long long
#define x first
#define y second
using namespace std;
LL d[2000][2000],d2[2000][2000];
vector<PII> ta;
vector<PII> w2[2000],w[2000]; // adj list:= (id, weight)
void dij(LL s,LL n, LL D[][2000], vector<PII> W[]){
        priority_queue<PII, vector<PII>, greater<PII> > q;
        FER(i,1,n) D[s][i] = 1LL<<50;
        D[s][s] = 0; q.push( PII(s,0));
        while(!q.empty()){
                PII tmp = q.top(); q.pop();
                LL a = tmp.x, b = tmp.y;
                if(b <= D[s][a]){
                        int l = W[a].size();
                        FOR(i,0,l){
                                if(D[s][a] + W[a][i].y < D[s][W[a][i].x]){
                                        D[s][W[a][i].x] = D[s][a] + W[a][i].y;
                                        q.push( PII(W[a][i].x, D[s][a] + W[a][i].y ) );
                                }
                        }
                }
        }
}

int main(){
        LL n,m,s,t,a,b,c;
        scanf("%I64d%I64d", &n,&m);
        scanf("%I64d%I64d", &s,&t);
        FER(i,1,m){
                scanf("%I64d%I64d%I64d", &a,&b,&c);
                w[a].pb(mp(b,c));
                w[b].pb(mp(a,c));
        }
        ta.pb(PII(-1,-1));
        FER(i,1,n){
                scanf("%I64d%I64d", &a,&b);
                ta.pb(PII(a,b));
        }
        FER(i,1,n)  dij(i,n, d, w);
        FER(i,1,n) FER(j,1,n) if(d[i][j] <= ta[i].x) w2[i].pb(mp(j,ta[i].y));
        dij(s,n,d2,w2);
        if(d2[s][t]!= (1LL<<50))printf("%I64d\n", d2[s][t]);
        else printf("-1\n");
        return 0;
}
