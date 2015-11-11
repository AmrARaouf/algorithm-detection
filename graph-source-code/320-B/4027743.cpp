//Language: GNU C++


/*
Imagine the intervals as nodes of a graph and draw directed edges between them as defined in the statement. 
Now answering the second query would be trivial if you are familiar with graph traversal algorithms like DFS or BFS or even Floyd-Warshall!
*/

#include<iostream>
#include<string.h>
using namespace std;
int a[111],b[111];bool f[111];int n = 0;int k;int x,y,m;

void dfs(int i)
{
    f[i] = true; // mark the present visited vertex
    
    if (i==y) 
        {cout << "YES" << endl;return;}
        
    for(int k = 1; k <= n;k++)
    {
        if(f[k]) // if kth vertex is visited
            continue;
        if(a[i]>a[k] && a[i] < b[k])
            dfs(k);
        else if(b[i] > a[k] && b[i] < b[k])
            dfs(k);
    }
}

int main()
{
    cin >> k;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(f,0,sizeof(f));
    for(int i = 1; i <= k; i++)
    {
        cin >> m;
        if(m == 1)
        {
            n++;
            cin >> a[n];
            cin >> b[n];
        }
        if(m == 2)
        {
            cin >> x;
            cin >> y;
            memset(f,0,sizeof(f));
            dfs(x);
            if(!f[y]) // if yth vertex visited
                cout << "NO" << endl;
                
        }
    }
}