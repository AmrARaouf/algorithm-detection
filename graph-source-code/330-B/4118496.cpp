//Language: GNU C++


#include <tr1/unordered_map>
#include <set>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace tr1;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair

struct tri{
    int de, para;
    
};


int n, m, vii = 1;
typedef vector < int > vi;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

vector < pair < int, int > > grafo;
vector < pair < int, int >  > grau;
vector < pair < int, int > > resp;

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    int de, para;
    cin >> n >> m;
    grau.resize(n);
    REP(i,n){ grau[i].first = 0; grau[i].second = i; }
    REP(i,m){
        cin >> de >> para;
        grau[de-1].first++;
        grau[para-1].first++;
    }
    sort(ALL(grau));
    cout << n-1 << "\n";
    REP(i,n){
        if( grau[0].second != i )
            cout << grau[0].second + 1 << " " << i+1 << "\n";
    }
    return 0;
}