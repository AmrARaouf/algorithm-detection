//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector< pair<int,int> >arr[100005];
vector<int>stack1;
int visited[100005]={0};
int dfs(int n,int h)
{
    int s=0;
    visited[n]=1;
    for(int i=0;i<arr[n].size();i++)
    {
        int v=arr[n][i].first;
        int t=arr[n][i].second;
        if(!visited[v])
            s=max(s,dfs(v,t));
    }
    if(s==0 && h==1)
        stack1.push_back(n+1);
    if(h==1)
        s=1;
    return s;
}
int main()
{
    int n,t,a,b,c,i;
    cin>>n;
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b>>c;
        a--; b--; c--;
        arr[a].push_back(make_pair(b,c));
        arr[b].push_back(make_pair(a,c));
    }
    dfs(0,0);
    cout<<stack1.size()<<endl;
    for(i=0;i<stack1.size();i++)
        cout<<stack1[i]<<" ";
    return 0;
}

