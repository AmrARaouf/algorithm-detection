//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <utility>

#define min(a, b) (((a)<(b))?(a):(b))

using namespace std;

typedef long long ll;

const int N = 1e5 + 3;

int p[N], h[N], an[N][2];
ll s[N];

int get(int i)
{
    if(p[i] == i)
        return i;
    else
        return p[i] = get(p[i]);
}

int set_union(int i, int j)
{
    int x, y, t;
    x = get(i);
    y = get(j);


    if(x==y)
        return x;
    if(h[x]<h[y])
    {
        t = x;
        x = y;
        y = t;
    }

    p[y] = x;
    if(h[x] == h[y])
        ++h[x];

    return x;
}


int main()
{
  // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int i, j, l, x, y, u, n, m, P, q, k, ln;
    set< pair<ll, int> > st;
    //pair<int, ll> t;

    scanf("%d %d %d %d", &n, &m, &P, &q);

    for(i=0; i<n; ++i)
    {
        p[i] = i;
        h[i] = 1;
        s[i] = 0;
        st.insert(make_pair(0, i));
    }

    ln = 0;
    for(u=0; u<m; ++u)
    {
        scanf("%d %d %d", &i, &j, &l);
        --i; --j;
        x = get(i);
        y = get(j);
        st.erase(make_pair(s[x], x));
        st.erase(make_pair(s[y], y));

        x = set_union(x, y);
        s[x] += l;
        st.insert(make_pair(s[x], x));
    }

    k = 0;
    for(i=0; i<n; ++i)
        k += (i == get(i));

    if(k<q)
    {
        printf("NO\n");
        return 0;
    }


    if(n==1)
    {
        if(P)
        {
            printf("NO\n");
        }
        else
            printf("YES\n");

        return 0;
    }

    ll tt;
    while( (k>q) && (P) )
    {
        x = st.begin()->second;
        st.erase(make_pair(s[x], x));
        y = st.begin()->second;
        st.erase(make_pair(s[y], y));

        an[ln][0] = x;
        an[ln][1] = y;
        ++ln;

       // printf("x=%d s[x]=%lld y=%d s[y]=%d\n", x+1, s[x], y+1, s[y]);

        tt = s[x]+s[y] + min(s[x]+s[y]+1, 1e9);
        x = set_union(x, y);
        s[x] = tt;
       // printf("x=%d s[x]=%lld\n", x+1, s[x]);
        st.insert(make_pair(s[x], x));
        --P;
        --k;
    }

    if(k>q)
    {
        printf("NO\n");
        return 0;
    }

    i=0;
    while((i<n) && (i==get(i)))
        ++i;

    if(P && (i==n))
    {
        printf("NO\n");
        return 0;
    }

    j = get(i);
    while(P)
    {
        an[ln][0] = i;
        an[ln][1] = j;
        ++ln;
        --P;
    }

    printf("YES\n");
    for(i=0; i<ln; ++i)
        printf("%d %d\n", an[i][0]+1, an[i][1]+1);





    return 0;
}
