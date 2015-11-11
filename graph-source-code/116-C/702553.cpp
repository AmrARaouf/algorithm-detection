//Language: GNU C++



#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<set>
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x), (y))
#define sqr(x) ((x)*(x))
#define eps 1e-9
#define fle(x,y) ((x) < (y)+eps)
#define flt(x,y) ((x) < (y)-eps)
#define fge(x,y) ((x) > (y)-eps)
#define fgt(x,y) ((x) > (y)+eps)
#define feq(x,y) (fabs(x-y) < eps)
#define FOR(x,y,z) for(int x=y; x<z;x++)
#define FER(x,y,z) for(int x=y; x<=z;x++)
#define x first
#define y second
#define MAXM 1000005
#define MAXN 210
#define LL long long
using namespace std;
vector<int> w[2005];
int n;
int dfs(int s, int d){
        int ans = d;
        int l = w[s].size();
        FOR(i,0,l){
                ans = max(ans, dfs(w[s][i],d+1));
        }
        return ans;
}
int main(){
        int a;
        scanf("%d", &n);
        FOR(i,0,2005) w[i].clear();
        FER(i,1,n){
                scanf("%d", &a);
                if(a != -1){
                        w[a].pb(i);
                }
        }
        int ans = 0;
        FER(i,1,n){
                ans = max(ans,dfs(i,1));
        }
        printf("%d\n", ans);
        return 0;
}
