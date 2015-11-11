//Language: GNU C++


#include <iostream>
#include <cstring>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
vector<string>arr;
bool graph[200][200];
bool vis[26];
int ra[26];
stack<char>ss;
bool check(){
    int i=0,j=0;
    while(i < arr.size()-1){
        if(arr[i][j] == arr[i+1][j]){
            if(j+1 >= arr[i+1].length())return false;
            else if(j+1 >= arr[i].length())i++,j = 0;
            else j++;
        }else{
            if(ra[arr[i][j]-'a'] > ra[arr[i+1][j]-'a'])return false;
            i++,j = 0;
        }
    }
    return true;
}
void dfs2(int i){
    if(vis[i])return;
    vis[i] = 1;
    for(int j=0;j<26;j++)if(graph[i][j])dfs2(j);
    ss.push('a'+i);
}
void dfs(int i,int j){
    if(i >= arr.size()-1)return;
    if(arr[i][j] == arr[i+1][j]){
        if(j + 1 < arr[i].size() && j+1 < arr[i+1].size())
            dfs(i,j+1);
        else
            dfs(i+1,0);
    }else{
        graph[arr[i][j]-'a'][arr[i+1][j]-'a'] = true;
        dfs(i+1,0);
    }
}

int main()
{
    int n;
    cin >> n;
    string x;
    while(n--){
        cin >> x;
        arr.push_back(x);
    }
    dfs(0,0);
    string ans = "";
    for(int i=0;i<26;i++){
        if(!vis[i])
            dfs2(i);
    }
    while(!ss.empty()){
        ans += ss.top();
        ra[ss.top()-'a'] = ans.size();
        ss.pop();
    }
    if(check())
        cout << ans << endl;
    else cout << "Impossible";
    return 0;
}
