//Language: GNU C++


#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX = 1000005;

ll N,M;
ll deg[MAX];

ll C3( ll a){
    return a * (a-1) * (a-2) / 6;
}
ll C2(ll a){
    return a * (a-1) / 2;
}

int main(){
    scanf("%d%d", &N, &M);
    //for(int i=0; i<N; i++) deg[i] = 0;
    memset (deg, 0, sizeof(deg));
    for(int i=0; i<M; i++){
        int a,b; scanf("%d%d", &a, &b) ; a--; b--;
        deg[a] ++;
        deg[b] ++;
    }
    ll bad = 0;
    for(int i=0; i<N; i++){
        bad += deg[i] * (N - 1 - deg[i]);
    }
    cout << C3(N) - (bad / 2) << endl;
}    