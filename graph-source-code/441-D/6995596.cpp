//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define sz(x) int(x.size())
using namespace std;

const int N = 3e3 + 9;
int a[N], n, m;
vector<int> o;
bool vi[N];
int cal()
{
    memset(vi, 0, sizeof(vi));
    int r = 0;
    for(int i = 1; i <= n; ++ i)
    {
        if(!vi[i])
        {
            int nu = 0;
            for(int j = i; !vi[j]; j = a[j])
            {
                vi[j] = 1; nu ++;
            }
            r += nu - 1;
        }
    }
    return r;
}
void partition()
{
    memset(vi, 0, sizeof(vi));
    for(int i = 1; i <= n; ++ i)
    {
        if(!vi[i] && i != a[i])
        {
            o.push_back(i);
            vi[i] = 1;
            int mi = n;
            for(int j = a[i]; !vi[j]; j = a[j])
            {
                vi[j] = 1;
                mi = min(mi, j);
            }
            o.push_back(mi);
            break;
        }
    }
    swap(a[*--o.end()], a[*----o.end()]);
}
void merge()
{
    memset(vi, 0, sizeof(vi));
    int c = 0;
    for(int i = 1; i <= n; ++ i)
    {
        if(!vi[i])
        {
            o.push_back(i);
            c ++;
            if(c == 2) break;
            for(int j = i; !vi[j]; j = a[j])
            {
                vi[j] = 1;
            }
        }
    }
    swap(a[*--o.end()], a[*----o.end()]);
}
int main()
{
//    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i)
    {
        int x; scanf("%d", &x); a[i] = x;
    }
    scanf("%d", &m);


    int t = cal();
//    cout << t << endl;
    if(t < m)
    {
        t = m - t;
        while(t --)
        {
            merge();
        }
    }
    else
    {
//        cout << "SB " << endl;
        t = t - m;
//        cout << t << endl;
        while(t --)
        {
//            cout << "SBSB" << endl;
            partition();
        }
    }

    printf("%d\n", sz(o) / 2);
    for(int i = 0; i < sz(o); ++ i)
    {
        if(i > 0) putchar(' ');
        printf("%d", o[i]);
    }
    puts("");
    return 0;
}
