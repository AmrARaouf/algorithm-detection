//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n,m;
    cin>>n>>m;
    vector <vector <int> > v(n+1);
    int a,b;
    while(m--)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()>=2)
        {
            for(int j=0;j<v[i].size();j++)
            {
                for(int k=j+1;k<v[i].size();k++)
                {
                        if(binary_search(v[v[i][j]].begin(),v[v[i][j]].end(),v[i][k]))
                        {
                            if(ans==-1)
                            {
                                ans=v[i].size()+v[v[i][j]].size()+v[v[i][k]].size()-6;
                            }
                            else
                                ans=min(ans,int(v[i].size()+v[v[i][j]].size()+v[v[i][k]].size()-6));
                        }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}