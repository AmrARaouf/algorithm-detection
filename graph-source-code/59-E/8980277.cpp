//Language: GNU C++


#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<list>
#include<set>

using namespace std;

const int MAXN = 10086;
const int INF = 1000000000;

list<short> E[3001];
map<pair<short,short> , set<short> > mp;//(a,b,c)
int dp[3001][3001] ;
short pre[3001][3001];

void print(int last , int now){
    if(last == -1)return;
    print(pre[last][now] , last);
    printf("%d ",last);
}

int main()
{
    for(int n , m, k;~scanf("%d%d%d",&n,&m,&k);){
        for(int i = 1 ; i <= n; i ++){
            E[i].clear();
        }
        int a,b,c;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&a,&b);
            E[a].push_back(b);
            E[b].push_back(a);
        }
        mp.clear();
        for(int i = 0 ; i < k ; i++){
            scanf("%d%d%d",&a,&b,&c);
            mp[make_pair(a,b)].insert(c);
        }

        fill(dp[1],dp[n+1],INF);

        queue<pair<short,short> > Q;
        for(list<short>::iterator it = E[1].begin() ; it != E[1].end() ; it++){
            dp[1][*it] = 1;
            pre[1][*it] = -1;
            Q.push(make_pair(1,*it));
        }
        E[1].clear();
        while(!Q.empty()){
            pair<short,short> p = Q.front();
            Q.pop();
            a = p.first;
            b = p.second;
            set<short> &iset = mp[p];
            for(list<short>::iterator it = E[b].begin() ; it != E[b].end();){
                if(iset.count(*it) > 0){
                    it++;
                }
                else{
                    dp[b][*it] = dp[a][b] + 1;
                    pre[b][*it] = a;
                    Q.push(make_pair(b,*it));
                    it = E[b].erase(it);//处理判重！！
                }
            }
        }
        
        int ans = INF , ansPre;
        for(int i = 1 ; i < n ; i++){
            if(dp[i][n] < ans){
                ans = dp[i][n];
                ansPre = i;
            }
        }

        if(ans == INF)puts("-1");
        else{
            printf("%d\n",ans);
            print(ansPre,n);
            printf("%d\n",n);
        }
    }
    return 0;
}