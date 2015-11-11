//Language: GNU C++


#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <stdio.h>
using namespace std;

#define REP(i,N) for (int i = 0; i < (N); ++i)

typedef unsigned int ui;
typedef long long ll;

typedef vector<int> vi;

template<class T> void printImpl(const vector<T> & coll) { copy(coll.begin(), coll.end(), ostream_iterator<T>(cout, " ")); cout << endl; }
template<class T, int N> void printImpl(T (&coll)[N]) { copy(coll, coll + N, ostream_iterator<T>(cout, " ")); cout << endl; }
template<class Key, class Value> void printImpl(const map<Key, Value> & data) { typename map<Key, Value>::const_iterator it; for (it = data.begin(); it != data.end(); ++it) { cout << it->first << ":" << it->second << endl; } }
template <class T> void printImpl(const T & data) { cout << data << endl; }

#define DEBUGPRINT
#ifdef DEBUGPRINT
#define print(x) cout << #x" = "; printImpl(x);
#else
#define print(x) ;
#endif

int main()
{
    cout.precision(15);
    cout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed
    

    int n, m;
    cin >> n >> m;
    vector<double> x(n);
    REP(i,n)
    {
        cin >> x[i];
    }
    
    vi a(m), b(m), c(m);
    REP(i,m)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }
    
    double res = 0;
    REP(i,m)
    {
        double t = (x[a[i]] + x[b[i]]) / c[i];
        res = max(res, t);
    }
    
    cout << res << endl;
    
    return 0;
}