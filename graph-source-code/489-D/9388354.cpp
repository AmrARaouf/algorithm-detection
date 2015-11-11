//Language: GNU C++


#include<cstdio>
#include<vector>
using namespace std;

typedef long long ll;

typedef  vector<int> vi;
typedef  vector<int> vl;

#define pb    push_back

bool edge[3005][3005];
vi g[3005];

int main(void)
{
  
    int n,m;
    scanf("%d%d",&n,&m);
    
        int i,j,k,u,v,cnt;
        for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
        edge[i][j]=false;


        while(m--)
        {
          scanf("%d%d",&u,&v);
          u--,v--;
            edge[u][v]=true;
            g[u].pb(v);
        }

     /*   for(i=0;i<n;i++)
            cout<<g[i].size()<<endl;*/

        ll res=0;
       // cout<<"n "<<n<<endl;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                    continue;
             
                cnt=0;
                for(k=0;k<g[i].size();k++)
                {
                    v=g[i][k];

                    if(v!=i && v!=j && edge[i][v] && edge[v][j])
                        {
                            cnt++;
                        }
                }
             
              
                res+=((ll)(cnt*(cnt-1))/2ll);
            }
        }
                   printf("%I64d\n",res);


    


    return 0;
} 