//Language: GNU C++


#include <bits/stdc++.h>
#define MAXN 200000
#define BASE 62
using namespace std;

int n;
int acnt;
int ANS[MAXN+10];

void init()
{
}

inline int c2i(char c) {
    if(islower(c))  return c - 'a';
    else if(isupper(c)) return c - 'A' + 26;
    else return c - '0' + 52;
}
inline char i2c(int c) {
    if(c < 26)  return c + 'a';
    else if(c < 52) return c + 'A' - 26;
    else return c + '0' - 52;
}

inline int encode(char c1, char c2)
{
    return c2i(c1) * BASE + c2i(c2);
}

struct Graph
{   
    int inDeg[MAXN+10];
    int outDeg[MAXN+10];
    int s, t;
    int max_node;
    
    /*
    struct node
    {
        int v;
        bool vis;
        node* next;
    } Nodes[2*MAXN+10], *adj[2*MAXN+10], *ecnt;
    */
    
    int G[3844 + 2][3844 + 2];
    
    void init()
    {
        max_node = 0;
    }
    
    inline void addedge(int u, int v)
    {
        max_node = max(max(u,v), max_node);
        
        outDeg[u]++;
        inDeg[v]++;
        
        G[u][v]++;
    }
    
    bool is_euler()
    {
        s = t = -1;
        int pos = -1;
        
        for (int i=0; i <= max_node; i++)
        {
            if (inDeg[i] != outDeg[i])
            {
                if (inDeg[i] - outDeg[i] == 1 && t < 0) 
                    t = i;
                else if (outDeg[i] - inDeg[i] == 1 && s < 0) 
                    s = i;
                else 
                    return false;
            }
            if (inDeg[i] || outDeg[i]) pos = i;
        }
        if (s < 0) s = pos;
        
        acnt = 0;
        dfs(s);
        
        return acnt + 1 >= n;
    }
    
    void dfs(int u)
    {
        for (int v = 0; v <= max_node; v++)
        {
            while (G[u][v])
            {
                G[u][v]--;
                dfs(v);
                ANS[acnt++] = v;
            }
        }
    }
    
    void prt()
    {
        printf("%c%c", i2c(s / BASE), i2c(s % BASE));
        while (acnt)
        {
            int v = ANS[--acnt];
            printf("%c", i2c(v % BASE));
        }
    }
} G;

char buff[100];

void read()
{
    G.init();
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%s", buff);
        int u = encode(buff[0], buff[1]);
        int v = encode(buff[1], buff[2]);
        G.addedge(u, v);
    }
}

int main()
{
    //freopen("tanya.in", "r", stdin);
    init();
    read();
    if (G.is_euler())
    {
        printf("YES\n");
        G.prt();
    }
    else
    {
        printf("NO");
    }
}