//Language: GNU C++


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#define mod 1000000007
using namespace std;
int n,k;
int win[1003];
struct ans
{
    int x,y;
};
ans a[1000003];
int coun;
int main()
{
    scanf("%d %d",&n,&k);
    int i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            if(win[i]<k)
            {
                win[i]++;
                a[coun].x=i+1;
                a[coun++].y=j+1;
            }
            else if(win[j]<k)
            {
                win[j]++;
                a[coun].x=j+1;
                a[coun++].y=i+1;
            }
        }
    for(i=0;i<n;i++)
        if(win[i]<k)
        {
            printf("-1\n");
            return 0;
        }
    printf("%d\n",coun);
    for(i=0;i<coun;i++)
        printf("%d %d\n",a[i].x,a[i].y);
    return 0;
}
/*


 */
