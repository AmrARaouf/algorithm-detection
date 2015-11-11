//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cstring>
#include<numeric>

using namespace std;

#define ll long long int 
#define ss1(a) scanf("%d",&a)
#define ss2(a,b) scanf("%d %d",&a,&b)
#define ss3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loope(i,a,b) for(int i=a;i<=b;i++)
#define loopd(i,a,b) for(int i=a;i>=b;i--)

typedef vector<int> vi; 
typedef vector< vi > vvi; 
typedef pair<int,int> pii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp(a,b) make_pair(a,b)

vector < pair<int,int> > adjlist[100010];
priority_queue < pii , vector< pii >,greater< pii > > q;
vector < pair< pair<int,int>,int > > edges;

int dist[100010];
int mark[100010];
int n,m,s,l;
int ret=0;

int main()
{
    ss3(n,m,s);
    loop(i,0,m)
    {
        int u,v,w;
        ss3(u,v,w);
        adjlist[u].pb(mp(v,w));
        adjlist[v].pb(mp(u,w));
        edges.pb(mp(mp(u,v),w));
    }
    ss1(l);
    loope(i,1,n)
    {
        dist[i]=1e9;
        mark[i]=0;
    }

    dist[s]=0;
    mark[s]=1;
    q.push(mp(0,s));    
        
    while(!q.empty())
    {
        int d=q.top().first;
        int u=q.top().second;
        mark[u]=1;
        q.pop();
        //cout<<u<<" ";
        loop(i,0,sz(adjlist[u]))
        {
            
            int v=adjlist[u][i].first;
            int w=adjlist[u][i].second;
            //cout<<dist[u] + w<<"\n";  

            if(mark[v]==0)
                if(dist[u]+w<dist[v])
                {
                    //cout<<u<<" "<<v<<"*";
                    dist[v]=dist[u]+w;
                    q.push(mp(dist[v],v));
                }
        }
    }
    

    /*loope(i,1,n)
        cout<<dist[i]<<" ";*/

    loope(i,1,n)
    {   
        if(dist[i]==l)
            ret++;
    }
    
    loop(j,0,sz(edges))
    {
        int u=edges[j].first.first;
        int v=edges[j].first.second;
        int w=edges[j].second;
        
        
        {
            if(dist[u]<l && l-dist[u]<w && w-(l-dist[u])+dist[v]>l)
                ret++; 
                
            if(dist[v]<l && l-dist[v]<w && w-(l-dist[v])+dist[u]>l)
                ret++;

            if(dist[u]<l && dist[v]<l && dist[u]+dist[v]+w==2*l)
                ret++;
        }
    }   
        
    
    printf("%d\n",ret);
    return 0;
}
        
    
