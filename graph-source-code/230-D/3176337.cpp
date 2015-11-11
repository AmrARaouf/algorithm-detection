//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
struct put
{
    int nom,ras;
};
put x;
vector < vector <put> > g;
struct tim
{
    int ti,zaz;
};
tim b;
vector < vector <tim> > t;
int n,m;
struct ans
{
    int ver,res;
};
ans a[9800003];
int cou[100003];
bool flag[100003];

int main()
{
    scanf("%d %d",&n,&m);
    int i,j,jj;
    int y,z,c;
    g.resize(n+1);
    t.resize(n+1);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&z,&y,&c);
        z--;
        y--;
        x.ras=c;
        x.nom=y;
        g[z].push_back(x);
        x.nom=z;
        g[y].push_back(x);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&y);
        for(j=0;j<y;j++)
        {
            scanf("%d",&z);
            b.ti=z;
            b.zaz=0;
            t[i].push_back(b);
        }
        j=t[i].size()-1;
        if(j>-1)
        {
            t[i][j].zaz=t[i][j].ti+1;
            j--;
        }
        while(j>-1)
        {
            if(t[i][j].ti==t[i][j+1].ti-1)
                t[i][j].zaz=t[i][j+1].zaz;
            else
                t[i][j].zaz=t[i][j].ti+1;
            j--;
        }
    }
    for(i=0;i<n;i++)
        cou[i]=2000000000;
    cou[0]=0;
    for(i=1;i<=9800000;i++)
        a[i].res=2000000000;

    while(cou[0]<t[0].size() && t[0][cou[0]].ti==cou[0])
        cou[0]++;
    a[1].ver=0;
    a[1].res=cou[0];
    int last=1;
    int l,r,re;
    while(last>0)
    {
        flag[a[1].ver]=true;
        if(a[1].ver==n-1)
        {
            cou[n-1]=a[1].res;
            break;
        }
        for(i=0;i<g[a[1].ver].size();i++)
        {
            if(!flag[g[a[1].ver][i].nom])
            {
                j=a[1].res;
                l=0;
                r=t[a[1].ver].size();
                while(r-l>1)
                {
                    re=((l+r)>>1);
                    if(j<t[a[1].ver][re].ti)
                        r=re;
                    else
                        l=re;
                }
                if(l<t[a[1].ver].size())
                    if(j==t[a[1].ver][l].ti)
                        j=t[a[1].ver][l].zaz;

                y=j+g[a[1].ver][i].ras;
                last++;
                z=last;
                while(z>1 && y<a[(z>>1)].res)
                {
                    a[z]=a[(z>>1)];
                    z>>=1;
                }
                a[z].res=y;
                a[z].ver=g[a[1].ver][i].nom;
            }
        }
        z=1;
        y=a[last].res;
        while(z*2<last && y>min(a[z*2].res,a[z*2+1].res))
        {
            if(a[z*2].res<=a[z*2+1].res)
            {
                a[z]=a[z*2];
                z*=2;
            }
            else
            {
                a[z]=a[z*2+1];
                z*=2;
                z++;
            }
        }
        a[z]=a[last];
        last--;
    }


    if(cou[n-1]==2000000000)
        printf("-1\n");
    else
        printf("%d\n",cou[n-1]);
    return 0;
}
