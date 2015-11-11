//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

const int N=100010;
int a,b,n,pr;
vector<int>adj[N];

int main()
{
   //freopen("r.txt","r",stdin);
   scanf("%d",&n);
   printf("%d\n",n-1);
   for(int i=1;i<n;i++)
   {
       scanf("%d %d",&a,&b);
       adj[a].push_back(i), adj[b].push_back(i);///a and b are childreen of i
       printf("2 %d %d\n",a,b);
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=0;j<adj[i].size()-1;j++)
       {
           if(pr>=n-1)
              break;
           printf("%d %d\n", adj[i][j],adj[i][j+1]);
           pr++;
       }
   }

    return 0;
}
