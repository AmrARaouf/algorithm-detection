//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define rep(x, y, z) for(int x=y;x<z;x++)

const int maxn=5e2+7;
int n, m;
char s[maxn][maxn];
int flag;
struct Node{
    char b;
    int pi, pj;
    Node(){}
    Node(char c, int x, int y) {b=c;pi=x;pj=y;}
};
vector<Node> ans;
const char dr[]={-1, 0, 1, 0};
const char dc[]={0, 1, 0, -1};

void dfs(int x, int y, int flag){
    if(x<0 || x >= n || y<0 || y >= m || s[x][y] == '#') return ;
    s[x][y]='#';
    ans.push_back(Node('B', x+1, y+1));
    //cout<<"B "<<x+1<<" "<<y+1<<endl;
    rep(i, 0, 4){
        if(x+dr[i] >= 0 && x+dr[i]<n && y+dc[i] >= 0 && y+dc[i]<m && s[x+dr[i]][y+dc[i]] != '#') dfs(x+dr[i], y+dc[i], 0);
        
    }
    if(flag == 0){
        ans.push_back(Node('D', x+1, y+1));
        ans.push_back(Node('R', x+1, y+1));
        //cout<<"D "<<x+1<<" "<<y+1<<endl;
        //cout<<"R "<<x+1<<" "<<y+1<<endl;
    }
}
void solve(){
    rep(i, 0, n) rep(j, 0, m) {
        if(s[i][j] != '#')
            flag=1;
            dfs(i, j, 1);
    }
    int len=(int)ans.size();
    //cout<<len<<endl;
    printf("%d\n", len);
    rep(i, 0, len) printf("%c %d %d\n", ans[i].b, ans[i].pi, ans[i].pj);
    //cout<<ans[i].b<<" "<<ans[i].pi<<" "<<ans[i].pj<<endl;
    
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    cin>>n>>m;
    rep(i, 0, n) scanf("%s", s[i]);
    solve();
    return 0;
}

 	 	 		 			     					  	   		