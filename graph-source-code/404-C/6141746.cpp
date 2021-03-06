//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define PI acos(-1.0)
#define LL long long

using namespace std;

vector<vector<int> > graph(100005);
LL counter[100005];

int main()
{
    LL n,k;
    scanf("%I64d%I64d",&n,&k);
    pair<int,int> arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i].first);
        counter[arr[i].first]++;
        arr[i].second = i+1;
    }
    sort(arr,arr+n);
    bool impossible = false;
    for(int i=2;i<n;i++)
        if((LL)(counter[i-1] * (k-1)) < counter[i])
        {
            impossible = true;
            break;
        }
    if((LL)(counter[0] * k < counter[1]) || counter[0] > 1 || impossible)
    {
        printf("-1");
        return 0;
    }
    int start,counte=0;
    for(int i = 1;i < n;i++)
    {
        start = i;
        if(arr[i].first == 2)
            break;
        graph[arr[0].second].push_back(arr[i].second);
        counte++;
    }
    for(int i=1;i<=n;i++)
        for(start;arr[start].first == arr[i].first + 1 && (int)graph[arr[i].second].size() < k-1 && start < n;start++)
            graph[arr[i].second].push_back(arr[start].second),counte++;
    printf("%d\n",counte);
    for(int i=1;i<=n;i++)
        for(int j=0;j<graph[i].size();j++)
            printf("%d %d\n",i,graph[i][j]);
    return 0;
}