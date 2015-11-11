//Language: GNU C++


/*
    ID : ping128
    LANG : C++
*/
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <algorithm>
#include <map>

#define INF (1<<30)

using namespace std;

typedef pair<int,int>PII;
typedef pair<PII,int>PII2;
typedef long long LL;

// first four directions + four diagonal directions + itself
int cx[]={-1,0,0,1,-1,-1,1,1,0},cy[]={0,-1,1,0,-1,1,1,-1,0};

int ingrid(int ii,int jj,int R,int C){
    if(ii < 0 || jj < 0 || ii >= R || jj >= C) return 0;
    return 1;
}

// ----------------------------------------------------------------------------------------------------------------

int par[100005];

int find(int x){
    if(x == par[x]) return x;
    else {
        int a = find(par[x]);
        par[x] = a;
        return a;
    }
}

int main(){
    int a,b;
    int n,m;
    long long sol = 1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) par[i] = i;
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        int x = find(a);
        int y = find(b);
        if(x == y){
            sol *= 2;
            sol %= 1000000009;
        } else par[x] = y;
        cout << (sol + 1000000009 - 1 ) % 1000000009 << endl;
    }
    



return 0;
}

