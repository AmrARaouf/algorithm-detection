//Language: GNU C++


#include<bits/stdc++.h>
#define pb push_back
#define mm 100
using namespace std;
/*
int x[]={1,-1,0,0,1,1,-1,-1};
int y[]={0,0,1,-1,1,-1,1,-1};
bool taken[mm][mm];
int dist[mm][mm];
int ans;
int n;
int m;

char a[mm][mm];
void dfs(int i,int j)
{
    taken[i][j]=1;
    for(int k=0;k<8;k++)
    {
        int ki=i+y[k];
        int kj=j+x[k];
        if(ki>=0 && ki<n && kj>=0 && kj<m && a[ki][kj]==a[i][j])

        {
            if(taken[ki][kj]==0){
           dist[ki][kj]=dist[i][j]+1;
           dfs(ki,kj);}
           else
           {
               if(dist[i][j]-dist[ki][kj]>=3)ans=1;
           }
        }
    }

}
int main()
{
    //int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans=0;
            memset(taken,0,sizeof taken);
            dist[i][j]=0;
            dfs(i,j);
            if(ans==1)
            break;

        }
        if(ans==1)break;

    }
    if(ans==1)printf("Yes\n");
    else printf("No\n");
    return 0;
}
*/
vector<string>a;
vector<int>ad[26];
int in[26];
int out[26];
bool taken[26];
int main()
{

    int n;
    scanf("%d",&n);
    string x;
    for(int i=1;i<=n;i++)
    {

       //printf("rue");
        cin>>x;
    //cout<<x<<endl;
        a.pb(x);
    }
    char f=a[0][0];
   // printf("%c",f);
   int imp=0;
   for(int i=1;i<n;i++)
   {
       //printf("a");
       string nw=a[i];
       string pr=a[i-1];
       //printf("%d",nw.size());
       if(f==nw[0])
       {
           //printf("efwf");
           int j;
           int xx=min(pr.size(),nw.size());
           for( j=1;j<xx;j++)
           {
               if( pr[j]==nw[j])
               {
                   //printf("fguwer");
                   continue;
               }
               else
               {
                   //printf("iiii");
                   ad[pr[j]-97].pb(nw[j]-97);
                   out[pr[j]-97]++;
                   in[nw[j]-97]++;
                   break;
               }
           }
           if(j==xx&& nw.size()<pr.size())imp=1;
           //printf("asa");
       }
       else
       {
           ad[f-97].pb(nw[0]-97);
           out[pr[0]-97]++;
            in[nw[0]-97]++;
       }
       f=nw[0];

   }
   vector<int>ans;
   while(1)
   {
       //printf("rue");
       int c=0;
       for(int i=0;i<26;i++)
       {
           if(in[i]==0 && out[i]!=0)
           {
               ans.pb(i);
               //printf("+%c\n",i+97);
               taken[i]=1;
               c=1;
               for(int j=0;j<ad[i].size();j++)
               {
                   int u=ad[i][j];
                   out[i]--;
                   in[u]--;
               }
           }
       }
       if(c==0)break;
   }
   for(int i=0;i<26;i++)
   {
       if(!(in[i]==0 &&out[i]==0)){imp=1;break;}
   }
   if(imp==1)printf("Impossible\n");
   else
   {
       //printf("Yes\n");
       for(int i=0;i<ans.size();i++)printf("%c",ans[i]+97);
       for(int i=0;i<26;i++)
       {
           if(!taken[i])printf("%c",i+97);
       }
       printf("\n");
   }


    return 0;
}

