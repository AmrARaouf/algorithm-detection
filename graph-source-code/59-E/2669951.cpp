//Language: MS C++


#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

int N , M , K , D[3500][3500] , Par[3500][3500];

map <pair <int , pair<int , int> > , bool> Banned;

vector <int> Graph[3500];

queue <pair <int , int> > Q;

int main()
{
scanf("%d %d %d",&N , &M , &K);
for (int i = 1 ; i <= M ; i ++ )
{
    int L , R ;
    scanf("%d %d",&L , &R);
    Graph[L].push_back(R);
    Graph[R].push_back(L);
};
for (int i = 1 ; i <= K ; i ++ )
{
    int A , B , C;
    scanf("%d %d %d",&A , &B , &C);
    Banned[make_pair(A , make_pair(B , C) )] = true;
};
for (int i = 1 ; i <= N ; i ++ )
    for (int j = 1 ; j <= N ; j ++ )
        D[i][j] = 1 << 30;
D[1][1] = 0;
Q.push(make_pair(1 , 1) );
while ( !Q.empty() )
{
    int v = Q.front().first , par = Q.front().second;
    Q.pop();
    for (int i = 0 ; i < Graph[v].size() ; i ++ )
    {
        int u = Graph[v][i];
        if ( Banned.find(make_pair(par , make_pair(v , u) ) ) != Banned.end() )
            continue;
        if ( D[v][u] > D[par][v] + 1 )
        {
            D[v][u] = D[par][v] + 1;
            Par[v][u] = par;
            Q.push(make_pair(u , v) );
        };
    };
};
int answer = 1 << 30 , cur_par , v = N;
for (int i = 1 ; i < N ; i ++ )
    if ( answer > D[i][N] )
    {
        answer = D[i][N];
        cur_par = i;
    };
if ( answer == 1 << 30 )
{
    printf("-1\n");
    return 0;
};
printf("%d\n",answer);
vector <int> path;
path.push_back(N);
for ( ; Par[cur_par][v] ; )
{
    int u = Par[cur_par][v];
    path.push_back(cur_par);
    v = cur_par;
    cur_par = u;
};
for (int i = path.size() - 1 ; i >= 0 ; i -- )
    printf("%d ",path[i]);
printf("\n");
return 0;
}