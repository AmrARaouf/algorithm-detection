//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
const int maxn=1000100;
const long long INF=1000000000;
long long x[maxn],d[maxn],t[maxn],p[maxn],n,ww[maxn];
vector<int>mohem,impo,ans,jav,finall,co[maxn];
vector<pair<int,int> >adj[maxn],rrr[maxn];
set<pair<long long,int> >s;
int par[maxn];
int bar=0;
vector< pair<int , pair<int, int> > >ramp;
int serch(int qq)
{
    int l=-1,r=impo.size();
    while(r-l>1)
    {
        int mid=(r+l)/2;
        if(impo[mid]==qq)
            return mid;
        if(impo[mid]<qq)
            l=mid;
        if(impo[mid]>qq)
            r=mid;
    }
    return -1;
}
void dijstra(int x)
{
    d[x]=0;
    s.insert(make_pair(d[x],x));
    while(!s.empty())
    {
        int v=s.begin()->second;
        s.erase(make_pair(d[v],v));
        for(int i=0;i<adj[v].size();i++)
        {
            int u=adj[v][i].second,w=adj[v][i].first;
            if(d[u]>d[v]+w)
            {
                par[u]=v;
                s.erase(make_pair(d[u],u));
                d[u]=d[v]+w;
                s.insert(make_pair(d[u],u));
            }
        }
    }
}
int main()
{
    int l;
    ios::sync_with_stdio(0);
    cin>>n>>l;
    int realn=n;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>d[i]>>t[i]>>p[i];
        ww[i]=x[i]-p[i]+t[i];
        if(x[i]-p[i]>=0 && d[i]>=t[i])
        {
            mohem.push_back(x[i]-p[i]);
            mohem.push_back(x[i]+d[i]);
            ramp.push_back(make_pair(x[i]-p[i],make_pair(x[i]+d[i],i)));
        }
    }
    if(ramp.size()==0)
    {
        cout<<l<<endl<<"0"<<endl;
        return 0;
    }
    mohem.push_back(0),mohem.push_back(l);
    sort(ramp.begin(),ramp.end());
    sort(mohem.begin(),mohem.end());
    impo.push_back(mohem[0]);
    for(int i=1;i<mohem.size();i++)
        if(mohem[i]!=mohem[i-1])
            impo.push_back(mohem[i]);
    for(int i=1;i<impo.size();i++)
    {
        adj[i].push_back(make_pair(impo[i]-impo[i-1],i-1));
        adj[i-1].push_back(make_pair(impo[i]-impo[i-1],i));
    }
    for(int i=0;i<n;i++)
    {
        if(x[i]-p[i]>=0 && d[i]>=t[i])
        {
            int andis1=serch(x[i]-p[i]);
            int andis2=serch(x[i]+d[i]);
            int w=p[i]+t[i];
            adj[andis1].push_back(make_pair(w,andis2));
            rrr[andis1].push_back(make_pair(w,andis2));
            co[andis1].push_back(i);
        }
    }
    int n=impo.size();
    for(int i=0;i<n;i++)
        d[i]=INF;
    dijstra(0);
    cout<<d[n-1]<<endl;
    int t=n-1;
    par[0]=-1;
    while(t!=-1)
    {
        jav.push_back(impo[t]);
        t=par[t];
    }
    for(int i=jav.size()-1;i>=0;i--)
        ans.push_back(jav[i]);
    int m=ramp.size();
    for(int i=0;i<ans.size()-1;i++)
    {
        int f=serch(ans[i]),g=serch(ans[i+1]);
        bool isramp=false;
        int look,minn;
        for(int j=0;j<rrr[f].size();j++)
        {
            if(rrr[f][j].second==g)
            {
                if(!isramp)
                {
                    minn=rrr[f][j].first;
                    look=co[f][j];
                }
                else
                {
                    if(rrr[f][j].first==minn)
                    {
                        if(co[f][j]<look)
                            look=co[f][j];
                    }
                    if(rrr[f][j].first<minn)
                    {
                        minn=rrr[f][j].first;
                        look=co[f][j];
                    }

                }
                isramp=true;
            }
        }
        if(isramp)
            finall.push_back(look);
    }
    cout<<finall.size()<<endl;
    for(int i=0;i<finall.size();i++)
        cout<<finall[i]+1<<" ";
    //
    return 0;
}
