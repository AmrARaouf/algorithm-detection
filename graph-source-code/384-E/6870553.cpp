//Language: GNU C++


#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX (int)3e5

typedef pair<int, int> pii;

bool vis[MAX+5];
int arr[MAX+5], levelof[MAX+5], real[MAX+5], mp_even, mp_odd, even_bit[MAX+5], odd_bit[MAX+5];
vector<int > adj[MAX+5];
pii odd_range[MAX+5], even_range[MAX+5];

int Read(int (&bit)[MAX+5], int x){
    int ret = 0;
    while (x > 0){
        ret += bit[x];
        x -= (x&(-x));
    }
    return ret;
}

void Update(int (&bit)[MAX+5], int x, int val){
    if (!x) return ;
    while (x <= MAX){
        bit[x] += val;
        x += (x&(-x));
    }
    return ;
}

void UpdateRange(int (&bit)[MAX+5], int s, int e, int val){
    if (!s) return ;
    Update(bit, s, val);
    Update(bit, e+1, -val);
}

void DFS (int node, int level){
    int cur_odd = mp_odd, cur_even = mp_even;
    vis[node] = 1;
    
    levelof[node] = level;
    if (level & 1) real[node] = ++mp_odd, UpdateRange(odd_bit, mp_odd, mp_odd, arr[node]);
    else real[node] = ++mp_even, UpdateRange(even_bit, mp_even, mp_even, arr[node]);
    
    for (int i = 0 ; i < (int)adj[node].size() ; i ++){
        if (vis[adj[node][i]]) continue;
        DFS(adj[node][i], level+1);
    }
    
    if (cur_odd < mp_odd) odd_range[node] = pii(cur_odd+1, mp_odd);
    if (cur_even < mp_even) even_range[node] = pii(cur_even+1, mp_even);
}

int main(){
    // freopen("in.in", "r", stdin);
    
    int N, Q, node, val, check;
    
    scanf("%d %d",&N,&Q);
    for (int i = 1 ; i <= N ; i ++)
        scanf("%d",&arr[i]);
    for (int i = 0 ; i < N-1 ; i ++){
        scanf("%d %d",&node,&val);
        adj[node].push_back(val);
        adj[val].push_back(node);
    }
    
    DFS(1, 1);
    
    /*for (int i = 1 ; i <= N ; i ++){
        printf("Node %d: ",i);
        if (levelof[i] & 1) printf("[%d]\n",odd_bit[real[i]]);
        else printf("[%d]\n",even_bit[real[i]]);
        printf("\tEven: %d %d\n",even_range[i].first, even_range[i].second);
        printf("\tOdd: %d %d\n",odd_range[i].first, odd_range[i].second);
    }*/
    
    for (int i = 0 ; i < Q ; i ++){
        scanf("%d %d",&check,&node);
        if (check == 1){
            scanf("%d",&val);
            
            UpdateRange(odd_bit, odd_range[node].first, odd_range[node].second, levelof[node]&1? val : -val);
            UpdateRange(even_bit, even_range[node].first, even_range[node].second, levelof[node]&1? -val : val);
        }else printf("%d\n",Read(levelof[node] & 1? odd_bit : even_bit, real[node]));
    }
    
    return 0;
    
}
