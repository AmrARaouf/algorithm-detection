//Language: GNU C++


# include <stdio.h>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>
# include <assert.h>

using namespace std;

# define SIZE 2000
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
typedef pair<int, PII> TIII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);

#define GI ({int t;scanf("%d",&t);t;})
#define REP(i,a,b) for(int i=a;i<b;i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define ALL(v) (v).begin(),(v).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define PB push_back
#define SZ size()
#define MP make_pair
#define CL clear()
#define fill(ar,val) memset((ar),(val), sizeof(ar))
#define MIN(a,b) {if((a)>(b)) (b);}
#define MAX(a,b) {if((a)<(b)) (b);}
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MT(a,b,c) MP(a, MP(b, c))
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

LL gcd(LL a, LL b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

vector <vector <int> > neighbours(50010);
int new_dist[50010];

int main() {
    int n, r1, r2;
    n = GI;
    r1 = GI;
    r2 = GI;
    for (int i = 1; i < n+1; i++) {
        if (i == r1) continue;
        int b = GI;
        neighbours[b].push_back(i);
        neighbours[i].push_back(b);
    }
    set <int> visited;
    stack <pair <int, int> > states;
    states.push(MP(r2, 1));
    while (states.size() > 0) {
        pair <int, int> curr = states.top();
        states.pop();
        int curr_state = curr.first;
        int curr_cost = curr.second;
        for (int i = 0; i < neighbours[curr_state].size(); i++) {
            if (visited.find(neighbours[curr_state][i]) == visited.end()) {
                states.push(make_pair(neighbours[curr_state][i], curr_cost + 1));
                visited.insert(neighbours[curr_state][i]);
                new_dist[neighbours[curr_state][i]] = curr_state;
            }
        }
    }
    for (int i = 1; i < n+1; i++) {
        if (i == r2) continue;
        cout << new_dist[i] << " ";
    }
    return 0;
}
