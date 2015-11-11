//Language: GNU C++


#include <algorithm>
#include <complex>
#include <exception>
#include <list>
#include <stack>
#include <bitset>
#include <csetjmp>
#include <fstream>
#include <locale>
#include <stdexcept>
#include <cassert>
#include <csignal>
#include <functional>
#include <map>
#include <cctype>
#include <cstdarg>
#include <iomanip>
#include <memory>
#include <streambuf>
#include <cerrno>
#include <cstddef>
#include <ios>
#include <new>
#include <string>
#include <cfloat>
#include <cstdio>
#include <iosfwd>
#include <numeric>
#include <typeinfo>
#include <ciso646>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <utility>
#include <climits>
#include <cstring>
#include <istream>
#include <queue>
#include <valarray>
#include <clocale>
#include <ctime>
#include <iterator>
#include <set>
#include <vector>
#include <cmath>
#include <deque>
#include <limits>
#include <sstream>
 
using namespace std;

#define ull unsigned long long 
#define ll long long
#define rep(a, b, e) for(int a = (int) b; a < (int) e; ++a)
#define clr(a, val) memset(a, val, sizeof(a))
#define debug(a) cerr << #a << ": " << a << endl;
#define debugv(b, t) cerr << #b << ":\n"; rep(countvec, 0, t) { cerr << b[countvec] << '\t'; } cerr << endl;
#define debugm(c, t, u) cerr << #c << ":\n"; rep(countmat, 0, t) { rep(countbb, 0, u) { cerr << c[countmat][countbb] << '\t'; } cerr << endl; }
#define sorta(a) sort(a, 0, sizeof(a))
#define sortv(x) sort((x).begin(),(x).end())
#define sortr(v) sort((v).rbegin(),(v).rend())
#define Node pair< int , int >
#define tam(x) sizeof x / sizeof *x
#define INF 1 << 90
#define MOD 1000000007
#define MAXN 50005
 
int conversion(string p){ int num; num=atoi(p.c_str()); return num; }
string toString(int h){ stringstream ss; ss<<h; return ss.str(); }
long long gcd(long long a,long long b) { return (b==0 ? a : gcd(b,a%b)); }
long long lcm(long long a,long long b) { return (a*(b/gcd(a,b))); }
bool cmp(pair <int ,int> a, pair <int ,int> b) { return a.first > b.first; }

vector< int > v[MAXN];
bool vis[MAXN]; 
int padre[MAXN];

void dfs(int u){
    vis[u] = true;
    for (int i = 0; i < v[u].size(); ++i){
        int hijo = v[u][i];
        if(!vis[hijo]){
            padre[hijo] = u;
            dfs(hijo);
        }
    }
}

void solve(){
    int n, r1, r2; cin >> n >> r1 >> r2;
    for (int i = 0; i < n - 1; ++i){
        int a; cin >> a;
        int num = i;
        if(i >= r1 - 1) num++;
        v[a - 1].push_back(num);
        v[num].push_back(a - 1);
    }
    dfs(r2 - 1);
    for (int i = 0; i < n; ++i){
        if(i != r2 - 1){
            cout << padre[i] + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        ios::sync_with_stdio(true);
        freopen("D:/Sublime/in.txt","r",stdin);
        freopen("D:/Sublime/out.txt","w",stdout);
        clock_t start = clock();
    #endif

        solve();

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start)); 
    #endif
    return 0;
}