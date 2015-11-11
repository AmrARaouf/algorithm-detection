//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<sstream>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<bitset>
#include<cctype>
#include<ctime>
using namespace std;

typedef long long ll;
#define INF (long long)1e12+3LL
#define EPS 1e-11
#define PI acos(-1)
#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define FORV(i,vt) for(size_t i = 0; i < vt.size(); ++i)
#define siz(x) (int)x.size()
#define pb push_back
#define m_p make_pair
#define pii pair<int,int>
#define pss pair<string, string>
#define psi pair<string, int>
#define mpsr make_pair(sender, receiver)
#define mprs make_pair(receiver, sender)

struct Coder {
    int idx;
    int a;
    int h;
    int nIBetter;
    Coder() {
        idx = 0;
        a = 0;
        h = 0;
        nIBetter = 0;
    }
    void display() {
        cout << idx << " " << a << " " << h << endl;
    }
};

struct TimeFormat {
    int hour;
    int minute;
    TimeFormat() {
    }
    void display() {
        cout << hour << ":";
        if (minute < 10) {
            cout << "0" << minute;
        } else
            cout << minute;
    }
};

struct Appointment {
    TimeFormat start;
    TimeFormat end;
    string name;
    Appointment() {
    }

};

TimeFormat dist(TimeFormat a, TimeFormat b) {
    int minutea = a.hour * 60 + a.minute;
    int minuteb = b.hour * 60 + b.minute;
    int d = minuteb - minutea;
    TimeFormat ret;
    ret.hour = d / 60;
    ret.minute = d % 60;
    return ret;
}

bool cmpTimeFormat(TimeFormat a, TimeFormat b) {
    if (a.hour != b.hour) {
        return a.hour < b.hour;
    }
    return a.minute < b.minute;
}

bool cmpAppointment(Appointment a, Appointment b) {
    return cmpTimeFormat(a.start, b.start);
}

int myabs(int x) {
    return x < 0 ? -x : x;
}
int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int toInt(char xx) {
    return xx - '0';
}

char toChar(int xx) {
    return xx + '0';
}

bool isNum(char xx) {
    return ('0' <= xx && xx <= '9');
}

bool isCharacter(char xx) {
    return (('a' <= xx && xx <= 'z') || ('A' <= xx && xx <= 'Z'));
}

bool isUpper(char xx) {
    return ('A' <= xx && xx <= 'Z');
}

bool isLower(char xx) {
    return ('a' <= xx && xx <= 'z');
}

bool isPalin(string x) {
    int len = x.length();
    REP(i,0,len/2) {
        if (x[i] != x[len - 1 - i])
            return false;
    }
    return true;
}

