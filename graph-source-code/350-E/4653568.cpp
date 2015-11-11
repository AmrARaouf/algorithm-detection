//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, k;

int a[305];
bool is[305];
std::vector<int> v;
int main(){
    cin>>n>>m>>k;
    for(int i = 1; i <= k; i++){
        cin>>a[i];
        is[a[i]] = 1;
        v.push_back(a[i]);
    }
    for(int i = 1; i <= n; i++){
        if(!is[i]) v.push_back(i);
    }
    if(k==n || m > n*(n-1)/2 - k+1){
        puts("-1");
        return 0;
    }
    for(int i = 1; i < n-1; i++){
        printf("%d %d\n", v[i], v[i+1]);
    }
    printf("%d %d\n", v[n-1], v[0]);
    int sum = n-1;
    for(int i = k; i < n-1; i++){
        if(sum==m) break;
        printf("%d %d\n", v[0], v[i]);
        sum++;
    }
    for(int i = 1; i < n; i++){
        if(sum==m) break;
        for(int j = i+2; j < n; j++){
            if(sum==m) break;
            printf("%d %d\n", v[i],v[j]);
            sum++;
        }
    }
    return 0;
}
