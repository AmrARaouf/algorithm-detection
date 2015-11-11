//Language: GNU C++


/*
Author : OmarEl-Mohandes
PROG   : E
LANG   : C++
*/
#include <map>
#include <string>
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
#include <memory.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)m;i++)
#define REP(i,k,m) for(int i=k;i<(int)m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
#define oo ((int)1e9)
int main()
{
    //freopen("E.in" , "rt" , stdin);
    //freopen("E.out" , "wt" , stdout);
    int n;
    scanf("%d" , &n);
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    int ii , res = 0;
    REP(i , 1 , n+1){
        int k = n - i;
        if(k*i > res)
        {
            res = k*i;
            ii = i;
        }
    }
    vector<pair<int , int> >a;
    REP(i , 1 , ii+1){
        REP(j , ii+1 , n+1){
            a.pb(mp(i , j));
        }
    }
    cout << a.size() << endl;
    rep(i , a.size())
        cout << a[i].first << " " << a[i].second << endl;

    return 0;
}
