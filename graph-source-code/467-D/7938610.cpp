//Language: GNU C++


#include<stdio.h>
#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#define foru(i,a,b) for(int i=a;i<=int(b);i++)
using namespace std;
const int maxn=int(2e5)+100;
struct strip{ int a,b,c; };
struct both{ int a,b; } dau[maxn];
typedef pair<string,int> ii;
string str[maxn];
map<string,int> lst;
vector<int> vec[maxn];
int res[maxn],check[maxn],lst2[300005];
int nlst;
void get(string &s){
    int val1=0;
    foru(j,0,s.size()-1){
            s[j]=tolower(s[j]);
            val1+=(s[j]=='r');
    }
    int val2=s.size();
    if (lst.find(s) == lst.end()) {
        dau[lst.size()].a=val1;
        dau[lst.size()].b=val2;
        lst.insert(ii(s,lst.size()));
    }
}
void dfs(int u){
    stack<int> st; st.push(u);
    res[u]=u;
    while (!st.empty()){
        int x=st.top();
        if (check[x]){
            st.pop();
            continue;
        }
        check[x]=1;
        foru(i,0,vec[x].size()-1)
        if (!check[vec[x][i]]) {
            int v=vec[x][i];
            res[v]=u;
            st.push(v);
        }
    }
}
int cmp(int x, int y) {
    return (dau[x].a<dau[y].a||(dau[x].a==dau[y].a&&dau[x].b<dau[y].b));
}
int main(){
//    freopen("test.inp","r",stdin);
    int n,m;
    cin >> n;
    scanf("\n");
    foru(i,0,n-1){
        cin >> str[i];
        get(str[i]);
        int u=lst.find(str[i])->second;
        lst2[nlst++]=u;
    }
    cin >> m;
    foru(i,1,m) {
        string s1,s2;
        cin >> s1 >> s2;
        get(s1); get(s2);
        int u= lst.find(s1)-> second, v= lst.find(s2) -> second;
        vec[v].push_back(u);
        lst2[nlst++]=u; lst2[nlst++]=v;
    }
    sort(lst2,lst2+nlst,cmp);
    foru(i,0,nlst-1) if (!check[lst2[i]]) dfs(lst2[i]);
    long long res1=0,res2=0;
    foru(i,0,n-1){
        int u=lst.find(str[i]) -> second;
        res1+=dau[res[u]].a;
        res2+=dau[res[u]].b;
    }
    cout << res1 << ' ' << res2;
}
