//Language: GNU C++0x


#define _CRT_SECURE_NO_WARNINGS
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define all(c) (c).begin(), (c).end()
#define loop(i,a,b) for(ll i=a; i<ll(b); i++)
#define rep(i,b) loop(i,0,b)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
template<class T> istream& operator>>(istream& is, vector<T>& v);
template<class T> ostream& operator<<(ostream& os, vector<T> const& v);
template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream&, const tuple<T...>&){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream& os, const tuple<T...>& t){ os << (n==0?"":" ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream& operator<<(ostream& os, const tuple<T...>& t){ _ot<0>(os, t); return os; }
template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _it(istream&, tuple<T...>&){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _it(istream& is, tuple<T...>& t){ is >> get<n>(t); _it<n+1>(is, t); }
template<class...T> istream& operator>>(istream& is, tuple<T...>& t){ _it<0>(is, t); return is; }
template<class T> istream& operator>>(istream& is, vector<T>& v){ rep(i,v.size()) is >> v[i]; return is; }
template<class T> ostream& operator<<(ostream& os, vector<T> const& v){ rep(i,v.size()) os << v[i] << (i+1==(int)v.size()?"":" "); return os; }
#ifdef DEBUG
#define dump(...) (cerr<<#__VA_ARGS__<<" = "<<mt(__VA_ARGS__)<<" ["<<__LINE__<<"]"<<endl)
#else
#define dump(...)
#endif

typedef vector<string> vs;

int n;
vs v;

bool isPrefix(const string& a, const string &b){
    if(a.size() <= b.size()){
        rep(i, a.size()){
            if(a[i] == b[i]) continue;
            else return false;
        }
    } else {
        return false;
    }
    return true;
}

bool vis[26];
int g[30][30], h[30][30];

void dfs(int k, string & ord){
    vis[k] = true;
    rep(i,26) if(!vis[i] && g[k][i]) dfs(i,ord);
    ord.pb(k+'a');
}

string solve(){
    memset(g,0,sizeof(g));
    loop(i,1,n){
        if(isPrefix(v[i-1], v[i])) continue;
        else if(isPrefix(v[i], v[i-1])) return {};
        else {
            rep(j, min(v[i].size(),v[i-1].size())){
                char a = v[i][j], b = v[i-1][j];
                if(a == b){
                    continue;
                } else {
                    g[a-'a'][b-'a'] = 1;
                    break;
                }
            }
        }
    }
    rep(i,26) rep(j,26) h[i][j] = g[i][j];
    rep(k,26) rep(i,26) rep(j,26) g[i][j] |= g[i][k] && g[k][j];
    rep(i,26) if(g[i][i]) return {};
    rep(i,26) vis[i] = 0;
    string ord;
    rep(i,26) if(!vis[i]) dfs(i,ord);
    return ord;
}

int main(){
    while(cin>>n){
        v.resize(n);
        rep(i,n) cin >> v[i];
        string ans = solve();
        if(ans.size()){
            cout << ans << endl;
        } else {
            puts("Impossible");
        }
    }
}
