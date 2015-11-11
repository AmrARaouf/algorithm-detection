//Language: GNU C++


#include<iostream>
#include<vector>
using namespace std;

int all[1001][1001];
int e[1001];
vector< vector<int> > allv(1001);

int main()
{
    int n,m,i,j,a,b,r=0;
    cin>>n>>m;
   // allv.resize(n+1);
    for(i=1;i<=n;++i)
    {
        cin>>e[i];
    }
    for(i=1;i<=m;++i)
    {
        cin>>a>>b;
        allv[a].push_back(b);
        //allv[b].push_back(a);
    }
    for(i=1;i<=n;++i)
    {
        for(j=0;j<allv[i].size();++j)
        {
            r += e[i]<e[allv[i][j]]?e[i]:e[allv[i][j]];
        }
    }
    cout<<r<<endl;
}
