//Language: MS C++


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[500];
int x[500];
int y[500];
int n;

void dfs(int vertex)
{
    visited[vertex] = true;
    for (int i = 1; i <= n; i++)
    {
        if ((x[i - 1] == x[vertex - 1] || y[i - 1] == y[vertex - 1]) && (!visited[i]))
            dfs(i);
    }
}

int main()
{
    cin >> n;
    int answer = 0;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= n; i++)
        if (!(visited[i]))
        {
            dfs(i);
            answer += 1;
        }
    cout << answer - 1 << endl;
}