//Language: MS C++


#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

int k , n , m , c[200000];
map <int , int> Tr;
map <int , int> DeTr;
vector <int> graph[200000];
set <int> clr[200000];

int main()
{
scanf("%d %d",&n,&m);
for (int i = 1 ; i <= n ; i ++ )
{
    scanf("%d",&c[i]);
    if ( !Tr[c[i]] )
    {
        Tr[c[i]] = ++k;
        DeTr[k] = c[i];
    };
    c[i] = Tr[c[i]];
};
for (int i = 1 ; i <= m ; i ++ )
{
    int L , R ;
    scanf("%d %d",&L,&R);
    graph[L].push_back(R);
    graph[R].push_back(L);
};
int max_p = -1 , min_ans = 2e9;
for (int i = 1 ; i <= n ; i ++ )
    for (int j = 0 ; j < graph[i].size() ; j ++ )
        if ( c[graph[i][j]] != c[i] )
            clr[c[i]].insert(c[graph[i][j]]);
for (int i = 1 ; i <= k ; i ++ )
    max_p = max(max_p , (int)clr[i].size() );
for (int i = 1 ; i <= k ; i ++ )
    if ( clr[i].size() == max_p )
        min_ans = min(min_ans , DeTr[i]);
printf("%d\n",min_ans);
return 0;
}