//Language: GNU C++


#include<set>
#include<cmath>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<numeric>
#include<vector>
#include<ctime>
#include<queue>
#include<list>
#include<map>
#define pi acos(-1)
#define INF 0x7fffffff
#define clr(x)  memset(x,0,sizeof(x));
#define clrto(x,siz,y)  for(int xx=0;xx<=siz;xx++)  x[xx]=y;
#define clrset(x,siz)  for(int xx=0;xx<=siz;xx++)  x[xx]=xx;
#define clrvec(x,siz) for(int xx=0;x<=siz;xx++)  x[xx].clear();
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define myprogram By_135678942570
#define clrcpy(x,siz,y)  for(int xx=0;xx<siz;xx++)  x[xx]=y[xx];
using namespace std;
priority_queue<pair<int,int> >Q1,Q2;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        if(t1==0)
           Q1.push(make_pair(-t2,i));
        else Q2.push(make_pair(-t2,i));
    }
    for(int i=1;i<n;i++)
    {
        pair<int,int> a=Q1.top(),b=Q2.top();
        Q1.pop();
        Q2.pop();
        if((-a.first)<(-b.first))
        {
            loop2:;
            printf("%d %d %d\n",a.second,b.second,-a.first);
            Q2.push(make_pair(b.first-a.first,b.second));
        }
        else if((-a.first)>(-b.first))
        {
            loop1:;
            printf("%d %d %d\n",a.second,b.second,-b.first);
            Q1.push(make_pair(a.first-b.first,a.second));
        }
        else
        {
           if(Q1.size()>Q2.size())
             goto loop2;
           else goto loop1;
        }
    }
    //while(1);
    return 0;
}
     