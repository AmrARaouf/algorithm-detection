//Language: GNU C++0x


#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define gc getchar_unlocked
using namespace std;
string s[200];
int adj[30][30],n,in[30];
bool visited[30];

bool dfs(int pos,int v,int &cc)
{
    cc++;
    visited[pos]=true;
    bool ret=true;
    
    v= (v | (1<<pos));
    
    for(int i=0;i<26;i++)
    {
        if(adj[pos][i]==0)continue;
        
        if((v & (1<<i))!=0)
        {
            ret=false;
            break;
        }
        
        if(visited[i])continue;
        
        ret=ret & dfs(i,v,cc);
        
        
    }
    
    
    return ret;
}

bool dodfs()
{
    int vis=0;
    bool ret=true;
    while(vis<26)
    {
        int st;
        
        int mi=100000;
        for(int i=0;i<26;i++){ if(!visited[i] && in[i]<mi){ st=i;mi=in[i]; break; } }
        
        //if(vis==0)cout<<st<<"  ";
        ret=ret & dfs(st,0,vis);
    }
    return ret;
}
vector<int> res;

void dfs2(int pos,int &cc)
{
    cc++;
    visited[pos]=true;
    for(int i=0;i<26;i++)
    {
        if(adj[pos][i]==0 || visited[i])continue;
        
        dfs2(i,cc);
        
    }
    
    res.pb(pos);
}

void dodfs2()
{
    int vis=0;
  
    while(vis<26)
    {
        int st;
        int mi=100001;
        for(int i=0;i<26;i++){ if(!visited[i] && in[i]<mi){ st=i;mi=in[i]; break; } }
        
        dfs2(st,vis);
    }
    
}

int main() {
    cin>>n;
    cin>>s[0];
    
    bool oho=true;
    for(int i=1;i<n;i++)
    {
        cin>>s[i];
        int pos=0;
        
        while(pos<s[i].length() && pos<s[i-1].length() && s[i][pos]==s[i-1][pos])pos++;
        
        if(pos<s[i].length() && pos<s[i-1].length())
        {
        adj[s[i-1][pos]-'a'][s[i][pos]-'a']=1;
        in[s[i][pos]-'a']++;
        
        } 
        else if(s[i].length()<s[i-1].length()){ oho=false; }   
    }
    if(!oho)
    {
    cout<<"Impossible";
    return 0;
    }
    if(!dodfs())cout<<"Impossible";
    else
    {
        memset(visited,false,sizeof(visited));
        dodfs2();
        int don[30]={0};
        
       // cout<<res.size()<<" ";
        for(int i=res.size()-1;i>=0;i--){ cout<<(char)(res[i]+'a'); don[res[i]]=1;}
        for(int i=0;i<26;i++){ if(!don[i])cout<<(char)(i+'a'); }
    }

    return 0; 
}