//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int maxn=122;
bool used[maxn][maxn];
int n, m, mm;
int c[maxn][4];
vector<int> que;

void yansuan()
{
    int ret=0;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            for(int k=j+1;k<=n;++k)
                if(used[i][j] && used[j][k] && used[i][k])
                    ++ret;
    cout<<ret<<endl;
    if(ret==mm)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;    
}
int main()
{
    scanf("%d", &m);
    mm=m;
    c[1][0]=1;
    c[1][1]=1;
    for(int i=2;i<=100;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=3;++j)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    
    for(int i=100;i>=3;--i)
        if(m>=c[i][3])
        {
            que.push_back(i);
            m-=c[i][3]; 
            
            break;             
        }
        
    while(m>0)
    {
        for(int i=que[0];i>=2;--i)
            if(m>=c[i][2])
            {
                que.push_back(i);
                m-=c[i][2];             
            }          
    }
    
    memset(used, false, sizeof(used));
    for(int i=1;i<=que[0];++i)
        for(int j=i+1;j<=que[0];++j)
            for(int k=j+1;k<=que[0];++k)
            {
                used[i][j]=true;
                used[j][i]=true;
                
                used[j][k]=true;
                used[k][j]=true;
                
                used[i][k]=true;  
                used[k][i]=true;      
            }
            
    for(int i=1;i<que.size();++i)
    {
        for(int j=1;j<=que[i];++j)
        {
            used[j][que[0]+i]=true;   
            used[que[0]+i][j]=true;
        }     
    }
    
    n=que[0]+que.size()-1;
    printf("%d\n", n);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            if(used[i][j]) printf("1");
            else printf("0");
        printf("\n");        
    }
    
    //yansuan();
    //system("pause");
    return 0;
}
