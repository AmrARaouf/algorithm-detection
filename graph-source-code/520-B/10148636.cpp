//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,m;
scanf("%d%d",&n,&m);
if(m<=n)cout<<n-m;
else
{
int ctr=0;
while(m>n)
{
if(m&1){m++;ctr++;}
m = m/2;
ctr++;
}
ctr+=n-m;
cout<<ctr;
}
return 0;
}
