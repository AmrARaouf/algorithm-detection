//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>
#include <climits>
#include <deque>
#include <bitset>
#include <cassert>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int dy[]={-1,0,1,0},dx[]={0,1,0,-1};
// adjust problem by problem
const double EPS=1e-8;
const double PI=acos(-1.0);
#ifdef __GNUC__
int popcount(int n){return __builtin_popcount(n);}
int popcount(ll n){return __builtin_popcountll(n);}
#endif
#ifndef __GNUC__
template<class T> int popcount(T n){int cnt=0;while(n){if(n%2)cnt++;n/=2;}return cnt;}
#endif
template<class T>int SIZE(T a){return a.size();}
template<class T>string IntToString(T num){string res;stringstream ss;ss<<num;return ss.str();}
template<class T>T StringToInt(string str){T res=0;for(int i=0;i<SIZE(str);i++)res=(res*10+str[i]-'0');return res;}
template<class T>T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template<class T>T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> void PrintSeq(T &a,int sz){for(int i=0;i<sz;i++){cout<<a[i];if(sz==i+1)cout<<endl;else cout<<' ';}}
bool EQ(double a,double b){return abs(a-b)<EPS;}
void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}
vector<string> split(string str,char del){
  vector<string> res;
  for(int i=0,s=0;i<SIZE(str);i++){
    if(str[i]==del){if(i-s!=0)res.push_back(str.substr(s,i-s));s=i+1;}
    else if(i==SIZE(str)-1){res.push_back(str.substr(s));}
  }
  return res;
}

int N;
int CS[100001];
int SS[100001];
int main(){

  cin>>N;
  for(int i=0;i<N;i++)cin>>CS[i]>>SS[i];
  vector<pii> v[2];
  for(int i=0;i<N;i++){
    v[CS[i]].push_back(make_pair(SS[i],i));
  }
  for(int i=0;i<2;i++)
    sort(v[i].begin(),v[i].end(),greater<pii>());
  int oPos=0;
  for(int i=0;i<(int)v[0].size();i++){
    int cnt=v[0][i].first;
    int idx=v[0][i].second;
    if(oPos==(int)v[1].size()){
      cout<<idx+1<<" "<<oPos<<" "<<0<<endl;
    }
    else{
      for(int j=oPos;j<(int)v[1].size();j++){
        if(v[1][j].first-cnt>=0){
          cout<<idx+1<<" "<<v[1][j].second+1<<" "<<cnt<<endl;
          v[1][j].first-=cnt;
          break;
        }
        else{
          cout<<idx+1<<" "<<v[1][j].second+1<<" "<<v[1][j].first<<endl;
          cnt-=v[1][j].first;
          v[1][j].first=0;
          oPos=j+1;
        }
      }
    }
  }
  oPos++;
  for(int j=oPos;j<(int)v[1].size();j++){
    cout<<v[0][v[0].size()-1].second+1<<" "<<v[1][j].second+1<<" "<<0<<endl;
  }
  return 0;
}
