//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;


#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M)
{
    LL ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}

vector < LL > G[300001], E[300001],dis[300001];
LL edge[300001][3], d[300001], path[300001];
struct node
{
    LL city,cost;
    node() {}
    node(LL city,LL cost): city(city),cost(cost) {}
    bool operator <(const node& p)const
    {
        return cost>p.cost;
    }
};

priority_queue <node>Q;
int main()
{

     LL n,e,u,v,w;
    cin>>n>>e;
    for(LL i=0; i<e; i++)
    {
        cin>>u>>v>>w;
        G[u].push_back(v);
        G[v].push_back(u);
        dis[u].push_back(w);
        dis[v].push_back(w);
        E[u].push_back(i);
        E[v].push_back(i);
        edge[i][0]=u,edge[i][1]=v,edge[i][2]=w;

    }

    int src;
    cin >> src;
    for(int i=0; i<300005; i++)
        d[i]=1ll<<50;

    d[src] = 0;
    Q.push(node(src,0));
    memset(path, -1, sizeof path);

  while(!Q.empty())
    {
        node a;
        a=Q.top();
        Q.pop();
        LL u=a.city;
        if(a.cost!=d[u])continue;

        for(LL i=0; i<G[u].size(); i++)
        {

            LL v=G[u][i];

            //  cout<<v<<" ";
            //cout<<d[u]<<" "<<dis[u][i]<<endl;
            if(d[u]+dis[u][i]<d[v])
            {
                //puts("ffffffffff");

                d[v]=d[u]+dis[u][i];
                path[v]=E[u][i];
                Q.push(node(v,d[v]));

            }
            else if(d[v]==dis[u][i]+d[u])
            {
                path[v]=E[u][i];


            }



        }

    }

//    while(!Q.empty())
//    {
//        node p = Q.top();
//        Q.pop();
//        int u=p.city;
//        if(d[u]!=p.cost)
//        {
//            // cout<<"PORN : "<<d[u]<<" "<<p.xx;
//            // for(;;);
//            continue;
//
//        }
//        REP(i, G[u].size())
//        {
//            int v=G[u][i];
//            if(d[v] > d[u] + dis[u][i])
//            {
//                d[v] = d[u] + dis[u][i];
//                path[v] = E[u][i];
//                Q.push(node(v,d[v]));
//            }
//            else if(d[v]==d[u] + dis[u][i])
//            {
////                if(edge[ E[p.yy][i] ][2] <= edge[ path[ G[p.yy][i] ] ][2])
//                    path[v] = E[u][i];
//            }
//        }
//    }
    LL sum = 0;
    FOR(i, 1, n+1)
    {
        if(path[i] == -1) continue;
        sum += edge[ path[i] ][2];
    }
    cout << sum << endl;
    FOR(i, 1, n+1)
    {
        if(path[i] == -1) continue;
        cout << path[i]+1 << " ";
    }
    cout << endl;
}
