//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct node
{
  int sx,sy,tx,ty;  
};
struct node2
{
   int dian,next;
   double len;
};
const double maxn=1000000000;
int ge;
int g[2000],s,t;
double len[2000];
node2 bin[2000000];
node line[2000];
double map[2000][2000];
bool use[2000];
void jia(int x,int y,double z)
{
    ge++;
    bin[ge].dian=y;
    bin[ge].next=g[x];
    bin[ge].len=z;
    g[x]=ge;
}
double getlen(int x,int y,int x1,int y1)
{
    double xx,yy;
     xx=x-x1;
     yy=y-y1;
     return sqrt(xx*xx+yy*yy);
}
double getlen(int x,int y,node z)
{
    if(z.sx==z.tx)
    {
        if(y>=min(z.sy,z.ty) && y<=max(z.sy,z.ty)) return abs(z.sx-x);  
        else
        {
            return min(getlen(x,y,z.sx,z.sy),getlen(x,y,z.tx,z.ty));
        }
    }else
    {
        if(x>=min(z.sx,z.tx) && x<=max(z.sx,z.tx)) return abs(z.sy-y);
        else
        {
           return min(getlen(x,y,z.sx,z.sy),getlen(x,y,z.tx,z.ty));
        }   
    }
}

double getlen(node x,node y)
{
    return min(min(getlen(x.sx,x.sy,y),getlen(x.tx,x.ty,y)),
        min(getlen(y.sx,y.sy,x),getlen(y.tx,y.ty,x)));
}

void getshort()
{
    
    for(int j=1;j<=t;j++) {len[j]=maxn; use[j]=false;}
    len[s]=0;
    while(true)
    {
        double da=maxn;
        int p;
       for(int j=1;j<=t;j++)
           if(!use[j] && len[j]<da)
           {
              da=len[j];
              p=j;
           }
       if(da==maxn) break; 
       use[p]=true;
       int ke=g[p];
       while(ke!=0)
       {
           int d=bin[ke].dian;
           if(len[p]+bin[ke].len<len[d]) len[d]=len[p]+bin[ke].len;
           ke=bin[ke].next;
       }
    }

}
int main()
{
    int a,b,sx,sy,tx,ty,n;
    scanf("%d %d",&a,&b);
    scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
    scanf("%d",&n);
    for(int j=1;j<=n;j++)
    {
        scanf("%d %d %d %d",&line[j].sx,&line[j].sy,&line[j].tx,&line[j].ty);
    }
    s=n+1; t=n+2;
    map[s][t]=map[t][s]=getlen(sx,sy,tx,ty);
    for(int j=1;j<=n;j++)
    {
        map[s][j]=getlen(sx,sy,line[j]);
        map[j][s]=map[s][j];
        map[t][j]=getlen(tx,ty,line[j]);
        map[j][t]=map[t][j];
    }
    for(int j=1;j<n;j++)
        for(int i=j+1;i<=n;i++)
        {
           map[j][i]=getlen(line[j],line[i]);
           map[i][j]=map[j][i];
        }
   for(int j=1;j<=t;j++)
   {
      for(int i=1;i<=t;i++)
          if(j!=i && map[j][i]<=a)
          {
              if(i!=t)
              jia(j,i,a+b);
              else jia(j,i,map[j][i]);
          }
   }
   getshort();
   if(len[t]==maxn) printf("-1\n");
   else printf("%0.8lf\n",len[t]);
   return 0;
}