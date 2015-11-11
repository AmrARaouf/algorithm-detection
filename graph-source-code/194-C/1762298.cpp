//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <string.h>
#define For(i, a, b) for(long i=long(a);i<=long(b);i++)
#define Ford(i, b, a) for(long i=long(b);i>=long(a);i--)
#define LEN(s) long(s.length())
#define pii pair<int, int>
typedef long long i64;
using namespace std;

    bool a[55][55], fr[55][55];
    int n, m, cnt = 0, ret;

void dfs(int u, int v){
    fr[u][v] = false;
    if(a[u+1][v]&&fr[u+1][v])   dfs(u+1,v);
    if(a[u][v+1]&&fr[u][v+1]) dfs(u,v+1);
    if(a[u-1][v]&&fr[u-1][v])   dfs(u-1,v);
    if(a[u][v-1]&&fr[u][v-1]) dfs(u,v-1);
}
bool check(int x, int y){
    memset(fr, true, sizeof(fr));
    bool ok = true;
    fr[x][y] = false;
    For(i, 1, n)
        For(j, 1, m)if(fr[i][j]&&a[i][j]){
            if(!ok)return true;
            dfs(i, j);
            ok = false;
        }
    return false;
}
int main(){
    //freopen("CF.txt", "r", stdin);
    scanf("%d%d\n", &n, &m);
    memset(a, 0, sizeof(a));
    For(i, 1, n){
        char c;
        For(j, 1, m){
            scanf("%c", &c);
            if(c=='#')a[i][j] = true, cnt++;
        }
        scanf("\n");
    }
    if(cnt<=2){ printf("-1"); return 0; }
    ret = n*m;
    For(i, 1, n)
        For(j, 1, m)if(a[i][j]){
            int sum = 0;
            if(check(i,j))sum=1;
            else
            {
                if(a[i+1][j])sum++;
                if(a[i][j+1])sum++;
                if(a[i-1][j])sum++;
                if(a[i][j-1])sum++;
            }
            if(sum+1<cnt)ret = min(ret, sum);
        }
    printf("%d", ret);
    return 0;
}
