//Language: GNU C++


#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;
int main()
{
    int k,i,j,num=2,n,m;
    scanf("%d",&k);
    if(k%2==0)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    n=2*(1+(k-1)+(k-1));
    m=n*k/2;
    printf("%d %d\n",n,m);
    printf("1 2\n");
    for(i=1;i<k;i++)
    {
        num++;
        printf("%d %d\n",1,num);
        v.push_back(num);
    }
    for(i=1;i<=(k-1)/2;i++)
    {
        num+=2;
        printf("%d %d\n",num-1,num);
        for(j=0;j<k-1;j++)
        {
            printf("%d %d\n",num-1,v[j]);
            printf("%d %d\n",num,v[j]);
        }
    }
    v.clear();
    for(i=1;i<k;i++)
    {
        num++;
        printf("%d %d\n",2,num);
        v.push_back(num);
    }
    for(i=1;i<=(k-1)/2;i++)
    {
        num+=2;
        printf("%d %d\n",num-1,num);
        for(j=0;j<k-1;j++)
        {
            printf("%d %d\n",num-1,v[j]);
            printf("%d %d\n",num,v[j]);
        }
    }
}
