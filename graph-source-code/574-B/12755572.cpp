//Language: GNU C++


#pragma comment (linker,"/stack:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int N = 4005;
const int M = 40005;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double Pi = acos(-1.0);

#define key_value ch[ch[root][1]][0]
#define lson (i<<1)
#define rson (i<<1|1)

int lowbit(int x) { return x & (-x); }
template < class T > inline T f_min(T a, T b) { return a < b ? a : b; }
template < class T > inline T f_max(T a, T b) { return a > b ? a : b; }
template < class T > inline T f_abs(T a) { return a > 0 ? a : -a; }
template < class T > inline T f_gcd(T a, T b) { return b == 0 ? a : f_gcd(b, a%b); }
template < class T > inline T f_Lcm(T a, T b) { return a / f_gcd(a, b) * b; }
template < class T > inline void f_swap(T &a, T &b) { T t = a;a = b;b = t; }
bool is_digit(char a) { if (a >= '0' && a <= '9')return true;return false; }
bool is_lowch(char a) { if (a >= 'a' && a <= 'z')return true;return false; }
bool is_upch(char a) { if (a >= 'A' && a <= 'Z')return true;return false; }

struct Node{
    int x, y;
}a[N];
int num[N], mp[N][N];
int main(){
    int n, m;
    while(cin >> n >> m){
        memset(num, 0, sizeof(num));
        memset(mp, 0, sizeof(mp));
        for(int i = 0;i < m;++i)cin >> a[i].x >> a[i].y,
            num[a[i].x]++, num[a[i].y]++,
            mp[a[i].x][a[i].y] = mp[a[i].y][a[i].x] = true;
        int ans = INF;
        for(int i = 0;i < m;++i){
            for(int j = 1;j <= n;++j)if(mp[a[i].x][j] && mp[a[i].y][j])
                ans = f_min(ans, num[a[i].x] + num[a[i].y] + num[j] - 6);
        }
        if(ans == INF)  puts("-1");
        else 
            cout << ans << endl;
    }
    return 0;
}
