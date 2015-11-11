//Language: GNU C++


#include <stdio.h>
#include <vector>

using namespace std;

vector<int> vA;

int rec(int n)
{
    return (n*(n-1)*(n-2))/6;
}

int rec2(int n)
{
    return (n*(n-1))/2;
}

int main()
{
    int k, sumA=0;

    scanf(" %d", &k);

    int n = 2;
    while(++n)
    {
        if(rec(n) > k)
            break;
    }

    sumA += rec(--n);
    while(sumA != k)
    {
        for(int i=2; i<=n; i++)
        {
            if(sumA+rec2(i) > k)
            {
                sumA += rec2(i-1);
                vA.push_back(i-1);
                break;
            }
        }
    }

    printf("%d\n",  n + vA.size());

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<= n + vA.size(); j++)
        {
            if(i==j)
                printf("0");
            else if(j <= n)
                printf("1");
            else if(j > n && vA[j-n-1] >= i)
                printf("1");
            else
                printf("0");
        }
        if(i != n + vA.size())
            printf("\n");
    }

    for(int i=n+1; i <=n + vA.size(); i++)
    {
        for(int j=1; j<=n + vA.size(); j++)
        {
            if(j > vA[i-n-1])
                printf("0");
            else
                printf("1");
        }
        if(i != n + vA.size())
            printf("\n");
    }
    return 0;
}