void swapInt(int &x, int &y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

string tolowerStr(string x) {
    string ret = "";
    FOR(i,0,siz(x)) {
        ret.pb(tolower(x[i]));
    }
    return ret;
}

string toupperStr(string x) {
    string ret = "";
    FOR(i,0,siz(x)) {
        ret.pb(toupper(x[i]));
    }
    return ret;
}
template<class T>
bool isInArray(T x, vector<T> vt) {
    FOR(i,0,siz(vt)) {
        if (vt[i] == x) {
            return true;
        }
    }
    return false;
}
string trim(string x) {
    int l = 0, r = x.size() - 1;
    char arr[] = { '\f', '\v', '\t', '\r', '\n', ' ' };
    vector<char> delimiter(arr, arr + sizeof(arr) / sizeof(char));
    while (isInArray(x[l], delimiter)) {
        l++;
    }
    while (isInArray(x[r], delimiter)) {
        r--;
    }
    return x.substr(l, r - l + 1);
}

vector<string> getToken(string x, vector<char> tokens) {
    int icounter = 0, lastIndex = x.length() - 1;
    vector<string> ret;
    for (;;) {
        string tmp = "";
        while (icounter <= lastIndex && isInArray(x[icounter], tokens))
            icounter++;
        while (icounter <= lastIndex && !isInArray(x[icounter], tokens)) {
            tmp.pb(x[icounter]);
            icounter++;
        }
        if (tmp.length() > 0)
            ret.pb(tmp);
        if (icounter > lastIndex)
            break;
    }
    return ret;
}

inline void clear_buffer() {
    string tmp;
    getline(cin, tmp);
}

bool cmp(Coder x, Coder y) {
    if (x.a != y.a) {
        return x.a < y.a;
    }
    if (x.h != y.h) {
        return x.h < y.h;
    }
    return x.idx < y.idx;
}

ll val(ll x) {
    if (x < 0)
        return -x;
    return x;
}

int nextIndexInCircle(int n, int currentPosition, int firstPointIndex) {
    if (firstPointIndex == 0) {
        return (currentPosition + 1) % n;
    } else {
        if (currentPosition == n - 1) {
            return n;
        } else {
            return (currentPosition + 1) % n;
        }
    }
}
const int bfsz = 1 << 16;
char bf[bfsz + 5];
int rsz = 0;
int ptr = 0;

char gc() {
    if (rsz <= 0) {
        ptr = 0;
        rsz = fread(bf, 1, bfsz, stdin);
        if (rsz <= 0)
            return EOF;
    }
    --rsz;
    return bf[ptr++];
}

void ga(char &c) {
    c = EOF;
    while (!isalpha(c))
        c = gc();
}

int gs(char s[]) {
    int l = 0;
    char c = gc();
    while (isspace(c))
        c = gc();
    while (c != EOF && !isspace(c)) {
        s[l++] = c;
        c = gc();
    }
    s[l] = '\0';
    return l;
}

template<class T> bool gi(T &v) {

    v = 0;
    char c = gc();
    while (c != EOF && c != '-' && !isdigit(c))
        c = gc();
    if (c == EOF)
        return false;
    bool neg = c == '-';
    if (neg)
        c = gc();

    while (isdigit(c)) {
        v = v * 10 + c - '0';
        c = gc();
    }
    if (neg)
        v = -v;
    return true;

}

template<class T> inline void checkmin(T &a, T b) {
    if (b < a)
        a = b;
}

/* example of very quick - read :
 * read int : gi(n) <=> scanf("%d",&n);
 * read char : ga(x) <=> scanf("%c",&x);
 */

/** Segment Tree store MAX value **/
void st_build(vector<int> &t, vector<int> data, int node, int l, int r) {
    if (l == r) {
        t[node] = l;
        return;
    }
    int mid = (l + r) / 2;
    st_build(t, data, 2 * node, l, mid);
    st_build(t, data, 2 * node + 1, mid + 1, r);
    int datal = data[t[2 * node]];
    int datar = data[t[2 * node + 1]];
    if (datal > datar) {
        t[node] = t[2 * node];
    } else {
        t[node] = t[2 * node + 1];
    }
}

void st_create(vector<int> &t, const vector<int> &data) {
    int n = data.size();
    int len = (int) (2 * pow(2.0, floor((log((double) n) / log(2.0)) + 1)));
    t.assign(len, 0);
    st_build(t, data, 1, 0, n - 1);
}

int st_query(vector<int>& t, vector<int>& data, int node, int l, int r, int i,
        int j) {
    /*
     * This function return index of element , not value of element!
     */
    if (r < i || j < l)
        return -1;
    if (l == r) {
        return l;
    }
    if (l >= i && r <= j) {
        return t[node];
    }
    int mid = (l + r) / 2;
    int tl = st_query(t, data, 2 * node, l, mid, i, j);
    int tr = st_query(t, data, 2 * node + 1, mid + 1, r, i, j);

    if (tl == -1)
        return tr;
    if (tr == -1)
        return tl;

    if (data[tl] > data[tr]) {
        return tl;
    } else {
        return tr;
    }
}

int st_update(vector<int> &t, vector<int> &data, int node, int l, int r,
        int idx, int newVal) {
    if (l > idx || idx > r) {
        return -1;
    }
    if (l == r) {
        if (l == idx) {
            data[idx] = newVal;
            return idx;
        } else {
            return l;
        }
    }
    int mid = (l + r) / 2;
    int tl = st_update(t, data, 2 * node, l, mid, idx, newVal);
    int tr = st_update(t, data, 2 * node + 1, mid + 1, r, idx, newVal);
    if (tl == -1) {
        t[node] = tr;
        return tr;
    }
    if (tr == -1) {
        t[node] = tl;
        return tl;
    }
    if (data[tl] > data[tr]) {
        t[node] = tl;
        return tl;
    } else {
        t[node] = tr;
        return tr;
    }
}

/*** Fenwick Tree store FREQUENCY value ***/
#define LSOne(S) (S & (-S))
#define maxVal 100001
void ft_create(vector<int> &t, int n) {
    t.assign(n + 1, 0);
}

int ft_get(vector<int> &t, int idx) {
    int ret = 0;
    while (idx > 0) {
        ret += t[idx];
        idx -= LSOne(idx);
    }
    return ret;
}

void ft_update(vector<int> &t, int idx) {
    int incrementValue = 1;
    while (idx < maxVal) {
        t[idx] += incrementValue;
        idx += LSOne(idx);
    }
}

/*** IMPLEMENTATION ***/

const int maxn = 1e3 + 3;
int n, m;
int x, y;
long long w[maxn][maxn];
long long t[maxn], c[maxn];
long long d[maxn][maxn], ret[maxn];
vector<int> adj[maxn];
bool checked[maxn];

void readEachTest() {

}

void solveEachTest() {

}

void dijikstra(vector<int> adj[maxn], long long w[maxn][maxn], long long d[maxn][maxn], bool checked[maxn], int n, int org, bool print = false) {
    REP(i,1,n) checked[i] = false;
    REP(i,1,n){
            d[org][i] = (i == org ? 0LL : INF);
    }
    priority_queue<pair<long long , int> > pq; 
    pq.push(make_pair(0,org));
    
    while(!pq.empty()){
        pii tmppii = pq.top();
        pq.pop();
        int j = tmppii.second;
        if(!checked[j]){
        
        checked[j] = true;
                        
            FOR(k,0,siz(adj[j])){
                
                int i = adj[j][k];
                
                if(!checked[i]){
                    //if(print && i == 4){
//                        printf("\n ***come from %d, before relax : d[ %d %d] = %lld *** \n\n",j,org,i,d[org][i]);
//                    }
                    
                    d[org][i] = min(d[org][i], d[org][j] + w[j][i]);    
                    
                   // if(print && i == 4){
//                        printf("\n ***after relax : d[ %d %d] = %lld *** \n\n",org,i,d[org][i]);
//                    }                      
                }
                
                if(!checked[i]){
                    pq.push(make_pair(-d[org][i],i));
                }
            }
        }
    }    
}


void read() {
    cin >> n >> m;
    cin >> x >> y;

    REP(i,1,n) {
        ret[i] = (i == x ? 0 : INF);
        REP(j,1,n) {
            w[i][j] = (i == j ? 0 : INF);
            d[i][j] = (i == j ? 0 : INF);
        }
    }
    int u, v;
    long long ww;
    REP(i,1,m) {
        cin >> u >> v >> ww;
        w[u][v] = min(w[u][v], ww);
        w[v][u] = min(w[v][u], ww);

        adj[u].pb(v);
        adj[v].pb(u);
    }

    REP(i,1,n) {
        cin >> t[i] >> c[i];
    }
}

void init() {

}
void bfs() {
    REP(i,1,n)
        ret[i] = INF;
    ret[x] = 0;    
}

void solve() {
    REP(i,1,n){
        dijikstra(adj,w,d,checked,n,i);
    }
    
   // REP(i,1,n)
//        REP(j,1,n)
//            printf("shortest path from vertext %d to %d is %lld\n",i,j,d[i][j]);

            
            
    REP(i,1,n){
        REP(j,1,n){
            if(i != j){
                if(d[i][j] == INF || d[i][j] > t[i]){
                    w[i][j] = INF;
                }
                else {                    
                    if(w[i][j] == INF) {
                        // two node i, j has not connected yett
                        adj[i].pb(j);
                    }
                    w[i][j] = c[i];
                }
            }
           // printf("w[%d][%d] = %lld\n",i,j,w[i][j]);
        }
    }        
    
    dijikstra(adj,w,d,checked,n,x);
    if (d[x][y] == INF) {
        cout << "-1\n";
    } else {
        cout << d[x][y] << endl;
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read();
    init();
    solve();
    return 0;
}
