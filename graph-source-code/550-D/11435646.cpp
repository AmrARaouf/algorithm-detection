//Language: GNU C++


#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <memory.h>
#define EPSILON 0.0000001
#define ll long long
#define oo 2000000000
using namespace std;
int k,n,m,arr[300],b1,b2,dis1,dis2;
bool ad[300][300];
int main()
{
    scanf("%d",&k);
    if(k%2==0){
        printf("NO\n");
    }else if(k == 1){
        printf("YES\n2 1\n1 2\n");
    }else{
        printf("YES\n");
        dis1 = dis2 = (k-1)/2;
        b1 = k+k+3,b2 = k+k+4;
        for(int i = 1;i <= (k+1);i++){
            for(int j = i+1;j <= (k+1);j++){
                if(dis1 and !ad[i][b1] and !ad[j][b1]){
                    ad[i][b1] = true;
                    ad[j][b1] = true;
                    m += 2;
                    dis1--;
                }else{
                    ad[i][j] = true;
                    m++;
                }
            }
        }
        for(int i = (k+2);i <= (k+k+2);i++){
            for(int j = i+1;j <= (k+k+2);j++){
                if(dis2 and !ad[i][b2] and !ad[j][b2]){
                    ad[i][b2] = true;
                    ad[j][b2] = true;
                    m += 2;
                    dis2--;
                }else{
                    ad[i][j] = true;
                    m++;
                }
            }
        }
        ad[b1][b2] = 1;
        m++;
        n = b2;
        printf("%d %d\n",n,m);
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                if(ad[i][j]){
                    cnt++;
                    arr[i]++;
                    arr[j]++;
                    printf("%d %d\n",i,j);
                }
            }
        }
    }
    return 0;
}
