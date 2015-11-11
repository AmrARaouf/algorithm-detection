//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

#define PN(n) printf("%d\n", n)
#define DEBUG if(0)

#define LL long long int
#define ULL unsigned long long int

#define PII pair<int, int>

using namespace std;

vector<PII> dist;
vector<PII> edges;
int n, k;

void disaster(){
    PN(-1);
}

int main(void) {
    scanf("%d %d", &n, &k);
    dist.resize(n);

    int temp;
    for(int i = 1; i <= n; i++){
        scanf("%d", &temp);
        dist[i-1] = PII(temp, i);
    }
    sort(dist.begin(), dist.end());

    DEBUG for(int i = 0; i < n; i++){
        printf("%d %d\n", dist[i].first, dist[i].second);
    }

    if((n >= 2) && dist[1].first == 0){
        printf("-1\n");
        return 0;
    }
    else if(dist[0].first != 0){
        printf("-1\n");
        return 0;
    }

    queue<int> q;
    queue<int> next;
    q.push(dist[0].second);
    int ROOT = dist[0].second;
    int cd = 0;
    int i = 1;
    while(i < n){
        cd++;
        if(q.empty()) {
            PN(-1);
            return 0;
        }
        int p = q.front(); q.pop();
        int count = 1;
        while(dist[i].first == cd){
            DEBUG printf("Count: %d\n", count);
            if(i >= n) break;

            DEBUG printf("%d - %d\n", dist[i].second, cd);
            if(p == ROOT && count > k){
                if(q.empty()){
                    printf("-1\n");
                    return 0;
                }
                p = q.front(); q.pop();
                count = 1;
            }
            else if(p != ROOT && count >= k){
                if(q.empty()){
                    printf("-1\n");
                    return 0;
                }
                p = q.front(); q.pop();
                count = 1;
            }
            int q = dist[i].second;
            edges.push_back(PII(p, q));
            DEBUG printf("Edge: %d %d\n", p, q);
            next.push(q);
            i++;
            count++;
        }
        q = next;
        queue<int> empty;
        swap(next, empty);

    }

    int en = edges.size();
    PN(en);
    for(int i = 0; i < en; i++){
        printf("%d %d\n", edges[i].first, edges[i].second);
    }

    return 0;
}

