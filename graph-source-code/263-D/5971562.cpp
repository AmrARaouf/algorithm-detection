//Language: GNU C++


/*
 *
 *  Created on: Dec 11, 2013
 *      Author: Ghoooo
 */

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <cassert>
//#include <windows.h>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define reset(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)
#define clrq(x) while(!x.empty()) x.pop();
#define clrvv(v) rep(i,sz(v))v[i].clear();

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;
typedef unsigned long long ull;

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
bool falg = false, print = false;
int n, m, k;
int visited[100010];
int target = -1;
bool rec(int curr, int cnt, vector<vector<int> > & v){
    if(visited[curr]){
        if(cnt-visited[curr] > k){
            target = curr;
            cout << cnt-visited[curr] << endl;
            return true;
        }
        return false;
    }
    visited[curr] = cnt;
    rep(i,sz(v[curr])){
        if(rec(v[curr][i], cnt+1, v)){
            if(target == -1) return true;

            if(print) cout << " " << curr+1;
            else print = 1, cout << curr+1;
            if(curr == target) target = -1;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m >> k;
    vector<vector<int> > adjmat(n);
    int a, b;
    rep(i,m){
        cin >> a >> b;
        adjmat[a-1].push_back(b-1);
        adjmat[b-1].push_back(a-1);
    }
    rec(0,0,adjmat);

    return 0;
}
