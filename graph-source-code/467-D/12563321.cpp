//Language: GNU C++11


#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<unordered_map>
#include<ctype.h>
using namespace std;
vector<int> essay,adj[300000];
pair<int,int> mem[300000];
unordered_map<long long,int> mp;
long long words,dic,MnR,len;
int _hash(string &str)
{
    for(int i=0;str[i];i++)   str[i]=tolower(str[i]);
    long long h=hash<string>()(str);
    if(!mp.count(h))
    {
        mp[h]=mp.size();
        int r=0;
        for(int i=0;str[i];i++)    r+=(str[i]=='r');
        mem[mp[h]]={r,str.size()};
    }
    return mp[h];
}
int index[300000],lowLink[300000],compIdx[300000];
stack<int> s;
bool inStack[300000];
vector<vector<int> > SCC;
void Tarjan(int v,int& idx)
{
    index[v]=lowLink[v]=idx++;
    s.push(v);
    inStack[v]=1;
    for(int a : adj[v])
        if(!index[a])
        {
            Tarjan(a,idx);
            lowLink[v]=min(lowLink[v],lowLink[a]);
        }
        else if(inStack[a])
            lowLink[v]=min(lowLink[v],lowLink[a]);
    if(lowLink[v]==index[v])
    {
        set<int> edges;
        SCC.push_back(vector<int>(0));
        auto &comp=SCC.back();
        pair<int,int> Mn={300000,300000};
        int a;
        do
        {
            a=s.top();
            s.pop();
            inStack[a]=0;
            comp.push_back(a);
            compIdx[a]=SCC.size()-1;
            Mn=min(Mn,mem[a]);
            for(int e : adj[a]) edges.insert(e);
        }while(a!=v);
        for(int i=0;i<(signed)comp.size();i++)
        {
            mem[comp[i]]=Mn;
            adj[comp[i]].clear();
            for(auto e : edges)  if(compIdx[e]!=compIdx[comp[i]])
                adj[comp[i]].push_back(e);
        }
    }
}
pair<int,int> dfs(int v)
{
    if(inStack[v])  return mem[v];
    inStack[v]=1;
    for(int i=0;i<(signed)adj[v].size();i++)
        mem[v]=min(mem[v],dfs(adj[v][i]));
    return mem[v];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>words;
    for(int i=0;i<words;i++)
    {
        string str;cin>>str;
        int num=_hash(str);
        essay.push_back(num);
    }
    cin>>dic;
    for(int i=0;i<dic;i++)
    {
        string a,b;cin>>a>>b;
        int num1=_hash(a),num2=_hash(b);
        adj[num1].push_back(num2);
    }
    int idx=1;
    for(int i=0;i<words;i++)    if(!index[essay[i]])
        Tarjan(essay[i],idx);
    for(int i=0;i<words;i++)
    {
        auto c=dfs(essay[i]);
        MnR+=c.first,len+=c.second;
    }
    cout<<MnR<<' '<<len<<endl;
    return 0;
}
