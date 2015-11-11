//Language: GNU C++0x


#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include <map>
#include <set>
#include <limits.h>
#include <cmath>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int a[2001],f[2001] = {0}, n;

int dfs(int i) {
    if (f[i]) return f[i];
    if (a[i]==-1) return f[i]=1;
    return f[i]=1+dfs(a[i]);    
}

int main(){
    cin>>n;
    memset(f,0,sizeof(int)*2001);
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    int ans=0;
    for (int i = 1; i <=n; i++)
        ans=max(dfs(i),ans);
    cout<<ans<<endl;
}
