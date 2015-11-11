//Language: GNU C++0x


#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

const int SIZE = 202;
int n, m;
int from[SIZE *SIZE], to[SIZE *SIZE], cst[SIZE *SIZE], mat[SIZE][SIZE];
void floyd()
{
    rep(k, n)
    rep(i, n)
    rep(j, n)
    mat[i][j] = mat[j][i] = min(mat[i][j], mat[i][k] + mat[k][j]);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    rep(i, SIZE) {
        fill(mat[i], mat[i] + SIZE, 1 << 28);
        mat[i][i] = 0;
    }
    scanf("%d%d", &n, &m);
    int a, b, c;
    rep(i, m) {
        scanf("%d%d%d", &a, &b, &c);
        --a, --b, c *= 2;
        mat[a][b] = mat[b][a] = c;
        from[i] = a, to[i] = b, cst[i] = c;
    }
    floyd();
    int mn = 1 << 28;

    rep(k, m) {
        map<int, vi > ev;
        set<pii> lf, rt;
        int len = mat[from[k]][to[k]];
        rep(i, n) {
            //a+x=b+(len-x)
            //2x=b+len-a
            //x=(b+len-a)/2;

            int a = mat[i][from[k]] , b = mat[i][to[k]];
            int x = (b + len - a) / 2;
            if(x > 0 && x <= len)
                ev[x].push_back(i);
            if(a < b + len)
                lf.insert(mp(a, i));
            else
                rt.insert(mp(b, i));

        }
        ev[0];
        ev[len];
        repi(it, ev) {
            vi &v =  it->second;
            rep(l, sz(v)) {
                int i = v[l];
                int a = mat[i][from[k]] , b = mat[i][to[k]];

                lf.erase(mp(a, i));
                rt.insert(mp(b, i));

            }
            int x1 = 0, x2 = 0;
            if(sz(lf))
                x1 = lf.rbegin()->first;
            if(sz(rt))
                x2 = rt.rbegin()->first;
            int ps = (x1 + x2 + len) / 2 - x1;
            if(ps > len || ps < 0) continue;
            mn = min(mn, max(x1 + ps, x2 + len - ps));

        }

    }

    printf("%.1lf\n", mn / 2.0);
    return 0;
}
