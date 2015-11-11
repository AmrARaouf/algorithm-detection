//Language: GNU C++




#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> a;
int ed[100500][3];
int s[100500][3];
int name[100500];

int bins1(int x)
{
    int l,r,m;
    l=0; r=a.size();
    while (r>l+1)
    {
        m=(r+l)/2;
        if (x>=a[m]) l=m; else r=m;
    }
    return l;

}


inline void dfs(int v,int b)
{
    printf("%d ",name[v]);
    if (s[v][0]!=1)
     if (s[v][1]==b)
         dfs(s[v][2],v); else dfs(s[v][1],v);
}

int main()
{
 //   freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n,start;

    cin >> n;
    for (int i=0; i<n; i++)
    {
        int x,y;
        cin >> x >> y;
        ed[i][0]=x; ed[i][1]=y;
        a.push_back(x); a.push_back(y);
    }
    sort(a.begin(),a.end());
    int j=0;
    for (int i=0; i<a.size();i++) if (a[i]!=a[i+1]) a[j++]=a[i];
    a.resize(j);
   
    int xx,yy;
    for (int i=0; i<n; ++i)
    {
        xx=bins1(ed[i][0]); yy=bins1(ed[i][1]);
        s[xx][++s[xx][0]]=yy; name[xx]=ed[i][0];
        s[yy][++s[yy][0]]=xx; name[yy]=ed[i][1];
     //   cout <<ed[i][0]<<"->"<<xx<<"  "<<ed[i][1]<<"->"<<yy<<" ";
    }
    for (int i=0; i<n; i++) if (s[i][0]==1) {start=i; break;}
    printf("%d ",name[start]);
    dfs(s[start][1],start);
}
