//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <map>
#include <cctype>
#include <stack>

#define DEBUG 0

#if (DEBUG)
    #define debug(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#else
    #define debug(fmt, ...) 
#endif

#define INFTY 2000000000
#define INFTYLL 4000000000000000000LL
using namespace std;

typedef pair<int,int> pint;
typedef long long int lint;
typedef unsigned int unint;

/* FAST IO ********************** */
char onechar() {
    static const int BUFSIZE = 1<<20;
    static char buf[BUFSIZE], *ptr = buf+BUFSIZE;
    if (ptr == buf+BUFSIZE) fread(ptr = buf, 1, BUFSIZE, stdin);
    return *ptr++;
}
char nextchar() { char c; while (isspace(c=onechar())); return c; }
int nextint() { char c; while (!isdigit(c = onechar())) ;
    int ans = c-'0'; while (isdigit(c = onechar())) ans = ans * 10 + c-'0';
    return ans;
}
string nextstring() {
    char c; string ret; while (!isspace(c = onechar())) ret += c;
    return ret;
}
/* ****************************** */
template <typename T> vector<T>& operator+=(vector<T> &v, const T &e) { v.push_back(e); return v; }
template <typename T> string tobin(T n) { string ret; do ret = char('0'+(n&1)) + ret; while (n /= 2); return ret; }
inline unint nextbitperm(unint mask) {
    unint ile = __builtin_ctz (mask), t = ~(mask>>ile), q = __builtin_ctz (t);
    return ~(((((((t>>q)-1)<<1)+1)<<ile)|((1<<(ile))-1))<<(q-1));
}
#define MP make_pair
#define FRUin for (int i=0; i<n; i++)
#define FRUi(n) for (int i=0; i<(n); i++)
#define FRUj(n) for (int j=0; j<(n); j++)

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */

stack<int> order;
vector<vector<int> > v, rv;
vector<int> vis1, vis2;
inline int &vis(int x) { return x>0 ? vis1[x] : vis2[-x]; }
void dfs(int x, int numer) //numer przy okazji oznacza tryb (==0 ? pierwszy dfs, dorzucaj do stosu : drugi dfs, numeruj składowe)
{
    vis(x) = numer ? numer : true;
//x => y równoważne -y => -x. Czyli szukanie krawędzi z -x'a równoważne szukaniu odwrotnych krawędzi z x
    vector<int> &graph = 
        ((x>0 && numer) || (x<0 && !numer)) 
            ? v[abs(x)]
            : rv[abs(x)]; 
    for (int i=0; i<graph.size(); i++) {
        int y = graph[i] * (x<0?-1:1);
        if (!vis(y)) dfs(y, numer);
    }
    if (!numer) order.push(x);
}
void clear(int newsize) {
    v.clear(); rv.clear(); v.resize(newsize); rv.resize(newsize);
    vis1.clear(); vis2.clear(); vis1.resize(newsize, 0); vis2.resize(newsize, 0);
}
/* inst: wektor par (a,b), oznaczających pojedynczą alternatywę. -a to neg(a). Zmienne numerujemy od 1!! 
Zwraca bool: czy się udało oraz przykłądowe rozwiązanie */
bool solve(const vector<pint>& inst, vector<bool>& sampleresult)
{
    int maxnr = 0;
    for (int i=0; i<inst.size(); i++) maxnr = max(maxnr, max(abs(inst[i].first), abs(inst[i].second)));
    clear(maxnr+1);
    for (int i=0; i<inst.size(); i++) {
        int a = inst[i].first, b = inst[i].second;
        if (a>0) rv[a].push_back(-b); else v[-a].push_back(b);
        if (b>0) rv[b].push_back(-a); else v[-b].push_back(a);
    } //ma mocy uwagi w dfsie, krawędź x => y wystarczy dodać raz
    for (int i=1; i<=maxnr; i++) {
        if (!vis(i)) dfs(i, false);
        if (!vis(-i)) dfs(-i, false);
    }
    for (int i=1; i<=maxnr; i++) vis1[i] = vis2[i] = 0;
    for (int numer=1; !order.empty();) {
        int x = order.top(); order.pop();
        if (vis(x)) continue;
        dfs(x, numer++);
    }
    sampleresult.resize(1+maxnr);
    for (int i=1; i<=maxnr; i++) 
        if (vis(i) == vis(-i)) return false;
        else sampleresult[i] = vis(i) > vis(-i);
    return true;
}

int main(int argc, char **argv) 
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pint> sat;
    for (int i = 1; i <= m; i ++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        if (c == 0) //trzeba jedno z miast wziac  
        {
            sat.push_back(pint(a,b));
            sat.push_back(pint(-a,-b));
        }
        else //albo oba albo zadnego
        {
            sat.push_back(pint(-a,b));
            sat.push_back(pint(a,-b));
        }
    }
    
    vector<bool> solution;
    bool possible = solve(sat, solution);
    if (!possible) printf("Impossible\n");
    else {
        vector<int> tmp;
        solution.resize(n+1, false);
        for (int i = 1; i <= n; i ++) if (solution[i]) tmp.push_back(i);
        printf("%d\n", (int)tmp.size());
        for (int i = 0; i < tmp.size(); i ++) printf("%d ", tmp[i]);
        printf("\n");
    }
    
    
    return 0;
}
