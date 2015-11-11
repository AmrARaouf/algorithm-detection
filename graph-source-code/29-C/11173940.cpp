//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
#define si(n) scanf("%d",&n)
#define sli(n) scanf("%lld",&n)
#define ss(a) scanf("%s",a)
#define pb push_back
//typedef pair<int,int >pr;
typedef struct pars{
     int first;
     int second;
}pr;

pr a[100011];
int main(){
     int n,i,j,x1,x2;
     map<int,int>mp;
     multiset<int> st;
     int ans[100011];
     si(n);

     for(i=0;i<n;i++)
     {
          si(a[i].first),si(a[i].second);
          if(st.find(a[i].first)!=st.end())
               mp[-a[i].first]=i;
          else
               mp[a[i].first]=i;

          if(st.find(a[i].second)!=st.end())
               mp[-a[i].second]=i;
          else
               mp[a[i].second]=i;

          st.insert(a[i].first);
          st.insert(a[i].second);
     }
     for(i=0;i<n;i++)
     {
          if(st.count(a[i].first)==1 )
          {
               ans[0]=a[i].first;
               ans[1]=a[i].second;
               if(mp[a[i].second]==i)
                    mp.erase(a[i].second);

               else
                    mp.erase(-a[i].second);
               break;
          }

          if(st.count(a[i].second)==1)
          {
               ans[0]=a[i].second;
               ans[1]=a[i].first;
               if(mp[a[i].first]==i)
                    mp.erase(a[i].first);

               else
                    mp.erase(-a[i].first);
               break;
          }

     }
     char fl='\0';

     for(i=2;i<n+1;i++)
     {
          if(mp.find(ans[i-1])!=mp.end())
               x1=mp[ans[i-1]],fl='p';
          else
               x1=mp[-ans[i-1]],fl='n';
          //cout<<"x1="<<x1<<endl;
          if(a[x1].first!=ans[i-1])	
          {
               ans[i]=a[x1].first;
               if(mp[ans[i]]==x1)
               {	//cout<<"1"<<endl;
                    mp.erase(ans[i]);
               }

               else
                    mp.erase(-ans[i]);//,cout<<"2"<<endl;
               x1=ans[i];
          }

          else
          {
               ans[i]=a[x1].second;
               if(mp[ans[i]]==x1)
                    mp.erase(ans[i]);

               else
                    mp.erase(-ans[i]);
               x1=ans[i];
          }
     }

     for(i=0;i<n+1;i++)
          printf("%d ",ans[i]); printf("\n");
     return 0;
}

