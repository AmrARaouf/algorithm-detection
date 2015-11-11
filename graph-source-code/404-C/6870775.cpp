//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int ver[111111];
vector <int> A[111111];
vector <int> G[111111];
int size[111111];
int main()
{
//    freopen("data.in", "r", stdin);
    int n, k, dis, Max, flag, cnt = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i <= n; i++) ver[i] = 0;
    Max = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &dis);
        A[dis].push_back(i);
        Max = max(Max, dis);
    }

    for(int i = 0; i <= Max; i++)
        size[i] = A[i].size();
    if(size[0] != 1)
    {
        puts("-1");
        return 0;
    }
    for(int i = 1; i <= Max; i++)
    {
        for(int j = 0; j < size[i]; j++)
        {
            int v = A[i][j];
            flag = 0;
            if(ver[v] < k)
            {
                int u;
                for(int p = 0; p < size[i-1]; p++)
                {
                    u = A[i-1][p];
                    if(ver[u] < k)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag)
                {
                    G[u].push_back(v);
                    cnt++;
                    ver[u]++;
                    ver[v]++;
                }

            }
            if(!flag)
            {
                puts("-1");
                return 0;
            }
        }
    }
    printf("%d\n", cnt);
    for(int i = 1; i <= n; i++)
    {
        for(vector<int>::iterator it = G[i].begin(); it != G[i].end(); it++)
        {
            printf("%d %d\n", i, *it);
        }
    }
    return 0;
}
		  	  		 		  	 	  						