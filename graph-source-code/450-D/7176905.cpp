//Language: GNU C++


#include <vector>
#include <list>
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
#include <memory.h>
#include <cstring>
using namespace std;
typedef pair<long long,long long> pi;
long long nn[100001];
vector<long long> neb[100001];
vector<long long> cost[100001];
long long train[100001];
set< pi >q;
long long val[100001];
long long visit[100001];
long long n,m,k,ans;
long long maxi=100000000000000000;
int main()
{
    cin>>n>>m>>k;
    memset(visit,-1,sizeof(visit));
    for(long long i=0;i<100001;i++)
        train[i]=maxi,val[i]=maxi;
    for(long long i=0;i<m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        neb[u].push_back(v);
        neb[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    for(long long i=0;i<k;i++)
    {
        long long u,c;
        cin>>u>>c;
        u--;
        if(train[u]!=maxi)
            ans++;
        train[u]=min(train[u],c);
    }
    for(int i=1;i<n;i++)
    {
        if(train[i]!=maxi)
        {
            q.insert(pi(train[i],i));
            val[i]=train[i];
            visit[i]=1;
        }
    }
    val[0]=0;
    q.insert(pi(0,0));
    while(!q.empty())
    {
        pi top= *q.begin();
        q.erase(q.begin());
        long long u=top.second;
        long long d=top.first;
        if(visit[u]==0)
            ans++; 

        for(long long i=0;i<neb[u].size();i++)
        {
            long long v=neb[u][i];
            long long len=cost[u][i];
            if(val[v]>=len+d)
            {
                if(val[v]!=maxi)
                {
                    q.erase(q.find(pi(val[v], v)));
                }
                val[v]=len+d;
                q.insert(pi(val[v], v));
                if(visit[v]==1)
                visit[v]=0;
            }
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;

}