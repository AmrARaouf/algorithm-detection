//Language: GNU C++


#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cctype>
// #include <bits/stdc++.h>
using namespace std;

#define Input_File freopen("input.txt","r",stdin)
#define Output_File freopen("output.txt","w",stdout)

inline int _Int()
{
    char Syed_Zafrul_Lipu [1000];
    scanf("%s", Syed_Zafrul_Lipu );
    return atoi( Syed_Zafrul_Lipu );
}
/*
 *   Syed Zafrul Lipu (ShockProof)
 */
const int M = 1001;

bool edge[M][M];
int n, val[M], cost[M];
vector<int> G[M];

int main()
{
    n=_Int();
    int m= _Int();
    for(int i=1; i<=n; i++) val[i]= _Int(), cost[i]=0;

    int u,v, ans=0;
    for(int i=0; i<m ; i++)
    {
        u= _Int();
        v= _Int();
        if(!edge[u][v])
        {
           ans+=min(val[v],val[u]);
        }
        edge[u][v]=edge[v][u]=1;
    }
    cout<<ans<<endl;
    return 0;
}