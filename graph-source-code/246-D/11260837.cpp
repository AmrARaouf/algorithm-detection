//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

#define MAX 100010

set<int> Set[MAX], colors;
int color[MAX];
bool visited[MAX];
list<int> graph[MAX];

int main(){
    int n, m, u, v;
    cin>>n>>m;

    for(int i=1 ; i<=n ; i++){
        cin>>color[i];
        colors.insert(color[i]);
    }

    for(int i=0 ; i<m ; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            int s = i;
            visited[s] = true;
            list<int> queue;
            queue.push_back(s);

            while(!queue.empty()){
                s = queue.front();
                queue.pop_front();

                list<int>::iterator j;
                for(j = graph[s].begin() ; j != graph[s].end() ; j++){
                    if(!visited[*j]){
                        visited[*j] = true;
                        queue.push_back(*j);
                    }
                    if(color[s] != color[*j])
                        Set[color[s]].insert(color[*j]);
                }
            }
        }
    }

    int maximum, index, temp;
    index = 0, maximum = -1;

    set<int>::iterator i;
    for(i = colors.begin() ; i != colors.end() ; i++){
        temp = Set[*i].size();
        if(maximum < temp){
            index = *i;
            maximum = Set[*i].size();
        }
    }

    cout<<index<<endl;

    return 0;
}