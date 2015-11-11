//Language: GNU C++


/*
 * Author: Gatevin
 * Created Time:  2014/6/1 22:37:11
 * File Name: hehe.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rise(i, a, b) for (int i = (a); i <= (b); i++)
#define fall(i, a, b) for (int i = (a); i >= (b); i--)
#define clrs( x , y ) memset( x , y , sizeof(x) )

struct Node{
    int id;
    int v;
};

int n,m;
Node node[1010];
int p[1010];
int f[1010][1010];

bool cmp(Node a, Node b) {
    return b.v < a.v;
}

int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n ; i++) {
        cin>>p[i];
        node[i].v = p[i];
        node[i].id = i;
    }
    sort(node +1,node + n + 1,cmp);
    for (int i = 1; i <= m ; i++) {
        int x,y;
        cin>>x>>y;
        f[x][y] = 1;
        f[y][x] = 1;
    }
    int answer = 0;
    for (int i = 1 ; i <= n; i++) {
        int x = node[i].id;
        for (int j = 1 ; j <= n; j++) 
            if ( f[x][j] ) {
                answer += p[j];
                f[x][j] = 0;
                f[j][x] = 0; 
            }
    }
    cout<<answer<<endl;
}
