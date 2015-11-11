//Language: GNU C++


#include <iostream>
#include <stdio.h>

#define ll long long
using namespace std;

int g[1005]={0};

int main()
{
    int n,m,a,b,r;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        g[a]=1; g[b]=1;
    }
    for(int i = 1; i <=n; i++)
        if(g[i]==0){r=i;break;}
    cout << n-1 << endl;
    for(int i = 1; i <=n; i++)
        if(i!=r)cout <<i <<" " << r << endl;

    return 0;
}

