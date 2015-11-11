//Language: GNU C++


#include <cstdio>
#include <iostream>
using namespace std;
const int MAX = 1e3;
int r[MAX+5];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        r[a-1]=1;
        r[b-1]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(r[i]==0)
        {
            printf("%d\n",n-1);
            for(int j=0;j<n;j++)
            {
                if(j != i)
                {
                    printf("%d %d\n",i+1,j+1);
                }
            }
            return 0;
        }
    }
    printf("-1");
    return 0;
}