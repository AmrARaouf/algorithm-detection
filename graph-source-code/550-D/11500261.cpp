//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
int k;
vector <int > go[1100];
int main()
{
   // freopen("in.txt","r",stdin);
    scanf("%d",&k);

    if (k % 2 == 0)
    {
        puts("NO");
        return 0;
    }

    for (int i = 1;i <= k-1;i++) // 1..2k-1
    {
        for (int j = k;j <= 2*k-2;j++)
        {
            go[i].push_back(j);
        }
    }

    for (int i = 1;i <= k-1;i++) go[2*k-1].push_back(i);
    for (int i = k;i <= 2*k-2;i+=2) go[i].push_back(i+1);

    int del = 2*k-1;

    for (int i = 1;i <= k-1;i++) // 1..2k-1
    {
        for (int j = k;j <= 2*k-2;j++)
        {
            go[i+del].push_back(j+del);
        }
    }

    for (int i = 1;i <= k-1;i++) go[2*k-1+del].push_back(i+del);
    for (int i = k;i <= 2*k-2;i+=2) go[i+del].push_back(i+1+del);
    go[2*k-1].push_back(2*k-1+del);


    puts("YES");
    printf("%d %d\n",4*k-2,(4*k-2) * k / 2);
    for (int i = 1;i <= 4*k-2;i++)
    {
        for (int j = 0;j < go[i].size();j++)
        {
            printf("%d %d\n",i,go[i][j]);
        }
    }
}
