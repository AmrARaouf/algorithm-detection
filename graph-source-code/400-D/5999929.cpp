//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<sstream>
#include<vector>

using namespace std;

int maximum_number = 1000 + (int) 1e9;
int n, m, k, color[100005];
int current_color = 1;

int dist[505][505];
vector<int> free_methods[100005];

void dfs(int n)
{
    color[n] = current_color;
    vector<int>::iterator it = free_methods[n].begin();
    while (it < free_methods[n].end())
    {
        if (color[*it] == 0)
        {
            color[*it] = current_color;
            dfs(*it);
        }
        it ++;
    }
}
int main()
{


    /*
     * get input
     */
    scanf("%d%d%d", &n, &m, &k);
    int c[k + 5];
    for (int i = 1; i <= k; i++)
        scanf("%d", c + i);
    // initialize dist
    for (int i = 1; i <= k; i++)
    {
        for (int j = i + 1; j <= k; j++)
        {
            dist[i][j] = maximum_number;
            dist[j][i] = maximum_number;
        }
    }

    /*
     * set up type/first_in_type
     * and get methods
     */
    int type[n + 5];
    int first_in_type [k + 5];
    int sum = 0;
    for (int i = 1; i <= k; i++)
    {
        first_in_type[i] = sum + 1;
        for (int j = 1; j <= c[i]; j++)
            type[sum + j] = i;

        sum += c[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v, cost;
        scanf("%d%d%d", &u, &v, &cost);
        if (cost == 0)
        {
            free_methods[u].push_back(v);
            free_methods[v].push_back(u);
        }
        if (dist[type[u]][type[v]] > cost)
        {
            dist[type[u]][type[v]] = cost;
            dist[type[v]][type[u]] = cost;
        }
    }


     /*
      * run dfs
      */
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            dfs(i);
            current_color ++;
        }
    }

     /*
      * check if it's right
      */
    for (int i = 1; i <= n; i++)
    {
        if (color[i] != color[first_in_type[type[i]]])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");

     /*
      * find min 
      */
    for (int middle = 1; middle <= k; middle ++)
    {
        for (int u = 1;  u <= k; u++)
        {
            for (int v = u + 1;  v <= k; v++)
            {
                int new_cost = dist[u][middle] + dist[middle][v];
                if (dist[u][v] > new_cost)
                {
                    dist[u][v] = new_cost;
                    dist[v][u] = new_cost;
                }
            }
        }
    }

    for (int u = 1;  u <= k; u++)
    {
        for (int v = 1;  v <= k; v++)
        {
            cout << (dist[u][v] == maximum_number ? -1 : dist[u][v]);
            if (v + 1 <= k)
                printf(" ");
            else
                printf("\n");
        }
    }

    return 0;
}

