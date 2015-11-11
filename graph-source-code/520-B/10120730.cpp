//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    if(m<=n){
        printf("%d\n",n-m);
    }
    else{
        int count=0;
        while(n<m){
            count++;
            if(m%2==0){
                m/=2;
            }
            else{
                m++;
            }
        }
        printf("%d\n",count+n-m);
    }
    return 0;
}