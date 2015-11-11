//Language: GNU C++


// <editor-fold defaultstate="collapsed" desc="include">
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <list>
using namespace std;
// </editor-fold>
// <editor-fold defaultstate="collapsed">
#define DEBUG() if(_DEBUG)
#define Dprintf DEBUG() printf
#define _DEBUG (__DEBUG && !ONLINE_JUDGE)

typedef vector<int> VI;
typedef long long LL;
typedef pair<int, int> PI;
typedef vector< PI > VPI;
typedef vector< vector<int> > VVI;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define FT first
#define SD second
#define ST first
#define ND second
#define ft FT
#define sd SD
#define MP make_pair
#define BTW(x,a,b) (x >= a && x <= b)
#define ON_MAP(x,n,m) (BTW(x.FT,0,n-1) && BTW(x.SD,0,m-1))
#define TESTS(testName) int __tests; scanf("%d", &__tests); REP(testName, __tests)
#ifndef _BV
#define _BV(bit) ((LL)1<<bit)
#endif
#define SAME_SIGN(a,b) (a>0 && b>0 || a<0 && b<0)
#define DIFF_SIGN(a,b) (a>0 && b<0 || a<0 && b>0)
#define SQUARE(a) ((a)*(a))
#define PITA_SQUARE(a) (SQUARE(a.ft)+SQUARE(b.ft))
#define DIST0(a) PITA_SQUARE(a)
#define EVEN(a) ((a) % 2 == 0)
#define ODD(a) ((a) % 2 == 1)
#define maxUp(x, maxi) maxi = max((x), (maxi))
#define minDown(x, mini) mini = min((x), (mini))
// </editor-fold>
#define __DEBUG 1
#define ONLINE_JUDGE 1
const int INF = 1000000111;
const int LIM = 10000010;
const int S_N = 17;
const int MOD = 1000000007;
const int S_LEN = 9;
// <editor-fold defaultstate="collapsed" desc="debugs">

#define PVAR(x) DEBUG(){ cout << (#x) << ": " << x << "; "; }
template<typename A, typename B>
ostream& operator <<(ostream& out, pair<A, B>& p){
    cout << "(" << p.ft << "," << p.sd << ") ";
}
template<typename A, typename B>
void printP(const pair<A, B>& p, const char* str = NULL){
    if(str != NULL) cout << str << ":";
    cout << "(" << p.ft << "," << p.sd << ") ";
}
template<typename T>
void printV(const vector<T>& v, const char* str = NULL){
    if(str != NULL) cout << str << ": ";
    REP(i, v.size()) cout << v << " ";
    cout << endl;
}

// </editor-fold>
/************************************/ 
typedef pair<int, int> Pnt;

int LEN, n, m;

struct Pos {
    Pnt t[S_LEN];
    Pnt& operator [](int i){ return t[i]; }
    const Pnt& operator [](int i) const { return t[i]; }
    bool operator <(const Pos& b) const {
        REP(i, LEN) if(t[i] != b[i]){
            return t[i] < b[i];
        }
        return false;
    }
    void print(){
        REP(i, LEN) cout << t[i] << "-";
        cout << endl;
    }
    Pnt nHead(PI mv){
        return Pnt(t[0].ft+mv.ft, t[0].sd+mv.sd);
    }
    bool valid(Pnt p){
        REP(i, LEN-1) if(p == t[i]) return false;
        return true;
    }
    Pos create(PI mv){
        Pos v = *this;
        REP(i, LEN-1) v[i+1] = t[i];
        v[0] = nHead(mv);
        return v;
    }
};

Pos start;
char Map[S_N][S_N];

void read(){
    cin >> n >> m;
    DEBUG() cout << n << "; " << m << endl;
    
    REP(r, n){
        string s; cin >> s; DEBUG() cout << s << endl;
        REP(c, m){
            char sign = s[c];
            Map[r][c] = sign;
            if(sign == '#') Map[r][c] = '#';
            else if(sign == '@') Map[r][c] = '@';
            else Map[r][c] = '.';
            if(BTW(sign, '1', '9')){
                start[sign-'1'] = Pnt(r, c);
                maxUp(sign-'0', LEN);
            }
        }
    }
    PVAR(LEN);
    DEBUG() start.print();
}

void solve(){
    read();
    
    map<Pos, int> S;
    queue<Pos> Q;
    Q.push(start);
    S[start] = 0;
    PI DIR[4] = {MP(1, 0), MP(0, 1), MP(-1, 0), MP(0, -1)};
    
    int res = -1;
    while(!Q.empty()){
        Pos u = Q.front(); Q.pop();
        int d = S[u];
        
        DEBUG(){ cout << d << ": "; u.print(); }
        
        REP(i, 4){
            Pnt npos = u.nHead(DIR[i]);
            if(!ON_MAP(npos, n, m) || Map[npos.ft][npos.sd] == '#' || !u.valid(npos)) continue;
            Pos v = u.create(DIR[i]);
            if(S.count(v) == 1) continue;
            
            if(Map[v[0].ft][v[0].sd] == '@') {
                res = d+1;
                break;
            }
            
            S[v] = d+1;
            DEBUG() cout << "D: " << d+1 << " " << S[v] << endl;
            Q.push(v);
        }
        if(res != -1) break;
    }
    cout << res << endl;
}

// <editor-fold defaultstate="collapsed" desc="main">
int main(){
#if (ONLINE_JUDGE)
    solve();
#else
    while(true){
        solve();
        if(cin.peek() == istream::traits_type::eof()) break;
        cout << "---###END OF THE TEST###---" << endl;
    }
    cout << "END OF FILE" << endl;
#endif
    return 0;
}// </editor-fold>
