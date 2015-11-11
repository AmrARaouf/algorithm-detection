//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

const double EPS = 1e-8, PI = atan(1) * 4;
const int M = 1e5+100, K = 555;

struct Rela{
    int u,v,w;
} r[M];
int nums[K];


int n, m, k;

int father[M];

int find(int x){
    return father[x] == -1 ? x : father[x] = find(father[x]);
}

bool ok(int begin, int end){

//    printf("%d %d\n", begin, end);
    if(begin == end)
        return true;

    int f = find(begin);
    for(int i = begin+1; i <= end; i++){
        int f2 = find(i);
        if(f2 != f)
            return false;
    }

    return true;
}

bool _union(int u, int v){

    int f1 = find(u);
    int f2 = find(v);
    if(f1 == f2)
        return false;
    father[f1] = f2;
    return true;
}

int low[K], high[K];

bool check(){

    memset(father, -1, sizeof(father));
    for(int i = 0; i < m; i++){
        if(!r[i].w)
        _union(r[i].u, r[i].v);
    }

//     for(int i = 1; i <= n; i++)
//        printf("%d ", find(i));
//    puts("");

    int begin = 1;
    for(int i = 0, j = 1; i < k; i++, j++){
        low[j] = begin;
        high[j] = begin + nums[i] - 1;
        if(!ok(low[j], high[j]))
            return false;
//        printf("%d %d %d\n", low[j], high[j], ok(low[j],high[j]));
        begin += nums[i];
    }


    return true;
}

int d[K][K];

int turn(int u){
    for(int i = 1; i <= k; i++)
        if(u >= low[i] && u <= high[i])
            return i;
    return -1;
}

void build(){
    memset(d, -1, sizeof(d));
    for(int i = 1; i <= k; i++)
        d[i][i] = 0;
    for(int i = 0; i < m; i++){
        int u = turn(r[i].u);
        int v = turn(r[i].v);
        int w = r[i].w;

        if(d[u][v] == -1 || d[u][v] > w)
            d[u][v] = d[v][u] = w;
    }
}

void floyd(){

    int n = k;

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            if(d[i][k] != -1)
                for(int j = 1; j <= n; j++)
                    if(d[k][j] !=-1){//
                    int tmp = d[i][k] + d[k][j];
                    if(d[i][j] == -1 || (d[k][j] != -1 && d[i][j] > tmp))
                    d[j][i] = d[i][j] = tmp;
                }
}

void print(){
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++)
            printf(j==k? "%d\n":"%d ",d[i][j]);
    }
}

int main()
{
//    freopen("in", "r", stdin);

    while(~scanf("%d%d%d", &n, &m, &k)){
        for(int i = 0; i < k; i++)
            scanf("%d", nums + i);
        for(int i = 0; i < m; i++)
            scanf("%d%d%d", &r[i].u, &r[i].v, &r[i].w);
        if(!check()){
            puts("No");
            continue;
        }


        build();

        puts("Yes");
        floyd();
        print();
    }

    return 0;
}
