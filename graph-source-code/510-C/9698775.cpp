//Language: GNU C++


#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
vector <int> v[102];
string s[102];
vector <char> ans;
int mark[26];

int cmp(int x,int y)
{
    //cout<<x<<" "<<y<<endl;
    int len=min(s[x].size(),s[y].size());
    for(int i=0; i<len; i++)
        if(s[x][i]!=s[y][i])
        {
            
            v[s[x][i]-'a'].push_back(s[y][i]-'a');
            return 1;
        }
    if(s[x].size()>s[y].size())
    {
        //cout<<"alo"<<endl;
        return 0;
    }
    //cout<<"lol"<<endl;
    return 1;
}
int dfs(int x)
{
    //cout<<"dfs("<<x<<")"<<endl;
    int res=1;
    mark[x]=1;
    
    for(int i=0; i<v[x].size(); i++)
    {
        if(mark[v[x][i]] == 1)
            return 0;
        else if(mark[v[x][i]] == 0)
            res*=dfs(v[x][i]);
    }
    
    mark[x]=2;
    ans.push_back('a'+x);
    return res;
}
main()
{
    int r=1;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>s[i];
    
    for(int j=0; j<n-1; j++)
        if(cmp(j,j+1)==0)
            r=0;
    for(int i=0; i<26; i++)
    {
        if(mark[i] == 0)
            if(dfs(i) == 0)
                r=0;
    }
    if(r==0)
        cout<<"Impossible"<<endl;
    else
        for(int i=25; i>=0; i--)
            cout<<ans[i];
    
}