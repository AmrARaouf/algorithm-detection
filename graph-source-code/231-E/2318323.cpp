//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int mm,n,m,d,l,a[1000],sum,i;

int x[210000],y[210000],next[210000],pr[210000], a1[210000], a2[210000], ti, ib[210000], u[210000], t1[210000], t2[210000], countt[210000], par[210000][20], h[210000];
int px[210000],py[210000],pnext[210000],ppr[210000];

int ee,co,tx,ty,tz;

void dfs(int v, int p)
{
     int i;
     ti++;
     a1[v] = ti;
     a2[v] = ti;
     
     i = pr[v];
     while (i)
           {
               if (y[i] == p)
                  {
                        i = next[i];
                        continue;
                  }
               if (a1[y[i]] == 0)
                  {
                    dfs(y[i],v);
                    if (a2[y[i]] < a2[v]) a2[v] = a2[y[i]];
                    
                    if (a2[y[i]]> a1[v])
                       {
                        ib[i] = 1;
                        if (i<=m) ib[i+m] = 1; else ib[i-m] = 1;
                       }
                  } else
               if (a1[y[i]] < a2[v]) a2[v] = a1[y[i]];
               i = next[i];
           }

     return ;
}

void rec(int v)
{
     int i;
     i = pr[v];
     u[v] = co;
     countt[co]++;
     while (i)
           {
               if (!ib[i])
               if (!u[y[i]]) rec(y[i]);
               
               i = next[i];
           }
     return ;
}

void go(int v, int p)
{
     int i;
     
     ee++;
     t1[v] = ee;
     
     par[v][0] = p;
     for (i=1;i<=19;i++) 
         {
          par[v][i] = par[par[v][i-1]][i-1];
          if (par[v][i] == 0) par[v][i] = 1;
         }
     if (p>0) h[v] = h[p];
     if (countt[v]>1) h[v]++;

     i = ppr[v];
     while (i)
           {

               if (py[i] != p) go(py[i],v);
               i = pnext[i];
           }
     
     ee++;
     t2[v] = ee;
     
     return ;
}

int ip(int v, int vv)
{
    if ((t1[v] <= t1[vv]) && (t2[vv]<= t2[v])) return 1; else return 0;
}

int lca(int v, int vv)
{
    if (ip(v,vv)) return v;
    if (ip(vv,v)) return vv;
    
    for (int i=19;i>=0;i--)
     if (!ip(par[v][i],vv)) v = par[v][i];
    return par[v][0];
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (i=1;i<=m;i++)
        {
         scanf("%d%d",&x[i],&y[i]);
         x[m+i] = y[i];
         y[m+i] = x[i];
        }
    for (i=1;i<=m+m;i++)
        {
         next[i] = pr[x[i]];
         pr[x[i]] = i;
        }
    ti = 0;
    dfs(1,0);

    co = 0;
    for (i=1;i<=n;i++)
        {
         if (!u[i])
            {
                   co++;
                   rec(i);
            }
        }
        
    mm = 0;
    for (i=1;i<=m+m;i++)
        if (u[x[i]] != u[y[i]])
        {
                        mm++;
                        px[mm] = u[x[i]];
                        py[mm] = u[y[i]];

                        pnext[mm] = ppr[px[mm]];
                        ppr[px[mm]] = mm;
        }        
    ee = 0;
    go(1,0);

    int k;    
    int tmp;
    long long ans,st, md = 1000000007;
    int aa;
    cin >> k;
    
  /*  for (i=1;i<=co;i++)
        {
                       cout << countt[i] << " " << endl;
        }*/
    while (k)
          {
                 k--;
                 scanf("%d%d",&tx,&ty);
                 
//                 cout << u[tx] << "   " << u[ty] << endl;
                 

                 if (ip(u[ty],u[tx]))
                    {
                     tmp = h[u[tx]];
                     if (u[ty] != 1) tmp -= h[par[u[ty]][0]];
                    } else
                 if (ip(u[tx],u[ty]))
                    {
                     tmp = h[u[ty]];
                     if (u[tx] != 1) tmp -= h[par[u[tx]][0]];
                    } else
                    {

                     tz = lca(u[tx],u[ty]);
                     tmp = h[u[tx]]+h[u[ty]];
                     if (tz != 1) tmp -= 2*h[par[tz][0]];
                     if (countt[tz]>1) tmp--;
                    }
                 ans = 1;
                 st = 2;   
                 while (tmp)
                       {
                            if (tmp %2 == 1) ans = (ans*st) % md;
                            st = (st*st)%md;
                            tmp /=2;
                       }
                 aa = ans;
                 printf("%d\n",aa);
          }

//    system("pause");
    return 0;
}
