//Language: GNU C++0x


/*kee template*/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FOR(i,k,n) for(decltype(n) (i) = (k);(i)<(n);(i)++)
#define all(v) v.begin(),v.end()
#define SORT(v) sort(all(v))
#define SORTd(v) sort(v.rbegin(),v.rend())
#define minv(v) min_element(all(v))
#define maxv(v) max_element(all(v))
#define V vector
/***********************************************/
/* Dear GCC compiler:
 * If my code doesn't compile, this doesn't mean it's wrong.
 * It just mean that you don't understand what I want.
 * Here's my safety pig, I hope my code compile and get accepted.
 * _._ _..._ .-',     _.._(`))
 *'-. `     '  /-._.-'    ',/
 *   )         \            '.
 *  / _    _    |             \
 * |  a    a    /              |
 * \   .-.     /               ;
 *  '-('' ).-'       ,'       ;
 *     '-;           |      .'
 *        \           \    /
 *        | 7  .__  _.-\   \
 *        | |  |  ``/  /`  /
 *       /,_|  |   /,_/   /
 *          /,_/      '`-'
 */
const ll mod = 1000000007;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,a,b,c,q;
    V<V<V<int> > > graphs;
    cin>>n>>m;
    V<V<int> >emp(n,V<int>(0));
    graphs = V<V<V<int> > >(m,emp);
    while(m--){
        cin>>a>>b>>c;
        a--;
        b--;
        c--;
        graphs[c][a].pb(b);
        graphs[c][b].pb(a);
    }
    cin>>q;
    while(q--){
        int ans = 0;
        cin>>a>>b;
        a--;
        b--;
        FOR(i,0,graphs.size()){
            queue<int> notYet;
            notYet.push(a);
            V<bool> visited(n,false);
            visited[a] = true;
            bool found = false;
            while(!notYet.empty() && !found){
                int v = notYet.front();
                notYet.pop();
                for(size_t j = 0; j<graphs[i][v].size(); j++){
                    int u = graphs[i][v][j];
                    if(u==b){
                        ans++;
                        found = true;
                        break;
                    }
                    if(!visited[u]){
                        visited[u] = true;
                        notYet.push(u);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/**/
