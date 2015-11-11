//Language: GNU C++


#include <bits/stdc++.h>
using namespace std; 
#define PII pair <int, int> 
#define PXI pair <int, PII>
map <PII, int> isbroken, thereal, done; vector <int> edges[100005]; int dist[100005]; int vis[100005]; 
int ans[100005]; int first[100005]; 
void djikstra ()
{
    priority_queue <PXI, vector <PXI>, greater <PXI> > k; 
    k.push(PXI(0, PII(0, 1)));
    ans[1]=0; 
    while (k.size())
    {
        int distance=k.top().first; 
        int badedges=k.top().second.first; 
        int node=k.top().second.second;
        k.pop(); 
        if (ans[node]<badedges) continue; 
        for (int y=0; y<edges[node].size(); y++)
        {
            int weight=(isbroken[PII(edges[node][y], node)]==1) ? 0 : 1; 
            if (dist[edges[node][y]]==distance+1 && badedges+weight<ans[edges[node][y]])
            {
                ans[edges[node][y]]=badedges+weight; 
                first[edges[node][y]]=node; 
                k.push(PXI(distance+1, PII(badedges+weight, edges[node][y])));
            }
        }
    }
}
main()
{
    for (int g=0; g<=100000; g++) ans[g]=1e9;
    vector <PII> roads;  
    priority_queue <int> b; 
    int a, e; cin >> a >> e;
    int num1=0; 
    for (int g=0; g<e; g++)
    {
       int u, i, y; cin >> u >> i >> y; 
       roads.push_back(PII(u, i)); 
       if (y==1) num1++; 
       isbroken[PII(u, i)]=y; 
       thereal[PII(u, i)]=1; 
       isbroken[PII(i, u)]=y; 
       edges[u].push_back(i); 
       edges[i].push_back(u); 
    }
    queue <PII> z; 
    vis[1]=1; 
    z.push(PII(0, 1)); 
    while (z.size())
    {
        int dista=z.front().first; 
        int node=z.front().second; 
        z.pop(); 
        for (int y=0; y<edges[node].size(); y++)
        {
            if (vis[edges[node][y]]) continue;
            dist[edges[node][y]]=dista+1; 
            vis[edges[node][y]]=1; 
            z.push(PII(dista+1, edges[node][y])); 
        }
    }
    djikstra (); 
    cout << (num1-dist[a]+ans[a])+ans[a] << '\n';
    vector <int> l; int node=a;  
    while (node!=0)
    {
        l.push_back(node); node=first[node]; 
    }
    reverse(l.begin(), l.end()); 
    for (int g=0; g<l.size()-1; g++)
    {
        done[PII(l[g], l[g+1])]=1; 
        done[PII(l[g+1], l[g])]=1;
        if (isbroken[PII(l[g], l[g+1])]) continue; 
        if (thereal[PII(l[g], l[g+1])]) cout << l[g] << ' ' << l[g+1] << ' ' << 1<< '\n'; 
        else cout << l[g+1] << ' ' << l[g] <<' ' << 1 << '\n'; 
    }
    for (int g=0; g<roads.size(); g++)
    {
        if (done[roads[g]]) continue; 
        if (!isbroken[roads[g]]) continue;
        if (thereal[roads[g]]){
            cout << roads[g].first << ' ' << roads[g].second << ' ' << 0 << '\n'; 
        }
        else cout << roads[g].second << ' ' << roads[g].first << ' ' << 0 << '\n'; 
    }
    return 0; 
}