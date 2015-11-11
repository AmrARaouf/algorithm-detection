//Language: GNU C++


#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
using namespace std;

typedef long long LL;

string s[200];

vector<int> G[26];
int ans = 0;
int vis[200];

bool isCyclicUtil(int i, bool visited[], bool *recStack)
{
    if(visited[i] == false)
    {
        visited[i] = true;
        recStack[i] = true;

        for(int j = 0; j < G[i].size() ; ++j)
        {
            int v = G[i][j];
            if ( !visited[v] && isCyclicUtil(v, visited, recStack) )
                return true;
            else if (recStack[v])
                return true;
        }
    }
    recStack[i] = false;
    return false;
}

bool isCyclic()
{
    bool *visited = new bool[26];
    bool *recStack = new bool[26];
    for(int i = 0; i < 26; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i = 0; i < 26; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

vector<char> p;
int deg[26];

void dfs(int i)
{
    if (vis[i] == 1){
        return;
    }
    vis[i] = 1;
    for (int j=0;j<G[i].size(); j++){
        dfs(G[i][j]);
    }
    p.pb(i + 'a');
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>s[i];
    }
    if (n == 1){
        for (int i=0;i<26;i++){
            char ch = (i + 'a');
            cout<<ch;
        }
        cout<<"\n";
        return 0;
    }
    for (int i=0;i+1<n; i++){
        string a, b;
        a = s[i];
        b = s[i+1];
        int flag = 0;
        for (int j=0;j<min(a.size(), b.size()); j++){
            if (a[j] == b[j]){
                continue;
            } else{
                flag = 1;
                G[b[j] - 'a'] .pb(a[j] - 'a');
                deg[a[j] - 'a']++;
                break;
            }
        }
        if (flag == 0){
            if (a.size() > b.size()){
                cout<<"Impossible\n";
                return 0;
            }
        }
    }
    /*
    for (int i=0;i<26;i++){
        cout<<i<<": ";
        for (int j=0;j<G[i].size(); j++){
            cout<<G[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    if (isCyclic()){
        ans = 1;
    }

    if (ans == 1){
        cout<<"Impossible\n";
    } else {
        for (int i=0;i<26;i++){
            if (deg[i] == 0 && vis[i] == 0){
                dfs(i);
            }
        }
        for (int i=0;i<p.size(); i++){
            cout<<p[i];
        }
    }
    return 0;
}
