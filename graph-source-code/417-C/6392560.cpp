//Language: GNU C++


#include <set>
#include <map>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <bitset>
#include <climits>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <utility>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define PP pair<int, int>
#define MM 101
#define sqr(x) ((x) * (x))
#define ABS(x) ((x < 0) ? -(x) : (x))
#define eps (1e-9)
#define equal(a, b) (ABS(a - b) < eps)
typedef unsigned long long ULL;
typedef long long LL;
typedef pair< int, PP > Edge;

template<class T> string tostring(T x) { ostringstream out; out<<x; return out.str();}
LL toint(string s) { istringstream in(s); LL x; in>>x; return x; }

int main(){
    int n, k;
    cin>>n>>k;
    int s = 0;
    for(int i = 1; i <= n - 1; i++)
        s += i;
    int d = s / n;
    if(d < k) {
        cout<<-1<<endl;
        return 0;
    }
    cout << k * n << endl;
    for(int i = 1; i <= n; i++) {
        int t = i;
        for(int j = 0; j < k; j++) {
            t++;
            if(t % n == 0)
                cout<<i<<" "<<n<<endl;
            else 
                cout<<i<<" "<<t % n<<endl;
            
        }
    }
    return 0;
}