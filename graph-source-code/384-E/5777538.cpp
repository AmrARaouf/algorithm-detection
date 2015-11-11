//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
typedef long long lld;

struct CV
{
    lld from, to;
};
struct Q
{
    lld vert, dist;
};


lld n, m, queries;

vector<lld> Graph[200002], fg[200002];
lld nickname[200002], real[200002];

lld initv[200002];

bool evendist[200002];

bool TFO[200002];
CV cover[200002];
lld cnt = 0;

void GiveName (lld vert)
{
    TFO[vert] = true;

    cnt++;
    nickname[vert] = cnt;
    real[cnt] = vert;
    cover[vert].from = cnt;


    lld i, j;
    for (i=0;i<fg[vert].size();i++)
    {
        if (TFO[fg[vert][i]]) continue;

        GiveName(fg[vert][i]);
    }

    cover[vert].to = cnt;
}

void FillDist()
{
    memset(TFO, 0, sizeof(TFO));

    queue<Q> q;
    Q helper, cur;
    lld i, j;

    helper.vert = 1;
    helper.dist = 0;
    q.push(helper);

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        evendist[cur.vert] = (cur.dist % 2 == 0);

        for (i=0;i<Graph[cur.vert].size();i++)
        {
            if (TFO[Graph[cur.vert][i]]) continue;

            TFO[Graph[cur.vert][i]] = true;

            helper.vert = Graph[cur.vert][i];
            helper.dist = cur.dist + 1;
            q.push(helper);
        }
    }
}

struct Element
{
    lld l, r;
    lld ev, nev;
};

struct IntervalTree
{
    Element IT[700002];
    lld lbeg, lend;

    void Initialize(lld elements)
    {
        lld i, j;

        lbeg = 1;
        while (lbeg < elements)
        {
            lbeg *= 2;
        }

        lend = lbeg + elements -1;

        for (i=lbeg; i<=lbeg*2; i++)
        {
            IT[i].l = i - lbeg + 1;
            IT[i].r = IT[i].l;
            IT[i].ev = 0;
            IT[i].nev = 0;
        }

        for (i=lbeg-1; i>=1; i--)
        {
            IT[i].l = IT[i*2].l;
            IT[i].r = IT[i*2+1].r;
            IT[i].ev = 0;
            IT[i].nev = 0;
        }
    }

    lld GetAnswer(lld vert, bool even)
    {
        lld cur = vert + lbeg - 1;
        lld ret = 0;

        while (cur > 0)
        {
            if (even)
            {
                ret += IT[cur].ev;
            }
            else
            {
                ret += IT[cur].nev;
            }

            cur /= 2;
        }

        return ret;
    }

    void Update(lld ind, lld from, lld to, lld add, bool even)
    {
        if (ind > lend) return;

        if (IT[ind].l > to || IT[ind].r < from) return;

       // cout<<"Vruh "<<ind<<" pokriva ot "<<IT[ind].l<<" do "<<IT[ind].r<<", nie tursim ot "<<from<<" do "<<to<<endl;

        if (from <= IT[ind].l && IT[ind].r <= to)
        {
           // cout<<"Podhodqsht e "<<endl;

            if (even)
            {
                IT[ind].ev += add;
                IT[ind].nev -= add;
            }
            else
            {
                IT[ind].ev -= add;
                IT[ind].nev += add;
            }

        //    cout<<"Stoinostite mu stanaha "<<IT[ind].ev<<" pri chetni i "<<IT[ind].nev<<" pri nechetni."<<endl;

            return;
        }

        Update(ind*2, from, to, add, even);
        Update(ind*2+1, from, to, add, even);
    }
};

IntervalTree magic;

int main ()
{
    lld i, j, ii, jj, ind, q;
    lld type, a, b;

    scanf("%I64d %I64d",&n, &queries);
    m = n-1;

    for (i=1;i<=n;i++)
    {
        scanf("%I64d", &initv[i]);
    }


    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d", &a, &b);

        fg[a].push_back(b);
    }

    memset(TFO, 0, sizeof(TFO));
    GiveName(1);

    for (i=1;i<=n;i++)
    {
        for (j=0;j<fg[i].size();j++)
        {
            Graph[nickname[i]].push_back(nickname[fg[i][j]]);
        }
    }

    FillDist();

    magic.Initialize(n);

   // cout<<"BEGIN"<<endl<<endl;

    for (q=1; q<=queries; q++)
    {
        scanf("%I64d", &type);

        if (type == 1)
        {
            scanf("%I64d %I64d", &a, &b);

          //  cout<<"Da dobavim na vruh "<<a<<", a.k.a "<<nickname[a]<<" e da dobavim ot "<<cove

            lld rl = nickname[a];
            magic.Update(1, cover[a].from, cover[a].to, b, evendist[rl]);
        }
        else
        {
            scanf("%I64d", &a);

            lld rl = nickname[a];
            lld ans = initv[a];

            ans += magic.GetAnswer(rl, evendist[rl]);

            printf("%I64d\n", ans);
        }
    }

    return 0;
}


/*
5 5
1 2 1 1 2
1 2
1 3
2 4
2 5
1 2 3
1 1 2
2 1
*/
