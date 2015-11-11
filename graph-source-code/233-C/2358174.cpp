//Language: GNU C++


#include <iostream>
using namespace std;
int map[101][101];
int main()
{
     int n;
     cin>>n;
     n--;
     map[1][2]=1,map[1][3]=1;
     map[2][1]=1,map[2][3]=1;
     map[3][1]=1,map[3][2]=1;
     int m=3;
     while(n)
     {
         m++;
         map[m][1]=1;
         map[1][m]=1;
         int t=1;
         while(n>=t&&t<m-1)
         {
            n-=t;
            map[m][t+1]=1;
            map[t+1][m]=1;
            t++;        
         }
     }
     int i,j;
     cout<<m<<endl;
     for(i=1;i<=m;i++)
     {
        for(j=1;j<=m;j++)
         cout<<map[i][j];
        cout<<endl;
     }   
     return 0;
}
