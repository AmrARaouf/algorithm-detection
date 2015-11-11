//Language: MS C++


#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <set>
#include <map>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define rp(i,s,n) for((i)=(s);(i)<(n);(i)++)    
#define _INF (1e9+1)
#define ll long long
#define _N 100001
#define MP make_pair 
#define PB push_back
#define X first
#define Y second


using namespace std;            

ll i,j,N,M,n,m,k,p;

int main() {

   // freopen("input.txt","r",stdin);
    
    ll x,i,j,k;
    cin>>x;
    
    ll a[101][101];
    ll s=0;
    
    rp(i,0,101)
    {
        rep(j,i+1)
        {
            if (i==j) {a[i][j]=0;continue;}
            ll count=0; 
            rep(k,i+1)
            {
                if (k==i || k==j) continue;
                if (a[i][k] && a[j][k]) count++;
            }
        //  cout<<i<<" "<<j<< " " <<count<<endl;
            if (s+count <= x)   a[i][j]=a[j][i]=1;
            else break;
            s += count;
            if (s==x) break;    
        }
        if (s==x) break;
    }
    
    cout<<i+1<<endl;
    rep(j,i+1)
    {
        rep(k,i+1)
        {
            cout<<a[j][k];
        }
        cout<<endl;
    }
    
    
    
return 0;
}