//Language: GNU C++11


#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include <limits>
#include <string>
#include <cstring> // memset
#include <iostream> // cin, cout
#include <fstream> // io redirection
#include <sstream> // topcoder testcase
#include <iomanip>      // std::setprecision

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define REP(i, a, b) for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
#define OUTBOOL(boolean,true_string,false_string) cout << ((boolean) ? true_string : false_string)<< endl

#define MOD 1000000007

#define endl "\n"


int main()
{
    ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    ifstream arq(getenv("INPUT"));
    cin.rdbuf(arq.rdbuf());
    
    //  ofstream brq(getenv("OUTPUT"));
    //  cout.rdbuf(brq.rdbuf());
#endif
    int k;
    cin >> k;
    
    if(k%2==0){
        cout << "NO" << endl; return 0;
    }
    int n= (k-1)*2*k+k+1;
    int m= (n*k)/2;
    cout << "YES" << endl;
    
    set<pair<int,int>> s;
    REP(i,0,k-1){
        REP(j,k-1,2*k-2){
            s.insert({i,j});
        }
        for(int j=k-1;j<2*k-2;j=j+2){
            s.insert({j,j+1});
        }
    }
    
    cout << n << " " << m << endl;
    REP(i,2,k+2){
        cout << 1 << " " << i << endl;
    }
    int x = k+2;
    REP(i,2,k+2){
        REP(j,0,k-1){
            cout << i << " " << x+j << endl;
        }
        
        for (auto kv : s) {
            cout << kv.first+x << " " << kv.second+x << endl;
        }
        
        x+=2*k-2;
        
    }
    
    
}