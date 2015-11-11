//Language: GNU C++11


#include<bits/stdc++.h>
#define int long long
using namespace std;

long long all,a[1000000],b[1000000],c[1000000];
int n,m;
vector<int> ans,v[1000000],v1[1000000],vn[1000000];
vector<pair<int,pair<int,pair<int,int> > > >vv;
set<pair<int,int> >s;
int d[1000000];
int p[1000000];
int findset(int x)
{
    if(p[x]!=x)p[x]=findset(p[x]);
    return p[x];
}

bool unionset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx==yy)return false;
    p[xx]=yy;
    return true;
}

main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
        v1[a[i]].push_back(c[i]);
        v1[b[i]].push_back(c[i]);
        vn[a[i]].push_back(i);
        vn[b[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)d[i]=100000000000000000;
    int start;
    cin>>start;
    d[start]=0;
    s.insert(make_pair(0,start));
    while(!s.empty())
    {
        int x=(*s.begin()).second;
        s.erase(s.begin());
        for(int i=0;i<v[x].size();i++)
        {
            int to=v[x][i];
            if(d[x]+v1[x][i]<d[to])
            {
                s.erase(make_pair(d[to],to));
                d[to]=d[x]+v1[x][i];
                s.insert(make_pair(d[to],to));
            }
        }
    }
    /**for(int i=1;i<=m;i++)
    {
        if(d[a[i]]+c[i]==d[b[i]] || d[b[i]]+c[i]==d[a[i]])
            vv.push_back(make_pair(c[i],make_pair(a[i],make_pair(b[i],i))));
    }
    sort(vv.begin(),vv.end());
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=0;i<vv.size();i++)
    {
        int x=vv[i].second.first;
        int y=vv[i].second.second.first;
        ///cout<<x<<' '<<y<<endl;
        if(unionset(x,y))
        {
            all+=vv[i].first;
            ans.push_back(vv[i].second.second.second);
        }
    }
    cout<<all<<"\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';*/
    for(int i=1;i<=n;i++)if(i!=start)
    {
        int mx=1000000000000000;
        int numb=-1;
        for(int j=0;j<v[i].size();j++)
        {
            int to=v[i][j];
            if(d[to]+v1[i][j]==d[i])
            {
                if(v1[i][j]>=mx)continue;
                mx=v1[i][j];
                numb=vn[i][j];
            }
        }
        ans.push_back(numb);
        all+=mx;
    }
    cout<<all<<"\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
}
