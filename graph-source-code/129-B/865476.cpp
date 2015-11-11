//Language: GNU C++


#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

#define MAX_N 105

int N, M;
int num[MAX_N];
bool adjmat[MAX_N][MAX_N];

queue <int> bfs;

int main() {
    scanf("%d %d",&N,&M);

    for(int i=0;i<M;i++) {
        int a, b;
        scanf("%d %d",&a,&b);
        a--;
        b--;
        num[a]++;
        num[b]++;
        adjmat[a][b] = true;
        adjmat[b][a] = true;
    }


    int ans = 0;
    while(true) {
        for(int i=0;i<N;i++) {
            if(num[i] == 1) {
                bfs.push(i);
            }
        }
        if(bfs.empty()) {
            break;
        }
        ans++;
        while(!bfs.empty()) {
            int next = bfs.front();
            bfs.pop();

            num[next] = 0;
            for(int i=0;i<N;i++) {
                if(adjmat[next][i]) {
                    adjmat[next][i] = false;
                    adjmat[i][next] = false;
                    num[i]--;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
