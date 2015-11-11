//Language: GNU C++0x


/*
 * This is my code,
 * my code is amazing...
 */
//Template v2.0
//iostream is too mainstream
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<iomanip>
//clibraries
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
//defines
#define ll long long
#define lld long double
#define pll pair<ll,ll>
#define pld pair<lld,lld>
#define vll vector<ll>
#define vvll vector<vll>
#define INF 1000000000000000047
const char en='\n';
#define debug(x){cerr<<x<<en;}
#define prime 47
#define lprime 1000000000000000009
#define lldmin LDBL_MIN
#define MP make_pair
#define PB push_back
using namespace std;

vll V,U;
int n;


void cycle(int p){
for(int i=p; U[i]!=-1; i=V[i]){
U[i]=-1;
}
}


int main(){
	ios::sync_with_stdio(false);
cin>>n;
V.resize(n+47,0);

for(int i=1; i<=n; i++)
    cin>>V[i];
int k;
cin>>k;
int cyc=0;
vll X=V;
U.resize(n+47,0);
for(int i=1; i<=n; i++){
if(U[i]!=-1){
cyc++;
cycle(i);
}
}

int swaps=n-cyc;

U.clear();
U.resize(n+47,0);
V=X;
cout<<abs(k-swaps)<<en;

if(swaps<k){
cycle(1);
    for(int i=2; i<=n; i++){
        if(U[i]!=-1){
            swaps++;
            cycle(i);
            cout<<"1 "<<i;
        }
        if(k==swaps){cout<<en;break;}
        else cout<<" ";
    }
}
else{
vector<set<ll>>S;
S.resize(n+47);
for(int i=1; i<=n; i++){
int p=i;
for(int j=i; U[j]!=-1; j=V[j])
{
    U[j]=-1;
    S[i].insert(j);
}
}

for(int i=1; i<=n; i++){
while(S[i].size()>1){
    if(swaps==k)break;
int najm=*S[i].upper_bound(i);
cout<<i<<" "<<najm;

swap(V[i],V[najm]);
int p=V[najm];
S[najm].insert(najm);
S[i].erase(S[i].find(najm));
while(p!=najm){

    S[najm].insert(p);
    S[i].erase(p);
    p=V[p];
}



swaps--;
if(swaps==k)cout<<en;
else cout<<" ";
}
}




}

}


