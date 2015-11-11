//Language: GNU C++


/* HellGeek */
/* Shiva Bhalla */
/* iit2012077 */

 
#include<stdio.h>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<set>
#include<string>
#include<string.h>
#include<time.h>
#include<iostream>
#include<queue>
#include<stack>
#include<math.h>

#define LL long long
#define FIT(i,t) for(i=0;i<t;i++)
#define FIN(i,n) for(i=0;i<n;i++)
#define FJT(j,t) for(j=0;j<t;j++)
#define FJN(j,n) for(j=0;j<n;j++)
#define MAX2(a,b) a>b?a:b
#define MIN2(a,b) a>b?b:a
#define REP(i,a,b) for(i=a;i<=b;i++)

using namespace std;

int dp[1005][1005];
int mat[6][1005];
int k,n;
int mp[6][1005];

int func(int curr, int prev) 
{
    if(curr == n + 1)
    return 0;
    
    if(dp[curr][prev] != -1)
    return dp[curr][prev];
    
    int flag = 0;
    
    int i,j;
    
    for ( i = 2 ; i <= k ; i++ ) {
        if(mp[i][mat[1][prev]] > mp[i][mat[1][curr]])
        flag = 1;
    }
    int m1,m2;
    
    m1 = m2 = 0;
    
    if(flag == 0) {
            m1 = 1 + func(curr + 1 , curr);
    }
    m2 = func(curr+ 1 , prev);
    
    return dp[curr][prev] = max(m1,m2);
}
    
                      

int main()
{
    int i,j,l,m,t;
    
    cin >> n >> k;
    
    for(i=1;i<=k;i++) {
                     for(j=1;j<=n;j++)  {
                                       cin >> mat[i][j] ;
                     }
    }
    
    memset(dp,-1,sizeof dp);
    
    for(i=1;i<=k;i++) {
                     for(j=1;j<=n;j++) {
                                      mp[i][mat[i][j]] = j;
                     }
    }
    
    mp[1][0] = mp[2][0] = mp[3][0] = mp[4][0] = mp[5][0] = 0;
    mat[1][0] = mat[2][0] = mat[3][0] =  mat[4][0] = mat[5][0] = 0;
    
    l = func(1,0);
    
    cout << l << endl;
    
     
    return 0;
}
