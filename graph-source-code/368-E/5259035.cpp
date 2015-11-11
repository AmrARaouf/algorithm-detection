//Language: GNU C++0x


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

ll aux(ll n){
  if(n%2==1)
    return ((n*(n-1))/2+1);
  else
    return ((n*(n-1))/2)+n/2;
}

int main(){
  ll n, m;
  cin >> n >> m;
  vector<ll> t(m);
  for(ll i=0;i<m;++i){
    ll a;
    cin >> a >> t[i];
  }

  sort(begin(t), end(t));
  reverse(begin(t), end(t));

  while(aux(m)>n) --m;

  ll res=0;
  for(ll i=0;i<m;++i)
    res+=t[i];

  cout << res << '\n';
}
