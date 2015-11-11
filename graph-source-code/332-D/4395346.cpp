//Language: GNU C++


/*
#ifdef ONLINE_JUDGE
#pragma comment(linker, "/STACK:16777216")
#endif
*/
#include <algorithm>
//#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <ctime>
//#include <deque>
#include <functional>
//#include <iomanip>
#include <iostream>
#include <map>
//#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
// #include <sys/time.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define x first
#define y second
#define fi(n) fo(i, n)
#define fj(n) fo(j, n)
#define fk(n) fo(k, n)
#define fd(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define fo(i,n) fr(i,0,n)
#define fr(i,a,b) for(int i=(int)a; i<(int)b; i++)
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define srt(x) sort(all(x))
//#define foreach(it, a) for(__typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
//#define me (*this)
//#define PQ(t) priority_queue< t, vector< t >, greater< t > >
//#define CLR(a, v) memset(a, v, sizeof(a))
//#define UNIQUE(a) srt(a), a.resize(unique(all(a))-a.begin())
//#define RAND (((double)rand()/RAND_MAX) + ((double)rand()/RAND_MAX/RAND_MAX))
//#define assert(cond,msg) if(!(cond)){ fprintf(stderr, "assert failed at line %d: %s\n", __LINE__, msg); exit(1); }
/*
char systemBuffer[1<<10];
#define execute(...) {\
  sprintf(systemBuffer, __VA_ARGS__); \
  system(systemBuffer); \
}

#ifdef LOCAL
  #define debug(msg, ...) fprintf(stderr, msg, __VA_ARGS__)
#else
  #define debug(msg, ...)
#endif
*/
typedef long long ll;
typedef pair<int, int> ii;
typedef vector< ii > vii;
typedef vector< vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;
typedef vector< double > vd;
typedef vector< vd > vvd;
typedef vector< ll > vll;
typedef vector< bool > vb;

const int INF = 1000*1000*1000+7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template<class T> int chmin(T &t, T f){ return (t>f) ? (t=f, 1) : 0; }
template<class T> int chmax(T &t, T f){ return (t<f) ? (t=f, 1) : 0; }
/* 
struct timeval startTime, finishTime;
double timeElapsed(){
  gettimeofday(&finishTime, NULL);
  int top = finishTime.tv_sec-startTime.tv_sec-(startTime.tv_usec > finishTime.tv_usec);
  int bot = finishTime.tv_usec-startTime.tv_usec;
  if(bot < 0)
    bot += 1e6;
  return top+bot/1e6;
}
*/
inline int getint() {
  int a;
  return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}

inline double getdouble() {
  double a;
  return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}





void myCode() {

  int n=getint(), k=getint();
  ll sum = 0;
  vvii a(n);
  fi(n)
    fj(n-1-i){
      int x=getint();
      if(x != -1){
        a[i].pb(ii(i+1+j, x));
        a[i+1+j].pb(ii(i, x));
        sum += x;
      }
    }
  if(k == 1 || k == n-1){
    cout << 2*sum/n << endl;
    return;
  }

  sum = 0;
  fi(n)
    srt(a[i]);
  fi(n)
    fr(j,i+1,n)
      if(sz(a[i]) < sz(a[j])){
        fk(sz(a[i])){
          vii::iterator it = lower_bound(all(a[j]), ii(a[i][k].x,-1));
          if(it != a[j].end() && it->x == a[i][k].x)
            sum += a[i][k].y + it->y;
        }
      }else{
        fk(sz(a[j])){
          vii::iterator it = lower_bound(all(a[i]), ii(a[j][k].x,-1));
          if(it != a[i].end() && it->x == a[j][k].x)
            sum += a[j][k].y + it->y;
        }
      }

  cout << sum / (n*(n-1)/2) << endl;

}

int main() {
/*
  // seed the random number generator with microseconds
  gettimeofday(&startTime, NULL);
  srand(startTime.tv_usec);
*/
  myCode();
  return 0;
}










