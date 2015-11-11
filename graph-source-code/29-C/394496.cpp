//Language: MS C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <numeric>
#include <functional>
#include <set>
#include <cmath>
#include <stack>
#include <fstream>
#include <cassert>
#ifdef HOME_PC
#include <ctime>
#endif
using namespace std;

#pragma comment(linker,"/stack:16000000")
#pragma warning (disable : 4996)

#define ALL(v) v.begin(),v.end()
#define SZ(v) (int)v.size()
#define mset(A,x) memset((A),(x),sizeof(A))
#define FOR(i,start,N) for(int i=(start);i<(N);++i)
#define FORSZ(i,start,v) FOR(i,start,SZ(v))
#define REPSZ(i,v) FORSZ(i,0,v)
#define FORE(i,start,N) FOR(i,start,N+1)
#define make_unique(v) v.resize(unique(ALL(v))-v.begin())
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define adebug(A,N) FOR(i,0,N) cout<<#A<<"["<<i<<"] = "<<A[i]<<endl;
#define adebug2d(a,n,m) FOR(i,0,n) { FOR(j,0,m) { cout<<a[i][j]<<" ";} cout<<endl;}
#define vdebug(v) REPSZ(i,v) cout<<#v<<"["<<i<<"] = "<<v[i]<<endl;
#define selfx(x,f,a) x = f(x,a)
#define sqr(x) ((x)*(x))


typedef pair<int,int> pii;
typedef long long i64;
typedef vector<int> VI; typedef vector< vector<int> > VVI;
typedef vector<string> VS;

const int inf = 1<<25;
const double eps = 1e-9;

int main()
{
#ifdef HOME_PC
    //freopen ("input.txt","r",stdin);
    //freopen ("in.txt","r",stdin);
    //freopen ("output.txt","w",stdout);
#endif

    map<int, VI > adj;
    int n;
    cin>>n;
    FOR(i,0,n)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = -1;
    for(map<int,VI>::iterator it = adj.begin(); it != adj.end(); ++it)
        if(it->second.size() == 1)
        {
            root = it->first;
            break;
        }

    int u = root;
    int p = -1;
    do 
    {
        printf("%d ",u);
        int tu = u;
        if( u == root)
            u = adj[u][0];
        else
        {
            int v1 = adj[u][0], v2 = adj[u][1];
            u = v1 == p?v2:v1;
        }
        p = tu;
    } while (adj[u].size()>1);

    if(u!=root)
        printf("%d\n",u);


#ifdef HOME_PC
    cerr<<endl<<"Execution time = "<<clock()<<" ms"<<endl;
#endif
    return 0;
}

