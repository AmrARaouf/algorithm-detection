//Language: GNU C++


#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

#define REP(i,n)      FOR(i,0,n)
#define FOR(i,a,b)    for(int i = a; i < b; i++)
#define ROF(i,a,b)    for(int i=a;i>b;i--)
#define GI 		      ({int t;scanf("%d",&t);t;})
#define GL 		      ({LL t;scanf("%lld",&t);t;})
#define GD 		      ({double t;scanf("%lf",&t);t;})
#define pb 	          push_back
#define mp 	          make_pair
#define MOD 	      1000000007
#define INF	          (int)1e9
#define EPS	          1e-9
#define TR(a,it)      for (typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

class Prioritize
{
public:
    int operator() ( const pair<int, int>& p1, const pair<int, int>& p2 )
    {
        return p1.first > p2.first;
    }
};

LL n,m;
LL a,b,c,t,k,temp;
vector<vector<pair<LL,LL> > > e;
vector<vector<LL> > v;
priority_queue<pair<LL,LL> ,vector<pair<LL,LL> >,Prioritize> Q;
set<LL> S;
pair<LL,LL> p;
LL u,w,f;
LL d[100001];
LL r[1];
int main()
{
    cin>>n>>m;
    e.resize(n+1);
    v.resize(n+1);
    FOR(i,0,m)
    {
      scanf("%d %d %d",&a,&b,&c);
      e[a].pb(mp(b,c));
      e[b].pb(mp(a,c));
    }
    FOR(i,1,n+1)
    {
      scanf("%d",&k);
      FOR(j,0,k)
      {
        scanf("%d",&t);        
        v[i].pb(t);        
      }        
    }

    //Now do dijkastra search for shortest part to n

    S.empty();
    memset(d,127,sizeof(d));
    memset(r,127,sizeof(r));
    Q.push(mp(0,1));
    d[1]=0;
    while(!Q.empty())
    {
                     
      p=Q.top();
      t=p.second;  
     // cout<<"p.first"<<p.first<<endl;
      
      Q.pop();
      //get first free time for t,more then its d[t];
      temp=0;
      
      for(int i=0;i<v[t].size();i++)
      {
   //      cout<<"V[t][i] "<<v[t][i]<<" d[t] "<<d[t]<<endl;     
         if(v[t][i]==d[t])
         {
           temp=1;            
           for(int j=i+1;j<v[t].size();j++)
           {
             if(v[t][j]==(d[t]+temp))
                temp++;
             else
               break;   
           }
           break;        
         }        
      }
     // cout<<"temp is"<<temp<<" "<<"d["<<t<<"] is "<<d[t]<<endl; 
      //d[t]+temp; is time of leaving from t
      for(int i=0;i<e[t].size();i++)
      {
        // cout<<"e[t].size()"<<e[t].size();     
         f=e[t][i].first;
         w=e[t][i].second;
         u=d[t]+temp;     
       //  cout<<"f: "<<f<<"w: "<<w<<"u: "<<u<<endl;
         if(d[f]>(w+u))
         {
           d[f]=w+u;
         //  cout<<"pushing f"<<f<<" and d[f]" <<d[f]<<endl;
           if(S.find(f)!=S.end())
            continue;

           Q.push(mp(d[f],f));            
         }
      }
      S.insert(t);
                     
    }
    if(d[n] < r[0])
       cout<<d[n];
    else
       cout<<"-1";
	return 0;
}
