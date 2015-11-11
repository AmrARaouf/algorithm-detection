//Language: GNU C++


#include<bits/stdc++.h>
#include <stdio.h>
#include<set>
#include<map>
#include<queue>
#define sf(x) scanf("%d", &x);
#define scan(x) scanf("%I64d", &x);
#define pr(x) printf("%d ", x);
#define distance(x1,y1,x2,y2) sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
/**********************************************
ll fact(ll x){ return (x==1 ?  1 : (x*fact(x-1))); }
/***************************************************
int gcd (int x,int y) {return ( y ? gcd(y,x%y) : x);}
/*****************************************************
void seive()
{for(ll i=2;i<=1000000;i++){prime[i]++;for(ll j=i+i;j<=1000000;j+=i)prime[j]++;}}
/********************************************************/
void yala_bena(){cin.tie(0);std::ios::sync_with_stdio(0);}
const int m_r=199999;
int main()
{
yala_bena();
int n,cycle=0;
cin>>n;
cycle=(n/2)*(n-n/2);
cout<<cycle<<endl;
if(n==4 || n==3)
{
 for(int i=1;i<=cycle;i++)
 {
     if(i==4)
     cout<<i<<" "<<1<<endl;
     else
        cout<<i<<" "<<i+1<<endl;
 }
 return 0;
}
for(int i=1;i<=n/2;i++)
{
 for(int j=(n/2)+1,k=1;k<=((n/2)+(n%2));j++,k++)
 {
     cout<<i<<" "<<j<<endl;
 }
}
}
