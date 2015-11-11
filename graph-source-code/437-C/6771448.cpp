//Language: GNU C++


#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>

#define LL long long
#define MX 5000+7
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

struct Z
{
    int a;
    int b;
    LL c;
    Z() {}
    Z(int w,int bb, LL  in)
    {
        a=w;
        b = bb;
        c =in;
    }
};

bool operator<(Z A, Z B)
{
    if(A.b == B.b) return A.c>B.c;
    return A.b<B.b;
}

int arr[1001];
int cost[1001];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,m,u,v;
    cin>>n>>m;
    vector<int>V[100001];
    for(int i =0 ; i<100001; i++)
        V[i].clear();


    for(i = 1; i <= n; i++)
        cin>>arr[i];
    for(i = 0; i < m; i++)
    {
        cin>>u>>v;
        cost[u]+= arr[v];
        cost[v]+=arr[u];
        V[u].PB(v);
        V[v].PB(u);
    }
    priority_queue<Z>Q;
    for(int i = 1; i<= n; i++)
    {
        Q.push(Z(i,arr[i], cost[i]));
    }
    LL ans = 0;
    bool vis[100001];
   memset(vis, false, sizeof vis);
    while(!Q.empty())
    {
        Z top = Q.top();
        Q.pop();
        int x = top.a;
        int c = top.c;

        if(vis[x]) continue;
        vis[x] = true;
        ans += c;
      //  cout<<x<<" "<<c<<endl;
        int sz = V[x].size();
        for(int i = 0; i<sz; i++)
        {
            int adjn = V[x][i];
            if(vis[adjn]) continue;
            int adjc = cost[adjn] - arr[x];
            cost[adjn]= min(cost[adjn], adjc);
            Q.push(Z(adjn,arr[adjn], adjc));
        }
    }
    cout<<ans<<endl;

    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
