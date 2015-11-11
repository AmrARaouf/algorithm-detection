//Language: MS C++


#include <iostream>

using namespace std;
const int MAXN = 2100;

int DFN[MAXN], LOW[MAXN],index,instack[MAXN],Stap[MAXN],Belong[MAXN],Bcnt,Stop;

struct edge{
    int t;
    edge *next;
};

edge *V[MAXN];
edge all[MAXN*MAXN];
int cnt = 0;
void add(int u, int v){
    edge *x = &all[cnt++];
    x->t = v;
    x->next = V[u];
    V[u] = x;
}

void init(){
    memset(DFN, 0, sizeof(DFN));
    memset(LOW, 0, sizeof(LOW));
    memset(V, 0, sizeof(V));
    Stop = Bcnt = index = 0;
}
void tarjan(int i)
{
    int j;
    DFN[i] = LOW[i] = ++index;
    instack[i] = true;
    Stap[++Stop] = i;
    for (edge *e = V[i]; e; e = e->next)
    {
        j = e->t;
        if (!DFN[j])
        {
            tarjan(j);
            if (LOW[j] < LOW[i])
                LOW[i] = LOW[j];
        }
        else if (instack[j] && DFN[j] < LOW[i])
            LOW[i] = DFN[j];
    }
    if (DFN[i] == LOW[i])
    {
        Bcnt++;
        do
        {
            j = Stap[Stop--];
            instack[j] = false;
            Belong[j] = Bcnt;
        } while (j != i);
    }
}

int main(){

    int n,tmp;
    cin >> n;
    init();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &tmp);
            if (tmp) add(i, j);
        }
    }
    bool f = false;
    for (int i = 1; i <= n; i++){
        if (!DFN[i]) {
            if (f==false)
            tarjan(i), f = true;
            else {
                puts("NO");
                return 0;
            }
        }
        
    }
    if (Bcnt == 1) puts("YES");
    else puts("NO");
}