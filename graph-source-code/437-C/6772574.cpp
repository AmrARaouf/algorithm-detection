//Language: GNU C++


#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int val;
    vector<int> nbs;
    int sum;
    int idx;
};

int n,m;
vector<Node> nodes;
int sums[1001];

Node mNode(int val, int idx) {
    Node node;
    node.val = val;
    node.idx = idx;
    return node;
}

bool comp(const Node &A, const Node &B) {
    return A.val > B.val;
    //return sums[A.idx] < sums[B.idx];
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        int v;
        scanf("%d",&v);
        nodes.push_back(mNode(v,i));
    }
    int a,b;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&a,&b);
        --a;
        --b;
        nodes[a].nbs.push_back(b);
        sums[a] += nodes[b].val;
        nodes[b].nbs.push_back(a);
        sums[b] += nodes[a].val;
    }
    sort(nodes.begin(),nodes.end(),comp);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += sums[nodes[0].idx];
        for (int k = 0; k < (int)nodes[0].nbs.size(); ++k) {
            sums[nodes[0].nbs[k]]-=nodes[0].val;
        }
        nodes.erase(nodes.begin());
        sort(nodes.begin(),nodes.end(),comp);
    }
    printf("%d\n", ans);
    return 0;
}