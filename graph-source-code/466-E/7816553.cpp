//Language: GNU C++0x


#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
typedef long long ll;
const int M = 100000+10;
struct Node
{
    int a,b,c;
};
Node d[M];
struct Ans
{
  int index;
  int num,who;
};
Ans ans[M];
int p[M],asd[M],b[M];
int n,m,aa,bb;
bool cmp(Ans a,Ans b)
{
    return a.num < b.num;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        p[i] = i;
    aa = bb = 0;
    for(int i = 0; i < m; i++)
    {
        int a;
        scanf("%d",&a);
        if(a == 3)
        {
            scanf("%d%d",&ans[aa].who,&ans[aa].num);
            ans[aa].index = aa++;
        }
        else if(a == 1)
        {
            scanf("%d%d",&d[bb].b,&d[bb].c);
            d[bb].a = a;
            bb++;
        }
        else
        {
            scanf("%d",&d[bb].b);
            d[bb].a = a;
            bb++;
        }
    }
    sort(ans,ans+aa,cmp);
    int temp = 1,flag = 0;
    for(int i = 0; i < bb; i++)
    {
        if(d[i].a == 1)
        {
            p[d[i].b] = d[i].c;
        }
        else
        {
            for(int j = flag; j < aa; j++)
            {
                int x = d[i].b;
                if(ans[j].num == temp)
                {
                    bool tab = false;
                    int tab2 = 0;
                    while(1)
                    {
                        if(x == ans[j].who)
                        {
                            tab = true;
                            break;
                        }
                        x = p[x];
                        if(x == p[x])
                            tab2++;
                        if(tab2 > 1)
                            break;
                    }
                    if(tab)
                        asd[ans[j].index] = 1;
                    else
                        asd[ans[j].index]  = 0;
                    flag++;
                }
                else
                    break;
            }
            temp++;
        }
    }
    for(int i = 0; i < aa; i++)
    {
        if(asd[i] == 1)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
