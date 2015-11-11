//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>
#include <fstream>
 
using namespace std;
//typedefs
typedef long long ll; 
typedef unsigned long long ull;
typedef pair<int,int> pii;
 
 
#define MOD 1000000007
 
bool isReachable(vector<int>  adj[],int s, int d,int V)
{
    // Base case
    if (s == d)
      return true;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // it will be used to get all adjacent vertices of a vertex
    vector<int>::iterator i;
 
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // If this adjacent node is the destination node, then return true
            if (*i == d)
                return true;
 
            // Else, continue to do BFS
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
 
    return false;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    
    vector<int> graph[101][101];
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            graph[i][j].clear();
        }
    }
    int a, b,c,n,m;
    cin>>n>>m;
    
   // cout<<"memmory allocated!\n";
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        
        
        graph[c][a].push_back(b);
        graph[c][b].push_back(a);

    }

 /*   for(int k=0;k<=m;k++){
        cout<<"Graph in color K="<<k<<":\n";
        for(int i=1;i<=n;i++){
            cout<<i<<": ";
            for(int j=0;j<graph[k][i].size();j++){
                cout<<graph[k][i][j]<<" ";
            }cout<<endl;
        }cout<<endl;
    }cout<<endl;
*/
    int q;
    cin>>q;
    int count;
    while(q--){
        cin>>a>>b;
        count=0;
        for(int i=1;i<=m;i++){
            if(isReachable(graph[i],a,b,n+1)){
                count++;
                //cout<<a<<" "<<b<<" reachable in color:"<<i<<endl;
            }
        }
        
        cout<<count<<endl;
    }
    //system("pause");
    return 0;
}
