//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <ctime>

#define PB push_back
#define MP std::make_pair
#define vs vector<string>
#define vi vector<int>
#define PHI 3.14159265359

time_t waktu=clock();
void gettime() {
    printf("\nTime : %.2lf",(clock()-waktu)/double(CLOCKS_PER_SEC));
}

bool comp(int a,int b) {
    return (a>b);
}

using namespace std;

int n,m,hasil[3002][2]={},x;
vi data[3002];

void cek(int y,int count) {
     if (count<=2) {
        if (count==2) {
           if (hasil[y][1]==x) hasil[y][0]++;
           else {
                hasil[y][0]=1;
                hasil[y][1]=x;
           }
        }
        else {
             int i,j=data[y].size();
             count++;
             for (i=0;i<j;i++) {
                 cek(data[y][i],count);
             }
        }
     }
}

int main()
{
    int a,b,i,j,c;
    long long int ans=0;
    scanf("%d %d",&n,&m);
    for (i=0;i<m;i++) {
        scanf("%d %d",&a,&b);
        data[a].PB(b);
    }
    for (i=1;i<=n;i++) {
        x=i;
        cek(i,0);
        for (j=1;j<=n;j++) {
            if (hasil[j][1]==i && j!=i) {
               c=hasil[j][0];
               c*=(hasil[j][0]-1);
               c/=2;
               ans+=c;
            }
        }
    }
    cout<<ans;
    return 0;
}
