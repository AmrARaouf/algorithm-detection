//Language: GNU C++


//
//  main.cpp
//  cf3
//
//  Created by chengshuo on 14-9-5.
//  Copyright (c) 2014年 chengshuo. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define mod 1000000007
#define maxn 100005

using namespace std;

vector<int> con[maxn];

long long dp[maxn][2];

int check[maxn];

void init() {
    memset(dp,0,sizeof(dp));
    memset(check,0,sizeof(check));
    int n,u;
    scanf("%d",&n);
    for (int i=1;i<n;i++) {
        scanf("%d",&u);
        con[u].push_back(i);
    }
    for (int i=0;i<n;i++) {
        scanf("%d",&check[i]);
    }
}

void dfs(int u) {
    if (check[u]) {
        dp[u][0]=0;
        dp[u][1]=1;
    }
    else {
        dp[u][1]=0;
        dp[u][0]=1;
    }
    for (int i=0;i<con[u].size();i++) {
        int v=con[u][i];
        dfs(v);
        dp[u][1]=dp[u][1]*(dp[v][0]+dp[v][1])+dp[u][0]*dp[v][1];
        dp[u][0]=dp[u][0]*(dp[v][0]+dp[v][1])%mod;
        dp[u][1]%=mod;
    }
}

int main(int argc, const char * argv[])
{
    init();
    dfs(0);
    printf("%lld",dp[0][1]);
    return 0;
}
