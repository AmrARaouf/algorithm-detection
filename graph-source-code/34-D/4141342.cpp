//Language: GNU C++


#include<iostream>
#include<vector>
#include<cstdio>
#include<stack>
using namespace std;

int main()
{
    int i,x,n,p,q,j;
    
    vector<int> v[50004];
    scanf("%d %d %d",&n,&p,&q);
    for(i=1;i<=n-1;i++) {
        scanf("%d",&x);
        if(i>=p) {
            v[i+1].push_back(x);
            v[x].push_back(i+1);
        }
        else {
            v[i].push_back(x);
            v[x].push_back(i);
            
        }
    }
/*  for(i=1;i<=n;i++) {
        for(j=0;j<v[i].size();j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    int vis[50002] = {0};
    stack<int> s;
    s.push(q);
    vis[q] = 1;
    int tp;
    int par[50002];
    while(!s.empty())
    {
        tp = s.top();
        s.pop();
        for(i=0;i<v[tp].size();i++) {   
            if(vis[v[tp][i]] == 0) {
    //          cout<<v[tp][i]<<":)" << "\n";
                par[v[tp][i]] = tp;
                s.push(v[tp][i]);
                vis[v[tp][i]] = 1;
            }       
        }   
    }
    for(i=1;i<=n;i++) {
        if(i==q)
        continue;
        else {
            cout<<par[i]<<" ";
        }
    }
    cout<<"\n";
    return 0;
}