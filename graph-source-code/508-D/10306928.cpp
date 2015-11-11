//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int in[N],out[N],vis[N],go[N];
map<string,int> ma;
map<int,string> mb;
vector<pair<int,int> > g[N];
int tot = 0,flag = 0;
string ans;
int add(string s)
{
    if(ma.find(s) == ma.end())
    {
        ma[s] = tot;
        mb[tot] = s;
        tot++;
    }
    return ma[s];
}
void dfs(int u)
{
    for(; go[u]<g[u].size(); go[u]++)//本来使用i=0写的...果断超时了。
    {
        if(!vis[g[u][go[u]].second])
        {
            vis[g[u][go[u]].second] = 1;
            dfs(g[u][go[u]].first);
        }
    }
    if(!flag)
    {
        flag = 1;
        ans += mb[u][1];
    }
    ans += mb[u][0];
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    string str;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> str;
        int u = add(str.substr(0,2));//起始位置0,长度2的子串
        int v = add(str.substr(1,2));
        in[v]++;
        out[u]++;
        g[u].push_back(make_pair(v,i));
    }
    ans = "";//多组的话要清空字符串
    int start = 0,cnt = 0;
    for(int i=0; i<tot; i++)
    {
        if(out[i]>in[i])
        {
            cnt += out[i] - in[i];
            if(cnt > 1)
            {
                puts("NO");
                return 0;
            }
            start = i;
        }
    }
    dfs(start);
    if(ans.length() == n + 2)//这里是防止输入的数据里有多组循环子串如：4 aba bab cdc dcd
    {
        puts("YES");
        //reverse(ans.begin(),ans.end());
        //cout << ans << endl;
        for(int i=ans.length()-1; i>=0; i--)
            cout << ans[i];
        cout << endl;
    }
    else
        puts("NO");
    return 0;
}
