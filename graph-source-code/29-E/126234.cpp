//Language: GNU C++


#include <stdio.h>
#include <memory.h>
#define MAX 501
int G[MAX][MAX];
int rl[MAX];
bool hash[MAX][MAX];
int frouta[MAX*MAX];
int froutb[MAX*MAX];
struct node
{
    int index;
    int location_a;
    int location_b;
    int t;
    int pre;
}q[MAX*MAX];
int bfs(int n)
{
    int i, j, k, cc = 1;
    int head , tail ;
    node cur, next;
    head = tail = 0;
    memset(hash, false, sizeof(bool) * n * n);
    q[0].location_a = 0;
    q[0].location_b = n - 1;
    q[0].pre = -1;
    q[0].t = 0;
    q[0].index = 0;
    tail ++;
    hash[q[0].location_a][q[0].location_b] = true;
    while(head < tail)
    {
        cur = q[head ++];
        next.t = cur.t + 1;
        for(i = 0; i < rl[cur.location_a]; i ++)
        {
            
            for(j = 0; j < rl[cur.location_b]; j ++)
            {
                next.location_a = G[cur.location_a][i] ;
                next.location_b = G[cur.location_b][j] ;
                if(hash[next.location_a][next.location_b] == false && next.location_a != next.location_b )
                {
                    next.pre = cur.index;
                    next.index = tail;
                    hash[next.location_a][next.location_b] = true;
                    q[tail] = next;
                    tail ++;
                    if(next.location_a == n - 1 && next.location_b == 0)
                    {
                        for(cur = q[tail - 1], k = next.t; ;  cur = q[cur.pre], k --)
                        {
                            frouta[k] = cur.location_a;
                            froutb[k] = cur.location_b;
                            if(k == 0)
                                return next.t;
                        }
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    int n, m, i, j, a, b;
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%d %d", &a, &b);
        G[a - 1][rl[a-1] ++ ] = b - 1;
        G[b - 1][rl[b-1] ++ ] = a - 1;
    }
    int t = bfs(n);
    if(t == -1)
        printf("-1\n");
    else 
    {
        printf("%d\n", t);
        
        printf("%d", frouta[0] + 1);
        for(i = 1; i <= t; i ++)
            printf(" %d", frouta[i] + 1);
        printf("\n");
        printf("%d", froutb[0] + 1);
        for(i = 1; i <= t; i ++)
            printf(" %d", froutb[i] + 1);
        printf("\n");
    }
    
}