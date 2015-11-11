//Language: GNU C++11


#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <iomanip>
#include <vector>
#include <ctime>

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define clr(a, v) memset( a , v , sizeof(a) )
#define pb push_back
#define mp make_pair
#define sz size()
#define FORN( i , s , n ) for( int i = (s) ; i < (n) ; i++ )
#define FOR( i , n ) FORN( i , 0 , n )
#define FORIT( i , x ) for( auto i = x.begin() ; i != x.end() ; i++ )
#define trace(x)    cout << #x << ": " << x << endl;
#define trace2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define read ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef long long int64;
typedef vector <int64> vi;
typedef pair <int64,int64> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

vi T;
map<int, int> M;

void KMP(string s){
    T.resize(s.sz+1,-1);
    FORN(i,1,s.sz+1){
        int pos = T[i-1];
        while(pos!=-1 and s[pos]!=s[i-1]) pos = T[pos];
        T[i] = pos+1;
    }
    int curr = T[s.sz],cont = 1;
    M[s.sz] = 0;
    while(curr!=0){
        M[curr] = cont++;
        curr = T[curr];
    }
}

int64 INF = 2e15;

int main(){
    int N, M, v, w, c;
    cin>>N>>M;
    int64 dis[N][N];
    FOR(i,N) FOR(j,N) if (i==j) dis[i][j] = 0; else dis[i][j] = INF;
    vector< pair<ii,int64> > V(M);
    FOR(i,M){
        scanf("%d %d %d",&v,&w,&c);
        dis[v-1][w-1] = dis[w-1][v-1] = c;
        V[i] = mp( ii(v-1,w-1) ,c);
    }
    FOR(k,N) FOR(i,N) FOR(j, N) dis[i][j] = min (dis[i][j], dis[i][k]+dis[k][j]);
    int aux[N];
    FOR(ini,N){
        clr(aux,0);
        FOR(i,M) {
            v = V[i].fst.fst;
            w = V[i].fst.snd;
            c = V[i].snd;
            if ( dis[ini][v]>dis[ini][w] ) swap(v,w);
            if ( dis[ini][v]+c==dis[ini][w] ) aux[w]++;
        }

        FORN(lst,ini+1,N){
            int ans = 0;
            FOR(k,N) if ( dis[ini][k]+dis[k][lst] == dis[ini][lst] ) ans+=aux[k];
            printf("%d ",ans);
        }

    }
}
