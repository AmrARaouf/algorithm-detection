//Language: GNU C++


#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
bool map[105][105];

void set(int i,int j)
{
    map[i][j]=map[j][i]=1;
}

void initial()
{
    memset(map,0,sizeof(map));
    set(1,3);set(1,4);set(2,100);
    for(int i=3;i<60;i+=2)
    {
         set(i,i+2),set(i,i+3);
         set(i+1,i+2),set(i+1,i+3);
    }
    for(int i=63;i<100;i++)  set(i,i+1);
}

void slove()
{
    int n;
    cin>>n;
    for(int i=30;i>0;i--)
         if(n>=(1<<i))
         {
             n-=(1<<i);
             set(2*i+1,65+i);
             set(2*i+2,65+i);
         }
    if(n)  set(1,65);
}

void input()
{
    cout<<"100"<<endl;
    for(int i=1;i<=100;i++)
    {
         for(int j=1;j<=100;j++)
         {
             if(map[i][j]) cout<<"Y";
             else cout<<"N";
         }
         cout<<endl;
    }
}

int main()
{
    initial();
    slove();
    input();
}


                                                                                                                                                               