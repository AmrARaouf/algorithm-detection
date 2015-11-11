//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define For(i,s,t) for (int i=s; i<=t; i++)
#define log 29
int ways;
bool G[999][999];

int id(int x,int y) {return x*30+y+3;}
void AddEdge(int u,int v) {G[u][v]=G[v][u]=true;}

int main() {
    scanf("%d",&ways);
    For(i,0,log) AddEdge(1,id(0,i));
    For(i,1,log) {
        For(j,0,log) AddEdge(id(i-1,j),id(i,j));
        For(j,i,log) AddEdge(id(i-1,j-1),id(i,j));
    }
    For(i,0,log) if (ways&(1<<i))
        AddEdge(id(log,i),2);
    printf("902\n");
    For(i,1,902) {
        For(j,1,902) printf("%c",G[i][j]?'Y':'N');
        printf("\n");
    }
    return 0;
}