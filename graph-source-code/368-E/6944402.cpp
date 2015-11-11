//Language: GNU C++


#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#define sf(x) scanf("%d", &x)
#define sff(x) scanf("%lf", &x)
#define sfc(x) scanf("%c", &x)
#define pf(x) printf("%d", x)
#define pff(x) printf("%lf", x)
#define pfc(x) printf("%c", x)
#define pfs(x) printf("%s", x)
#define ENDL printf("\n")
#define INF 2147483647
#define pf2(x,y) printf("%d %d", x,y)
#define sf2(x,y) scanf("%d %d", &x,&y)

using namespace std;

typedef long long ll; 


int w[100001];

int main()
{
    int n,m;
    sf2(n,m);
    int q;
    for(int i=0; i<m; i++)
    {
        sf2(q,w[i]);
    }
    sort(w,w+m);
    ll res=0;
    ll k;
    for(int i=0; i<m; i++)
    {
        if((i+1)%2) k=(i+1)*(i)/2;
        else
        k=(i+1)*(i)/2+(i+1)/2-1;
        if(k>=n) break;
        res+=w[m-1-i];
    }
    cout<<res;
    return 0;
}

  










