//Language: MS C++


#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int pow(int a, int b)
{
    int c= 1;
    for(int i = 0; i < b; i ++)
    {
        c *= a;
    }
    return c;
}
void main()
{
    int n, m; cin >> n >> m;
    int counter = 0;
    while(n != m)
    {
        if(n * 2 < m)
        {
            int c2 = ceil((log(m / (n + 0.0)))/ log(2.0));
            //cout << n << endl;
            int x = (m / (pow(2, c2)+ 0) - n);
            if((n * pow((int)2, c2)) -pow(2,c2)>= m)
            {
                n --; counter ++;
            }
            else
            {
                n*=2; counter ++;
            }
        }
        else if(n * 2 -m >= 2)
        {
            n--; counter ++;
        }
        else if(n * 2 == m)
        {
            n *= 2; counter ++;
        }
        else
        {
            n *= 2; n--; counter +=2;
        }
    }
    cout << counter;
}