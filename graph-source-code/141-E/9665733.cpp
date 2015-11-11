//Language: GNU C++


#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define sz(x) ((int)x.size())
#define rep(i,n) for (int i = 0; i < (n); i++)
#define InTheNameOfGod ios_base::sync_with_stdio(0);cin.tie(0);

const int N = 2000 + 7;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii ,int> piii;


int mrk[1000000 + 7] = {}, par[N] = {};
vector<pii> e;
vector<int> ans;

int find(int x){
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}
bool Union(int x, int y){
    if (find(x) != find(y)){
        par[find(x)] = find(y);
        return true;
    }
    return false;
}

int main()
{
    InTheNameOfGod
    
    int n, m; cin >> n >> m;
    if(!(n % 2)) {cout << -1; return 0;}
    rep(i,m){
        int x, y; char c;
        cin >> x >> y >> c;
        x--, y--;
        if (c == 'M') mrk[i] = true;
        e.push_back(mp(x,y));
    }
    rep(i,n) par[i] = i;
    
    rep(i,m) if (!mrk[i])
        Union(e[i].ff, e[i].ss);
    
    rep(i,m) if(mrk[i] && Union(e[i].ff, e[i].ss))
        ans.push_back(i);
    if ( sz(ans) > n/2 ){ cout << -1;return 0; }
    
    rep(i,n) par[i] = i;
    
    rep(i,sz(ans))
        Union(e[ans[i]].ff, e[ans[i]].ss);
    
    for(int i = 0; i < m && sz(ans) < n/2; i++)
        if(mrk[i] && Union(e[i].ff, e[i].ss))
            ans.push_back(i);
    
    if (ans.size() != n/2) {cout << -1; return 0;}

    for(int i = 0; i < m ; i++)
        if (!mrk[i] && Union(e[i].ff, e[i].ss))
            ans.push_back(i);
    
    if(ans.size() != n - 1){cout << -1 ;return 0;}
    
    cout << n-1 << endl;
    rep(i,sz(ans)) cout << ans[i] + 1 << ' ';
    
    return 0;
}



/*vector<piii> s,m, use;
vector<int> v[N], o;
int pars[N], parm[N], park[N], par[N], cnm, cns;
map<pii, int> edj, col, mark;

int find(int x, int* pr){
    if(pr[x] == x)
        return x;
    return pr[x] = pr[pr[x]];
}
bool Union(int x, int y, int* pr){
    if (find(x,pr) != find(y, pr)){
        pr[find(x,pr)] = find(y, pr);
        return true;
    }
    return false;
}
void dfs(int x, int pr){
    par[x] = pr;
    rep(i,sz(v[x])) if(v[x][i] != pr && !mark[mp(v[x][i], x)])
        dfs(v[x][i], x);
}
void bizz(int x){
    if (par[x] == -1)
        return;
    o.push_back(x);
    bizz(par[x]);
}
int main()
{
    InTheNameOfGod
    int n, e; cin >> n >> e;
    rep(i,e){
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'S')
            s.push_back(mp(mp(x,y),i+1));
        else
            m.push_back(mp(mp(x,y),i+1));
    }
    rep(i,n)
    pars[i+1] = parm[i+1] = park[i+1] = i+1;
    // dsu S = 1
    rep(i,sz(s)){
        if(Union(s[i].ff.ff, s[i].ff.ss ,pars))
            use.push_back(s[i]);
    }
    s.clear();
    s = use;
    rep(i,n) pars[i+1] = i+1;
    use.clear();
    // dsu M = 2
    rep(i,sz(m)){
        if(Union(m[i].ff.ff, m[i].ff.ss ,park)){
            use.push_back(m[i]);
            cnm ++;
            v[m[i].ff.ff].push_back(m[i].ff.ss);
            v[m[i].ff.ss].push_back(m[i].ff.ff);
            edj[mp(m[i].ff.ss, m[i].ff.ff)] = edj[mp(m[i].ff.ff, m[i].ff.ss)] = m[i].ss;
            col[mp(m[i].ff.ss, m[i].ff.ff)] = col[mp(m[i].ff.ff, m[i].ff.ss)] = 'M';
        }
    }
    m.clear();
    m = use;
    use.clear();
    //
    rep(i,sz(s)){
        if(Union(s[i].ff.ff, s[i].ff.ss ,park)){
            Union(s[i].ff.ff, s[i].ff.ss ,pars);
            cns ++;
            v[s[i].ff.ff].push_back(s[i].ff.ss);
            v[s[i].ff.ss].push_back(s[i].ff.ff);
            edj[mp(s[i].ff.ss, s[i].ff.ff)] = edj[mp(s[i].ff.ff, s[i].ff.ss)] = s[i].ss;
            col[mp(m[i].ff.ss, m[i].ff.ff)] = col[mp(m[i].ff.ff, m[i].ff.ss)] = 'S';
        }
    }
    if (cnm + cns != n-1 || cns > cnm){
        cout << -1 << endl;
        return 0;
    }
    rep(i,sz(s)){
        if (find(s[i].ff.ss, pars) !=  find(s[i].ff.ff, pars) && !edj[mp(s[i].ff.ss, s[i].ff.ff)] ){
            dfs(s[i].ff.ff, -1);
            bizz(s[i].ff.ss);
            rep(i,sz(o)-1)
            o.clear();
        }
    }
}*/

			 		 	  											  	  	 			