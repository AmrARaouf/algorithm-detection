//Language: GNU C++


#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <functional>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <queue>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <queue>
#include <list>
#define min(a,b) ((a)<(b) ? (a) : (b))
#define max(a,b) ((a)>(b) ? (a) : (b))
#define forn(i,n) for(ll i=0;i<n;i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef long long ll ;
typedef long double ld;
const int sz = 1500000;
const ll MAX = 10000000000000000;
template<typename T> T abs(T a) { return a < 0 ? -a : a; }
//template<typename T> T min(T aa, T bb) { return (aa<bb ? aa : bb); }


int main()
{
    //freopen("input.txt","r",stdin);
    int n, mm;
    cin>>n>>mm;
    vector<int> c(n);
    ll minZn = MAX;
    forn(i,n)
    {
        cin>>c[i];
        minZn = min(minZn,c[i]);
    }
    vector<vector<int> > graph(n);
    map<int, int> m;
    ll maxMn = 0, minC = MAX;
    map<ll, set<ll> > ans;
    forn(i,mm)
    {
        int u,v;
        cin>>u>>v;

        if(c[u-1]!=c[v-1])
        {
            m[c[u-1]]++;
            m[c[v-1]]++;
            ans[c[u-1]].insert(c[v-1]);
            ans[c[v-1]].insert(c[u-1]);
//            if(maxMn<m[c[u-1]] || (maxMn==m[c[u-1]] && minC>c[u-1]))
//            {
//                maxMn = m[c[u-1]];
//                minC = c[u-1];
//            }

//            if(maxMn<m[c[v-1]] || (maxMn==m[c[v-1]] && minC>c[v-1]))
//            {
//                maxMn = m[c[v-1]];
//                minC = c[v-1];
//            }
        }
    }
    map<ll,set<ll> >::iterator aa;
    int maxV = -1;
    for(map<ll,set<ll> >::iterator b = ans.begin();b!=ans.end();b++)
    {
        if((int)b->second.size()>maxV)
        {
            aa = b;
            maxV = b->second.size();
        }
    }
    if(maxV!=-1)
    cout<<aa->first<<endl;
    else
        cout<<minZn<<endl;
    return 0;
}
