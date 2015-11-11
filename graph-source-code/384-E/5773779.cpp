//Language: GNU C++


#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

vector <int> graph [200010];
int tree [3] [200010], n, m, parent [200010], values [200010], range [200010];
bool divisible [200010];

void update (int ind, int index, int value)
{
    while (index <= n)
    {
        tree [ind] [index] += value;
        index += index & (-index);
    }
}
int get(int ind, int index)
{
    if (index == 0)
        return 0;
    int sum = 0;
    while (index)
    {
        sum += tree [ind] [index];
        index -= index & (-index);
    }
    return sum;
}

int global_node0, global_node1, node_index [200010];

int dfs0 (int current_node, int div)
{
    if (!div)
    {
        global_node0++;
        node_index [current_node] = global_node0;
        divisible [current_node] = false;
    }
    for (int i = 0; i < graph [current_node].size(); i++)
    {
        parent [graph [current_node] [i]] = current_node;
        range [current_node] += dfs0 (graph [current_node] [i], !div);
    }

    return range [current_node] + !div;
}

int dfs1 (int current_node, int div)
{
    int tmp;
    if (div)
    {
        global_node1++;
        node_index [current_node] = global_node1;
        divisible [current_node] = true;
    }
    else
        tmp = range [current_node];

    range [current_node] = 0;

    for (int i = 0; i < graph [current_node].size(); i++)
        range [current_node] += dfs1 (graph [current_node] [i], !div);

    int new_value = range [current_node];

    if (!div)
    {
        range [current_node] = tmp;
        return new_value;
    }
    else
        return range [current_node] + 1;
}

int get_range(int ind, int start, int end)
{
    return get (ind, end) - get (ind, start - 1);
}

int get_value (int ind, int index)
{
    return get(ind, index) - get(ind, index - 1);
}

int main()
{
    FILE *in = stdin;

    fscanf (in, "%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        fscanf (in, "%d", &values [i]);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;

        fscanf (in, "%d %d", &a, &b);

        graph [a].push_back (b);
    }

    dfs0 (1, 0);
    dfs1 (1, 0);

    for (int i = 1; i <= n; i++)
    {
        update (divisible [i], node_index [i], values [i]);
        update (divisible [i], node_index [i] + 1, -values [i]);

    }

    int q;

    while (m--)
    {
        fscanf (in, "%d", &q);
        if (q == 1)
        {
            int x, val;
            fscanf (in, "%d %d", &x, &val);

            update (divisible [x], node_index [x], val);
            update (divisible [x], node_index [x] + range [x] + 1, -val);

            val = -val;

            for (int i = 0; i < graph [x].size(); i++)
            {
                update (!divisible [x], node_index [graph [x] [i]], val);
                update (!divisible [x], node_index [graph [x] [i]] + range [graph [x] [i]] + 1, -val);
            }
        }
        else
        {
            int x;
            fscanf (in, "%d", &x);
            printf ("%d\n", get (divisible [x], node_index [x]));
        }
    }


    return 0;
}





