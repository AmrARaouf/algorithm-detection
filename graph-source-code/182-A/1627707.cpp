//Language: MS C++


#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int a,b;
const double INF=999999999;

double rast(int x, int y, int x1, int y1)
{
    return (x-x1)*(x-x1)+(y-y1)*(y-y1);
}

double dist(pair<pair<int, int>, pair<int, int> > line1, pair<pair<int, int>, pair<int, int> > line2 )
{
    int x11=line1.first.first;
    int x12=line1.second.first;
    int y11=line1.first.second;
    int y12=line1.second.second;

    int x21=line2.first.first;
    int x22=line2.second.first;
    int y21=line2.first.second;
    int y22=line2.second.second;
double ddist=INF;
    if (y11==y12) {
        if (x11>x12) swap(x11, x12);
        if (y21==y22) {
            if (x21>x22) swap(x21, x22);
            if (max(x12, x22)-min(x11, x21)<=(x12-x11)+(x22-x21) )
                ddist=(y11-y21)*(y11-y21);
            else
            {
                if (x11<x21) ddist=((y11-y21)*(y11-y21)+(x12-x21)*(x12-x21));
                else ddist=((y11-y21)*(y11-y21)+(x11-x22)*(x11-x22));
            }
        }
        else
        {
            if (y21>y22) swap(y21, y22);
            if (y11>=y21&&y11<=y22) {
                ddist=min(abs(x21-x12), abs(x21-x11));              
                ddist*=ddist;
            }
            else if(x11<=x21&&x21<=x12){ 
                ddist=min((y21-y11)*(y21-y11), (y22-y11)*(y22-y11));                
            }
            else {
                ddist=min(ddist, rast(x11,y11, x21, y21));
                ddist=min(ddist, rast(x12,y12, x21, y21));
                ddist=min(ddist, rast(x11,y11, x22, y22));
                ddist=min(ddist, rast(x12,y12, x22, y22));
            }
        }
    }
    else ddist=dist(make_pair(make_pair(y11, x11), make_pair(y12, x12)), make_pair(make_pair(y21, x21), make_pair(y22, x22)));
    
    return (ddist>a)? INF: ddist;

}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int  aa;
    cin>>a>>b;
    aa=a;
    a*=a;
    pair<int, int> start, fin;
    cin>>start.first>>start.second>>fin.first>>fin.second;
    int n;
    cin>>n;
    vector <pair<pair<int, int>, pair<int, int> > > v(n+2);
    for (int i=0; i<n; ++i)
        cin>>v[i].first.first>>v[i].first.second>>v[i].second.first>>v[i].second.second;
    vector <double> tp(n+2, INF);


    vector <vector<double> > g(n+2, tp);
    v[n].first.first=v[n].second.first=start.first;
    v[n].first.second=v[n].second.second=start.second;

    v[n+1].first.first=v[n+1].second.first=fin.first;
    v[n+1].first.second=v[n+1].second.second=fin.second;

    for (int i=0; i<n+2; ++i)
        for (int j=0; j<n+2; ++j)
            g[i][j]=dist(v[i], v[j]);

    n+=2;
    vector <int>lay(n, 0);
    vector <bool> used(n , false);
    queue<int> q;
    
    q.push(n-2);
    used[n-2]=true;
    while (!q.empty())
    {
        int t=q.front();
        q.pop();
        for (int i=0; i<n; ++i)
            if (!used[i]&&g[t][i]!=INF)
            {
                used[i]=true;
                lay[i]=lay[t]+1;
                q.push(i);
            }
    }

    if (!used[n-1]) {
        cout<<-1<<endl;
        return 0;
    }

    double ans=0;
    ans=(aa+b)*(lay[n-1]-1);
    double mmin=INF;
    for (int i=0; i<n; ++i)
        if(lay[i]+1==lay[n-1]&&g[n-1][i]<mmin)
            mmin=g[n-1][i];
    ans+=sqrt(mmin);
    cout<<ans<<endl;

    


}