//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <climits>
#include <cassert>
#include <string>
#include <bitset>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

#define INF 1000000000
#define LL_INF 4000000000000000000ll
#define EPS (1e-9)

#define Lowbit(x) ((x) & (-(x)))
#define Lc(x) ((x) << 1)
#define Rc(x) (Lc(x) + 1)
#define Pow2(x) (1 << (x))
#define Contain(a, x) ((bool)(a & Pow2(x)))

#define Rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define Til(i, a, b) for(int i = (a); i >= (b); --i)
#define Foru(i, a, b) for(int i = (a); i < (b); ++i)
#define Ford(i, a, b) for(int i = (a); i > (b); --i)

#define It iterator
#define For(i, x) for(__typeof(x.begin()) i = x.begin(); i != x.end(); ++i)

#define Debug(x) (cerr << #x << " = " << (x) << endl)
#define Debug2(x, y) (cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> pii;

template <class T> inline bool Up(T &a, const T &b) { if(a < b) {a = b; return true;} return false; }
template <class T> inline bool Down(T &a, const T &b) { if(a > b) {a = b; return true;} return false; }

inline int getus() { int tmp, c; while(tmp = fgetc(stdin), tmp < '0' || tmp > '9'); tmp -= '0'; while(c = fgetc(stdin), '0' <= c && c <= '9') tmp = tmp * 10 + c - '0'; return tmp; }
inline int getint() { int tmp, c, flag; while(flag = fgetc(stdin), flag != '-' && (flag < '0' || flag > '9')); if(flag == '-') tmp = 0; else tmp = flag - '0'; while(c = fgetc(stdin), '0' <= c && c <= '9') tmp = tmp * 10 + c - '0'; return flag == '-' ? -tmp : tmp; }

struct Node;

int Len = 0;
int N, M, aX = 0, aY = 0;
char G[23][23];
queue<Node> q;
map<Node, int> hash;

struct Node {
    int x[9], y[9];
    bool operator < (const Node &rhs) const {
        for(int i = 0; i < Len; ++i) {
            if(x[i] != rhs.x[i])
                return x[i] < rhs.x[i];
            if(y[i] != rhs.y[i])
                return y[i] < rhs.y[i];
        }
        return false;
    }
    void See() const {
        static char g[23][23];
        Rep(i, 1, N) Rep(j, 1, M)
            g[i][j] = G[i][j];
        Foru(i, 0, Len)
            g[ x[i] ][ y[i] ] = i + '1';
        Rep(i, 1, N) {
            Rep(j, 1, M) putchar(g[i][j]);
            putchar('\n');
        }
        puts("");
    }
} begin;

int main() {
    
    scanf("%d %d", &N, &M);
    Rep(i, 1, N) Rep(j, 1, M) {
        char &c = G[i][j];
        do c = getchar(); while(!isdigit(c) && c != '@' && c != '.' && c != '#');
        if(isdigit(c)) {
            int p = c - '1';
            begin.x[p] = i; begin.y[p] = j;
            Up(Len, p + 1);
            c = '.';
        }
        else if(c == '@') {
            c = '.';
            aX = i; aY = j;
        }
    }
//    begin.See();
    
    const static int dirX[] = {0, 1, -1, 0};
    const static int dirY[] = {1, 0, 0, -1};
    for(hash[begin] = 0, q.push(begin); !q.empty(); ) {
        Node lastNode(q.front()); q.pop();
        int x = lastNode.x[0], y = lastNode.y[0], step = hash[lastNode];
/*
        puts("Out Queue");
        lastNode.See();
*/
        for(int d = 0; d <= 3; ++d) {
            int xx = x + dirX[d], yy = y + dirY[d];
            if(!(1 <= xx && xx <= N)) continue;
            if(!(1 <= yy && yy <= M)) continue;
            if(G[xx][yy] == '#') continue;
            bool good = true;
            for(int i = 1; i < Len - 1; ++i)
                if(xx == lastNode.x[i] && yy == lastNode.y[i]) {
                    good = false;
                    break;
                }
            if(!good) continue;
            Node newNode(lastNode);
            newNode.x[0] = xx;
            newNode.y[0] = yy;
            for(int i = 1; i < Len; ++i) {
                newNode.x[i] = lastNode.x[i - 1];
                newNode.y[i] = lastNode.y[i - 1];
            }
            if(hash.count(newNode)) continue;
/*
            puts("In Queue");
            newNode.See();
*/          
            hash.insert(make_pair(newNode, step + 1));
            q.push(newNode);
            if(xx == aX && yy == aY) {
                printf("%d\n", step + 1);
                return 0;
            }
        }
    }
    puts("-1");
//    cerr << clock() << endl;
    return 0;
}
