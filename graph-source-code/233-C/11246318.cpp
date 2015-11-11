//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int main()
{
    int K;
    scanf("%d", &K);
    
    int tot=0;
    int v=2;
    
    while(tot<K)
    {
        for(int i=1; i<v && (tot+(i-1))<=K; i++)
        {
            a[i][v]=a[v][i]=1;
            tot+=(i-1);
        }
        v++;
    }
    
    v--;
    
    printf("%d\n", v);
    
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        printf("%d", a[i][j]);
        printf("\n");
    }
    return 0;
}