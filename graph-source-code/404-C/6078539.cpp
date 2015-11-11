//Language: GNU C++0x


#include <iostream>
#include <sstream>
#include <fstream>

#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cctype>

#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v){
    os << "{ ";
    for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
        os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", ");
    os << " }";
    return os;
}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define vv(type,w,h,init) vector<vector<type>>(h,vector<type>(w,init))
typedef vector<string> vs;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long ul;
typedef unsigned long long ull;

#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define loop(i,a,b) for(int i=(a); i<(int)(b); i++)
#define rep(i,b) loop(i,0,b)
#define pb push_back
#define mp make_pair

int main(){
    int n,k; cin>>n>>k;
    vi d(n);
    rep(i,n){
        cin>>d[i];
    }

    vi id(n);

    int size = *max_element(all(d));
    vvi count(size+1);
    rep(i,n){
        count[d[i]].push_back(i);
        id[i] = i+1;
    }

    bool ok = true;
    if(count[0].size()!=1) ok = false;

    vector<pair<int,int>> es;

    vi ks(n);
    if(ok){
        loop(i,1,count.size()){
            int cur = count[i].size();
            int prev = count[i-1].size();
            if(cur==0){
                ok = false;
                break;
            }
            int kk = cur/prev + (cur%prev!=0);
            if(i-1 != 0) kk++;
            ks[i-1] += kk;
            // cout << kk << endl;
            rep(j,count[i].size()){
                es.push_back(make_pair(count[i][j], count[i-1][j%prev]));
            }
        }
    }

    //cout << ks << endl;
    ok &= *max_element(all(ks)) <= k;
    
    if(ok){
        cout << es.size() << endl;
        rep(i,es.size()){
            cout << id[es[i].first] << " " << id[es[i].second] << endl;
        }
    } else {
        cout << -1 << endl;
    }
}
