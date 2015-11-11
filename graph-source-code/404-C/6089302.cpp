//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<cmath>
using namespace std;
int p[101010],s[101010];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r" ,stdin);
    #endif // ONLINE_JUDGE
    int  n,k,i,j;
    while(cin>>n>>k)
    {
        int mm=0;
        memset(s,0,sizeof(s));
        vector<int >ko[101010];
        for(i=1; i<=n; i++)
        {
            scanf("%d",&p[i]);
            mm=max(mm,p[i]);
            ko[p[i]].push_back(i);
            s[p[i]]++;
        }
        if(s[0]!=1)
        {
            printf("-1\n");
            continue;
        }
        int pos=0,sum=0;
        for(i=1; i<=mm; i++)
            if(s[i])
            {
                sum+=s[i];
                if(i==1)
                {
                    if(1ll*s[i-1]*k<s[i])
                    {
                        pos=1;
                        break;
                    }
                }
                else
                {
                    if(1ll*s[i-1]*(k-1)<s[i])
                    {
                        pos=1;
                        break;
                    }
                }
            }
        if(pos)
            printf("-1\n");
        else
        {
            printf("%d\n",sum);
            for(i=1; i<=mm; i++)
            {
                int ln=ko[i-1].size(),kk=0,ll=0;
                for(j=0; j<ln&&ll<ko[i].size();)
                {
                    if(i==1)
                    {
                        if(kk<k)
                        {
                            printf("%d %d\n",ko[i-1][j],ko[i][ll]);
                            ll++;
                            kk++;
                        }
                        if(kk==k)
                        {
                            kk=0;
                            j++;
                        }

                    }
                    else

                    {
                        if(kk<k-1)
                        {
                            printf("%d %d\n",ko[i-1][j],ko[i][ll]);
                            ll++;
                            kk++;
                        }
                        if(kk==k-1)
                        {
                            kk=0;
                            j++;
                        }
                    }

                }
            }
        }
    }
}
