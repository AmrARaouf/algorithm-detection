//Language: GNU C++


#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v[100024];

int main(){
    int i, a, b, n;

    scanf("%d", &N);
    printf("%d\n", N - 1);

    for(i = 1; i < N; i++){
        scanf("%d %d", &a, &b);
        
        v[a].push_back(i);
        v[b].push_back(i);

        printf("2 %d %d\n", a, b);
    }
    
    for(i = 1; i <= N; i++){
        for(n = 1; n < (int) v[i].size(); n++){
            printf("%d %d\n", v[i][n-1], v[i][n]);
        }
    }

    return 0;
}
