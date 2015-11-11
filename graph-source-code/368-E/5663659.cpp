//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int n,m,x,y[100000];
    long long a[2010],ans=0;
    for(int i=0;i<2010;i++)
        if((i+1)&1) a[i]=(i+1)*(i)/2+1;
        else a[i]=(i+1)*(i)/2+1+(i-1)/2;
    scanf("%d %d", &n, &m);
    int temp=min(upper_bound(a,a+2010,n)-a,m);
    for(int i=0;i<m;i++)
        scanf("%d %d", &x, &y[i]);
    sort(y,y+m);
    for(int i=m-1;i>=m-temp;i--)
        ans+=y[i];
    printf("%I64d\n",ans);
    //system("PAUSE");
    return 0;
}