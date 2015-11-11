//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n,m,node[1000]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>node[i];
    }
    int a,b,c;
    double max=0,answer=0;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        answer=(double)((node[a]+node[b])/c);
        if(answer>max)
        {
            max=answer;
        }
    }
    printf("%.9lf",max);
    return 0;
}
