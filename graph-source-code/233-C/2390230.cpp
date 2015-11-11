//Language: MS C++


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-8
#define DEBUG(a) cout<<#a" = "<<(a)<<endl;
#define DEBUGARR(a,n) for(int i=0;i<(n);i++) {cout<<#a"["<<i<<"] = "<<(a)[i]<<endl;}
#define pi acos(-1.0)
using namespace std;
int nc3[111];
int arr[111][111];
//nc3[100] = 161700
int main()
{
    #ifdef StyleTang_Code
    freopen("123.in","r",stdin);
    freopen("123.out","w",stdout);
    #endif
    int i,j,k;
//    for(i=3;i<=100;i++)
//    nc3[i]=(i*(i-1)*(i-2))/6;
//    DEBUGARR(nc3,101);
    int n;
    while(cin>>n)
    {
        memset(arr,0,sizeof arr);
        for(i=1;i<100;i++)
        arr[0][i]=arr[i][0]=1;
        for(i=2;i<100;i++)
        {
            for(j=1;j<i&&j<=n&&n>0;j++)
            arr[i][j]=arr[j][i]=1,n-=j;
        }
        cout<<"100"<<endl;
        for(i=0;i<100;i++)
        {
            for(j=0;j<100;j++)
            cout<<arr[i][j];
            cout<<endl;
        }
    }
    return 0;
}
