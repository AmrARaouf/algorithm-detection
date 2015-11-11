//Language: GNU C++


#include <vector>
#include <algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define F(k) for(long long i=1;i<=k;i++)

int main()
{
       //  ios_base::sync_with_stdio(false);
          int n,i,k,l,h;
            scanf("%d",&n);

              int p[n+1],a[n+1];
              vector<int> v[n+1],c[n+1],b(n+1),d(n+1); vector<int> :: iterator it,kt;
              queue<int> q;
              memset(a+1,0,sizeof(a));

               F(n) scanf("%d",&p[i]);

         /*      for(i=1;i<=n;i++)
               {
                    q.push(i);
                    while(!q.empty())
                    {
                        k=q.front(), q.pop();
                       for(l=1;l<=n;l++)
                         if(p[l]==k)
                         {
                              c[i].push_back(l);
                              q.push(l);
                         }

                    }

                    sort(c[i].begin(),c[i].end());

               }

                        */

               i=0;
               while(i++<n)
               {
                     l=i;
                     while(true)
                     {
                          v[i]. push_back(l);
                          if((l=p[l])==-1) break;
                     }

                     sort(v[i].begin(),v[i].end());
               }

                 i=0, k=0;
                 while(i++<n)
                 {
                       if(a[i]) continue;

                        vector<int> z;
                        l=i-1;

                         while(l++<n)
                         {
                             if(a[l]) continue;

                        it= set_intersection(z.begin(),z.end(),v[l].begin(),v[l].end(),b.begin());
                          if(it!=b.begin()) continue;

                               h=-1;
                               do
                               {
                                    h++;
                               }    while(h<z.size()&& !binary_search(v[z[h]].begin(),v[z[h]].end(),l));
                            //   {
                                 //   if(!binary_search(v[z[h]].begin(),v[z[h]].end(),l))
                                   //     break;
                                     //it= set_intersection(z.begin(),z.end(),v[l].begin(),v[l].end(),b.begin());
                              // }
                     //   kt= set_intersection(z.begin(),z.end(),c[l].begin(),c[l].end(),d.begin());

                             if(h==z.size())
                             {
                                   z.push_back(l);
                                   a[l]=true;
                             }

                         }

                           k++;

                 }

                       printf("%d",k);

          return 0 ;
}
