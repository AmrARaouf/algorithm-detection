//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#include <set>
#include <cmath>
using namespace std;
//for(map<int,int>::iterator mit = mp.begin(); mit != mp.end(); ++mit)
//ios::sync_with_stdio(false);
//map<int,int> mp;
#define mod  1000000007
#define MAX 10005
#define ll long long
using namespace std;
int n , Order[600];
long long F[510][510][2] , answer[510];
bool used[600];
int main()
{
    scanf("%d",&n);
    for (int i = 1 ; i <= n ; i++) for (int j = 1 ; j <= n ; j ++ ) scanf("%I64d", &F[i][j][1]);
    for (int i = 1 ; i <= n ; ++i) scanf("%d", &Order[i]);
    for (int k = n ; k >= 1 ; k -- )
    {
        used[Order[k]] = true;
        for (int i = 1 ; i <= n ; ++i)
            for (int j = 1 ; j <= n ; ++j)
                F[i][j][0] = min(F[i][Order[k]][1] + F[Order[k]][j][1] , F[i][j][1]);
        long long sum = 0 ;
        for (int i = 1 ; i <= n ; i ++ )
            if (used[i])
                for (int j = 1 ; j <= n ;  ++j)
                    if ( used[j] )
                        sum += F[i][j][0];
        answer[k] = sum;
    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= n ; ++j)
                F[i][j][1] = F[i][j][0] , F[i][j][0] = 0;
    };
    for (int t = 1 ; t <= n ; ++t){
        printf("%I64d ",answer[t]);
    }
}
