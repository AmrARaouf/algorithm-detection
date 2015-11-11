//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;

const int MAX=1e6;

int button(int n,int m)
{
    if (n>=m)
        return n-m;
    if (m%2==0)
        return button(n,m/2)+1;
    else
        return button(n,(m+1)/2)+2;
}

int main()
{
    int n,m; cin>>n>>m;
    cout<<button(n,m);
    return 0;
}
