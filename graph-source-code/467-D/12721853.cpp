//Language: GNU C++11


///////////////////////////////
// Template By: Agus Sentosa //
//       17 - 5 - 2014       //
///////////////////////////////
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <cstring>
#include <cmath>
#include <functional>
#include <utility>

//I/O
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <istream>
#include <ostream>

//Data Type
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <bitset>

//Data Type
#define pii pair<int,LL>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define LL long long
#define ULL unsigned long long

//Data Type Properties
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define popb pop_back

//Macro
#define sqr(x) ((x) * (x))
#define all(v) (v).begin(),(v).end()
#define sortv(v) sort(all(v))
#define num(x) ((x)-'0')
#define ch(x) ((x)+'0')
#define bit_count __builtin_popcount
#define bit_countll __builtin_popcountll
#define THIS (*this)

//Output
#define endl '\n'

//Compiling & Debugging
#ifdef DEBUG
#define DO_IF_DEBUG_FLAG_IS_ON 1
#else
#define DO_IF_DEBUG_FLAG_IS_ON 0
#endif
#define DoDebug if(DO_IF_DEBUG_FLAG_IS_ON)

//???????????????????
#define Fokus using
#define Tahun_Terakhir namespace std;

Fokus Tahun_Terakhir;

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
#define g getchar_unlocked
template<class T>
bool io(T &res){
    static char c=' ';
    while(c == ' ' || c == '\n')c = g();
    if(c == -1)return 0;
    res = num(c);
    while((c=g()) && c != ' ' && c != '\n' && c!=-1){ res = (res << 3) + (res << 1) + num(c); }
    return 1;
}

template<class T>
string inttostr(T x){
    string res="";
    while(x){
        char t=ch(x%10); x/=10; res=t+res;
    }
    return res;
}

template<class T>
T strtoint(string x){
    T res=0;
    for(int i=0;i<x.size();i++){
        res=(res<<3)+(res<<1)+num(x[i]);
    }
    return res;
}
void open(string a){
    freopen((a+".in").c_str(),"r",stdin);
    freopen((a+".out").c_str(),"w",stdout);
}
void close(){
    fclose(stdin);
    fclose(stdout);
}

//Constant
#define INF 1000000007
#define LINF 1000000000000000007ll
#define DINF 1000000000000000007.00
#define INV (-INF)
#define LINV (-LINF)
#define DINV (-DINF)
#define EPS 1e-9
#define MOD 1000000007
///////////////////////////////
//      End of Template      //
///////////////////////////////

string arr[100005];
map<string,int> cntr;
vector<int> V[200005];
pii data[200005];
int dfs_num[200005];
int dfs_low[200005];
int dfs_cntr;

int scc_id[200005];
int scc_num;
pii scc_data[200005];
vector<int> scc_list[200005];

int vis[200005];
int deg[200005];
stack<int> st;

void add(string &x){
    int num = 0;
    for(int i = 0 ; i < x.size() ; i ++){
        if(x[i] >= 'A' && x[i] <= 'Z')
            x[i] = x[i] - 'A' + 'a';
        if(x[i] == 'r')
            num++;
    }
    if(!cntr.count(x)){
        cntr[x] = cntr.size();
        cntr[x] --;
    }
        
    //cout << "ENTRY " << x << ' ' << cntr[x] << ' ' << cntr.size() << endl;
    
    data[cntr[x]] = {num , (LL)x.size()};
}

void DFS(int cur){
    dfs_num[cur] = dfs_low[cur] = dfs_cntr++;
    st.push(cur);
    vis[cur] = 1;
    
    for(int i : V[cur]){
        if(dfs_num[i] == -1){
            DFS(i);
        }
        if(vis[i])
            dfs_low[cur] = min(dfs_low[cur] , dfs_low[i]);
    }
    
    if(dfs_low[cur] == dfs_num[cur]){
        scc_data[scc_num] = {INF,INF};
        while(st.top() != cur){
            scc_list[scc_num].pb(st.top());
            scc_id[st.top()] = scc_num;
            scc_data[scc_num] = min(scc_data[scc_num] , data[st.top()]);
            vis[st.top()] = 0;
            st.pop();
        }
        scc_list[scc_num].pb(st.top());
        scc_id[st.top()] = scc_num;
        scc_data[scc_num] = min(scc_data[scc_num] , data[st.top()]);
        vis[st.top()] = 0;
        st.pop();
        
        //cout << scc_num << ' ' << scc_data[scc_num].f << ' ' << scc_data[scc_num].s << endl;
        scc_num++;
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    
    int n; cin >> n;
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
        add(arr[i]);
    }
    
    int m; cin >> m;
    for(int i = 0 ; i < m ; i ++){
        string a,b; cin >> a >> b;
        add(a); add(b);
        V[cntr[b]].pb(cntr[a]);
        //cout << cntr[b] << " -> " << cntr[a] << endl;
    }
    
    memset(dfs_num , -1, sizeof dfs_num);
    memset(vis,0,sizeof vis);
    
    scc_num = 0;
    dfs_cntr = 0;
    for(int i = 0 ; i < cntr.size() ; i ++){
        if(dfs_num[i] == -1)
            DFS(i);
    }


    //topo
    memset(deg , 0 ,sizeof deg);
    for(int i = 0 ; i < scc_num ; i ++){
        //cout << i << " : ";
        for(int j : scc_list[i]){
            //cout << j << ' ';
            for(int k : V[j])
                if(scc_id[k] != scc_id[j])
                    deg[scc_id[k]]++;
        }
        //cout << endl;
    }
    
    queue<int> q;
    for(int i = 0 ; i < scc_num ; i ++)
        if(deg[i] == 0)q.push(i);
        
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i : scc_list[cur])
            for(int j : V[i]){
                scc_data[scc_id[j]] = min(scc_data[scc_id[j]] , scc_data[cur]);
                
                if(scc_id[i] != scc_id[j]){
                    deg[scc_id[j]]--;
                    if(deg[scc_id[j]] == 0)q.push(scc_id[j]);
                }
            }
        //cout << cur << ' ' << data[cur].f << ' ' << data[cur].s << endl;
    }
    
    int a = 0;
    LL b = 0;
    for(int i = 0 ; i < n ; i ++){
        a += scc_data[scc_id[cntr[arr[i]]]].f;
        b += scc_data[scc_id[cntr[arr[i]]]].s;
        
        //cout << a << ' ' << b << endl;
    }
    
    
    cout << a << ' ' << b << endl;
        

    return 0;
}

