//Language: MS C++


#include <cstdio>
#include <cstring>
using namespace std;

int gr[500], data[2 * 10000], next[2 * 10000];
int sp = 0;

void addEdge(int a, int b)
{
    data[sp] = b;
    next[sp] = gr[a];
    gr[a] = sp;
    ++sp;
}

int H[500][500][2];
int Prev[500][500][2][3];
int Q[500 * 500 * 4 + 1][3];
int qb = 0, qe = 0;

int main()
{
#ifdef __USER_HOME__
    freopen("1.txt", "r", stdin);
#endif
    memset(gr, -1, sizeof(gr));
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        addEdge(a, b);
        addEdge(b, a);
    }

    memset(Prev, -1, sizeof(Prev));
    H[0][N - 1][0] = 1;
    Q[0][0] = 0;
    Q[0][1] = N - 1;
    Q[0][2] = 0;
    ++qe;

    while (qb < qe)
    {
        int u1 = Q[qb][0], v1 = Q[qb][1], turn = Q[qb][2];
        ++qb;
        int h = H[u1][v1][turn] + 1;
        if (turn == 0)
        {
            for (int j = gr[u1]; j != -1; j = next[j])
            {
                int u2 = data[j];
                if (H[u2][v1][1] == 0)
                {
                    H[u2][v1][1] = h;
                    Prev[u2][v1][1][0] = u1;
                    Prev[u2][v1][1][1] = v1;
                    Prev[u2][v1][1][2] = 0;

                    Q[qe][0] = u2;
                    Q[qe][1] = v1;
                    Q[qe][2] = 1;
                    ++qe;
                }
            }
        }
        else
        {
            for (int j = gr[v1]; j != -1; j = next[j])
            {
                int v2 = data[j];
                if (u1 != v2 && H[u1][v2][0] == 0)
                {
                    H[u1][v2][0] = h;
                    Prev[u1][v2][0][0] = u1;
                    Prev[u1][v2][0][1] = v1;
                    Prev[u1][v2][0][2] = 1;

                    Q[qe][0] = u1;
                    Q[qe][1] = v2;
                    Q[qe][2] = 0;
                    ++qe;
                }
            }
        }
    }

    if (H[N - 1][0][0] == 0)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", (H[N - 1][0][0] - 1) / 2);

    for (int e1 = N - 1, turn = 0, e2 = 0; e2 != -1; )
    {
        if (turn == 0)
            printf("%d ", e2 + 1);
        int ne1 = Prev[e1][e2][turn][0];
        int ne2 = Prev[e1][e2][turn][1];
        turn = Prev[e1][e2][turn][2];
        e1 = ne1;
        e2 = ne2;
    }
    printf("\n");
    for (int e1 = N - 1, turn = 0, e2 = 0; e1 != -1; )
    {
        if (turn == 0)
            printf("%d ", e1 + 1);
        int ne1 = Prev[e1][e2][turn][0];
        int ne2 = Prev[e1][e2][turn][1];
        turn = Prev[e1][e2][turn][2];
        e1 = ne1;
        e2 = ne2;
    }
    printf("\n");
    return 0;
}

