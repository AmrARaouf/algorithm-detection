//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int N=2011;
vector<int> cld[N];
int level[N];
int n;
int in[N];
void sol()
{
    queue<int> Q;
    while(!Q.empty()) Q.pop();
    for(int i=1;i<=n;i++)
       if(!in[i]){
          Q.push(i);
          level[i]=1;
       }
    int res=1;
    while(!Q.empty())
    {
        int fth=Q.front();Q.pop();
        int lmt=cld[fth].size();
        for(int i=0;i<lmt;i++)
        {
            int v=cld[fth][i];
            Q.push(v); level[v]=level[fth]+1;
            if(level[v]>res) res=level[v];
        }
    }
    printf("%d\n",res);
}
int main()
{
    while(scanf("%d",&n)!=-1)
    {
        for(int i=1;i<=n;i++){
           cld[i].clear();
           in[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            int fth;
            scanf("%d",&fth);
            if(fth+1){
                cld[fth].push_back(i);
                in[i]++;
            }
        }
        sol();
    }
    return 0;
}