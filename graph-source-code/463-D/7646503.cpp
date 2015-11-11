//Language: GNU C++0x


#include<iostream>
#include<cstdio>

using namespace std;
const int MAXN = 1000;
const int MAXK = 5;

int memo[MAXN+1];
int p[MAXK][MAXN+1];

bool check(int a, int b, const int& k){
    for(int i = 0; i < k; ++i){
        if(p[i][a] >= p[i][b]) return false;
    }

    return true;
}

int f(int i, const int& k, const int& n){
    if(memo[i]) return memo[i];
    int ans = 0;
    for(int pi = 0; pi < n; ++pi){
        if(check(pi, i, k)){
            ans = max(ans, f(pi, k, n));
        }
    }
    return memo[i] = ans+1;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < k; ++i){
        for(int j = 0; j < n; ++j){
            int x;
            cin >> x;
            --x;
            p[i][x] = j;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans, f(i, k, n));
    }

    cout << ans;
    return 0;
}
