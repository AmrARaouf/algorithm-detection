//Language: GNU C++


#include <bits/stdc++.h>
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define ff first
#define mod 1000000007
#define ss second
#define ios ios_base::sync_with_stdio(0)
#define MAXN 100000
using namespace std;
typedef long long int ll;


int main(){
    int n,k;
    cin >> n >> k;
    if(2*k > n-1) cout << -1 << endl;
    else{
        cout << n*k << endl;
        for(int i=0;i<n;i++){
            for(int j=1;j<=k;j++){
                cout << (i+1) << " " << ((i+j)%n + 1) << "\n";
            }

        }
    }
    return 0;
}



