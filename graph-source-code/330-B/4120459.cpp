//Language: GNU C++


#include<iostream>
#include<algorithm>
#include <cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include <cstring>
using namespace std;

int degree[3333];
struct node{
    int s,e;
}line[1111111];
bool con[1111][1111];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; i ++){
        degree[i] = n - 1;
    }
    memset(con,1,sizeof(con));
    for(int i = 0 ; i < m ; i ++){
        int a,b;
        scanf("%d%d",&a,&b);
        degree[a]--;
        degree[b]--;
        con[a][b] = 0;
        con[b][a] = 0;
    }
    bool ok = 0;
    int src = 0;
    for(int i = 1 ; i <= n ; i ++){
        if(degree[i] == n - 1)
        {
            ok = 1;
            src = i;
            break;
        }
    }
    if(ok){
        printf("%d\n",n-1);
        for(int i = 1 ; i <= n ; i ++){
            if(i == src)
                continue;

            printf("%d %d\n",i,src);
        }
    }
    return 0;
}
