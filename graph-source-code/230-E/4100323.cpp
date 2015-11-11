//Language: GNU C++


#include<iostream>
#define int long long
using namespace std;

int deg[1000001];

main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        cin>>a>>b;
        deg[a]++;
        deg[b]++;
    }
    int ans = n * (n - 1) * (n - 2) / 6, t=0;
    for (int i=1;i<=n;i++)
        t += deg[i] * (n - deg[i] - 1);
    cout<<ans - t / 2<<endl;
    return 0;
}