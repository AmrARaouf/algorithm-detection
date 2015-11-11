//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <numeric>
#include <limits>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define forin(it, col) for(typeof (col).begin() it = (col).begin(); it != (col).end(); it++)
#define range(col) (col).begin(), (col).end()
#define substr(s, from, to) (s).substr((from), (to)-(from))

typedef long long ll;
typedef vector<int> VInt;
typedef vector<VInt> VVInt;
typedef vector<bool> VBool;
typedef vector<VBool> VVBool;
typedef vector<char> VChar;
typedef vector<VChar> VVChar;
typedef pair<int, int> PInt;
typedef vector<PInt> VPInt;
typedef set<int> SInt;
typedef map<int, int> MIntInt;
typedef vector<double> VDouble;
typedef vector<VDouble> VVDouble;

int n;
int p[2001];
int mem[2001];

int get_depth(int i) {
    if(mem[i]!=-1)return mem[i];
    return mem[i]= ((p[i]==-1) ? 0 : (1+get_depth(p[i]-1)));
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &p[i]);

    int ans = 0;
    memset(mem, -1, sizeof mem);
    for(int i=0; i<n; i++) {
        ans = max(ans, get_depth(i)+1);
    }
    printf("%d\n", ans);
    return 0;
}
